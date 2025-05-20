//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 20

typedef struct field {
    char* name;
    char* value;
} Field;

typedef struct resume {
    int num_fields;
    Field fields[MAX_NUM_FIELDS];
} Resume;

Resume* parse_resume(FILE* fp) {
    Resume* resume = malloc(sizeof(Resume));
    resume->num_fields = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char* token = strtok(line, ",");
        while (token!= NULL) {
            if (resume->num_fields >= MAX_NUM_FIELDS) {
                printf("Error: too many fields in resume.\n");
                exit(1);
            }

            Field* field = malloc(sizeof(Field));
            field->name = strdup(token);
            field->value = strdup(strtok(NULL, ","));

            resume->fields[resume->num_fields++] = *field;
            free(field);

            token = strtok(NULL, ",");
        }
    }

    return resume;
}

void print_resume(Resume* resume) {
    printf("Name: %s\n", resume->fields[0].value);
    printf("Email: %s\n", resume->fields[1].value);
    printf("Phone: %s\n", resume->fields[2].value);
    printf("Address: %s\n", resume->fields[3].value);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        printf("Usage: %s <resume.txt>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: could not open resume file.\n");
        return 1;
    }

    Resume* resume = parse_resume(fp);
    fclose(fp);

    print_resume(resume);

    free(resume->fields);
    free(resume);

    return 0;
}