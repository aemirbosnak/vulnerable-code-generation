//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 1000

int main() {
    // Set random seed
    srand(time(NULL));

    // Initialize variables
    int num_terms = rand() % MAX_TERMS + 1;
    int a = 0, b = 1, c;

    // Print header
    printf("Fibonacci Sequence Visualizer\n");
    printf("=============================\n");

    // Generate sequence
    printf("Generating sequence with %d terms...\n", num_terms);
    for (int i = 0; i < num_terms; i++) {
        c = a + b;
        a = b;
        b = c;

        // Add some color to the output
        int color = rand() % 7;
        switch (color) {
            case 0:
                printf("\033[31m%d\033[0m ", c); // red
                break;
            case 1:
                printf("\033[32m%d\033[0m ", c); // green
                break;
            case 2:
                printf("\033[33m%d\033[0m ", c); // yellow
                break;
            case 3:
                printf("\033[34m%d\033[0m ", c); // blue
                break;
            case 4:
                printf("\033[35m%d\033[0m ", c); // magenta
                break;
            case 5:
                printf("\033[36m%d\033[0m ", c); // cyan
                break;
            default:
                printf("%d ", c); // white
                break;
        }
    }

    return 0;
}