//FormAI DATASET v1.0 Category: Benchmarking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform benchmarking
void benchmark(int max_count) {
    clock_t start, end;
    double total_time;
    
    // Start the timer
    start = clock();
    
    // Perform some task
    int sum = 0;
    for (int i = 1; i <= max_count; i++) {
        sum += i;
    }
    
    // End the timer
    end = clock();
    
    // Calculate total time taken
    total_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
    
    // Output the result
    printf("Total time taken for summing the numbers up to %d is %.5f seconds.\n", 
            max_count, total_time);
}

// Main function
int main() {
    printf("Welcome to the medieval style benchmarking program!\n\n");
    
    // Ask user for input
    printf("Please enter the maximum number to sum up: ");
    int max_count;
    scanf("%d", &max_count);
    
    // Check for valid input
    if (max_count <= 0) {
        printf("Invalid input! Please enter a positive number.\n");
        return 1;
    }
    
    // Perform benchmarking
    printf("Performing benchmarking...\n");
    benchmark(max_count);
    
    // Display closing message
    printf("\nThank you for using the medieval style benchmarking program!\n");
    
    return 0;
}