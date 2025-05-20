//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 100
#define DELIMITER ','

typedef struct {
    char *name;
    int index;
} field_t;

field_t *fields = NULL;
int num_fields = 0;

void add_field(char *name) {
    field_t *field = malloc(sizeof(field_t));
    field->name = strdup(name);
    field->index = num_fields;
    fields = realloc(fields, sizeof(field_t) * ++num_fields);
    fields[num_fields - 1] = *field;
    free(field);
}

int get_field_index(char *name) {
    for (int i = 0; i < num_fields; i++) {
        if (strcmp(fields[i].name, name) == 0) {
            return fields[i].index;
        }
    }
    return -1;
}

void read_csv_file(FILE *file) {
    char line[MAX_LINE_SIZE];
    char *token;
    int row = 0;
    int col = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        row++;
        col = 0;
        token = strtok(line, DELIMITER);
        while (token!= NULL) {
            col++;
            if (col > num_fields) {
                add_field(token);
            }
            printf("%s\t", token);
            token = strtok(NULL, DELIMITER);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    read_csv_file(file);

    fclose(file);
    return 0;
}