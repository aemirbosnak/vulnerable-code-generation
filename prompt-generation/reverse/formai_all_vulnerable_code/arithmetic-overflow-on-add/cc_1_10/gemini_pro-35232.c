//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Weather data structure
typedef struct {
    double temperature;
    double humidity;
    double pressure;
    double wind_speed;
    double wind_direction;
} WeatherData;

// Thread arguments structure
typedef struct {
    int thread_id;
    WeatherData *weather_data;
} ThreadArgs;

// Thread function
void *weather_thread(void *args) {
    // Get the thread arguments
    ThreadArgs *thread_args = (ThreadArgs *)args;

    // Initialize the random number generator
    srand(time(NULL) + thread_args->thread_id);

    // Generate random weather data
    thread_args->weather_data->temperature = (rand() % 100) / 10.0;
    thread_args->weather_data->humidity = (rand() % 100) / 100.0;
    thread_args->weather_data->pressure = (rand() % 1000) / 10.0;
    thread_args->weather_data->wind_speed = (rand() % 100) / 10.0;
    thread_args->weather_data->wind_direction = (rand() % 360);

    // Sleep for a random amount of time
    sleep(rand() % 10);

    // Return the thread arguments
    return thread_args;
}

// Main function
int main() {
    // Create the weather data structure
    WeatherData weather_data;

    // Create the thread arguments structure
    ThreadArgs thread_args;
    thread_args.weather_data = &weather_data;

    // Create the thread
    pthread_t thread;
    pthread_create(&thread, NULL, weather_thread, &thread_args);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    // Print the weather data
    printf("Temperature: %.1f degrees Celsius\n", weather_data.temperature);
    printf("Humidity: %.1f%%\n", weather_data.humidity * 100);
    printf("Pressure: %.1f millibars\n", weather_data.pressure);
    printf("Wind speed: %.1f meters per second\n", weather_data.wind_speed);
    printf("Wind direction: %.1f degrees\n", weather_data.wind_direction);

    return 0;
}