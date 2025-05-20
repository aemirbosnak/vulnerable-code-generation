//FormAI DATASET v1.0 Category: Data mining ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 5

// Struct to hold the data
typedef struct {
    int id;
    double values[MAX_COLS];
} Data;

// Function to read data from file
void readData(Data data[], char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    int row = 0, col = 0;
    while (fscanf(file, "%d", &data[row].id) != EOF) {
        for (col = 0; col < MAX_COLS; col++) {
            fscanf(file, "%lf", &data[row].values[col]);
        }
        row++;
        if (row == MAX_ROWS) {
            break;
        }
    }
    fclose(file);
}

// Function to print data
void printData(Data data[]) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        printf("%d, ", data[i].id);
        for (j = 0; j < MAX_COLS; j++) {
            printf("%lf, ", data[i].values[j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    Data data[MAX_ROWS];
    readData(data, "data.txt");

    printf("Original Data:\n");
    printData(data);
    printf("\n");

    // Find the average value of each column
    int i, j;
    double avg[MAX_COLS] = {0};
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            avg[j] += data[i].values[j];
        }
    }
    for (j = 0; j < MAX_COLS; j++) {
        avg[j] /= MAX_ROWS;
    }

    // Find the rows where each column has a value greater than the average for that column
    int matches[MAX_ROWS] = {0};
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLS; j++) {
            if (data[i].values[j] > avg[j]) {
                matches[i]++;
            }
        }
    }

    printf("Results:\n");
    for (i = 0; i < MAX_ROWS; i++) {
        if (matches[i] == MAX_COLS) {
            printf("Row %d matches all columns\n", data[i].id);
        } else if (matches[i] > 0) {
            printf("Row %d matches %d columns\n", data[i].id, matches[i]);
        }
    }

    return 0;
}