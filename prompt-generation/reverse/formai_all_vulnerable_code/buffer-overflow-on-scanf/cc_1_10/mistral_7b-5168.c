//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to print welcome message
void welcome() {
    printf("\n*********************************\n");
    printf("*                               *\n");
    printf("* Welcome to the Happiness Index *\n");
    printf("* Analyzer 3000!                 *\n");
    printf("*                               *\n");
    printf("*********************************\n");
}

// Function to read data from file
void readData(FILE *file, double *data, int size) {
    int i;
    for (i = 0; i < size; i++) {
        fscanf(file, "%lf", &data[i]);
    }
}

// Function to calculate happiness index
double happinessIndex(double *data, int size) {
    double sum = 0.0, avg = 0.0;
    int i;

    for (i = 0; i < size; i++) {
        sum += data[i];
    }

    avg = sum / size;

    for (i = 0; i < size; i++) {
        sum += pow(data[i] - avg, 2);
    }

    return sqrt(sum / size);
}

int main() {
    FILE *file;
    double *data;
    int size, i;

    // Read number of data points from user
    printf("Enter number of data points: ");
    scanf("%d", &size);

    // Allocate memory for data array
    data = (double *)malloc(size * sizeof(double));

    // Open input file
    file = fopen("happiness.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read data from file and store in array
    readData(file, data, size);

    // Calculate happiness index
    double index = happinessIndex(data, size);

    // Print happiness index
    printf("The happiness index is %.2f\n", index);

    // Free memory and close file
    free(data);
    fclose(file);

    return 0;
}