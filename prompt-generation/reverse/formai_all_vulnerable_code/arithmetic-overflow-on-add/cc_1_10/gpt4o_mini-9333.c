//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_REGIONS 5
#define SIMULATION_DURATION 20

typedef struct {
    int region_id;
    char condition[20];
} WeatherData;

void *simulate_weather(void *arg) {
    WeatherData *data = (WeatherData *)arg;
    const char *weather_conditions[] = {
        "Sunny", "Cloudy", "Rainy", "Stormy", "Snowy", "Windy"
    };
    
    int condition_index;
    srand(time(NULL) + data->region_id); // Seed with different values
    
    for (int i = 0; i < SIMULATION_DURATION; i++) {
        condition_index = rand() % 6; // Get a random weather condition
        snprintf(data->condition, sizeof(data->condition), "%s", weather_conditions[condition_index]);
        
        printf("Region %d: Weather is now %s\n", data->region_id, data->condition);
        
        // Sleep for 1 second to simulate time passing
        sleep(1);
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_REGIONS];
    WeatherData weather_data[NUM_REGIONS];

    // Create threads for each region
    for (int i = 0; i < NUM_REGIONS; i++) {
        weather_data[i].region_id = i + 1; // Region ID starts from 1
        pthread_create(&threads[i], NULL, simulate_weather, (void *)&weather_data[i]);
    }

    // Join all threads
    for (int i = 0; i < NUM_REGIONS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Weather simulation completed for all regions.\n");
    return 0;
}