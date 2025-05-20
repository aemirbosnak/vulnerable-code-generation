//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_TERMS 1000
#define MAX_WIDTH 80

// Function to print the Fibonacci sequence
void print_fibonacci(int n) {
    int i, t1 = 0, t2 = 1, nextTerm;

    printf("Fibonacci sequence:\n");
    for (i = 0; i < n; i++) {
        if (i == 0)
            printf("0\t");
        else if (i == 1)
            printf("1\t");
        else {
            nextTerm = t1 + t2;
            t1 = t2;
            t2 = nextTerm;
            printf("%d\t", t1);
        }
    }
}

// Function to generate a random number between min and max
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random Fibonacci number
int rand_fibonacci(int min, int max) {
    int n = rand_int(min, max);
    int i, t1 = 0, t2 = 1, fib;

    for (i = 0; i < n; i++) {
        fib = t1 + t2;
        t1 = t2;
        t2 = fib;
    }

    return t1;
}

// Function to get user input for number of terms
int get_input() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    return n;
}

int main() {
    srand(time(NULL));
    int n = get_input();
    int i, width = 0;

    // Calculate the maximum width of the Fibonacci numbers
    for (i = 0; i < n; i++) {
        int num = rand_fibonacci(1, MAX_TERMS);
        int len = (int)log10(num) + 1;
        if (len > width)
            width = len;
    }

    // Print the Fibonacci sequence
    printf("\n");
    for (i = 0; i < n; i++) {
        int num = rand_fibonacci(1, MAX_TERMS);
        int len = (int)log10(num) + 1;
        printf("%*d\t", width - len, num);
    }

    return 0;
}