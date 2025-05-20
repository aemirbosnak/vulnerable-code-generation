//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUM_DATA 10

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    int value;
} DataRecord;

bool isValidName(const char *name) {
    size_t len = strlen(name);
    if (len > MAX_NAME_LENGTH || len == 0) {
        return false;
    }
    for (size_t i = 0; i < len; i++) {
        if (!isalnum(name[i]) && name[i] != '_') {
            return false;
        }
    }
    return true;
}

bool readDataFile(const char *filename, DataRecord records[MAX_NUM_DATA]) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return false;
    }

    int num_records = 0;
    while (num_records < MAX_NUM_DATA && fscanf(file, "%s%d", records[num_records].name, &records[num_records].value) == 2) {
        if (!isValidName(records[num_records].name)) {
            fprintf(stderr, "Invalid name: %s\n", records[num_records].name);
            break;
        }
        num_records++;
    }

    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return false;
    }

    fclose(file);
    return true;
}

bool writeDataFile(const char *filename, const DataRecord *records, int num_records) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        return false;
    }

    for (int i = 0; i < num_records; i++) {
        if (!fprintf(file, "%s %d\n", records[i].name, records[i].value)) {
            perror("Error writing to file");
            fclose(file);
            return false;
        }
    }

    if (ferror(file)) {
        perror("Error writing to file");
        fclose(file);
        return false;
    }

    fclose(file);
    return true;
}

int main() {
    DataRecord data[MAX_NUM_DATA];

    if (!readDataFile("data.txt", data)) {
        fprintf(stderr, "Failed to read data file\n");
        return EXIT_FAILURE;
    }

    // Process the data
    // ...

    if (!writeDataFile("data.txt", data, MAX_NUM_DATA)) {
        fprintf(stderr, "Failed to write data file\n");
        return EXIT_FAILURE;
    }

    printf("Data file processed successfully.\n");
    return EXIT_SUCCESS;
}