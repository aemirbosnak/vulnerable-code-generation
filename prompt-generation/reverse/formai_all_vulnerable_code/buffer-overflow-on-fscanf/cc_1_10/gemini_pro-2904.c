//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

#define MAX_DISTANCES 100
#define MAX_STARS 1000

typedef struct {
    double distance;
    int num_stars;
} star_system;

star_system systems[MAX_DISTANCES];

int main() {
    FILE *fp = fopen("star_systems.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int num_systems = 0;
    while (fscanf(fp, "%lf %d", &systems[num_systems].distance, &systems[num_systems].num_stars) != EOF) {
        num_systems++;
    }

    fclose(fp);

    double max_distance = systems[num_systems - 1].distance;

    int num_stars = 0;
    for (int i = 0; i < num_systems; i++) {
        num_stars += systems[i].num_stars;
    }

    double avg_distance = 0.0;
    for (int i = 0; i < num_systems; i++) {
        avg_distance += systems[i].distance * systems[i].num_stars;
    }
    avg_distance /= num_stars;

    double std_dev = 0.0;
    for (int i = 0; i < num_systems; i++) {
        std_dev += pow(systems[i].distance - avg_distance, 2) * systems[i].num_stars;
    }
    std_dev = sqrt(std_dev / num_stars);

    double z_score = (max_distance - avg_distance) / std_dev;

    double probability = 1.0 - erf(z_score / sqrt(2.0));

    printf("Probability of an alien invasion: %.2f%%\n", probability * 100.0);

    return EXIT_SUCCESS;
}