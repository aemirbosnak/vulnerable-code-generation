//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

typedef struct {
    int row;
    int col;
} Cell;

int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[50];
    char line[1000];
    char *token;
    Cell *cell = (Cell *)malloc(sizeof(Cell));
    int row = 0;
    int col = 0;

    // Get filename from command line argument
    strcpy(filename, argv[1]);

    // Open the CSV file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    // Read the first line to get the number of columns
    fgets(line, sizeof(line), fp);
    token = strtok(line, ",");
    while (token!= NULL) {
        col++;
        token = strtok(NULL, ",");
    }

    // Allocate memory for the cell array
    cell = (Cell *)realloc(cell, sizeof(Cell) * row * col);

    // Read the rest of the lines and fill in the cell array
    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            row++;
            cell[row * col - 1].row = row;
            cell[row * col - 1].col = col;
            col++;
            token = strtok(NULL, ",");
        }
    }

    // Print the cell array
    for (row = 0; row < MAX_ROW; row++) {
        for (col = 0; col < MAX_COL; col++) {
            if (cell[row * col].row == row && cell[row * col].col == col) {
                printf("%d ", cell[row * col].row);
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }

    // Free memory
    free(cell);
    fclose(fp);
    return 0;
}