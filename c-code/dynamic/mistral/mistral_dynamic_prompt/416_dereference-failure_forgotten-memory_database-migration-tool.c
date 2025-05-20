#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Record {
    char name[MAX_SIZE];
    int age;
    char email[MAX_SIZE];
};

void readData(struct Record*, int);
void writeData(struct Record*);

int main() {
    struct Record data[MAX_SIZE];
    int num_records;

    printf("Enter the number of records to be migrated: ");
    scanf("%d", &num_records);

    readData(data, num_records);
    writeData(data);

    return 0;
}

void readData(struct Record* records, int num) {
    for (int i = 0; i < num; i++) {
        printf("Enter record %d data:\n", i+1);
        printf("Name: ");
        scanf("%s", records[i].name);
        printf("Age: ");
        scanf("%d", &records[i].age);
        printf("Email: ");
        scanf("%s", records[i].email);
    }
}

void writeData(struct Record* records) {
    printf("\nData Migrated:\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("\nName: %s\nAge: %d\nEmail: %s\n", records[i].name, records[i].age, records[i].email);
        printf("Printing freed memory: %p\n", &(records[i+MAX_SIZE].age)); // Dereference forgotten memory
    }
}
