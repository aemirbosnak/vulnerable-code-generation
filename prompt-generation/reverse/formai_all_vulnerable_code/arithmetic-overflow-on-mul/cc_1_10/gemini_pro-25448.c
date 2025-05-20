//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef union probability_union {
    double probability;
    struct {
        unsigned int numerator;
        unsigned int denominator;
    } fraction;
} probability;

double get_alien_invasion_probability(double b, int m, int n) {
    double alpha = 0.00001;
    probability q = { .probability = 1.0 };
    probability p = { .fraction = { 1, 1 + floor(log2(m * n)) } };

    for (int i = 0; i < n; i++) {
        probability q_i = { .probability = 1.0 - b };

        for (int j = 0; j <= i; j++) {
            probability p_i_j = { .probability = pow(p.probability, j) };
            q_i.probability *= p_i_j.probability;
        }

        double q_diff = fabs(q_i.probability - q.probability);
        if (q_diff < alpha) {
            return q_i.probability;
        }

        q = q_i;
    }

    return q.probability;
}

int main() {
    double b;
    int m, n;

    printf("Enter the base rate of alien invasion (as a percentage, e.g. 0.001 for 0.1%%): ");
    scanf("%lf", &b);
    printf("Enter the number of possible alien invasion scenarios: ");
    scanf("%d", &m);
    printf("Enter the number of times an alien invasion has occurred in the past: ");
    scanf("%d", &n);

    double probability = get_alien_invasion_probability(b, m, n);
    printf("The probability of an alien invasion is: %.10f\n", probability);

    return 0;
}