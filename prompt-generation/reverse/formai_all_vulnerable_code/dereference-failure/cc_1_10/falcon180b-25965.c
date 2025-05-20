//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 100

typedef struct {
    char *data;
    int size;
} Data;

typedef struct {
    char **rows;
    int num_rows;
    int num_cols;
} Table;

Table* create_table() {
    Table *table = malloc(sizeof(Table));
    table->rows = malloc(MAX_ROWS * sizeof(char*));
    table->num_rows = 0;
    table->num_cols = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        table->rows[i] = malloc(MAX_COLS * sizeof(char));
        memset(table->rows[i], '\0', MAX_COLS);
    }
    return table;
}

void delete_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        free(table->rows[i]);
    }
    free(table->rows);
    free(table);
}

void add_row(Table *table, char *data) {
    int len = strlen(data);
    if (len > MAX_COLS) {
        printf("Error: Data too long.\n");
        return;
    }
    table->rows[table->num_rows] = malloc(len + 1);
    strcpy(table->rows[table->num_rows], data);
    table->num_rows++;
}

void print_table(Table *table) {
    for (int i = 0; i < table->num_rows; i++) {
        printf("%s\n", table->rows[i]);
    }
}

int main() {
    Table *table = create_table();
    char input[MAX_DATA_SIZE];

    while (1) {
        printf("Enter command (add/print/exit): ");
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            printf("Enter data: ");
            scanf("%s", input);
            add_row(table, input);
        } else if (strcmp(input, "print") == 0) {
            print_table(table);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    delete_table(table);
    return 0;
}