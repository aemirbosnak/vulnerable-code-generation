//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50
#define DELIMITER ","

typedef struct record {
    char *fields[MAX_FIELD_SIZE];
    int num_fields;
} Record;

void read_csv_file(FILE *fp, Record *records, int *num_records) {
    char line[MAX_FIELD_SIZE * MAX_FIELD_SIZE];
    char *token;
    int i, j;

    for (i = 0; i < MAX_RECORDS; i++) {
        if (fgets(line, MAX_FIELD_SIZE * MAX_FIELD_SIZE, fp) == NULL) {
            break;
        }

        records[i].num_fields = 0;
        token = strtok(line, DELIMITER);
        while (token!= NULL) {
            if (records[i].num_fields >= MAX_FIELD_SIZE) {
                printf("Error: Too many fields in record.\n");
                exit(1);
            }

            records[i].fields[records[i].num_fields] = strdup(token);
            records[i].num_fields++;

            token = strtok(NULL, DELIMITER);
        }

        (*num_records)++;
    }
}

void print_records(Record *records, int num_records) {
    int i, j;

    for (i = 0; i < num_records; i++) {
        for (j = 0; j < records[i].num_fields; j++) {
            printf("%s ", records[i].fields[j]);
        }
        printf("\n");
    }
}

void free_records(Record *records, int num_records) {
    int i, j;

    for (i = 0; i < num_records; i++) {
        for (j = 0; j < records[i].num_fields; j++) {
            free(records[i].fields[j]);
        }
        free(records[i].fields);
    }
    free(records);
}

int main() {
    FILE *fp;
    Record records[MAX_RECORDS];
    int num_records;

    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    read_csv_file(fp, records, &num_records);
    print_records(records, num_records);

    fclose(fp);
    free_records(records, num_records);

    return 0;
}