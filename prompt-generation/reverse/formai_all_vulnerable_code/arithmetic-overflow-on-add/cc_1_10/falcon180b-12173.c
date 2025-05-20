//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_INVASIONS 1000
#define INVASION_THRESHOLD 50

struct city {
    char name[50];
    int population;
    int invasion_count;
};

void generate_cities(struct city cities[], int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        cities[i].population = rand() % 1000000;
        cities[i].invasion_count = 0;
        sprintf(cities[i].name, "City %d", i + 1);
    }
}

int check_invasion(struct city cities[], int num_cities, int city_index) {
    if (cities[city_index].invasion_count >= INVASION_THRESHOLD) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));

    int num_cities;
    printf("Enter the number of cities to simulate (up to %d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    struct city cities[num_cities];
    generate_cities(cities, num_cities);

    int num_invasions = 0;
    while (num_invasions < MAX_INVASIONS) {
        int city_index = rand() % num_cities;
        if (check_invasion(cities, num_cities, city_index)) {
            cities[city_index].invasion_count++;
            num_invasions++;
        }
    }

    int total_population = 0;
    int invaded_population = 0;
    for (int i = 0; i < num_cities; i++) {
        total_population += cities[i].population;
        if (cities[i].invasion_count > 0) {
            invaded_population += cities[i].population;
        }
    }

    double invasion_probability = (double)invaded_population / total_population;
    printf("The probability of an alien invasion is %.2f%%\n", invasion_probability * 100);

    return 0;
}