//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_FACTOR 10
#define MAX_TRIES 100

int main() {
    srand(time(NULL));

    int num_factors, i, j, k;
    int factors[MAX_FACTOR];
    int num;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter a number to calculate the probability of an alien invasion:\n");
    scanf("%d", &num);

    num_factors = 0;
    for (i = 1; i <= num; i++) {
        if (num % i == 0) {
            factors[num_factors++] = i;
        }
    }

    if (num_factors == 0) {
        printf("The number you entered is not a valid probability.\n");
        return 1;
    }

    int total_factors = 0;
    int max_factor = factors[0];
    for (i = 0; i < num_factors; i++) {
        total_factors += factors[i];
        if (factors[i] > max_factor) {
            max_factor = factors[i];
        }
    }

    int max_tries = MAX_TRIES;
    while (max_tries-- > 0 && total_factors == 0) {
        for (i = 0; i < num_factors; i++) {
            for (j = i + 1; j < num_factors; j++) {
                int factor = factors[i] * factors[j];
                for (k = 0; k < num_factors; k++) {
                    if (k == i || k == j) {
                        continue;
                    }
                    if (factors[k] % factor == 0) {
                        total_factors += factor;
                        break;
                    }
                }
                if (total_factors > 0) {
                    break;
                }
            }
            if (total_factors > 0) {
                break;
            }
        }
        if (total_factors == 0) {
            printf("No valid probability found after %d tries.\n", max_tries + 1);
            return 1;
        }
        max_tries = MAX_TRIES;
    }

    int probability = 0;
    for (i = 0; i < num_factors; i++) {
        probability += (int)pow(factors[i], 2);
    }

    printf("The probability of an alien invasion is %d.\n", probability);

    return 0;
}