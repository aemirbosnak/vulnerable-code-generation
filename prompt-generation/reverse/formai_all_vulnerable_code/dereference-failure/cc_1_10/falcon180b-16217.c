//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char name[MAX_WORD_LENGTH];
    char value[MAX_LINE_LENGTH];
} field_t;

typedef struct {
    field_t *fields;
    int num_fields;
} resume_t;

int read_line(char *buffer, int max_length) {
    int length = 0;
    char c;

    while ((c = fgetc(stdin))!= EOF) {
        if (length >= max_length) {
            printf("Line too long.\n");
            exit(1);
        }
        buffer[length++] = c;
    }

    buffer[length] = '\0';
    return length;
}

int read_resume() {
    resume_t *resume = malloc(sizeof(resume_t));
    char line[MAX_LINE_LENGTH];
    int length;

    printf("Enter your name:\n");
    length = read_line(resume->fields[0].name, MAX_WORD_LENGTH);
    strcpy(resume->fields[0].value, "");

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (line[0] == '\n') {
            break;
        }

        if (line[0] == '\0') {
            printf("Invalid line.\n");
            exit(1);
        }

        if (line[0] == '\t') {
            length = read_line(line + 1, MAX_LINE_LENGTH - 1);
            strcpy(resume->fields[resume->num_fields].name, line);
            strcpy(resume->fields[resume->num_fields].value, line + 1);
            resume->num_fields++;
        } else {
            printf("Invalid line.\n");
            exit(1);
        }
    }

    return 0;
}

int write_resume(resume_t *resume) {
    int i;

    printf("Name: %s\n", resume->fields[0].name);

    for (i = 1; i < resume->num_fields; i++) {
        printf("%s: %s\n", resume->fields[i].name, resume->fields[i].value);
    }

    return 0;
}

int main() {
    resume_t *resume;

    resume = read_resume();
    write_resume(resume);

    free(resume);
    return 0;
}