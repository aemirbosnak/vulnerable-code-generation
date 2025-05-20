//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 1024
#define MAX_NUM_FIELDS 100

typedef struct {
    char *name;
    char *value;
} Field;

typedef struct {
    Field *fields;
    int num_fields;
} Record;

void add_field(Record *record, char *name, char *value) {
    if (record->num_fields >= MAX_NUM_FIELDS) {
        printf("Error: Too many fields in record.\n");
        exit(1);
    }
    record->fields[record->num_fields].name = strdup(name);
    record->fields[record->num_fields].value = strdup(value);
    record->num_fields++;
}

void print_record(Record *record) {
    printf("{");
    for (int i = 0; i < record->num_fields; i++) {
        printf("%s: %s", record->fields[i].name, record->fields[i].value);
        if (i < record->num_fields - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void free_record(Record *record) {
    for (int i = 0; i < record->num_fields; i++) {
        free(record->fields[i].name);
        free(record->fields[i].value);
    }
    free(record->fields);
}

void process_line(char *line, Record *record) {
    char *token = strtok(line, ":");
    while (token!= NULL) {
        char *name = strtok(NULL, ":");
        char *value = strtok(NULL, ":");
        if (name == NULL || value == NULL) {
            printf("Error: Invalid field in line.\n");
            exit(1);
        }
        add_field(record, name, value);
        token = strtok(NULL, ":");
    }
}

int main() {
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    Record current_record = {NULL, 0};
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if (line[0] == '{') {
            if (current_record.num_fields > 0) {
                print_record(&current_record);
            }
            current_record.fields = NULL;
            current_record.num_fields = 0;
        } else if (line[strlen(line) - 1] == '}') {
            process_line(line, &current_record);
        } else {
            printf("Error: Invalid line in file.\n");
            exit(1);
        }
    }
    if (current_record.num_fields > 0) {
        print_record(&current_record);
    }
    fclose(fp);
    return 0;
}