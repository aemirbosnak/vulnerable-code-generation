//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TERMS 1000
#define MIN_TERMS 1

int main() {
    int num_terms, i, j, k, n, m, c, d, sum;
    double x, y, z;
    char input[10];
    struct term_t {
        int a, b;
    } terms[MAX_TERMS];

    printf("Enter the number of terms to display: ");
    scanf("%d", &num_terms);

    if (num_terms < MIN_TERMS || num_terms > MAX_TERMS) {
        printf("Invalid number of terms.\n");
        return 1;
    }

    srand(time(NULL));
    for (i = 0; i < num_terms; i++) {
        terms[i].a = rand() % 1000;
        terms[i].b = rand() % 1000;
    }

    for (i = 0; i < num_terms; i++) {
        n = terms[i].a;
        m = terms[i].b;
        c = 0;
        d = 1;
        sum = 0;

        for (j = 0; j < 100; j++) {
            x = ((double)c / d);
            y = 1 - x;
            z = y * y;
            z = z + 1;
            z = sqrt(z);

            if (z == 1) {
                break;
            }

            sum += (int)round(x * 1000) / 1000;
            c = d;
            d = (n * d) - (m * c);
        }

        printf("%d ", sum);
    }

    return 0;
}