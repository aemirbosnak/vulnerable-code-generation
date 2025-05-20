//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_SIZE 100
#define MAX_ROW_SIZE 1000

int main(int argc, char *argv[]) {
    char *csv_file;
    char *delimiter = ",";
    int max_field_size = MAX_FIELD_SIZE;
    int max_row_size = MAX_ROW_SIZE;
    int has_header = 0;

    /* Read configuration options */
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--delimiter") == 0) {
            if (i + 1 < argc) {
                delimiter = argv[i + 1];
            }
        } else if (strcmp(argv[i], "--field-size") == 0) {
            if (i + 1 < argc) {
                max_field_size = atoi(argv[i + 1]);
            }
        } else if (strcmp(argv[i], "--row-size") == 0) {
            if (i + 1 < argc) {
                max_row_size = atoi(argv[i + 1]);
            }
        } else if (strcmp(argv[i], "--header") == 0) {
            has_header = 1;
        } else if (i == argc - 1) {
            csv_file = argv[i];
        }
    }

    /* Open CSV file */
    FILE *fp = fopen(csv_file, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", csv_file);
        exit(1);
    }

    /* Read header row */
    char header_buffer[max_row_size];
    fgets(header_buffer, max_row_size, fp);
    if (has_header) {
        printf("Header: %s", header_buffer);
    }

    /* Read data rows */
    char row_buffer[max_row_size];
    int field_count = 0;
    char *field_ptr = NULL;
    while (fgets(row_buffer, max_row_size, fp) != NULL) {
        field_count = 0;
        field_ptr = strtok(row_buffer, delimiter);
        while (field_ptr != NULL) {
            field_count++;
            printf("Field %d: %s", field_count, field_ptr);
            field_ptr = strtok(NULL, delimiter);
        }
        printf("\n");
    }

    /* Close CSV file */
    fclose(fp);

    return 0;
}