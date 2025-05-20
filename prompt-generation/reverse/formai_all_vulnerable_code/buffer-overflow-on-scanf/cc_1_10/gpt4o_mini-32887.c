//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void print_fibonacci(int n) {
    long long f1 = 0, f2 = 1, f_next;
    printf("Fibonacci Sequence:\n");
    
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            printf("%lld ", i);
        } else {
            f_next = f1 + f2;
            f1 = f2;
            f2 = f_next;
            printf("%lld ", f_next);
        }
    }
    printf("\n");
}

void visualize_fibonacci(int n) {
    long long f1 = 0, f2 = 1, f_next;
    printf("Visualizing Fibonacci Sequence:\n");
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("0: ");
        } else if (i == 1) {
            printf("1: ");
        } else {
            f_next = f1 + f2;
            printf("%lld: ", f_next);
            f1 = f2;
            f2 = f_next;
        }
        
        // Create a visual representation
        for (long long j = 0; j < f_next; j += 10000) {
            printf("#");
            fflush(stdout);  // Force print to terminal
            usleep(20000);   // Sleep for 0.02 seconds
        }
        printf("\n");
    }
}

void run_fibonacci_sequence() {
    int n;
    printf("Enter the number of terms in the Fibonacci sequence you want to visualize: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        fprintf(stderr, "Please enter a positive integer.\n");
        return;
    }
    
    print_fibonacci(n);
    visualize_fibonacci(n);
}

void display_menu() {
    printf("\nFibonacci Sequence Visualizer\n");
    printf("1. Generate Fibonacci Sequence\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                run_fibonacci_sequence();
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 2);
    
    return 0;
}