//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 50
#define MAX_FIELDS 100

typedef struct {
    char *name;
    char *value;
} Field;

typedef struct {
    Field *fields;
    int num_fields;
} Resume;

Resume *create_resume() {
    Resume *resume = malloc(sizeof(Resume));
    resume->fields = NULL;
    resume->num_fields = 0;
    return resume;
}

void add_field(Resume *resume, char *name, char *value) {
    Field *field = malloc(sizeof(Field));
    field->name = strdup(name);
    field->value = strdup(value);
    resume->fields = realloc(resume->fields, sizeof(Field) * (resume->num_fields + 1));
    resume->fields[resume->num_fields] = *field;
    resume->num_fields++;
}

void print_resume(Resume *resume) {
    for (int i = 0; i < resume->num_fields; i++) {
        printf("%s: %s\n", resume->fields[i].name, resume->fields[i].value);
    }
}

void free_resume(Resume *resume) {
    for (int i = 0; i < resume->num_fields; i++) {
        free(resume->fields[i].name);
        free(resume->fields[i].value);
    }
    free(resume->fields);
    free(resume);
}

int main() {
    FILE *input_file = fopen("resume.txt", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    Resume *resume = create_resume();

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        char *token = strtok(line, ":");
        while (token!= NULL) {
            char *name = token;
            char *value = strtok(NULL, ":");

            if (value == NULL) {
                printf("Error: missing value for field '%s'.\n", name);
                free_resume(resume);
                fclose(input_file);
                return 1;
            }

            add_field(resume, name, value);

            token = strtok(NULL, ":");
        }
    }

    fclose(input_file);
    print_resume(resume);
    free_resume(resume);

    return 0;
}