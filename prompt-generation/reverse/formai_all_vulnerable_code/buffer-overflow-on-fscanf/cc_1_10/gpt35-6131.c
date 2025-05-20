//FormAI DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Open file for writing
    FILE *fp = fopen("data.txt", "w");

    // Check if file was successfully opened
    if(fp == NULL) {
        printf("Error opening file.");
        return 1; // Exit program with error code 1
    }

    // Generate and write random data to file
    int num_values = 100;
    fprintf(fp, "%d\n", num_values);
    for(int i = 0; i < num_values; i++) {
        int value = rand() % 100; // Generate random value between 0 and 99
        fprintf(fp, "%d\n", value);
    }

    // Close file
    fclose(fp);

    // Open file for reading
    fp = fopen("data.txt", "r");

    // Check if file was successfully opened
    if(fp == NULL) {
        printf("Error opening file.");
        return 1; // Exit program with error code 1
    }

    // Read data from file and compute statistics
    fscanf(fp, "%d", &num_values); // Read number of values from file
    int min = 100, max = 0, sum = 0;
    float mean;
    for(int i = 0; i < num_values; i++) {
        int value;
        fscanf(fp, "%d", &value); // Read value from file
        if(value < min) min = value; // Update minimum value
        if(value > max) max = value; // Update maximum value
        sum += value; // Update sum of values
    }
    mean = (float) sum / num_values;

    // Close file
    fclose(fp);

    // Print statistics
    printf("Number of values: %d\n", num_values);
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
    printf("Sum of values: %d\n", sum);
    printf("Mean: %.2f\n", mean);

    return 0; // Exit program with success code 0
}