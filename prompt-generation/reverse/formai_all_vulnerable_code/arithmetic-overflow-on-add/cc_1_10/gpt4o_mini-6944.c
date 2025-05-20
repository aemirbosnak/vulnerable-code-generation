//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 20

// Function to split a line by commas
void splitLine(char *line, char *columns[], int *numberOfColumns) {
    char *token = strtok(line, ",");
    *numberOfColumns = 0;

    while (token != NULL) {
        columns[(*numberOfColumns)++] = token;
        token = strtok(NULL, ",");
    }
}

// Function to calculate the average of a column
double calculateAverage(const char *filename, int columnIndex) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return 0.0;
    }

    char line[MAX_LINE_LENGTH];
    double sum = 0.0;
    int count = 0;

    // Skip the header line
    fgets(line, sizeof(line), file);

    // Read each line and calculate the sum of values in the specified column
    while (fgets(line, sizeof(line), file)) {
        char *columns[MAX_COLUMNS];
        int numColumns;
        splitLine(line, columns, &numColumns);
        
        if (numColumns > columnIndex) {
            sum += atof(columns[columnIndex]);
            count++;
        }
    }

    fclose(file);

    return count > 0 ? sum / count : 0.0; 
}

// Function to display the result
void displayAverage(const char *filename, int columnIndex) {
    double average = calculateAverage(filename, columnIndex);
    printf("The average of column %d in file %s is: %.2f\n", columnIndex + 1, filename, average);
}

int main() {
    const char *filename = "data.csv";  // Sample CSV file name
    int columnOfInterest;

    printf("Welcome to the Awesome Data Mining Program! 🎉\n");
    printf("We'll calculate the average of a specific column from a CSV file.\n");

    // Ask user for the column they want to analyze
    printf("Please enter the column number (1-indexed) you want to calculate the average for: ");
    scanf("%d", &columnOfInterest);

    // Adjust for 0-indexed array
    columnOfInterest -= 1;

    // Display the average
    displayAverage(filename, columnOfInterest);

    printf("Thanks for using the Awesome Data Mining Program! Have a fantastic day! 🌟\n");

    return 0;
}