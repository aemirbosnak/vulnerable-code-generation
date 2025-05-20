//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 100
#define MAX_NUM_ROWS 10
#define MAX_NUM_COLS 10

typedef struct {
    char data[MAX_DATA_SIZE];
    int numRows;
    int numCols;
} Data;

void createTable(Data *table) {
    printf("Enter the number of rows: ");
    scanf("%d", &table->numRows);
    printf("Enter the number of columns: ");
    scanf("%d", &table->numCols);
}

void insertData(Data *table, int row, int col, char *data) {
    strncpy(table->data + (row * MAX_DATA_SIZE) + (col * MAX_DATA_SIZE), data, MAX_DATA_SIZE);
}

void displayTable(Data *table) {
    int i, j;
    for (i = 0; i < table->numRows; i++) {
        for (j = 0; j < table->numCols; j++) {
            printf("%s ", table->data + (i * MAX_DATA_SIZE) + (j * MAX_DATA_SIZE));
        }
        printf("\n");
    }
}

int main() {
    Data table;
    createTable(&table);
    char data[MAX_DATA_SIZE];
    int row, col;

    while (1) {
        printf("\nEnter 1 to insert data, 2 to display table, 0 to exit: ");
        scanf("%d", &row);

        switch (row) {
        case 1:
            printf("Enter the row number: ");
            scanf("%d", &col);
            printf("Enter the data: ");
            scanf("%s", data);
            insertData(&table, col, col, data);
            break;
        case 2:
            displayTable(&table);
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}