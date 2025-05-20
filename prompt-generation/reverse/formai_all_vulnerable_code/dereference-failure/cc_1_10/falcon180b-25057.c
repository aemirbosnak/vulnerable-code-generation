//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUM_COLUMNS 100
#define MAX_NUM_ROWS 1000
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int numColumns;
    int numRows;
    char **values;
} Table;

void createTable(Table *table, char *name, int numColumns, int numRows) {
    strcpy(table->name, name);
    table->numColumns = numColumns;
    table->numRows = numRows;
    table->values = (char **)malloc(numColumns * sizeof(char *));
    for (int i = 0; i < numColumns; i++) {
        table->values[i] = (char *)malloc((numRows + 1) * sizeof(char));
        for (int j = 0; j <= numRows; j++) {
            table->values[i][j] = '\0';
        }
    }
}

void deleteTable(Table *table) {
    for (int i = 0; i < table->numColumns; i++) {
        free(table->values[i]);
    }
    free(table->values);
}

int addRow(Table *table) {
    for (int i = 0; i < table->numColumns; i++) {
        char *value = (char *)malloc((MAX_VALUE_LENGTH + 1) * sizeof(char));
        printf("Enter value for column %d:\n", i + 1);
        fgets(value, MAX_VALUE_LENGTH, stdin);
        value[strcspn(value, "\n")] = '\0';
        strcat(table->values[i], value);
        free(value);
    }
    return 0;
}

void printTable(Table *table) {
    printf("Table: %s\n", table->name);
    printf("Columns:\n");
    for (int i = 0; i < table->numColumns; i++) {
        printf("%d. %s\n", i + 1, table->values[i]);
    }
    printf("Rows:\n");
    for (int i = 0; i < table->numRows; i++) {
        for (int j = 0; j < table->numColumns; j++) {
            printf("%s ", table->values[j]);
        }
        printf("\n");
    }
}

int main() {
    Table table;
    char name[MAX_NAME_LENGTH];
    int numColumns, numRows;

    printf("Enter table name:\n");
    scanf("%s", name);

    printf("Enter number of columns:\n");
    scanf("%d", &numColumns);

    printf("Enter number of rows:\n");
    scanf("%d", &numRows);

    createTable(&table, name, numColumns, numRows);

    int choice;
    do {
        printf("1. Add row\n");
        printf("2. Print table\n");
        printf("3. Exit\n");
        printf("Enter choice:\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRow(&table);
                break;
            case 2:
                printTable(&table);
                break;
            case 3:
                deleteTable(&table);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}