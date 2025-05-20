//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 100
#define MAX_FACTOR 100

int main() {
    srand(time(NULL));

    int num_tries;
    int num_factors;
    int factors[MAX_FACTOR];
    int num_found = 0;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("This program will determine the probability of an alien invasion based on the number of factors of a given number.\n");
    printf("Please enter the number of tries you want to perform (between 1 and %d): ", MAX_TRIES);
    scanf("%d", &num_tries);

    for (int i = 0; i < num_tries; i++) {
        printf("Trial %d:\n", i + 1);
        printf("Please enter a positive integer (between 1 and %d): ", MAX_FACTOR);
        scanf("%d", &num_factors);

        int num = rand() % MAX_FACTOR + 1;
        int count = 0;

        for (int j = 1; j <= num; j++) {
            if (num % j == 0) {
                count++;
            }
        }

        if (count == num_factors) {
            printf("Congratulations! You found a number with %d factors!\n", num_factors);
            num_found++;
        } else {
            printf("Sorry, you only found %d factors.\n", count);
        }

        printf("\n");
    }

    if (num_found == num_tries) {
        printf("You are an expert in finding numbers with a specific number of factors! Congratulations!\n");
    } else {
        printf("You found %d numbers with the required number of factors out of %d tries.\n", num_found, num_tries);
    }

    return 0;
}