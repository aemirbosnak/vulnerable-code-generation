//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA 1000

typedef struct {
    char *name;
    int rows;
    int cols;
    char **data;
} Table;

Table *create_table(char *name, int rows, int cols) {
    Table *t = malloc(sizeof(Table));
    t->name = strdup(name);
    t->rows = rows;
    t->cols = cols;
    t->data = malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        t->data[i] = malloc(cols * sizeof(char));
        memset(t->data[i], '\0', cols);
    }
    return t;
}

void destroy_table(Table *t) {
    for (int i = 0; i < t->rows; i++) {
        free(t->data[i]);
    }
    free(t->data);
    free(t->name);
    free(t);
}

void print_table(Table *t) {
    for (int i = 0; i < t->rows; i++) {
        for (int j = 0; j < t->cols; j++) {
            printf("%s ", t->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table *t = create_table("example", 2, 3);
    strcpy(t->data[0][0], "1");
    strcpy(t->data[0][1], "2");
    strcpy(t->data[0][2], "3");
    strcpy(t->data[1][0], "4");
    strcpy(t->data[1][1], "5");
    strcpy(t->data[1][2], "6");
    print_table(t);
    destroy_table(t);
    return 0;
}