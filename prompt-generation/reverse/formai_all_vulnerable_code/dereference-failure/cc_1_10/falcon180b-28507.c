//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 1000

typedef struct {
    char *name;
    int num_rows;
    int num_cols;
    char **data;
} table;

table *create_table(char *name, int num_rows, int num_cols) {
    table *t = (table *)malloc(sizeof(table));
    t->name = strdup(name);
    t->num_rows = num_rows;
    t->num_cols = num_cols;
    t->data = (char **)malloc(num_rows * sizeof(char *));
    for (int i = 0; i < num_rows; i++) {
        t->data[i] = (char *)malloc(MAX_DATA_SIZE);
    }
    return t;
}

void delete_table(table *t) {
    for (int i = 0; i < t->num_rows; i++) {
        free(t->data[i]);
    }
    free(t->data);
    free(t->name);
    free(t);
}

void print_table(table *t) {
    printf("Table name: %s\n", t->name);
    printf("Number of rows: %d\n", t->num_rows);
    printf("Number of columns: %d\n", t->num_cols);
    for (int i = 0; i < t->num_rows; i++) {
        for (int j = 0; j < t->num_cols; j++) {
            printf("%s ", t->data[i]);
        }
        printf("\n");
    }
}

int main() {
    table *t = create_table("example_table", 3, 3);
    strcpy(t->data[0], "Name");
    strcpy(t->data[1], "Age");
    strcpy(t->data[2], "Gender");
    strcpy(t->data[3], "John");
    strcpy(t->data[4], "25");
    strcpy(t->data[5], "Male");
    strcpy(t->data[6], "Jane");
    strcpy(t->data[7], "30");
    strcpy(t->data[8], "Female");
    print_table(t);
    delete_table(t);
    return 0;
}