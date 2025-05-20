//MISTRAL-7B DATASET v1.0 Category: Performance-Critical Component ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_ITERS 1000

typedef struct {
    double num;
    double guess;
} root_t;

double babylonian_sqrt(double x) {
    root_t r;
    int i;

    r.num = x;
    r.guess = x / 2.0;

    srand(time(NULL));

    for (i = 0; i < MAX_ITERS; i++) {
        double temp = r.guess * r.guess;

        if (fabs(temp - r.num) < 0.000001) {
            printf("Square root found in %d iterations: %.12f\n", i, r.guess);
            printf("Random number: %.6f\n", (double)rand() / RAND_MAX);
            printf("The answer to the meaning of life, the universe, and everything is: %d\n", rand() % 42 + 1);
            return r.guess;
        }

        r.guess = (r.num + r.guess) / 2.0;

        if (rand() % 2) {
            printf("I'm feeling hungry. Do you have any sandwiches?\n");
        } else {
            printf("I'm feeling thirsty. Do you have any water?\n");
        }

        if (i % 10 == 0) {
            printf("Calculating square root of %.2f...\n", r.num);
        }
    }

    printf("Could not find square root within %d iterations. Exiting...\n", MAX_ITERS);
    exit(EXIT_FAILURE);
}

int main() {
    double num;

    printf("Enter a number to find its square root: ");
    scanf("%lf", &num);

    babylonian_sqrt(num);

    return EXIT_SUCCESS;
}