//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100
#define MAX_FIELD_LENGTH 1024

typedef struct {
    char *data;
    int length;
} string_t;

typedef struct {
    string_t *fields[MAX_FIELDS];
    int num_fields;
} csv_row_t;

char *read_line(FILE *fp) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        return NULL;
    }
    return line;
}

string_t *read_string(FILE *fp) {
    string_t *str = malloc(sizeof(string_t));
    str->data = malloc(MAX_FIELD_LENGTH);
    str->length = 0;

    char *line = read_line(fp);
    if (line == NULL) {
        return NULL;
    }

    char *p = line;
    while (*p!= '\n' && *p!= '\r') {
        if (str->length >= MAX_FIELD_LENGTH) {
            break;
        }
        if (*p == ',' || *p == ';') {
            break;
        }
        str->data[str->length] = *p;
        str->length++;
        p++;
    }
    str->data[str->length] = '\0';

    return str;
}

csv_row_t *read_row(FILE *fp) {
    csv_row_t *row = malloc(sizeof(csv_row_t));
    row->num_fields = 0;

    string_t *str = read_string(fp);
    if (str == NULL) {
        return NULL;
    }
    row->fields[row->num_fields++] = str;

    while (row->num_fields < MAX_FIELDS) {
        str = read_string(fp);
        if (str == NULL) {
            break;
        }
        row->fields[row->num_fields++] = str;
    }

    return row;
}

void print_row(csv_row_t *row) {
    for (int i = 0; i < row->num_fields; i++) {
        printf("%s", row->fields[i]->data);
        if (i < row->num_fields - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    csv_row_t *row;
    while ((row = read_row(fp))!= NULL) {
        print_row(row);
    }

    fclose(fp);
    return 0;
}