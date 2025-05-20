//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000000

int fibonacci[MAX];

void initialize() {
    int i;
    for(i=0; i<MAX; i++) {
        fibonacci[i] = -1;
    }
}

void calculate_fibonacci(int n) {
    int i, j, k;
    int *ptr;

    if(n == 0) {
        fibonacci[0] = 0;
    }
    else if(n == 1) {
        fibonacci[1] = 1;
    }
    else {
        initialize();
        fibonacci[0] = 0;
        fibonacci[1] = 1;
        ptr = &fibonacci[2];
        for(i=2; i<n; i++) {
            *ptr = fibonacci[i-1] + fibonacci[i-2];
            ptr++;
        }
    }
}

void display_fibonacci(int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%d ", fibonacci[i]);
    }
    printf("\n");
}

int main() {
    int n, max_num;
    int seed;
    srand(time(NULL));
    seed = rand();
    printf("Welcome to the Fibonacci Sequence Visualizer.\n");
    printf("I will generate a sequence of %d numbers.\n", MAX);
    printf("Press enter to continue.\n");
    scanf("%d", &n);
    max_num = MAX - n;
    printf("Generating sequence...\n");
    calculate_fibonacci(max_num);
    printf("Sequence generated.\n");
    printf("Press enter to display sequence.\n");
    scanf("%d", &n);
    display_fibonacci(n);
    return 0;
}