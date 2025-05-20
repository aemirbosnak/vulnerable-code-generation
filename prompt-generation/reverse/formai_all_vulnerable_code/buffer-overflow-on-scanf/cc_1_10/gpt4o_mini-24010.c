//GPT-4o-mini DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void display_fibonacci(int n) {
    int a = 0, b = 1, c;

    printf("\n");
    printf("Fibonacci Sequence Visualization:\n\n");
    printf("Index\tValue\tVisualization\n");
    printf("-----\t-----\t-------------\n");
    
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            c = a;
        } else if (i == 1) {
            c = b;
        } else {
            c = a + b;
            a = b;
            b = c;
        }
        
        // Print index, value, and ASCII art for Fibonacci value
        printf("%3d\t%5d\t", i, c);
        
        // Visualization: create a simple scale proportional to the Fibonacci value
        for (int j = 0; j < c; j += 2) { // Using j += 2 to keep the line shorter for large values
            printf("*");
        }
        
        // New line for next Fibonacci number
        printf("\n");

        // Slow down the output for better visual presentation
        usleep(500000); // Sleep for 0.5 seconds
    }
}

void print_menu() {
    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("--------------------------------------------------\n");
    printf("Please choose an option:\n");
    printf("1. Visualize Fibonacci Sequence\n");
    printf("2. Exit\n");
    printf("--------------------------------------------------\n");
}

int main() {
    int choice;
    int terms;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the number of terms to visualize: ");
            scanf("%d", &terms);
            
            if (terms < 0) {
                printf("Please enter a non-negative integer.\n");
                continue;
            }
            display_fibonacci(terms);
        } else if (choice == 2) {
            printf("Exiting the program. Thank you!\n");
            break;
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}