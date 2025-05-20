//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_VAL_LEN 100

typedef struct {
    char *name;
    int num_rows;
    int num_cols;
    char **values;
} Table;

Table *create_table(char *name, int num_rows, int num_cols) {
    Table *t = malloc(sizeof(Table));
    t->name = name;
    t->num_rows = num_rows;
    t->num_cols = num_cols;
    t->values = malloc(sizeof(char *) * num_rows);
    for (int i = 0; i < num_rows; i++) {
        t->values[i] = malloc(sizeof(char) * num_cols);
        for (int j = 0; j < num_cols; j++) {
            t->values[i][j] = '\0';
        }
    }
    return t;
}

void destroy_table(Table *t) {
    for (int i = 0; i < t->num_rows; i++) {
        free(t->values[i]);
    }
    free(t->values);
    free(t);
}

void print_table(Table *t) {
    for (int i = 0; i < t->num_rows; i++) {
        for (int j = 0; j < t->num_cols; j++) {
            printf("%s ", t->values[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Table *t = create_table("test_table", 3, 3);
    strcpy(t->values[0][0], "1");
    strcpy(t->values[0][1], "2");
    strcpy(t->values[0][2], "3");
    strcpy(t->values[1][0], "4");
    strcpy(t->values[1][1], "5");
    strcpy(t->values[1][2], "6");
    strcpy(t->values[2][0], "7");
    strcpy(t->values[2][1], "8");
    strcpy(t->values[2][2], "9");
    print_table(t);
    destroy_table(t);
    return 0;
}