//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a CSV file and store its contents in an array
int readCSV(const char* filename, char** lines) {
    // Open the file in read mode
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file\n");
        return -1;
    }

    // Initialize the array to store the lines
    int numLines = 0;
    char* line = NULL;
    while ((line = fgets(line, sizeof(line), file))!= NULL) {
        numLines++;
        lines[numLines] = line;
    }
    fclose(file);

    return numLines;
}

// Function to print the contents of the CSV file
void printCSV(char** lines, int numLines) {
    for (int i = 0; i < numLines; i++) {
        printf("%s\n", lines[i]);
    }
}

// Main function
int main() {
    // Prompt the user for the filename
    printf("Enter the filename: ");
    char* filename = malloc(sizeof(char) * 100);
    scanf("%s", filename);

    // Read the CSV file and store its contents in an array
    char** lines = malloc(sizeof(char*) * 100);
    int numLines = readCSV(filename, lines);
    if (numLines < 0) {
        free(lines);
        return 1;
    }

    // Print the contents of the CSV file
    printf("CSV File Contents:\n");
    printCSV(lines, numLines);

    // Free the memory allocated for the array
    free(lines);

    // Success
    return 0;
}