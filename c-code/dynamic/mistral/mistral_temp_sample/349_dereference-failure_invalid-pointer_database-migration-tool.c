#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct Record {
    char name[100];
    int age;
} Record;

Record* load_records(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    Record* records = (Record*)malloc(sizeof(Record) * 100);
    if (!records) {
        fprintf(stderr, "Error allocating memory for records\n");
        fclose(file);
        exit(1);
    }

    int count = 0;
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        sscanf(buffer, "%s %d", records[count].name, &records[count].age);
        count++;
    }
    fclose(file);

    return records;
}

void save_records(Record* records, const char* filename, int count) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d\n", records[i].name, records[i].age);
    }
    fclose(file);
}

int main() {
    Record* records = load_records("database.txt");

    // Deliberate invalid dereference
    printf("Name: %s, Age: %d\n", records[100].name, records[100].age);

    save_records(records, "new_database.txt", 100); // Assume we have 100 records
    free(records);

    return 0;
}
