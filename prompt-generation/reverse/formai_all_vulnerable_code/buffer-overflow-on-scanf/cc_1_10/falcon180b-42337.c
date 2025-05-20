//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_ALIENS 1000
#define MAX_YEARS 1000
#define MIN_YEARS_TO_INVASION 10
#define MAX_YEARS_TO_INVASION 50
#define PROBABILITY_OF_INVASION 0.1
#define PROBABILITY_OF_DETECTION 0.5
#define PROBABILITY_OF_DESTRUCTION 0.9

struct alien {
    int id;
    int year_of_invasion;
    int detected;
    int destroyed;
};

void generate_aliens(struct alien aliens[], int num_aliens) {
    srand(time(NULL));
    for (int i = 0; i < num_aliens; i++) {
        aliens[i].id = i + 1;
        aliens[i].year_of_invasion = rand() % MAX_YEARS + MIN_YEARS_TO_INVASION;
        aliens[i].detected = 0;
        aliens[i].destroyed = 0;
    }
}

void simulate_invasion(struct alien aliens[], int num_aliens, int num_years) {
    for (int year = 0; year < num_years; year++) {
        for (int i = 0; i < num_aliens; i++) {
            if (!aliens[i].destroyed && aliens[i].year_of_invasion == year) {
                if (rand() % 2 == 0) {
                    printf("Alien %d detected in year %d\n", aliens[i].id, year);
                    aliens[i].detected = 1;
                } else {
                    printf("Alien %d invades undetected in year %d\n", aliens[i].id, year);
                }
            }
        }
        for (int i = 0; i < num_aliens; i++) {
            if (!aliens[i].destroyed && aliens[i].year_of_invasion < year) {
                if (!aliens[i].detected) {
                    printf("Alien %d destroyed in year %d\n", aliens[i].id, year);
                    aliens[i].destroyed = 1;
                }
            }
        }
    }
}

int main() {
    struct alien aliens[MAX_ALIENS];
    int num_aliens;
    printf("Enter the number of aliens (1 to %d): ", MAX_ALIENS);
    scanf("%d", &num_aliens);
    generate_aliens(aliens, num_aliens);
    int num_years;
    printf("Enter the number of years to simulate (1 to %d): ", MAX_YEARS);
    scanf("%d", &num_years);
    simulate_invasion(aliens, num_aliens, num_years);
    return 0;
}