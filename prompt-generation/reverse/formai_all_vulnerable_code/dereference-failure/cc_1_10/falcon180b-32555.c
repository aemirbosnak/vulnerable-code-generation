//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FIELDS 1000
#define DELIMITER ','

typedef struct {
    char **fields;
    int num_fields;
} CSVRecord;

CSVRecord *read_csv_file(FILE *fp) {
    CSVRecord *record = NULL;
    char *line = NULL;
    size_t len = 0;
    char *delimiter = DELIMITER;
    int num_fields = 0;

    while ((getline(&line, &len, fp))!= -1) {
        char *token = strtok(line, delimiter);
        int i = 0;

        while (token!= NULL) {
            if (i >= MAX_FIELDS) {
                printf("Error: Too many fields in line.\n");
                exit(1);
            }

            record->fields[i] = token;
            i++;

            token = strtok(NULL, delimiter);
        }

        if (i == 0) {
            printf("Error: Empty line.\n");
            exit(1);
        }

        num_fields = i;
        record = realloc(record, sizeof(CSVRecord) + (num_fields * sizeof(char*)));
        record->num_fields = num_fields;
    }

    free(line);

    return record;
}

void print_csv_record(CSVRecord *record) {
    for (int i = 0; i < record->num_fields; i++) {
        printf("%s\t", record->fields[i]);
    }

    printf("\n");
}

int main() {
    FILE *fp;
    CSVRecord *record;

    fp = fopen("example.csv", "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    record = read_csv_file(fp);

    if (record == NULL) {
        exit(0);
    }

    print_csv_record(record);

    for (int i = 0; i < record->num_fields; i++) {
        free(record->fields[i]);
    }

    free(record->fields);
    free(record);

    fclose(fp);

    return 0;
}