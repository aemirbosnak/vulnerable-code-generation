//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FIELDS 10
#define MAX_FIELD_LENGTH 100
#define DELIMITER ","

typedef struct {
    char field[MAX_FIELD_LENGTH];
    int length;
} Field;

typedef struct {
    Field fields[MAX_FIELDS];
    int num_fields;
} Record;

char* read_line(FILE* f) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, f))!= -1) {
        if (line[read - 1] == '\n') {
            line[read - 1] = '\0';
            break;
        }
    }

    return line;
}

int parse_record(Record* record, char* line) {
    char* token = NULL;
    int i = 0;

    token = strtok(line, DELIMITER);
    while (token!= NULL && i < MAX_FIELDS) {
        strncpy(record->fields[i].field, token, MAX_FIELD_LENGTH);
        record->fields[i].length = strlen(token);
        i++;
        token = strtok(NULL, DELIMITER);
    }

    record->num_fields = i;

    return 0;
}

int main() {
    FILE* f = fopen("resume.csv", "r");
    Record record;
    char* line = NULL;

    if (f == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while ((line = read_line(f))!= NULL) {
        parse_record(&record, line);
        printf("Name: %s\n", record.fields[0].field);
        printf("Email: %s\n", record.fields[1].field);
        printf("Phone: %s\n", record.fields[2].field);
        printf("Address: %s\n", record.fields[3].field);
        printf("Education: %s\n", record.fields[4].field);
        printf("Experience: %s\n", record.fields[5].field);
        printf("Skills: %s\n", record.fields[6].field);
        printf("Certifications: %s\n", record.fields[7].field);
        printf("References: %s\n", record.fields[8].field);
        printf("\n");
    }

    fclose(f);

    return 0;
}