//Code Llama-13B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_N 20
#define MAX_W 60
#define MAX_H 20

void print_fibonacci(int n) {
    int i;
    int x = 0;
    int y = 0;
    int x_prev = 0;
    int y_prev = 0;
    int x_next = 0;
    int y_next = 0;
    char str[MAX_W];

    for (i = 0; i < n; i++) {
        x_next = x_prev + x;
        y_next = y_prev + y;
        x_prev = x;
        y_prev = y;
        x = x_next;
        y = y_next;

        sprintf(str, "%d", x);
        printf("%s", str);
    }

    printf("\n");
}

void print_fibonacci_sequence(int n) {
    int i;
    int x = 0;
    int y = 0;
    int x_prev = 0;
    int y_prev = 0;
    int x_next = 0;
    int y_next = 0;
    char str[MAX_W];

    for (i = 0; i < n; i++) {
        x_next = x_prev + x;
        y_next = y_prev + y;
        x_prev = x;
        y_prev = y;
        x = x_next;
        y = y_next;

        sprintf(str, "%d", x);
        printf("%s", str);
    }

    printf("\n");
}

void print_fibonacci_visualization(int n) {
    int i;
    int x = 0;
    int y = 0;
    int x_prev = 0;
    int y_prev = 0;
    int x_next = 0;
    int y_next = 0;
    char str[MAX_W];

    for (i = 0; i < n; i++) {
        x_next = x_prev + x;
        y_next = y_prev + y;
        x_prev = x;
        y_prev = y;
        x = x_next;
        y = y_next;

        sprintf(str, "%d", x);
        printf("%s", str);
    }

    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    print_fibonacci(n);
    print_fibonacci_sequence(n);
    print_fibonacci_visualization(n);

    return 0;
}