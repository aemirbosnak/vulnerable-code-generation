//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_ALIENS 1000
#define MAX_NUM_ATTACKS 100

struct alien {
    char name[20];
    int age;
    int strength;
};

struct attack {
    int num_aliens;
    int success;
};

void generate_aliens(struct alien aliens[]) {
    for (int i = 0; i < MAX_NUM_ALIENS; i++) {
        aliens[i].age = rand() % 1000;
        aliens[i].strength = rand() % 100;
        sprintf(aliens[i].name, "Alien %d", i + 1);
    }
}

void simulate_attack(struct alien aliens[], int num_aliens, int strength_threshold, struct attack *attack) {
    int total_strength = 0;
    for (int i = 0; i < num_aliens; i++) {
        total_strength += aliens[i].strength;
    }
    if (total_strength >= strength_threshold) {
        attack->num_aliens = num_aliens;
        attack->success = 1;
    } else {
        attack->num_aliens = num_aliens;
        attack->success = 0;
    }
}

void run_simulation(int num_iterations, int num_aliens, int strength_threshold) {
    struct alien aliens[MAX_NUM_ALIENS];
    generate_aliens(aliens);

    struct attack attacks[MAX_NUM_ATTACKS];
    for (int i = 0; i < num_iterations; i++) {
        int num_aliens_in_attack = rand() % (MAX_NUM_ALIENS - 1) + 1;
        simulate_attack(aliens, num_aliens_in_attack, strength_threshold, &attacks[i]);
    }

    int num_successful_attacks = 0;
    for (int i = 0; i < num_iterations; i++) {
        if (attacks[i].success) {
            num_successful_attacks++;
        }
    }

    double probability_of_invasion = ((double) num_successful_attacks / num_iterations) * 100;
    printf("Probability of alien invasion: %.2f%%\n", probability_of_invasion);
}

int main() {
    int num_iterations, num_aliens, strength_threshold;

    printf("Enter the number of iterations: ");
    scanf("%d", &num_iterations);

    printf("Enter the number of aliens: ");
    scanf("%d", &num_aliens);

    printf("Enter the strength threshold: ");
    scanf("%d", &strength_threshold);

    run_simulation(num_iterations, num_aliens, strength_threshold);

    return 0;
}