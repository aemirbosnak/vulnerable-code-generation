//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_DATA_SIZE 1000

typedef struct {
    char data[MAX_DATA_SIZE];
    int row;
    int col;
} Cell;

typedef struct {
    Cell **data;
    int numRows;
    int numCols;
} Spreadsheet;

Spreadsheet *createSpreadsheet(int numRows, int numCols) {
    Spreadsheet *spreadsheet = (Spreadsheet *) malloc(sizeof(Spreadsheet));
    spreadsheet->numRows = numRows;
    spreadsheet->numCols = numCols;
    spreadsheet->data = (Cell **) malloc(numRows * sizeof(Cell *));
    for (int i = 0; i < numRows; i++) {
        spreadsheet->data[i] = (Cell *) malloc(numCols * sizeof(Cell));
        for (int j = 0; j < numCols; j++) {
            spreadsheet->data[i][j].row = i;
            spreadsheet->data[i][j].col = j;
        }
    }
    return spreadsheet;
}

void destroySpreadsheet(Spreadsheet *spreadsheet) {
    for (int i = 0; i < spreadsheet->numRows; i++) {
        free(spreadsheet->data[i]);
    }
    free(spreadsheet->data);
    free(spreadsheet);
}

void setCellValue(Spreadsheet *spreadsheet, int row, int col, char *value) {
    Cell *cell = &(spreadsheet->data[row][col]);
    strncpy(cell->data, value, MAX_DATA_SIZE);
}

char *getCellValue(Spreadsheet *spreadsheet, int row, int col) {
    Cell *cell = &(spreadsheet->data[row][col]);
    return cell->data;
}

int main() {
    Spreadsheet *spreadsheet = createSpreadsheet(10, 10);

    setCellValue(spreadsheet, 0, 0, "Name");
    setCellValue(spreadsheet, 0, 1, "Age");
    setCellValue(spreadsheet, 1, 0, "John");
    setCellValue(spreadsheet, 1, 1, "25");

    char *name = getCellValue(spreadsheet, 1, 0);
    printf("Name: %s\n", name);

    destroySpreadsheet(spreadsheet);

    return 0;
}