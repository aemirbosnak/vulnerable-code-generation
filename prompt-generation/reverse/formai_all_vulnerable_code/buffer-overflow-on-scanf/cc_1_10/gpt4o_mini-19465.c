//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_fibonacci(int n) {
    unsigned long long a = 0, b = 1, c;
    printf("Fibonacci Sequence:\n");
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%llu, ", a);
            continue;
        }
        if (i == 1) {
            printf("%llu, ", b);
            continue;
        }
        c = a + b;
        a = b;
        b = c;
        printf("%llu, ", c);
        
        // Simple visualization for each Fibonacci number
        printf("\rProgress: ");
        int percent = (i + 1) * 100 / n;
        int bar_width = 50; // Width of the progress bar
        int pos = bar_width * percent / 100;
        printf("[");
        for (int j = 0; j < bar_width; j++) {
            if (j < pos) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("] %d%%", percent);
        fflush(stdout);
        usleep(500000); // Pause for half a second for visualization effect
    }
    printf("\n");
}

void display_menu() {
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Please choose an option:\n");
    printf("1. Generate Fibonacci Sequence\n");
    printf("2. Exit\n");
}

int main() {
    int choice, n;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the number of Fibonacci terms to generate: ");
            scanf("%d", &n);
            if (n <= 0) {
                printf("Please enter a positive integer.\n\n");
                continue;
            }
            print_fibonacci(n);
        } else if (choice == 2) {
            printf("Thank you for using the Fibonacci Sequence Visualizer!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}