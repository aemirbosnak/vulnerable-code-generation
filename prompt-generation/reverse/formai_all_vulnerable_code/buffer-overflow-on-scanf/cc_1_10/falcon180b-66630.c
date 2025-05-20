//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TERMS 100

int main() {
    int n;
    bool quit = false;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of terms you wish to visualize (up to %d): ", MAX_TERMS);
    scanf("%d", &n);

    int terms[MAX_TERMS];
    int current_term = 0;

    while (current_term < n) {
        int a = 0, b = 1, c;
        printf("\n");
        for (int i = 0; i < current_term; i++) {
            printf("%d ", terms[i]);
        }
        printf("\n");

        if (current_term == 0) {
            terms[current_term] = 0;
            current_term++;
            continue;
        }

        if (current_term == 1) {
            terms[current_term] = 1;
            current_term++;
            continue;
        }

        for (int i = 0; i < current_term; i++) {
            c = a + b;
            a = b;
            b = c;
        }

        terms[current_term] = c;
        current_term++;

        printf("Enter 'q' to quit or any other key to continue: ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'q' || choice == 'Q') {
            quit = true;
        }
    }

    printf("\nThank you for using the Fibonacci Sequence Visualizer!\n");
    return 0;
}