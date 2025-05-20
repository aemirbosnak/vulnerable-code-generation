//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 80

// Function to print the weather conditions
void print_weather(int weather_type, int temperature) {
    if (weather_type == 1) {
        printf("The weather is sunny with a temperature of %d degrees Celsius.\n", temperature);
    } else if (weather_type == 2) {
        printf("The weather is cloudy with a temperature of %d degrees Celsius.\n", temperature);
    } else {
        printf("The weather is rainy with a temperature of %d degrees Celsius.\n", temperature);
    }
}

// Function to simulate the weather conditions
void simulate_weather(int temperature, int humidity, int wind_speed) {
    int weather_type = rand() % 3;

    if (temperature >= 25 && humidity >= 80 && wind_speed >= 15) {
        weather_type = 2;
    } else if (temperature >= 30 && humidity >= 90 && wind_speed >= 20) {
        weather_type = 3;
    }

    print_weather(weather_type, temperature);
}

// Function to generate random weather conditions
void generate_weather() {
    int temperature = rand() % 41 + 10;
    int humidity = rand() % 91;
    int wind_speed = rand() % 21 + 1;

    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d km/h\n", wind_speed);

    simulate_weather(temperature, humidity, wind_speed);
}

int main() {
    srand(time(0));

    int choice;
    do {
        printf("Press 1 to generate weather conditions\n");
        printf("Press 0 to exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            generate_weather();
        }
    } while (choice == 1);

    return 0;
}