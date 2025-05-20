//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_ALIENS 1000
#define MAX_NUM_CITIES 100
#define MAX_NUM_DEFENSES 100
#define MAX_NUM_INVASIONS 1000

struct alien {
    int num_aliens;
    int invasion_probability;
};

struct city {
    int num_defenses;
    int invasion_probability;
};

void generate_aliens(struct alien aliens[], int num_aliens) {
    srand(time(NULL));
    for (int i = 0; i < num_aliens; i++) {
        aliens[i].num_aliens = rand() % MAX_NUM_ALIENS + 1;
        aliens[i].invasion_probability = rand() % 101;
    }
}

void generate_cities(struct city cities[], int num_cities) {
    srand(time(NULL));
    for (int i = 0; i < num_cities; i++) {
        cities[i].num_defenses = rand() % MAX_NUM_DEFENSES + 1;
        cities[i].invasion_probability = rand() % 101;
    }
}

int calculate_invasion_probability(struct alien aliens[], struct city cities[], int num_aliens, int num_cities) {
    int total_invasion_probability = 0;
    for (int i = 0; i < num_aliens; i++) {
        for (int j = 0; j < num_cities; j++) {
            total_invasion_probability += aliens[i].invasion_probability * cities[j].invasion_probability;
        }
    }
    return total_invasion_probability;
}

int main() {
    int num_aliens, num_cities, num_defenses, num_invasions;
    printf("Enter the number of aliens: ");
    scanf("%d", &num_aliens);
    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);
    printf("Enter the number of defenses: ");
    scanf("%d", &num_defenses);
    printf("Enter the number of invasions: ");
    scanf("%d", &num_invasions);
    struct alien aliens[MAX_NUM_ALIENS];
    struct city cities[MAX_NUM_CITIES];
    generate_aliens(aliens, num_aliens);
    generate_cities(cities, num_cities);
    int total_invasion_probability = calculate_invasion_probability(aliens, cities, num_aliens, num_cities);
    printf("The total invasion probability is: %d\n", total_invasion_probability);
    return 0;
}