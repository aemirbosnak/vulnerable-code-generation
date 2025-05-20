//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: cheerful
#include <stdio.h>

void printFibonacci(int n) {
    int first = 0, second = 1, next, i, j;

    printf("Here’s the Fibonacci sequence visualized!\n");
    printf("   ^\n   |\n");

    for (i = 0; i < n; i++) {
        // Print the Fibonacci number
        if (i == 0) {
            next = first;
        } else if (i == 1) {
            next = second;
        } else {
            next = first + second;
            first = second;
            second = next;
        }
        
        // Print stars for visualization
        printf("Fibonacci %d: %d\n", i, next);
        for (j = 0; j < next; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int count;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("How many Fibonacci numbers would you like to see? (e.g., 10): ");
    
    // Get the user's choice
    scanf("%d", &count);
    
    // Just a little validation for a cheerful experience
    if (count < 0) {
        printf("Oh no! Please enter a positive number next time! :)\n");
        return 1; // Exit with an error code
    }

    // Call the function to visualize Fibonacci
    printFibonacci(count);

    printf("\nThanks for using the Fibonacci Sequence Visualizer! Have a fantastic day! 🎉\n");
    return 0;
}