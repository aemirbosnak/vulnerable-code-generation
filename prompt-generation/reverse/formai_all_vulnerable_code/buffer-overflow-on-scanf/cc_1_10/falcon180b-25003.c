//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for weather conditions
#define SUNNY 0
#define CLOUDY 1
#define RAINY 2
#define THUNDERSTORM 3
#define SNOWY 4

// Define function prototypes
void generate_weather(int* weather_condition);
void print_weather(int weather_condition);

int main() {
    int weather_condition;
    int user_choice;

    srand(time(NULL));

    // Initialize weather condition to sunny
    weather_condition = SUNNY;

    // Simulate weather for 7 days
    for (int i = 0; i < 7; i++) {
        generate_weather(&weather_condition);
        print_weather(weather_condition);

        // Ask user if they want to continue simulation
        printf("Do you want to continue the simulation? (y/n)\n");
        scanf(" %c", &user_choice);

        // If user chooses to stop, break out of loop
        if (user_choice == 'n' || user_choice == 'N') {
            break;
        }
    }

    return 0;
}

// Function to generate random weather condition
void generate_weather(int* weather_condition) {
    int random_number = rand() % 5;

    // Update weather condition based on random number generated
    switch (random_number) {
        case 0:
            *weather_condition = SUNNY;
            break;
        case 1:
            *weather_condition = CLOUDY;
            break;
        case 2:
            *weather_condition = RAINY;
            break;
        case 3:
            *weather_condition = THUNDERSTORM;
            break;
        case 4:
            *weather_condition = SNOWY;
            break;
    }
}

// Function to print weather condition
void print_weather(int weather_condition) {
    switch (weather_condition) {
        case SUNNY:
            printf("The weather is sunny today.\n");
            break;
        case CLOUDY:
            printf("The weather is cloudy today.\n");
            break;
        case RAINY:
            printf("The weather is rainy today.\n");
            break;
        case THUNDERSTORM:
            printf("The weather is thunderstorm today.\n");
            break;
        case SNOWY:
            printf("The weather is snowy today.\n");
            break;
    }
}