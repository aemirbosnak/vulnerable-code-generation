//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TERMS 100
#define MAX_DIGITS 100
#define MAX_FIB_NUM 1000000

typedef struct {
    int num;
    int digits;
    int term;
} Term;

int main() {
    srand(time(NULL));

    Term terms[MAX_TERMS];
    int num_terms = 0;

    for (int i = 1; i <= MAX_DIGITS; i++) {
        if (i == 1 || i == 2) {
            continue;
        }

        int num = rand() % MAX_FIB_NUM + 1;
        int digits = 0;
        int term = 0;

        while (num > 0) {
            digits++;
            num /= 10;
        }

        while (num_terms < MAX_TERMS && num < MAX_FIB_NUM) {
            terms[num_terms].num = num;
            terms[num_terms].digits = digits;
            terms[num_terms].term = term;

            num += term;
            term = num - terms[num_terms-1].num;

            num_terms++;
        }
    }

    printf("Fibonacci sequence with %d terms:\n", num_terms);

    for (int i = 0; i < num_terms; i++) {
        printf("%d (%d digits)\n", terms[i].num, terms[i].digits);
    }

    return 0;
}