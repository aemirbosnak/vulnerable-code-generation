//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int main() {
    int num_runs, num_invasions, num_attempts, num_successful_attempts;
    double probability;
    char choice;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("This program will calculate the probability of an alien invasion based on the number of attempts made.\n");

    do {
        printf("Enter the number of attempts: ");
        scanf("%d", &num_attempts);
        if (num_attempts <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
        }
    } while (num_attempts <= 0);

    num_successful_attempts = 0;
    num_invasions = 0;
    num_runs = 0;

    while (num_runs < num_attempts) {
        num_runs++;
        if (num_runs % 1000 == 0) {
            printf("\r%d attempts made...", num_runs);
            fflush(stdout);
        }
        if (rand() % 100 == 0) {
            num_successful_attempts++;
            num_invasions++;
        }
    }

    probability = ((double) num_successful_attempts / num_attempts) * 100;

    printf("\n%d attempts made.\n", num_attempts);
    printf("%d successful attempts made.\n", num_successful_attempts);
    printf("%d invasions occurred.\n", num_invasions);
    printf("The probability of an alien invasion is %.2f%%\n", probability);

    printf("\nDo you want to run the simulation again? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        main();
    } else {
        exit(0);
    }

    return 0;
}