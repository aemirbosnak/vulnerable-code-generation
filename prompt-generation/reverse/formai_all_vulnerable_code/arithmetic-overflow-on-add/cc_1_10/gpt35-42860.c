//FormAI DATASET v1.0 Category: Memory management ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to our Memory Management System!\n");

    // User input for number of integers to store
    int numInts;
    printf("How many integers would you like to store? ");
    scanf("%d", &numInts);

    // Dynamic allocation of memory based on user input
    int* arr = (int*) malloc(numInts * sizeof(int));

    // Error checking for invalid allocation
    if (arr == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return 1;  // Exit program with error code
    }

    // User input for integers to store in allocated memory
    printf("Enter %d integers to store in memory:\n", numInts);
    for (int i = 0; i < numInts; i++) {
        scanf("%d", &arr[i]);
    }

    // User confirmation of stored integers
    printf("The integers stored in memory are: ");
    for (int i = 0; i < numInts; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // User input for number of integers to add to allocated memory
    int addInts;
    printf("How many integers would you like to add to memory? ");
    scanf("%d", &addInts);

    // Dynamic reallocation of memory based on user input
    arr = (int*) realloc(arr, (numInts + addInts) * sizeof(int));

    // Error checking for invalid reallocation
    if (arr == NULL) {
        printf("Error: Failed to reallocate memory.\n");
        return 1;  // Exit program with error code
    }

    // User input for additional integers to store in allocated memory
    printf("Enter %d more integers to store in memory:\n", addInts);
    for (int i = numInts; i < numInts + addInts; i++) {
        scanf("%d", &arr[i]);
    }

    // User confirmation of updated stored integers
    printf("The updated integers stored in memory are: ");
    for (int i = 0; i < numInts + addInts; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr);

    printf("Thank you for using our Memory Management System!\n");

    return 0;  // Exit program with success code
}