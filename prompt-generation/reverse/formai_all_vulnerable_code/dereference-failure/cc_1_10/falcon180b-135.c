//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 100

typedef struct {
    char *field1;
    char *field2;
    int field3;
} Record;

void read_csv(FILE *fp, Record *records) {
    int i = 0;
    char line[MAX_FIELD_SIZE];
    while (fgets(line, MAX_FIELD_SIZE, fp)) {
        if (i >= MAX_RECORDS) {
            printf("Error: Too many records.\n");
            exit(1);
        }
        char *token = strtok(line, ",");
        records[i].field1 = strdup(token);
        records[i].field2 = strdup(strtok(NULL, ","));
        records[i].field3 = atoi(strtok(NULL, ","));
        i++;
    }
}

void write_csv(FILE *fp, Record *records, int num_records) {
    for (int i = 0; i < num_records; i++) {
        fprintf(fp, "%s,%s,%d\n", records[i].field1, records[i].field2, records[i].field3);
    }
}

void sort_records(Record *records, int num_records, int (*compare_func)(const void *, const void *)) {
    qsort(records, num_records, sizeof(Record), compare_func);
}

int compare_field1(const void *a, const void *b) {
    Record *rec1 = (Record *)a;
    Record *rec2 = (Record *)b;
    return strcmp(rec1->field1, rec2->field1);
}

int main() {
    FILE *fp;
    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    Record records[MAX_RECORDS];
    int num_records = 0;
    read_csv(fp, records);
    num_records = 10;
    sort_records(records, num_records, compare_field1);

    fp = fopen("sorted_data.csv", "w");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    write_csv(fp, records, num_records);
    fclose(fp);

    return 0;
}