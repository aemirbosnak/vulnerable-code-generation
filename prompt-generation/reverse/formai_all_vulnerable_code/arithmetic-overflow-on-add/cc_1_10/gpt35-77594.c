//FormAI DATASET v1.0 Category: Weather simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define DELAY 1000

typedef struct {
    char name[20];
    int temperature;
} City;

void update_weather(City cities[]) {
    int i;
    for (i=0; i<MAX_CITIES; i++) {
        cities[i].temperature += (rand() % 5) - 2;
        if (cities[i].temperature < -10) cities[i].temperature = -10;
        if (cities[i].temperature > 40) cities[i].temperature = 40;
    }
}

void show_weather(City cities[]) {
    int i;
    for (i=0; i<MAX_CITIES; i++) {
        printf("%s: %dC\n", cities[i].name, cities[i].temperature);
    }
}

void simulate_weather(City cities[], int seconds) {
    time_t start = time(NULL);
    while (time(NULL) < start + seconds) {
        update_weather(cities);
        show_weather(cities);
        printf("\n");
        usleep(DELAY * 1000);
    }
}

int main() {
    srand(time(NULL));
    
    City cities[MAX_CITIES] = {
        {"Tokyo", 23}, {"New York", 13}, {"London", 8}, {"Sydney", 20},
        {"Paris", 11}, {"Los Angeles", 20}, {"Beijing", 14}, {"Moscow", -4},
        {"Cairo", 30}, {"Toronto", 2}
    };

    printf("Starting weather simulation...\n\n");
    simulate_weather(cities, 30);
    printf("Simulation ended.\n");
    
    return 0;
}