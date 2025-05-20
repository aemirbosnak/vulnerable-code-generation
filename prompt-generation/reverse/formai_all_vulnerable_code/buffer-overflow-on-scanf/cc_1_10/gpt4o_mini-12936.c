//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory and handle errors
void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed! Please make space for gratitude.\n");
        exit(EXIT_FAILURE); // Exit if memory allocation fails
    }
    return ptr;
}

// Function to read integer input and handle errors
int safe_input() {
    int num;
    while (1) {
        printf("Please enter a positive integer (or enter -1 to exit gracefully): ");
        if (scanf("%d", &num) != 1) {
            while(getchar() != '\n'); // Clear invalid input
            printf("Oh dear! That doesn't seem to be a valid integer. Let's try again with a positive number.\n");
            continue;
        }
        if (num == -1) {
            printf("Thank you for participating! Exiting gracefully.\n");
            exit(EXIT_SUCCESS); // Exit gracefully with a thank you
        }
        if (num < 0) {
            printf("Negative numbers cannot be accepted! Let's keep positivity alive!\n");
            continue;
        }
        break; // valid input
    }
    
    return num;
}

// Function to perform some calculations
void perform_calculations(int num) {
    printf("Wow! You've chosen the number %d. Let's perform some calculations together:\n", num);
    
    // Allocate memory for results
    int* results = (int*) safe_malloc(num * sizeof(int));

    // Calculate squares
    for (int i = 0; i < num; i++) {
        results[i] = i * i;
        printf("The square of %d is %d. Keep up the great work!\n", i, results[i]);
    }
    
    // Free allocated memory
    free(results);
    printf("Thank you for allowing me to allocate memory! It has been freed with joy.\n");
}

int main() {
    printf("Welcome to the Grateful Calculation Program!\n");

    while (1) {
        int number = safe_input();
        if(number != -1) {  // This check allows graceful exit before calculation
            perform_calculations(number);
        }
    }

    return 0;
}