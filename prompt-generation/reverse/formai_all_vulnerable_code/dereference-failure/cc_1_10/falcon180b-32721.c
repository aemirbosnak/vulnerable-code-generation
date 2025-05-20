//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 10
#define MAX_STRING_SIZE 50

typedef struct {
    char data[MAX_STRING_SIZE];
    int row;
    int col;
} Cell;

typedef struct {
    Cell **data;
    int numRows;
    int numCols;
} Spreadsheet;

Spreadsheet* createSpreadsheet(int numRows, int numCols) {
    Spreadsheet* sheet = malloc(sizeof(Spreadsheet));
    sheet->numRows = numRows;
    sheet->numCols = numCols;
    sheet->data = malloc(sizeof(Cell*) * numRows);
    for (int i = 0; i < numRows; i++) {
        sheet->data[i] = malloc(sizeof(Cell) * numCols);
        for (int j = 0; j < numCols; j++) {
            sheet->data[i][j].row = i;
            sheet->data[i][j].col = j;
            sheet->data[i][j].data[0] = '\0';
        }
    }
    return sheet;
}

void destroySpreadsheet(Spreadsheet* sheet) {
    for (int i = 0; i < sheet->numRows; i++) {
        free(sheet->data[i]);
    }
    free(sheet->data);
    free(sheet);
}

void setCellValue(Spreadsheet* sheet, int row, int col, char* value) {
    Cell* cell = &sheet->data[row][col];
    strncpy(cell->data, value, MAX_STRING_SIZE);
}

char* getCellValue(Spreadsheet* sheet, int row, int col) {
    Cell* cell = &sheet->data[row][col];
    return cell->data;
}

int main() {
    Spreadsheet* sheet = createSpreadsheet(MAX_ROWS, MAX_COLS);

    setCellValue(sheet, 0, 0, "Name");
    setCellValue(sheet, 0, 1, "Age");
    setCellValue(sheet, 0, 2, "Gender");

    for (int i = 1; i < MAX_ROWS; i++) {
        setCellValue(sheet, i, 0, "Person #" + i);
        setCellValue(sheet, i, 1, "25");
        setCellValue(sheet, i, 2, "Male");
    }

    int numRows = sheet->numRows;
    int numCols = sheet->numCols;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            printf("%s ", getCellValue(sheet, i, j));
        }
        printf("\n");
    }

    destroySpreadsheet(sheet);
    return 0;
}