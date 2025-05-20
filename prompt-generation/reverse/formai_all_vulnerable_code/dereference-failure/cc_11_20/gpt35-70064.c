//FormAI DATASET v1.0 Category: Data mining ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELD_LENGTH 50
#define MAX_FIELDS 10
#define MAX_RECORDS 1000

struct record {
    char fields[MAX_FIELDS][MAX_FIELD_LENGTH];
};

int main() {
    FILE *data_file;
    char line[MAX_LINE_LENGTH];
    struct record records[MAX_RECORDS];
    int num_records = 0, num_fields = 0;
    char delimiter = ',';

    data_file = fopen("data.csv", "r");
    if (!data_file) {
        printf("Unable to open data file!\n");
        return 1;
    }

    // Read the first line to get field names
    if (fgets(line, MAX_LINE_LENGTH, data_file) != NULL) {
        char *field = strtok(line, &delimiter);
        while (field != NULL && num_fields < MAX_FIELDS) {
            strcpy(records[0].fields[num_fields++], field);
            field = strtok(NULL, &delimiter);
        }
    }

    // Read the rest of the lines to get records
    while (num_records < MAX_RECORDS && fgets(line, MAX_LINE_LENGTH, data_file) != NULL) {
        int field_index = 0;
        char *field = strtok(line, &delimiter);
        while (field != NULL && field_index < num_fields) {
            strcpy(records[num_records].fields[field_index++], field);
            field = strtok(NULL, &delimiter);
        }
        num_records++;
    }

    // Close the file
    fclose(data_file);

    // Display the records
    printf("Found %d records with %d fields:\n", num_records, num_fields);
    for (int i = 0; i < num_records; i++) {
        for (int j = 0; j < num_fields; j++) {
            printf("%s\t", records[i].fields[j]);
        }
        printf("\n");
    }

    return 0;
}