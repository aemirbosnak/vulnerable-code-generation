//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_ALIENS 1000000
#define MAX_PROBABILITY 100

typedef struct Alien {
    int id;
    double probability;
} Alien;

void generate_aliens(Alien *aliens, int number_of_aliens) {
    int i;
    for (i = 0; i < number_of_aliens; i++) {
        aliens[i].id = i + 1;
        aliens[i].probability = (double) rand() / RAND_MAX;
    }
}

void sort_aliens(Alien *aliens, int number_of_aliens) {
    int i, j, temp_id, temp_probability;
    Alien temp;
    for (i = 0; i < number_of_aliens - 1; i++) {
        for (j = 0; j < number_of_aliens - i - 1; j++) {
            if (aliens[j].probability > aliens[j + 1].probability) {
                temp_id = aliens[j].id;
                temp_probability = aliens[j].probability;
                aliens[j].id = aliens[j + 1].id;
                aliens[j].probability = aliens[j + 1].probability;
                aliens[j + 1].id = temp_id;
                aliens[j + 1].probability = temp_probability;
            }
        }
    }
}

void print_aliens(Alien *aliens, int number_of_aliens) {
    int i;
    printf("Alien Invasion Probability Calculator\n");
    printf("------------------------------------\n");
    printf("ID\tProbability\n");
    for (i = 0; i < number_of_aliens; i++) {
        printf("%d\t%.2f\n", aliens[i].id, aliens[i].probability);
    }
}

void main() {
    Alien *aliens;
    int number_of_aliens, i;

    srand(time(NULL));

    printf("Enter the number of aliens: ");
    scanf("%d", &number_of_aliens);

    aliens = (Alien *) malloc(number_of_aliens * sizeof(Alien));

    generate_aliens(aliens, number_of_aliens);

    printf("Before sorting:\n");
    print_aliens(aliens, number_of_aliens);

    sort_aliens(aliens, number_of_aliens);

    printf("After sorting:\n");
    print_aliens(aliens, number_of_aliens);

    double invasion_probability = 0.0;
    for (i = 0; i < number_of_aliens && invasion_probability < MAX_PROBABILITY; i++) {
        invasion_probability += aliens[i].probability;
    }

    if (invasion_probability >= MAX_PROBABILITY) {
        printf("Alien invasion probability: %.2f\n", invasion_probability);
        printf("Invasion imminent!\n");
    } else {
        printf("Alien invasion probability: %.2f\n", invasion_probability);
        printf("No invasion detected.\n");
    }

    free(aliens);
}