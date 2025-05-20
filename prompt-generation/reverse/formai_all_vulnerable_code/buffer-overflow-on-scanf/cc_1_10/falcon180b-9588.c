//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIALS 1000000
#define MAX_ALIENS 100
#define MIN_DISTANCE 0.1
#define MAX_DISTANCE 1000

int num_trials = 0;
int num_successful_invasions = 0;
double min_distance = MIN_DISTANCE;
double max_distance = MAX_DISTANCE;

int main() {
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of trials you would like to run:\n");
    scanf("%d", &num_trials);

    printf("Calculating alien invasion probability...\n");
    for (int i = 0; i < num_trials; i++) {
        int num_aliens = rand() % MAX_ALIENS + 1;
        double distance = rand() % (int)(max_distance - min_distance + 1) + min_distance;
        if (simulate_invasion(num_aliens, distance)) {
            num_successful_invasions++;
        }
    }

    printf("The probability of an alien invasion occurring within the next %d trials is %.2f%%\n",
           num_trials, (double)num_successful_invasions / num_trials * 100);

    return 0;
}

int simulate_invasion(int num_aliens, double distance) {
    if (num_aliens == 1) {
        printf("There is only one alien. It does not pose a threat.\n");
        return 0;
    }

    if (distance <= 0) {
        printf("The aliens are already here! Invasion successful!\n");
        return 1;
    }

    int num_successful_attacks = 0;
    for (int j = 0; j < num_aliens; j++) {
        if (simulate_attack(distance)) {
            num_successful_attacks++;
        }
    }

    if (num_successful_attacks >= num_aliens / 2) {
        printf("The aliens have successfully invaded!\n");
        return 1;
    } else {
        printf("The invasion was repelled.\n");
        return 0;
    }
}

int simulate_attack(double distance) {
    if (distance <= MIN_DISTANCE) {
        printf("The aliens have successfully attacked!\n");
        return 1;
    } else if (distance >= MAX_DISTANCE) {
        printf("The aliens are too far away to attack.\n");
        return 0;
    } else {
        int attack_strength = rand() % 100 + 1;
        if (attack_strength >= distance) {
            printf("The aliens have successfully attacked!\n");
            return 1;
        } else {
            printf("The attack was repelled.\n");
            return 0;
        }
    }
}