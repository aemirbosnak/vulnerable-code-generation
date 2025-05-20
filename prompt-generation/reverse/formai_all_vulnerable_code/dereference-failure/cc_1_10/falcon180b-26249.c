//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FIELDS 10
#define MAX_FIELD_LENGTH 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char* field_name;
    char* field_value;
} field_t;

typedef struct {
    field_t fields[MAX_FIELDS];
    int num_fields;
} resume_t;

char* read_line(FILE* fp) {
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp))!= -1) {
        if (read > 0 && line[read - 1] == '\n') {
            line[--read] = '\0';
        }
    }

    return line;
}

char* trim_whitespace(char* str) {
    char* end;

    if (str == NULL) {
        return NULL;
    }

    end = str + strlen(str) - 1;

    while (isspace(*end)) {
        end--;
    }

    end[1] = '\0';

    return str;
}

bool is_valid_field(char* field) {
    char* start = field;
    char* end = field + strlen(field);

    while (start < end) {
        if (!isalnum(*start) && *start!= '.' && *start!= '-') {
            return false;
        }

        start++;
    }

    return true;
}

void add_field(resume_t* resume, char* field_name, char* field_value) {
    if (resume->num_fields >= MAX_FIELDS) {
        printf("Error: maximum number of fields reached.\n");
        return;
    }

    resume->fields[resume->num_fields].field_name = strdup(field_name);
    resume->fields[resume->num_fields].field_value = strdup(field_value);

    resume->num_fields++;
}

void print_fields(resume_t* resume) {
    int i;

    for (i = 0; i < resume->num_fields; i++) {
        printf("%s: %s\n", resume->fields[i].field_name, resume->fields[i].field_value);
    }
}

int main() {
    resume_t resume = { 0 };
    char* line;
    char* field_name;
    char* field_value;
    char* token;

    FILE* fp = fopen("resume.txt", "r");

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    while ((line = read_line(fp))!= NULL) {
        token = strtok(line, ":");

        if (token == NULL) {
            continue;
        }

        field_name = trim_whitespace(token);
        field_value = strdup(line + strlen(token) + 1);

        if (is_valid_field(field_name)) {
            add_field(&resume, field_name, field_value);
        } else {
            printf("Warning: invalid field name '%s'.\n", field_name);
        }
    }

    fclose(fp);

    print_fields(&resume);

    return 0;
}