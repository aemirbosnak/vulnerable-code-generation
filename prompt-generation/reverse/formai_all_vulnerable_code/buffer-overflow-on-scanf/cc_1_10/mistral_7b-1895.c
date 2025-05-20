//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_UFO_SIGHTINGS 10
#define MIN_UFO_SIGHTINGS 1
#define MAX_UFO_SIGHTINGS 10
#define MIN_ALIEN_SHIPS 1
#define MAX_ALIEN_SHIPS 10
#define MIN_ANALYSIS_POINTS 1
#define MAX_ANALYSIS_POINTS 10

// Function prototypes
int get_ufo_sightings(void);
int roll_dice(int sides);
int calculate_invasion_probability(int ufo_sightings, int alien_ships, int analysis_points);

int main() {
    srand(time(NULL));

    int ufo_sightings = get_ufo_sightings();
    int alien_ships = MIN_ALIEN_SHIPS + (rand() % (MAX_ALIEN_SHIPS - MIN_ALIEN_SHIPS + 1));
    int analysis_points = MIN_ANALYSIS_POINTS + (rand() % (MAX_ANALYSIS_POINTS - MIN_ANALYSIS_POINTS + 1));

    printf("UFO sightings: %d\n", ufo_sightings);
    printf("Alien ships: %d\n", alien_ships);
    printf("Analysis points: %d\n", analysis_points);

    int probability = calculate_invasion_probability(ufo_sightings, alien_ships, analysis_points);

    printf("Alien invasion probability: %d%%\n", probability);

    return 0;
}

int get_ufo_sightings() {
    int input = 0;

    while (input < MIN_UFO_SIGHTINGS || input > MAX_UFO_SIGHTINGS) {
        printf("Enter the number of UFO sightings between %d and %d: ", MIN_UFO_SIGHTINGS, MAX_UFO_SIGHTINGS);
        scanf("%d", &input);
    }

    return input;
}

int roll_dice(int sides) {
    return rand() % sides + 1;
}

int calculate_invasion_probability(int ufo_sightings, int alien_ships, int analysis_points) {
    int invasion_points = ufo_sightings + analysis_points;

    int probability = (invasion_points * 100) / (invasion_points + alien_ships);

    return probability;
}