//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 1024
#define MAX_NUM_FIELDS 1000

typedef struct {
    char *name;
    char *value;
} Field;

typedef struct {
    Field *fields;
    int num_fields;
} Resume;

Resume *parse_resume(FILE *fp) {
    Resume *resume = malloc(sizeof(Resume));
    resume->num_fields = 0;
    resume->fields = NULL;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        char *token = strtok(line, ":");
        while (token!= NULL) {
            if (resume->num_fields >= MAX_NUM_FIELDS) {
                printf("Error: Too many fields in resume.\n");
                exit(1);
            }
            Field *field = malloc(sizeof(Field));
            field->name = strdup(token);
            field->value = strdup(strtok(NULL, ":"));
            resume->fields = realloc(resume->fields, sizeof(Field) * ++resume->num_fields);
            resume->fields[resume->num_fields - 1] = *field;
            free(field);
            token = strtok(NULL, ":");
        }
    }

    return resume;
}

void print_resume(Resume *resume) {
    for (int i = 0; i < resume->num_fields; i++) {
        printf("%s: %s\n", resume->fields[i].name, resume->fields[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open resume file.\n");
        return 1;
    }

    Resume *resume = parse_resume(fp);
    fclose(fp);

    print_resume(resume);

    free(resume->fields);
    free(resume);

    return 0;
}