//Falcon-180B DATASET v1.0 Category: Email Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELD_LEN 256

typedef struct {
    char *name;
    char *value;
} field_t;

typedef struct {
    field_t *fields;
    int num_fields;
} header_t;

header_t *parse_header(char *header_line) {
    header_t *header = (header_t *)malloc(sizeof(header_t));
    header->num_fields = 0;
    header->fields = (field_t *)malloc(sizeof(field_t));

    char *ptr = strtok(header_line, ":");
    while (ptr!= NULL) {
        field_t *field = (field_t *)malloc(sizeof(field_t));
        field->name = strdup(ptr);
        field->value = strdup(strtok(NULL, ":"));
        header->fields = (field_t *)realloc(header->fields, sizeof(field_t) * ++header->num_fields);
        header->fields[header->num_fields - 1] = *field;
        free(field);
        ptr = strtok(NULL, ":");
    }

    return header;
}

void free_header(header_t *header) {
    for (int i = 0; i < header->num_fields; i++) {
        free(header->fields[i].name);
        free(header->fields[i].value);
    }
    free(header->fields);
    free(header);
}

int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        if (line[0] == 'F') {
            header_t *header = parse_header(line);
            printf("From: %s\n", header->fields[0].value);
            printf("To: %s\n", header->fields[1].value);
            printf("Subject: %s\n", header->fields[2].value);
            free_header(header);
        } else if (line[0] == 'M') {
            printf("Message:\n");
        }
    }

    fclose(fp);
    return 0;
}