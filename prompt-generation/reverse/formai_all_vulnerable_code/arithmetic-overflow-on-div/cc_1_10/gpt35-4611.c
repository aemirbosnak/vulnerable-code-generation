//FormAI DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void handle_error(int code) {
    switch(code) {
        case 1:
            printf("Error: Division by zero!\n");
            break;
        case 2:
            printf("Error: Invalid input!\n");
            break;
        case 3:
            printf("Error: Out of memory!\n");
            break;
        default:
            printf("Unknown error!\n");
            break;
    }
    
    // Log error to file
    FILE *fPtr;
    fPtr = fopen("error_log.txt", "a");
    if(fPtr != NULL) {
        time_t now = time(NULL);
        fprintf(fPtr, "Error: Code %d -- Timestamp: %s", code, ctime(&now));
        fclose(fPtr);
    }
    
    // Try to recover gracefully
    switch(code) {
        case 1:
            // Use default value instead
            break;
        case 2:
            // Ask for valid input
            break;
        case 3:
            // Free up memory and try again
            break;
        default:
            // Do nothing
            break;
    }
}

int main() {
    int a, b, c;
    
    // Get user input
    printf("Enter two numbers: ");
    if(scanf("%d %d", &a, &b) != 2) {
        handle_error(2);
        return EXIT_FAILURE;
    }
    
    // Perform calculation
    if(b == 0) {
        handle_error(1);
        return EXIT_FAILURE;
    } else {
        c = a / b;
    }
    
    // Allocate memory and check for errors
    int *arr;
    arr = malloc(c * sizeof(int));
    if(arr == NULL) {
        handle_error(3);
        return EXIT_FAILURE;
    }
    
    // Fill array with random numbers
    srand(time(NULL));
    for(int i = 0; i < c; i++) {
        arr[i] = rand();
    }
    
    // Display array
    printf("Array contents:\n");
    for(int i = 0; i < c; i++) {
        printf("%d: %d\n", i, arr[i]);
    }
    
    free(arr);
    
    return EXIT_SUCCESS;
}