//MISTRAL-7B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define LINE_LENGTH 80
#define FIB_LIMIT 50
#define DELAY 100000

void fibonacci(int limit) {
    int a = 0, b = 1, c;
    int i;

    printf("\nFibonacci Sequence up to %d:\n", limit);
    printf("----------------------------------\n");

    printf("%d %d ", a, b);

    for (i = 2; i < limit; i++) {
        usleep(DELAY);
        system("clear");
        printf("%s%s", "\x1b[1;1H", "");

        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}

void print_ascii_art(void) {
    char art[] =
        " _______          _______\n"
        "|       |        |       |\n"
        "|   ____|_ ______|___   _|\n"
        "|  |____| |_____|  | | |\n"
        "|   ___  |_____|  |_| |_\n"
        "|____|  |______|____| | \n"
        "|____|                 \n";

    printf("\n%s\n", art);
}

int main(void) {
    int limit;
    clock_t start, end;

    printf("Enter the Fibonacci sequence limit: ");
    scanf("%d", &limit);

    if (limit > FIB_LIMIT)
        printf("Warning: Sequence limit too large!\n");

    start = clock();
    fibonacci(limit);
    end = clock();

    double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nComputation time: %f seconds", elapsed_time);

    print_ascii_art();

    return 0;
}