//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 1000
#define MAX_COLUMNS 80
#define TERM_WIDTH 8
#define DIVIDER_WIDTH 2
#define INITIAL_DELAY 30
#define DELAY_INCREMENT 10

int main() {
    int num_terms = 0;
    int term_width = TERM_WIDTH;
    int divider_width = DIVIDER_WIDTH;
    int delay = INITIAL_DELAY;
    time_t start_time;
    time_t current_time;
    int seed;
    srand(time(&seed));

    printf("Enter the number of terms to generate (up to %d): ", MAX_TERMS);
    scanf("%d", &num_terms);

    if (num_terms > MAX_TERMS) {
        num_terms = MAX_TERMS;
    }

    printf("Generating Fibonacci sequence with %d terms...\n", num_terms);
    printf("Press any key to start.\n");
    getchar();

    start_time = time(NULL);

    for (int i = 0; i < num_terms; i++) {
        int term = fibonacci(i);
        printf("%*d", term_width, term);

        if (i < num_terms - 1) {
            printf("%*s", divider_width, "+");
        }

        if (i % 10 == 9) {
            printf("\n");
        }

        current_time = time(NULL);
        if (difftime(current_time, start_time) >= delay) {
            delay += DELAY_INCREMENT;
            printf("\nPress any key to continue...\n");
            getchar();
            start_time = current_time;
        }
    }

    printf("\nDone.\n");

    return 0;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}