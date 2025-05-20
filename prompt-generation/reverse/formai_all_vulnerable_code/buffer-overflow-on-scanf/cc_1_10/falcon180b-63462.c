//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TERMS 100

struct term {
    int coeff;
    int exp;
};

int compare_terms(const void *a, const void *b) {
    struct term *term_a = (struct term *)a;
    struct term *term_b = (struct term *)b;

    if (term_a->exp > term_b->exp) {
        return 1;
    } else if (term_a->exp < term_b->exp) {
        return -1;
    } else {
        return 0;
    }
}

void print_polynomial(struct term *terms, int num_terms) {
    printf("Polynomial: ");
    for (int i = 0; i < num_terms; i++) {
        printf("%d * x^%d ", terms[i].coeff, terms[i].exp);
    }
    printf("\n");
}

int main() {
    int num_terms;
    printf("Enter the number of terms: ");
    scanf("%d", &num_terms);

    struct term *terms = malloc(num_terms * sizeof(struct term));

    printf("Enter the coefficients and exponents of the terms:\n");
    for (int i = 0; i < num_terms; i++) {
        printf("Term %d: ", i+1);
        scanf("%d %d", &terms[i].coeff, &terms[i].exp);
    }

    qsort(terms, num_terms, sizeof(struct term), compare_terms);

    print_polynomial(terms, num_terms);

    free(terms);

    return 0;
}