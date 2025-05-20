//MISTRAL-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365
#define MIN_UFO_SIGHTINGS 1
#define MAX_UFO_SIGHTINGS 10

void ufo_sighting(int* ufo_count, int days) {
    int i;
    int rand_num;

    srand(time(NULL));

    for (i = 0; i < days; i++) {
        rand_num = rand() % 11 + 1;
        ufo_count[i] = rand_num > 5 ? 1 : 0;
    }
}

void print_statistics(int* ufo_count, int days) {
    int total_sightings = 0;
    int i;

    printf("\nStatistics for %d days:\n", days);
    printf("--------------------------\n");

    for (i = 0; i < days; i++) {
        printf("Day %d: %s\n", i + 1, ufo_count[i] ? "UFO sighting" : "No UFO sighting");
        total_sightings += ufo_count[i];
    }

    printf("\nTotal UFO sightings: %d\n", total_sightings);
    printf("Average UFO sightings per day: %.2f\n", (float)total_sightings / days);
    printf("Probability of UFO sighting: %.2f%%\n", (float)100.0 * total_sightings / (days * 10.0));
}

int main() {
    int ufo_count[MAX_DAYS];
    int days;

    printf("Enter number of days to monitor: ");
    scanf("%d", &days);

    if (days < 1 || days > MAX_DAYS) {
        printf("Invalid number of days. Exiting...\n");
        return 1;
    }

    ufo_sighting(ufo_count, days);
    print_statistics(ufo_count, days);

    return 0;
}