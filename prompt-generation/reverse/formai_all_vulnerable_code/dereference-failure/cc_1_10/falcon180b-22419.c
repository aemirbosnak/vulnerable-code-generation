//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 10

typedef struct {
    char field[MAX_LINE_LENGTH];
    int field_len;
} Field;

typedef struct {
    Field fields[MAX_FIELDS];
    int num_fields;
} Resume;

Resume *parse_resume(FILE *fp) {
    Resume *r = malloc(sizeof(Resume));
    r->num_fields = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        int i;
        for (i = 0; i < r->num_fields; i++) {
            if (strcmp(r->fields[i].field, "Name") == 0) {
                strcpy(r->fields[i].field, line);
                r->fields[i].field_len = strlen(line);
                break;
            }
        }
        if (i == r->num_fields) {
            if (r->num_fields >= MAX_FIELDS) {
                fprintf(stderr, "Error: too many fields in resume\n");
                exit(1);
            }
            r->fields[r->num_fields].field_len = strlen(line);
            strcpy(r->fields[r->num_fields].field, line);
            r->num_fields++;
        }
    }

    return r;
}

void print_resume(Resume *r) {
    printf("Name: %.*s\n", r->fields[0].field_len, r->fields[0].field);
}

int main() {
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open resume file\n");
        exit(1);
    }

    Resume *r = parse_resume(fp);
    fclose(fp);

    print_resume(r);

    free(r);
    return 0;
}