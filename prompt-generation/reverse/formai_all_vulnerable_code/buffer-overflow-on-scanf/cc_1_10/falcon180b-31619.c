//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function to print the Fibonacci sequence up to n terms
void printFibonacci(int n) {
    int first = 0, second = 1, nextTerm;

    printf("Fibonacci sequence up to %d terms:\n", n);
    printf("0 ");
    for (int i = 1; i < n; i++) {
        nextTerm = first + second;
        printf("%d ", nextTerm);
        first = second;
        second = nextTerm;
    }
}

// Function to visualize the Fibonacci sequence
void visualizeFibonacci(int n) {
    int width, height, x, y, count = 0;
    char ch;

    // Get terminal dimensions
    if (system("tput cols > cols.txt") == 0) {
        FILE *file = fopen("cols.txt", "r");
        fscanf(file, "%d", &width);
        fclose(file);
        remove("cols.txt");
    } else {
        printf("Error getting terminal width.\n");
        exit(1);
    }

    if (system("tput lines > lines.txt") == 0) {
        FILE *file = fopen("lines.txt", "r");
        fscanf(file, "%d", &height);
        fclose(file);
        remove("lines.txt");
    } else {
        printf("Error getting terminal height.\n");
        exit(1);
    }

    // Print the Fibonacci sequence as ASCII art
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        for (int k = 0; k < (width - 2 * i - 1); k++) {
            printf("-");
        }
        printf("+");
        count++;
        if (count == 10) {
            printf("\n");
            count = 0;
        }
    }

    // Print a legend
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf(" ");
        if (i == 0) {
            printf("0");
        } else if (i == 1) {
            printf("1");
        } else {
            printf("%d", i);
        }
    }
    printf("\n");
}

int main() {
    int n;

    // Get user input for number of terms
    printf("Enter the number of terms to display in the Fibonacci sequence: ");
    scanf("%d", &n);

    // Print the Fibonacci sequence
    printf("\n");
    printFibonacci(n);

    // Visualize the Fibonacci sequence
    printf("\n");
    visualizeFibonacci(n);

    return 0;
}