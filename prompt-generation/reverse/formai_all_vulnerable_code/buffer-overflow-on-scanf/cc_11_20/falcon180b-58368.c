//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FIBONACCI 10000

int main() {
    int n, i, t1, t2, nextTerm;
    char choice;

    do {
        printf("Enter the number of terms to display: ");
        scanf("%d", &n);
        if (n > MAX_FIBONACCI) {
            printf("Sorry, the maximum number of terms is %d.\n", MAX_FIBONACCI);
        }
    } while (n > MAX_FIBONACCI);

    printf("Enter 'y' to display the sequence in ascending order or 'n' to display it in descending order: ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        t1 = 0;
        t2 = 1;
        printf("The Fibonacci sequence in ascending order:\n");
    } else if (choice == 'n' || choice == 'N') {
        t1 = MAX_FIBONACCI;
        t2 = MAX_FIBONACCI - 1;
        printf("The Fibonacci sequence in descending order:\n");
    } else {
        printf("Invalid choice.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        if (choice == 'y' || choice == 'Y') {
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
        } else if (choice == 'n' || choice == 'N') {
            nextTerm = t1 - t2;
            t1 = t2;
            t2 = nextTerm;
        }
        printf("%d ", nextTerm);
    }

    printf("\n");

    return 0;
}