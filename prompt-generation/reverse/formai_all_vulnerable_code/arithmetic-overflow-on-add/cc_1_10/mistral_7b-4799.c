//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ALIENS 10
#define NUM_PROBABILITIES 5

typedef struct {
    int id;
    double probability;
} Alien;

Alien aliens[NUM_ALIENS];

void initialize_aliens() {
    srand(time(NULL));
    for (int i = 0; i < NUM_ALIENS; i++) {
        aliens[i].id = i + 1;
        aliens[i].probability = (double) rand() / RAND_MAX;
    }
}

void print_aliens() {
    printf("Aliens and their probabilities:\n");
    for (int i = 0; i < NUM_ALIENS; i++) {
        printf("%d: %.2f\n", aliens[i].id, aliens[i].probability);
    }
}

void find_most_probable_alien(Alien *aliens, int num_aliens, int *most_probable_alien_id) {
    double max_probability = 0.0;
    for (int i = 0; i < num_aliens; i++) {
        if (aliens[i].probability > max_probability) {
            max_probability = aliens[i].probability;
            *most_probable_alien_id = i;
        }
    }
}

int main() {
    Alien aliens[NUM_ALIENS];
    int most_probable_alien_id;

    initialize_aliens();

    print_aliens();

    find_most_probable_alien(aliens, NUM_ALIENS, &most_probable_alien_id);

    printf("The most probable alien is #%d with a probability of %.2f\n", most_probable_alien_id + 1, aliens[most_probable_alien_id].probability);

    return 0;
}