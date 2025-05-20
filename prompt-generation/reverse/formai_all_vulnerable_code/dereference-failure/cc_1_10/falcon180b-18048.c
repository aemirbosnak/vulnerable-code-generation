//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_TERMS 100
#define MAX_DIGITS 1000
#define MAX_COLOR_CODE_LENGTH 7

char *color_codes[] = {
    "\033[0m", // reset
    "\033[1m", // bold
    "\033[4m", // underline
    "\033[7m", // reverse
    "\033[31m", // red
    "\033[32m", // green
    "\033[33m", // yellow
    "\033[34m", // blue
    "\033[35m", // magenta
    "\033[36m", // cyan
};

void print_color(int term_index, int color_code_index) {
    printf("%s%d ", color_codes[color_code_index], term_index);
}

void visualize_fibonacci(int num_terms) {
    int i, j, term_index = 0;
    int prev_term = 0, curr_term = 1;
    int *fibonacci_numbers = (int *) malloc((num_terms + 1) * sizeof(int));
    fibonacci_numbers[0] = 0;
    fibonacci_numbers[1] = 1;

    for (i = 2; i <= num_terms; i++) {
        fibonacci_numbers[i] = prev_term + curr_term;
        curr_term = prev_term;
        prev_term = curr_term - prev_term;
    }

    printf("Visualizing Fibonacci sequence with %d terms:\n", num_terms);

    for (i = 0; i <= num_terms; i++) {
        if (i == num_terms || i == 0) {
            print_color(i, 0);
            printf("%d ", fibonacci_numbers[i]);
        } else {
            print_color(i, rand() % MAX_COLOR_CODE_LENGTH);
            printf("%d ", fibonacci_numbers[i]);
        }
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    int num_terms;

    srand(time(NULL));

    printf("Enter the number of terms to visualize: ");
    scanf("%d", &num_terms);

    if (num_terms <= 0 || num_terms > MAX_TERMS) {
        printf("Invalid number of terms.\n");
        return 1;
    }

    visualize_fibonacci(num_terms);

    return 0;
}