#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define RECORD_SIZE 200

struct Record {
    char data[RECORD_SIZE];
};

void readDataFile(const char *filename, struct Record *records, int *numRecords) {
    FILE *file = fopen(filename, "r");
    int i = 0;
    char line[RECORD_SIZE];

    while (fgets(line, RECORD_SIZE, file)) {
        if (i >= *numRecords) {
            *numRecords += 100;
            records = realloc(records, (*numRecords) * sizeof(struct Record));
        }
        strcpy(records[i].data, line);
        i++;
    }
    fclose(file);
    *numRecords = i;
}

void writeDataFile(const char *filename, struct Record *records, int numRecords) {
    FILE *file = fopen(filename, "w");

    for (int i = 0; i < numRecords; i++) {
        fprintf(file, "%s", records[i].data);
    }

    fclose(file);
}

int main(int argc, char **argv) {
    struct Record *records;
    int numRecords;

    if (argc != 3) {
        printf("Usage: migrate_db input_file output_file\n");
        return 1;
    }

    readDataFile(argv[1], records, &numRecords);

    // Memory leak! The memory allocated for records is not freed here.

    writeDataFile(argv[2], records, numRecords);

    return 0;
}
