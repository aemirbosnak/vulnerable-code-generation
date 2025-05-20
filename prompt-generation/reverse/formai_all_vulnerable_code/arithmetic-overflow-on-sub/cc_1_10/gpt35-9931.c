//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: curious
#include <stdio.h>

void printFibonacci(int n, int max, int level);

int main() {
    int n, i, max, level;

    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    max = n*2;
    level = n*2;

    printf("\nHere is the Fibonacci sequence up to term %d:\n\n", n);

    printFibonacci(0, max, level);

    return 0;
}

void printFibonacci(int n, int max, int level) {
    if (n == 0) {
        printf("  %c\n", 201); // Corner character
    }

    if (n == max) {
        return;
    }

    int i, num1 = 0, num2 = 1, sum = 0;

    for (i = 1; i <= n; i++) {
        sum = num1 + num2;
        num1 = num2;
        num2 = sum;
    }

    if (n == max - 1) {
        printf("%*d\n", level*3 - 2, sum);
    } else {
        printf("%*d%c\n", level*3 - 2, sum, 186); // Vertical line character
    }

    level--;

    printf("%*c%c\n", level*3, 186, 200); // T-shaped character
    printf("%*c\n", level*3, 186); // Vertical line character
    printf("%*c%c\n", level*3, 186, 188); // L-shaped character

    printFibonacci(n+1, max, level+1);
}