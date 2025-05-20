//FormAI DATASET v1.0 Category: Error handling ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Defining error codes
#define FILE_ERROR 1
#define MEMORY_ERROR 2
#define INPUT_ERROR 3
#define OUTPUT_ERROR 4

int main() {
    // Opening file
    FILE *f = fopen("example.txt", "r");
    if (f == NULL) {
        // Handling file error
        printf("Error in opening file. Error code: %d\n", FILE_ERROR);
        return FILE_ERROR;
    }

    // Allocating memory for input array
    int size;
    printf("Enter the size of array: ");
    if (scanf("%d", &size) != 1) {
        // Handling input error
        printf("Error in reading input. Error code: %d\n", INPUT_ERROR);
        return INPUT_ERROR;
    }
    int *arr = malloc(sizeof(int) * size);
    if (arr == NULL) {
        // Handling memory error
        printf("Error in allocating memory. Error code: %d\n", MEMORY_ERROR);
        return MEMORY_ERROR;
    }

    // Reading input array from file
    int i;
    for (i = 0; i < size; i++) {
        if (fscanf(f, "%d", &arr[i]) != 1) {
            // Handling input error
            printf("Error in reading input. Error code: %d\n", INPUT_ERROR);
            return INPUT_ERROR;
        }
    }

    // Closing file
    if (fclose(f) != 0) {
        // Handling output error
        printf("Error in writing output. Error code: %d\n", OUTPUT_ERROR);
        return OUTPUT_ERROR;
    }

    // Performing operations on input array
    int sum = 0;
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }

    // Writing output to file
    f = fopen("output.txt", "w");
    if (f == NULL) {
        // Handling file error
        printf("Error in opening file. Error code: %d\n", FILE_ERROR);
        return FILE_ERROR;
    }
    if (fprintf(f, "%d", sum) < 0) {
        // Handling output error
        printf("Error in writing output. Error code: %d\n", OUTPUT_ERROR);
        return OUTPUT_ERROR;
    }

    // Closing file
    if (fclose(f) != 0) {
        // Handling output error
        printf("Error in writing output. Error code: %d\n", OUTPUT_ERROR);
        return OUTPUT_ERROR;
    }

    // Freeing memory
    free(arr);

    return 0;
}