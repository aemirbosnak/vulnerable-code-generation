//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100 //Maximum numbers for Fibonacci Sequence

int fib_sequence[MAX] = { 0 }; //Initializing Fibonacci Sequence to 0

//Fibonacci Sequence Calculation Function
void *fib(void *arg) {
    int n = *((int*)arg);

    //First two numbers initialized to 0 and 1 respectively
    fib_sequence[0] = 0;
    fib_sequence[1] = 1;

    //Calculation of Fibonacci Sequence
    for (int i = 2; i <= n; i++) {
        fib_sequence[i] = fib_sequence[i - 1] + fib_sequence[i - 2];
    }
    pthread_exit(NULL); //Terminate the thread
}

//Visualization Function
void visualization(int n) {
    printf("\nFibonacci Sequence:\n");

    //Printing the numbers of Fibonacci Sequence
    for (int i = 0; i <= n; i++) {
        printf("%d ", fib_sequence[i]);
    }
    printf("\n");
}

int main() {
    int n;
    pthread_t tid; //Thread ID

    printf("Enter the number of terms for Fibonacci Sequence (maximum %d): ", MAX);
    scanf("%d", &n);

    if (n < 0 || n > MAX) {
        printf("Invalid input!\n");
        exit(0);
    }

    //Thread creation for Fibonacci Sequence calculation
    pthread_create(&tid, NULL, fib, &n);

    //Waiting for the thread to complete
    pthread_join(tid, NULL);

    //Visualization of Fibonacci Sequence
    visualization(n);

    return 0;
}