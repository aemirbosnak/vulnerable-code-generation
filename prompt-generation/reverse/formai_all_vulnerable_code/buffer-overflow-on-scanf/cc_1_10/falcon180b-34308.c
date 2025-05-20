//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define SUNNY 1
#define RAINY 2
#define CLOUDY 3
#define THUNDERSTORM 4

// Function to print the current weather condition
void print_weather(int weather) {
    switch(weather) {
        case SUNNY:
            printf("The weather is sunny today!\n");
            break;
        case RAINY:
            printf("It's raining outside.\n");
            break;
        case CLOUDY:
            printf("The sky is cloudy today.\n");
            break;
        case THUNDERSTORM:
            printf("There's a thunderstorm brewing!\n");
            break;
        default:
            printf("Invalid weather condition.\n");
            break;
    }
}

// Function to generate a random weather condition
int generate_weather() {
    int weather = rand() % 4;
    return weather;
}

// Function to simulate the weather for a given number of days
void simulate_weather(int days) {
    int i;
    for(i = 0; i < days; i++) {
        int weather = generate_weather();
        print_weather(weather);
    }
}

int main() {
    int num_days;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user to enter the number of days to simulate the weather
    printf("Enter the number of days to simulate the weather: ");
    scanf("%d", &num_days);

    // Simulate the weather for the given number of days
    simulate_weather(num_days);

    return 0;
}