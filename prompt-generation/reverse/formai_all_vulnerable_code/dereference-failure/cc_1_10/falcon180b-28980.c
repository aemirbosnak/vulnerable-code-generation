//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 50
#define MAX_FIELD_LENGTH 100

typedef struct {
    char *name;
    char *value;
} field_t;

typedef struct {
    field_t *fields;
    int num_fields;
} resume_t;

resume_t *parse_resume(char *filename) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    field_t *fields = NULL;
    int num_fields = 0;
    resume_t *resume = NULL;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            if (num_fields >= MAX_NUM_FIELDS) {
                printf("Error: too many fields in line\n");
                exit(1);
            }
            fields = realloc(fields, sizeof(field_t) * (num_fields + 1));
            fields[num_fields].name = strdup(token);
            fields[num_fields].value = strdup("");
            num_fields++;
            token = strtok(NULL, ",");
        }
    }

    if (num_fields == 0) {
        printf("Error: no fields found in file\n");
        exit(1);
    }

    resume = malloc(sizeof(resume_t));
    resume->fields = fields;
    resume->num_fields = num_fields;

    fclose(fp);
    return resume;
}

void print_resume(resume_t *resume) {
    int i;

    for (i = 0; i < resume->num_fields; i++) {
        printf("%s: %s\n", resume->fields[i].name, resume->fields[i].value);
    }
}

int main() {
    char *filename = "sample_resume.txt";
    resume_t *resume = parse_resume(filename);
    print_resume(resume);

    for (int i = 0; i < resume->num_fields; i++) {
        free(resume->fields[i].name);
        free(resume->fields[i].value);
    }
    free(resume->fields);
    free(resume);

    return 0;
}