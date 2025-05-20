//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_FIELD_SIZE 50

typedef struct {
    char *fields[MAX_FIELD_SIZE];
    int num_fields;
} Record;

Record *records = NULL;
int num_records = 0;

void add_record(char *line) {
    Record *new_record = malloc(sizeof(Record));
    new_record->num_fields = 0;
    char *token = strtok(line, ",");
    while (token!= NULL) {
        new_record->fields[new_record->num_fields] = token;
        new_record->num_fields++;
        token = strtok(NULL, ",");
    }
    records = realloc(records, sizeof(Record) * ++num_records);
    records[num_records - 1] = *new_record;
}

void print_records() {
    for (int i = 0; i < num_records; i++) {
        for (int j = 0; j < records[i].num_fields; j++) {
            printf("%s ", records[i].fields[j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    char line[MAX_FIELD_SIZE];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        add_record(line);
    }
    fclose(fp);
    printf("Number of records: %d\n", num_records);
    print_records();
    return 0;
}