//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store weather data
typedef struct {
    double temperature;
    double humidity;
    double wind_speed;
    double pressure;
} WeatherData;

// Function to generate random weather data
WeatherData generate_weather_data() {
    WeatherData weather;
    
    // Generate random temperature between -20 and 50 degrees Celsius
    weather.temperature = -20 + (rand() * 70) / (double)RAND_MAX;
    
    // Generate random humidity between 0 and 100%
    weather.humidity = (rand() * 101) / (double)RAND_MAX;
    
    // Generate random wind speed between 0 and 20 m/s
    weather.wind_speed = (rand() * 21) / (double)RAND_MAX;
    
    // Generate random pressure between 950 and 1050 hPa
    weather.pressure = 950 + (rand() * 101) / (double)RAND_MAX;
    
    return weather;
}

// Function to print weather data
void print_weather_data(WeatherData weather) {
    printf("Temperature: %.1f degrees Celsius\n", weather.temperature);
    printf("Humidity: %.1f%%\n", weather.humidity);
    printf("Wind speed: %.1f m/s\n", weather.wind_speed);
    printf("Pressure: %.1f hPa\n", weather.pressure);
}

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Generate random weather data
    WeatherData weather = generate_weather_data();
    
    // Print weather data
    print_weather_data(weather);
    
    return 0;
}