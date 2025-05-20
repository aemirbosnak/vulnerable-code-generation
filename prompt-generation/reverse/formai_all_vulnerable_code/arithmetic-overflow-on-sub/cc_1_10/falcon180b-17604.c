//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CITIES 5
#define NUM_DAYS 10
#define MAX_TEMP 40
#define MIN_TEMP -10
#define DELTA_TEMP 2

struct City {
    char name[20];
    int temperature;
};

void generateRandomCity(struct City *city) {
    city->temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
}

void printCity(struct City *city) {
    printf("%s: %d degrees Celsius\n", city->name, city->temperature);
}

int main() {
    struct City cities[NUM_CITIES];
    char cityNames[NUM_CITIES][20];
    int i, j;
    time_t currentTime;

    srand(time(NULL));

    // Generate random city names
    for (i = 0; i < NUM_CITIES; i++) {
        sprintf(cityNames[i], "City %d", i + 1);
    }

    // Initialize city temperatures
    for (i = 0; i < NUM_CITIES; i++) {
        generateRandomCity(&cities[i]);
    }

    // Print initial temperatures
    printf("Initial temperatures:\n");
    for (i = 0; i < NUM_CITIES; i++) {
        printCity(&cities[i]);
    }

    // Simulate weather changes over 10 days
    for (j = 0; j < NUM_DAYS; j++) {
        for (i = 0; i < NUM_CITIES; i++) {
            cities[i].temperature += rand() % 3 - 1;
            if (cities[i].temperature < MIN_TEMP) {
                cities[i].temperature = MIN_TEMP;
            } else if (cities[i].temperature > MAX_TEMP) {
                cities[i].temperature = MAX_TEMP;
            }
        }

        // Print daily temperatures
        printf("\nDay %d temperatures:\n", j + 1);
        for (i = 0; i < NUM_CITIES; i++) {
            printCity(&cities[i]);
        }
        printf("\n");

        // Wait for a second before continuing simulation
        currentTime = time(NULL) + j * 86400;
        sleep(currentTime - time(NULL));
    }

    return 0;
}