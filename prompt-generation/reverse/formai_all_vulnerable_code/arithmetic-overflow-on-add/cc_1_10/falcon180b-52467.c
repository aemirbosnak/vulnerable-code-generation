//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000
#define MAX_WIDTH 80

// Function to generate the Fibonacci sequence
void fibonacci(int n) {
    int a = 0, b = 1, c;
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    int n = 0;
    char choice;
    srand(time(0));

    do {
        // Clear the console
        system("clear");

        // Print the Fibonacci sequence
        fibonacci(MAX);
        printf("\n");

        // Get user input
        printf("Enter the number of Fibonacci numbers to display (0 to display all): ");
        scanf("%d", &n);

        // Check for valid input
        if (n < 0 || n > MAX) {
            printf("Invalid input. Please enter a number between 0 and %d.\n", MAX);
        }
    } while (n == 0);

    // Print the Fibonacci sequence up to the user-specified number
    fibonacci(n);

    do {
        printf("\nDo you want to generate another sequence? (y/n): ");
        scanf(" %c", &choice);
        choice = toupper(choice);
    } while (choice!= 'N');

    return 0;
}