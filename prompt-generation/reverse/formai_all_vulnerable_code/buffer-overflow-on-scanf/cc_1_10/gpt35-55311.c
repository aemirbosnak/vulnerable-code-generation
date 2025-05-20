//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: complex
#include <stdio.h>

void printFibonacci(int n) {
    int first = 0;
    int second = 1;
    int i;

    printf("%d %d ", first, second);

    for (i = 2; i < n; i++) {
        int next = first + second;
        first = second;
        second = next;
        printf("%d ", next);
    }
}

void printLine(int n, char ch) {
    for (int i = 0; i < n; i++) {
        printf("%c", ch);
    }
    printf("\n");
}

void printBox(int n, char ch) {
    printLine(2 * n + 2, ch);

    for (int i = 0; i < n; i++) {
        printf("%c ", ch);
        printLine(2 * i, ' ');
        printf("%c\n", ch);
    }

    printf("%c ", ch);
    printLine(2 * n, '_');
    printf("%c\n", ch);

    for (int i = n - 1; i >= 0; i--) {
        printf("%c ", ch);
        printLine(2 * i, ' ');
        printf("%c\n", ch);
    }

    printLine(2 * n + 2, ch);
}

int main() {
    int n;

    printf("Enter the number of terms to print in the Fibonacci sequence: ");
    scanf("%d", &n);

    printf("\nFibonacci Sequence:\n");
    printFibonacci(n);

    printf("\n\nBox Pattern:\n");
    printBox(n, '*');

    return 0;
}