//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define MAX_TERMS 1000

void generate_fibonacci(int terms) {
    int a = 0, b = 1, c;
    for (int i = 0; i < terms; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
}

void print_fibonacci(int terms) {
    int a = 0, b = 1, c;
    for (int i = 0; i < terms; i++) {
        c = a + b;
        a = b;
        b = c;
    }
}

int main() {
    srand(time(0));
    int terms = rand() % MAX_TERMS + 1;

    system("clear");

    printf("Fibonacci Sequence Visualizer\n");
    printf("-----------------------------------------------------\n");

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if ((y + x) % 2 == 0) {
                printf("  ");
            } else {
                printf("█");
            }
        }
        printf("\n");
    }

    printf("Press any key to generate Fibonacci sequence...\n");
    getchar();

    generate_fibonacci(terms);

    getchar();

    return 0;
}