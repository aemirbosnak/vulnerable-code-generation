//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_NUM_FIELDS 10

int main(int argc, char *argv[]) {
    FILE *csv_file;
    char line[MAX_LINE_LENGTH];
    char *fields[MAX_NUM_FIELDS];
    int num_fields, i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename.csv\n", argv[0]);
        return 1;
    }

    if ((csv_file = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    // Read header line
    if (fgets(line, MAX_LINE_LENGTH, csv_file) == NULL) {
        fprintf(stderr, "Error: Could not read header line\n");
        return 1;
    }

    num_fields = 0;
    fields[num_fields] = strtok(line, ",");
    while (fields[num_fields] != NULL && num_fields < MAX_NUM_FIELDS) {
        num_fields++;
        fields[num_fields] = strtok(NULL, ",");
    }

    if (num_fields == 0) {
        fprintf(stderr, "Error: No fields found in header line\n");
        return 1;
    }

    // Print header line
    for (i = 0; i < num_fields; i++) {
        printf("%s", fields[i]);
        if (i < num_fields - 1) {
            printf(",");
        } else {
            printf("\n");
        }
    }

    // Read data lines
    while (fgets(line, MAX_LINE_LENGTH, csv_file) != NULL) {
        num_fields = 0;
        fields[num_fields] = strtok(line, ",");
        while (fields[num_fields] != NULL && num_fields < MAX_NUM_FIELDS) {
            num_fields++;
            fields[num_fields] = strtok(NULL, ",");
        }

        if (num_fields != 0) {
            // Print data line
            for (i = 0; i < num_fields; i++) {
                printf("%s", fields[i]);
                if (i < num_fields - 1) {
                    printf(",");
                } else {
                    printf("\n");
                }
            }
        }
    }

    fclose(csv_file);
    return 0;
}