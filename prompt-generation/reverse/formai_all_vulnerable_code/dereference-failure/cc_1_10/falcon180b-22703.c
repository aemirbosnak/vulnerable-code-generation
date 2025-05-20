//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *data;
    size_t size;
} String;

void string_init(String *s) {
    s->data = NULL;
    s->size = 0;
}

void string_free(String *s) {
    if (s->data!= NULL) {
        free(s->data);
        s->data = NULL;
        s->size = 0;
    }
}

void string_append(String *s, const char *data, size_t size) {
    if (s->data == NULL) {
        s->data = malloc(size);
        s->size = size;
    } else {
        s->size += size;
        s->data = realloc(s->data, s->size);
    }
    memcpy(s->data + s->size - size, data, size);
}

int string_compare(const String *s1, const String *s2) {
    if (s1->size!= s2->size) {
        return -1;
    }
    return memcmp(s1->data, s2->data, s1->size);
}

int main() {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    String csv_data = {0};
    char *delimiter = ",";
    char *token;
    int row = 0;
    int col = 0;
    int num_cols = 0;

    fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if (row == 0) {
            num_cols = strlen(line) - strlen(strchr(line, '\r')) - strlen(strchr(line, '\n'));
            num_cols = num_cols / strlen(delimiter);
        }
        string_append(&csv_data, line, strlen(line));
        row++;
    }

    fclose(fp);

    token = strtok(csv_data.data, delimiter);
    while (token!= NULL) {
        printf("%s\t", token);
        col++;
        if (col == num_cols) {
            printf("\n");
            col = 0;
        }
        token = strtok(NULL, delimiter);
    }

    string_free(&csv_data);

    return 0;
}