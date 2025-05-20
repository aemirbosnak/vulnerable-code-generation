//Code Llama-13B DATASET v1.0 Category: File handling ; Style: complex
/*
 * File handling example program
 *
 * This program demonstrates how to read and write data to a file in C.
 * It creates a file named "data.txt" and writes a list of numbers to it, then
 * reads the numbers back from the file and prints them to the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_VALUES 10

int main(void) {
    // Declare variables
    FILE *fp;
    int values[NUM_VALUES];
    int i;

    // Open the file for writing
    fp = fopen("data.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    // Write the values to the file
    for (i = 0; i < NUM_VALUES; i++) {
        values[i] = i * 2;
        fprintf(fp, "%d\n", values[i]);
    }

    // Close the file
    fclose(fp);

    // Open the file for reading
    fp = fopen("data.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    // Read the values back from the file
    for (i = 0; i < NUM_VALUES; i++) {
        fscanf(fp, "%d", &values[i]);
    }

    // Close the file
    fclose(fp);

    // Print the values to the console
    for (i = 0; i < NUM_VALUES; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");

    return 0;
}