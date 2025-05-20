//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define TEMP_MIN -20
#define TEMP_MAX 50
#define HUMID_MIN 0
#define HUMID_MAX 100

// Define the weather data structure
typedef struct {
    int temperature;
    int humidity;
} WeatherData;

// Function to generate random weather data
WeatherData generateWeatherData() {
    WeatherData data;
    data.temperature = rand() % (TEMP_MAX - TEMP_MIN + 1) + TEMP_MIN;
    data.humidity = rand() % (HUMID_MAX - HUMID_MIN + 1) + HUMID_MIN;
    return data;
}

// Function to print the weather data
void printWeatherData(WeatherData data) {
    printf("Temperature: %d\n", data.temperature);
    printf("Humidity: %d\n", data.humidity);
}

// Function to simulate the weather
void simulateWeather(int duration) {
    srand(time(NULL));
    int i;
    for(i = 0; i < duration; i++) {
        WeatherData data = generateWeatherData();
        printWeatherData(data);
        printf("\n");
        usleep(1000000); // Sleep for 1 second
    }
}

int main() {
    int duration;
    printf("Enter the duration of the weather simulation (in seconds): ");
    scanf("%d", &duration);
    simulateWeather(duration);
    return 0;
}