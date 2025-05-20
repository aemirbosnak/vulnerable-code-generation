//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365
#define MAX_TEMP 100

// Function to generate random weather conditions
void generate_weather(int *temp, int *humidity, int *wind_speed, int *cloud_cover) {
    // Generate random temperature between 0 and MAX_TEMP
    *temp = rand() % MAX_TEMP;

    // Generate random humidity between 0 and 100
    *humidity = rand() % 101;

    // Generate random wind speed between 0 and 20
    *wind_speed = rand() % 21;

    // Generate random cloud cover between 0 and 100
    *cloud_cover = rand() % 101;
}

// Function to print weather conditions
void print_weather(int temp, int humidity, int wind_speed, int cloud_cover) {
    printf("Temperature: %d degrees\n", temp);
    printf("Humidity: %d%%\n", humidity);
    printf("Wind Speed: %d mph\n", wind_speed);
    printf("Cloud Cover: %d%%\n\n", cloud_cover);
}

// Function to simulate weather for a given number of days
void simulate_weather(int days) {
    int temp, humidity, wind_speed, cloud_cover;
    int i;

    // Initialize random seed
    srand(time(NULL));

    for (i = 0; i < days; i++) {
        // Generate random weather conditions
        generate_weather(&temp, &humidity, &wind_speed, &cloud_cover);

        // Print weather conditions for the day
        printf("Day %d:\n", i+1);
        print_weather(temp, humidity, wind_speed, cloud_cover);
    }
}

int main() {
    int num_days;

    // Get number of days to simulate from user
    printf("Enter number of days to simulate (max %d): ", MAX_DAYS);
    scanf("%d", &num_days);

    // Simulate weather for the given number of days
    simulate_weather(num_days);

    return 0;
}