//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 40
#define RAIN_CHANCE 30
#define SUN_CHANCE 70
#define CLOUD_CHANCE 60

// Function to print weather conditions
void print_weather(char weather) {
    switch(weather) {
        case 'S':
            printf("The sun is shining!\n");
            break;
        case 'C':
            printf("It is cloudy today.\n");
            break;
        case 'R':
            printf("It is raining cats and dogs!\n");
            break;
        default:
            printf("Unknown weather condition.\n");
    }
}

// Function to generate a random weather condition
char generate_weather() {
    int rand_num = rand() % 100;
    if(rand_num <= RAIN_CHANCE) {
        return 'R';
    } else if(rand_num <= RAIN_CHANCE + SUN_CHANCE) {
        return 'C';
    } else {
        return 'S';
    }
}

// Function to generate a random temperature
int generate_temperature() {
    return rand() % 41 - 20;
}

// Function to generate a random wind speed
int generate_wind_speed() {
    return rand() % 21 - 10;
}

// Function to simulate weather for a given number of days
void simulate_weather(int days) {
    srand(time(NULL));
    for(int i = 0; i < days; i++) {
        char weather = generate_weather();
        int temperature = generate_temperature();
        int wind_speed = generate_wind_speed();
        printf("Day %d:\n", i+1);
        printf("Weather: %c\n", weather);
        printf("Temperature: %d degrees\n", temperature);
        printf("Wind Speed: %d mph\n\n", wind_speed);
        sleep(1);
    }
}

int main() {
    int num_days;
    printf("How many days would you like to simulate the weather for? ");
    scanf("%d", &num_days);
    simulate_weather(num_days);
    return 0;
}