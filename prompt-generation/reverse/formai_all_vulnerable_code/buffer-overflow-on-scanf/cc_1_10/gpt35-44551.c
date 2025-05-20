//FormAI DATASET v1.0 Category: Weather simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct CityWeather {
    char cityName[20];
    int temperature;
    char weatherType[10];
};

void updateWeather(struct CityWeather *city) {
    // Generate a random temperature between -10 and 40 degrees Celsius
    int randomTemp = rand() % 51 - 10;
    city -> temperature = randomTemp;
    
    // Generate a random weather type based on the temperature
    if (randomTemp < 0) {
        sprintf(city -> weatherType, "%s", "Snow");
    } else if (randomTemp < 15) {
        sprintf(city -> weatherType, "%s", "Rain");
    } else {
        sprintf(city -> weatherType, "%s", "Sunny");
    }
}

int main() {
    struct CityWeather cities[5];
    char cityNames[5][20] = {"New York", "Los Angeles", "London", "Paris", "Sydney"};
    
    // Initialize the CityWeather struct for each city
    for (int i = 0; i < 5; i++) {
        sprintf(cities[i].cityName, "%s", cityNames[i]);
        updateWeather(&cities[i]);
    }
    
    int days;
    printf("Enter the number of days for which you want to simulate the weather (maximum 10): ");
    scanf("%d", &days);
    
    // Simulate the weather for the desired number of days
    for (int i = 1; i <= days; i++) {
        printf("Day %d:\n", i);
        for (int j = 0; j < 5; j++) {
            printf("%s - Temperature: %d°C, Weather: %s\n", cities[j].cityName, cities[j].temperature, cities[j].weatherType);
            updateWeather(&cities[j]);
        }
        printf("\n");
    }
    
    return 0;
}