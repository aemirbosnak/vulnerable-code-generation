//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

/* Function to generate a random number */
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

/* Function to simulate an alien invasion */
void alien_invasion(int num_aliens, int num_people, int num_rounds) {
    int i, j, k;
    int aliens_remaining = num_aliens;
    int people_remaining = num_people;

    /* Simulate each round of the invasion */
    for (i = 0; i < num_rounds; i++) {
        printf("Round %d:\n", i+1);

        /* Determine the number of aliens and people that survive */
        for (j = 0; j < aliens_remaining; j++) {
            for (k = 0; k < people_remaining; k++) {
                if (rand_num(0, 1) == 1) { /* Alien wins */
                    printf("Alien %d defeats person %d.\n", j+1, k+1);
                    people_remaining--;
                } else { /* Person wins */
                    printf("Person %d defeats alien %d.\n", k+1, j+1);
                    aliens_remaining--;
                }
            }
        }
    }
}

/* Function to calculate the probability of an alien invasion */
int calc_probability(int num_aliens, int num_people, int num_rounds) {
    int wins = 0;
    int total_rounds = num_rounds * num_aliens * num_people;

    /* Simulate the invasion and count the number of wins */
    while (num_people > 0 && num_aliens > 0) {
        alien_invasion(num_aliens, num_people, num_rounds);
        if (num_people > 0) {
            wins++;
        }
    }

    /* Calculate the probability */
    return (int) ((float) wins / total_rounds * 100);
}

int main() {
    int num_aliens, num_people, num_rounds;

    /* Prompt the user for input */
    printf("Enter the number of aliens: ");
    scanf("%d", &num_aliens);

    printf("Enter the number of people: ");
    scanf("%d", &num_people);

    printf("Enter the number of rounds: ");
    scanf("%d", &num_rounds);

    /* Calculate and print the probability */
    int probability = calc_probability(num_aliens, num_people, num_rounds);
    printf("The probability of an alien invasion is %d%%.\n", probability);

    return 0;
}