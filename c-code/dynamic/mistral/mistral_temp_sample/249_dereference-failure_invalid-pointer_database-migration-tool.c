#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record {
    char name[50];
    int age;
    char phone[15];
} Record;

Record* records;
int num_records;

void read_data() {
    FILE* file = fopen("data.txt", "r");
    if (!file) {
        fprintf(stderr, "Error: Unable to open data file.\n");
        exit(1);
    }

    Record temp_record;
    while (fscanf(file, "%s %d %s\n", temp_record.name, &temp_record.age, temp_record.phone) == 3) {
        if (num_records >= MAX_RECORDS) {
            fprintf(stderr, "Error: Reached maximum number of records.\n");
            exit(1);
        }
        records[num_records] = temp_record;
        num_records++;
    }

    fclose(file);
}

void write_data() {
    FILE* file = fopen("new_data.txt", "w");
    if (!file) {
        fprintf(stderr, "Error: Unable to open new data file.\n");
        exit(1);
    }

    for (int i = 0; i < num_records; i++) {
        fprintf(file, "%s %d %s\n", records[i].name, records[i].age, records[i].phone);
    }

    fclose(file);
}

int main() {
    records = (Record*) malloc(MAX_RECORDS * sizeof(Record));
    num_records = 0;

    read_data();

    // Dereference failure vulnerability:
    printf("%s\n", records[num_records].name);

    write_data();

    free(records);
    return 0;
}
