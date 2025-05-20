//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 1000
#define DELAY_BETWEEN_TERMS 20

int main() {
    int i, j, n, a = 0, b = 1, c;
    int terms_generated = 0;
    time_t start_time, end_time;
    double elapsed_time;

    printf("Enter the number of terms to generate: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of terms.\n");
        return 1;
    }

    printf("Generating Fibonacci sequence up to %d terms...\n", n);

    start_time = time(NULL);

    for (i = 0; i < n; i++) {
        if (i == 0) {
            c = a;
        } else if (i == 1) {
            c = b;
        } else {
            c = a + b;
            a = b;
            b = c;
        }

        printf("%d\n", c);
        fflush(stdout);

        terms_generated++;

        if (terms_generated >= MAX_TERMS) {
            break;
        }

        if (i < n - 1) {
            usleep(DELAY_BETWEEN_TERMS * 1000);
        }
    }

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);

    printf("\nFinished generating %d terms in %.2f seconds.\n", terms_generated, elapsed_time);

    return 0;
}