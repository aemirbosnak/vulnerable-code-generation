//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 80

// Function prototypes
void init_weather(int weather_type);
void display_weather(int weather_type, int temperature);

int main() {
    int weather_type;
    int temperature;
    int choice;

    srand(time(NULL));
    weather_type = rand() % 4; // Randomly choose a weather type
    temperature = rand() % 41 + 10; // Randomly choose a temperature between 10 and 50 degrees Celsius

    init_weather(weather_type);

    while (1) {
        system("clear");
        printf("Current weather: ");
        display_weather(weather_type, temperature);

        printf("\nPress 1 to continue or any other key to exit.\n");
        scanf("%d", &choice);

        if (choice!= 1) {
            break;
        }

        weather_type = rand() % 4; // Randomly choose a new weather type
        temperature = rand() % 41 + 10; // Randomly choose a new temperature between 10 and 50 degrees Celsius
        init_weather(weather_type);
    }

    return 0;
}

void init_weather(int weather_type) {
    switch (weather_type) {
        case 0:
            printf("Initializing sunny weather...\n");
            break;
        case 1:
            printf("Initializing rainy weather...\n");
            break;
        case 2:
            printf("Initializing cloudy weather...\n");
            break;
        case 3:
            printf("Initializing stormy weather...\n");
            break;
    }
}

void display_weather(int weather_type, int temperature) {
    switch (weather_type) {
        case 0:
            printf("Current weather: Sunny, %d degrees Celsius\n", temperature);
            break;
        case 1:
            printf("Current weather: Rainy, %d degrees Celsius\n", temperature);
            break;
        case 2:
            printf("Current weather: Cloudy, %d degrees Celsius\n", temperature);
            break;
        case 3:
            printf("Current weather: Stormy, %d degrees Celsius\n", temperature);
            break;
    }
}