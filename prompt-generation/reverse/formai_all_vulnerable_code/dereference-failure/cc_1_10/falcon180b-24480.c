//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_FIELD_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_FIELD_LEN];
} Field;

typedef struct {
    char delimiter;
    int num_fields;
    Field fields[10];
} Record;

void parse_record(Record *record, char *line) {
    char *token = strtok(line, record->delimiter);
    int i = 0;

    while (token!= NULL) {
        strncpy(record->fields[i].name, token, MAX_NAME_LEN);
        strncpy(record->fields[i].value, strchr(token, ':') + 1, MAX_FIELD_LEN);
        i++;

        if (i >= record->num_fields) {
            break;
        }

        token = strtok(NULL, record->delimiter);
    }
}

void print_record(Record *record) {
    printf("Name: %s\n", record->fields[0].name);

    for (int i = 1; i < record->num_fields; i++) {
        printf("%s: %s\n", record->fields[i].name, record->fields[i].value);
    }
}

int main() {
    FILE *fp;
    char line[MAX_FIELD_LEN];
    Record record;

    fp = fopen("resume.txt", "r");

    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    fscanf(fp, "%c", &record.delimiter);
    fscanf(fp, "%d", &record.num_fields);

    for (int i = 0; i < record.num_fields; i++) {
        fscanf(fp, "%s %s", record.fields[i].name, record.fields[i].value);
    }

    while (fgets(line, MAX_FIELD_LEN, fp)!= NULL) {
        parse_record(&record, line);
        print_record(&record);
    }

    fclose(fp);

    return 0;
}