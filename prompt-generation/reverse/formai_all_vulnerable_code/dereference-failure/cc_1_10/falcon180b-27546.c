//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns and rows in the CSV file
#define MAX_COLUMNS 1000
#define MAX_ROWS 1000

// Define the CSV file structure
typedef struct {
    char **data; // Pointer to the data in the CSV file
    int rows; // Number of rows in the CSV file
    int columns; // Number of columns in the CSV file
} CSVFile;

// Function to read the CSV file and store its data in the CSVFile structure
CSVFile read_csv(FILE *file) {
    CSVFile csv;
    int rows = 0, columns = 0;
    char line[1024]; // Buffer to store each line in the CSV file
    char **data = NULL; // Pointer to the data in the CSV file

    // Read the first line to determine the number of columns
    fgets(line, sizeof(line), file);
    char *token = strtok(line, ",");
    while (token!= NULL) {
        columns++;
        token = strtok(NULL, ",");
    }

    // Allocate memory for the data in the CSV file
    data = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        data[i] = (char *)malloc((columns + 1) * sizeof(char)); // +1 for the null character
    }

    // Read the CSV file and store its data in the CSVFile structure
    rewind(file);
    while (fgets(line, sizeof(line), file)!= NULL) {
        rows++;
        char *token = strtok(line, ",");
        int j = 0;
        while (token!= NULL) {
            strcpy(data[rows - 1] + j * (columns + 1), token);
            j++;
            token = strtok(NULL, ",");
        }
        data[rows - 1][j * (columns + 1) - 1] = '\0'; // Set the null character at the end of the string
    }

    csv.data = data;
    csv.rows = rows;
    csv.columns = columns;

    return csv;
}

// Function to print the CSV file data
void print_csv(CSVFile csv) {
    for (int i = 0; i < csv.rows; i++) {
        for (int j = 0; j < csv.columns; j++) {
            printf("%s ", csv.data[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    CSVFile csv = read_csv(file);
    print_csv(csv);

    fclose(file);
    return 0;
}