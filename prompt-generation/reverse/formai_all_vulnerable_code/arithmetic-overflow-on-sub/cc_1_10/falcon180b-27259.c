//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NUMBERS 1000000
#define MAX_WIDTH 80
#define MAX_HEIGHT 50
#define NUMBER_COLOR "\033[1;35m"
#define BACKGROUND_COLOR "\033[1;40m"
#define RESET_COLOR "\033[0m"

// Function to generate the Fibonacci sequence
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

// Function to print the Fibonacci sequence in a visually appealing way
void print_fibonacci(int arr[], int n) {
    int max_width = MAX_WIDTH - 5;
    int max_height = MAX_HEIGHT - 5;
    int x, y, i, j;

    for (i = 0; i < n; i++) {
        x = (i % max_width) * 3 + 2;
        y = (i / max_width) * 3 + 2;

        if (arr[i] == 1) {
            printf(NUMBER_COLOR "  " RESET_COLOR);
        } else {
            printf(NUMBER_COLOR " %d " RESET_COLOR, arr[i]);
        }
    }

    for (i = 0; i < max_width; i++) {
        printf(BACKGROUND_COLOR "  " RESET_COLOR);
    }

    printf("\n");
}

int main(void) {
    int n, i;
    int fib_arr[MAX_NUMBERS];
    time_t start_time, end_time;
    double elapsed_time;

    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    srand(time(NULL));
    fib_arr[0] = rand() % 1000000;
    fib_arr[1] = rand() % 1000000;

    start_time = clock();
    for (i = 2; i < n; i++) {
        fib_arr[i] = fibonacci(fib_arr[i-1]) + fib_arr[i-2];
    }
    end_time = clock();

    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time elapsed: %.2f seconds\n", elapsed_time);

    printf("\nFibonacci sequence:\n");
    print_fibonacci(fib_arr, n);

    return 0;
}