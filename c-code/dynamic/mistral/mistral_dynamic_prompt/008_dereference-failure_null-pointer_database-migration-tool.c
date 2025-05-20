#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[100];
    char address[150];
    int age;
} Record;

Record* records;
int num_records = 0;

void add_record(char name[], char address[], int age) {
    if (num_records == MAX_RECORDS) {
        printf("Error: Max number of records reached.\n");
        return;
    }
    records[num_records].age = age;
    strcpy(records[num_records].name, name);
    strcpy(records[num_records].address, address);
    num_records++;
}

int main() {
    char input_name[100], input_address[150];
    int input_age;

    printf("Database Migration Tool\n");

    while (1) {
        printf("\nEnter record details (or leave empty to exit):\n");
        printf("Name: ");
        scanf("%s", input_name);

        if (strlen(input_name) == 0)
            break;

        printf("Address: ");
        scanf("%s", input_address);
        printf("Age: ");
        scanf("%d", &input_age);

        // Dereference failure vulnerability in the next line
        add_record(input_name, input_address, input_age);

        // Access uninitialized memory after num_records, potentially causing a segmentation fault
        printf("Record added: %s %s %d\n", records[num_records].name, records[num_records].address, records[num_records].age);
    }

    return 0;
}
