//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>

static int running = 1;

void signal_handler(int signum)
{
    if (signum == SIGINT) {
        printf("\nExiting...\n");
        running = 0;
    }
}

void *fibonacci_thread(void *arg)
{
    int n = *(int *)arg;
    int a = 0, b = 1, c;

    printf("Fibonacci sequence for %d numbers: ", n);

    while (running && n > 0) {
        c = a + b;
        a = b;
        b = c;

        printf("%d ", c);

        n--;
        usleep(100000); // Sleep for 100 milliseconds
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    int n;

    // Register signal handler
    signal(SIGINT, signal_handler);

    // Get number of Fibonacci numbers to generate
    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    // Create and run Fibonacci thread
    pthread_t thread;
    pthread_create(&thread, NULL, fibonacci_thread, &n);

    // Wait for thread to finish
    pthread_join(thread, NULL);

    return 0;
}