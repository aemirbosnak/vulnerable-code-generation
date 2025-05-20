//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10
#define MAX_FIELD_LEN 100

typedef struct {
    char *field;
    int field_len;
} Field;

typedef struct {
    Field fields[MAX_FIELDS];
    int num_fields;
} Resume;

Resume *parse_resume(FILE *fp) {
    Resume *r = malloc(sizeof(Resume));
    int num_fields = 0;
    Field *f = r->fields;
    char line[MAX_FIELD_LEN];

    while (fgets(line, sizeof(line), fp)) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[--len] = '\0';
        }
        if (num_fields >= MAX_FIELDS) {
            break;
        }
        f->field = malloc(len + 1);
        strcpy(f->field, line);
        f->field_len = len;
        f++;
        num_fields++;
    }
    r->num_fields = num_fields;
    return r;
}

void print_resume(Resume *r) {
    Field *f = r->fields;
    for (int i = 0; i < r->num_fields; i++) {
        printf("%s\n", f->field);
        f++;
    }
}

void free_resume(Resume *r) {
    Field *f = r->fields;
    for (int i = 0; i < r->num_fields; i++) {
        free(f->field);
        f++;
    }
    free(r);
}

int main() {
    FILE *fp = fopen("resume.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    Resume *r = parse_resume(fp);
    print_resume(r);
    free_resume(r);
    fclose(fp);
    return 0;
}