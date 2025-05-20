//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

// Structure for CSV data
typedef struct {
    int row;
    int col;
    char *data;
} csv_data;

// Function to read CSV file and store data in 2D array
void read_csv(csv_data *data, int row, int col, FILE *fp) {
    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        int i = 0;
        while (line[i]!= ',') {
            i++;
        }
        data[row * col + (col - 1)].data = malloc(i * sizeof(char));
        strncpy(data[row * col + (col - 1)].data, line, i);
        data[row * col + (col - 1)].col = col - 1;
        data[row * col + (col - 1)].row = row;
        col--;
    }
}

// Function to print CSV data
void print_csv(csv_data *data, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%s\t", data[i * col + j].data);
        }
        printf("\n");
    }
}

// Function to free memory allocated for CSV data
void free_csv(csv_data *data, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            free(data[i * col + j].data);
        }
    }
    free(data);
}

int main() {
    FILE *fp;
    char filename[100];
    int row, col;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open CSV file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found!\n");
        exit(1);
    }

    // Get number of rows and columns from first line of CSV file
    fseek(fp, 0, SEEK_SET);
    fgets(filename, sizeof(filename), fp);
    sscanf(filename, "%d,%d", &row, &col);

    // Allocate memory for CSV data
    csv_data *data = malloc(row * col * sizeof(csv_data));

    // Read CSV file and store data in 2D array
    read_csv(data, row, col, fp);

    // Print CSV data
    print_csv(data, row, col);

    // Free memory allocated for CSV data
    free_csv(data, row, col);

    // Close CSV file
    fclose(fp);

    return 0;
}