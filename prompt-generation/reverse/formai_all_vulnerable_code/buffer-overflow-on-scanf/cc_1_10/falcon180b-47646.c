//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100
#define MAX_WIDTH 80

int main() {
    int n, i, j, width, sequence[MAX_NUMBERS];
    char *format = "%-*d";
    char *title = "Fibonacci Sequence";
    char *subtitle = "Up to 100 numbers, maximum width 80";

    printf("%s\n%s\n", title, subtitle);

    printf("Enter the number of terms to display: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_NUMBERS) {
        printf("Invalid number of terms. Exiting.\n");
        return 1;
    }

    sequence[0] = 0;
    sequence[1] = 1;

    for (i = 2; i < n; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
    }

    printf("\n");
    width = 0;
    for (i = 0; i < n; i++) {
        if (sequence[i] > width) {
            width = sequence[i];
        }
    }
    if (width == 0) {
        width = 1;
    }

    if (width > MAX_WIDTH) {
        printf("Warning: sequence will be truncated to fit within %d characters.\n", MAX_WIDTH);
        width = MAX_WIDTH;
    }

    printf("Fibonacci sequence of %d terms:\n\n", n);
    for (i = 0; i < n; i++) {
        printf(format, width, sequence[i]);
        if (i % 10 == 9) {
            printf("\n");
        }
    }

    return 0;
}