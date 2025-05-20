//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 1024

typedef struct {
    char *name;
    char *value;
} Field;

typedef struct {
    Field *fields;
    int num_fields;
} Resume;

Resume *parse_resume(FILE *fp) {
    Resume *resume = NULL;
    char line[MAX_LINE_SIZE];
    int line_num = 0;
    char *token;
    Field *field = NULL;

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        line_num++;
        token = strtok(line, ":");
        if (token == NULL) {
            continue;
        }
        field = (Field *) malloc(sizeof(Field));
        field->name = strdup(token);
        field->value = strdup("");
        resume = (Resume *) realloc(resume, sizeof(Resume) + sizeof(Field));
        resume->fields[resume->num_fields] = *field;
        resume->num_fields++;
    }

    return resume;
}

void print_resume(Resume *resume) {
    int i;

    for (i = 0; i < resume->num_fields; i++) {
        printf("%s: %s\n", resume->fields[i].name, resume->fields[i].value);
    }
}

int main() {
    FILE *fp;
    Resume *resume;

    fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    resume = parse_resume(fp);
    if (resume == NULL) {
        printf("Error parsing resume.\n");
        exit(1);
    }

    print_resume(resume);

    free(resume->fields);
    free(resume);

    fclose(fp);

    return 0;
}