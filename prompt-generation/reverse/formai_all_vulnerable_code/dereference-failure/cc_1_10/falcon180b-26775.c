//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 100
#define MAX_FIELD_LENGTH 100

typedef struct {
    char *field_name;
    char *field_value;
} Field;

typedef struct {
    int num_fields;
    Field *fields;
} Resume;

Resume *parse_resume(char *filename) {
    FILE *fp;
    Resume *resume = NULL;
    char line[MAX_FIELD_LENGTH];
    char *token;
    char *field_name;
    int field_count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_FIELD_LENGTH, fp)!= NULL) {
        token = strtok(line, ":");
        field_name = token;
        token = strtok(NULL, ":");
        if (token == NULL) {
            printf("Error: missing field value for field name %s\n", field_name);
            exit(1);
        }
        if (field_count >= MAX_FIELDS) {
            printf("Error: too many fields in resume\n");
            exit(1);
        }
        resume->fields[field_count].field_name = strdup(field_name);
        resume->fields[field_count].field_value = strdup(token);
        field_count++;
    }

    if (field_count == 0) {
        printf("Error: no fields found in resume\n");
        exit(1);
    }

    fclose(fp);
    return resume;
}

int main() {
    Resume *resume = parse_resume("example_resume.txt");
    int i;
    for (i = 0; i < resume->num_fields; i++) {
        printf("%s: %s\n", resume->fields[i].field_name, resume->fields[i].field_value);
    }
    return 0;
}