//FormAI DATASET v1.0 Category: Data mining ; Style: intelligent
#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Function to perform data mining on a CSV file
void dataMining(char filename[]) {
    FILE *fp;
    int row = 0, col = 0;
    double data[MAX_ROWS][MAX_COLS];
    double min, max, sum, avg;

    fp = fopen(filename, "r");

    // Read data from CSV file and store in data matrix
    while (!feof(fp)) {
        fscanf(fp, "%lf,", &data[row][col]);
        col++;
        if (col == MAX_COLS) {
            col = 0;
            row++;
        }
    }

    fclose(fp);

    // Calculate statistics for each column of data
    for (int c = 0; c < col; c++) {
        min = data[0][c];
        max = data[0][c];
        sum = 0;
        for (int r = 0; r < row; r++) {
            if (data[r][c] < min) {
                min = data[r][c];
            }
            if (data[r][c] > max) {
                max = data[r][c];
            }
            sum += data[r][c];
        }
        avg = sum / row;
        printf("Column %d:\n", c + 1);
        printf("Min: %lf\n", min);
        printf("Max: %lf\n", max);
        printf("Avg: %lf\n", avg);
    }
}

int main() {
    char filename[] = "data.csv";
    dataMining(filename);
    return 0;
}