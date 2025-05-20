//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 256
#define FILE_NAME "data.txt"

// Function to handle errors
void handleError(const char *errorMsg) {
    fprintf(stderr, "Error: %s\n", errorMsg);
    exit(EXIT_FAILURE);
}

// Function to read integers from a file
int* readIntegersFromFile(const char *filename, int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        handleError("Could not open file for reading.");
    }

    int *numbers = malloc(MAX_BUFFER * sizeof(int));
    if (!numbers) {
        fclose(file);
        handleError("Memory allocation failed.");
    }

    int num, index = 0;
    while (fscanf(file, "%d", &num) != EOF) {
        numbers[index++] = num;
        if (index >= MAX_BUFFER) {
            handleError("Too many numbers in file, exceeding buffer limit.");
        }
    }

    *count = index;
    fclose(file);
    return numbers;
}

// Function to calculate the average of an array of integers
double calculateAverage(int *numbers, int count) {
    if (count == 0) {
        handleError("Cannot calculate average of zero elements.");
    }

    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum / count;
}

// Function to write the result to a file
void writeResultToFile(const char *filename, double result) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        handleError("Could not open file for writing.");
    }

    fprintf(file, "Average: %.2f\n", result);
    fclose(file);
}

// Main function
int main() {
    int count;
    int *numbers = readIntegersFromFile(FILE_NAME, &count);
    if (numbers == NULL) {
        handleError("Failed to read integers from file.");
    }

    double average = calculateAverage(numbers, count);
    printf("Calculated Average: %.2f\n", average);

    writeResultToFile("result.txt", average);
    printf("Result written to result.txt\n");

    free(numbers);
    return 0;
}