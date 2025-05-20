//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 512
#define MAX_WORD_SIZE 64

typedef struct {
    char name[MAX_WORD_SIZE];
    char value[MAX_WORD_SIZE];
} field_t;

typedef struct {
    int num_fields;
    field_t fields[MAX_LINE_SIZE / 2];
} line_t;

line_t* parse_line(char* str) {
    int i = 0;
    int j = 0;
    line_t* line = malloc(sizeof(line_t));

    while (str[i]!= '\0') {
        char* field = strtok(str + i, " ");

        if (field == NULL) {
            break;
        }

        if (j >= MAX_LINE_SIZE / 2) {
            break;
        }

        strncpy(line->fields[j].name, field, MAX_WORD_SIZE);
        line->fields[j].value[0] = '\0';
        j++;

        i += strlen(field) + 1;
    }

    line->num_fields = j;

    return line;
}

void print_line(line_t* line) {
    for (int i = 0; i < line->num_fields; i++) {
        printf("%s: %s\n", line->fields[i].name, line->fields[i].value);
    }
}

int main() {
    FILE* file = fopen("resume.txt", "r");

    if (file == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    char line[MAX_LINE_SIZE];

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        line_t* parsed_line = parse_line(line);
        print_line(parsed_line);
        free(parsed_line);
    }

    fclose(file);

    return 0;
}