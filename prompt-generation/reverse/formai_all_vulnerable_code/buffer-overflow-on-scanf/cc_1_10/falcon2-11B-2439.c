//Falcon2-11B DATASET v1.0 Category: Weather simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to calculate temperature based on latitude and longitude
float calculateTemperature(float latitude, float longitude) {
    float sinLatitude = sin(latitude * M_PI / 180);
    float cosLatitude = cos(latitude * M_PI / 180);
    float sinLongitude = sin(longitude * M_PI / 180);
    float cosLongitude = cos(longitude * M_PI / 180);

    float temperature = (sinLatitude * sinLatitude + cosLatitude * cosLongitude * cosLatitude) / (sinLongitude * sinLongitude + cosLatitude * cosLongitude * cosLatitude);
    return temperature;
}

// Function to calculate wind speed based on latitude and longitude
float calculateWindSpeed(float latitude, float longitude) {
    float sinLatitude = sin(latitude * M_PI / 180);
    float cosLatitude = cos(latitude * M_PI / 180);
    float sinLongitude = sin(longitude * M_PI / 180);
    float cosLongitude = cos(longitude * M_PI / 180);

    float windSpeed = sqrt(sinLatitude * sinLatitude + cosLatitude * cosLongitude * cosLatitude * cosLongitude);
    return windSpeed;
}

// Function to simulate random noise in temperature and wind speed
float simulateNoise(float noiseFactor) {
    float randomNumber = (float)rand() / RAND_MAX;
    return noiseFactor * randomNumber;
}

// Main function
int main() {
    // Set up random seed for reproducibility
    srand(time(NULL));

    // Read latitude and longitude from user
    printf("Enter latitude: ");
    float latitude = atof(scanf("%f", &latitude));
    printf("Enter longitude: ");
    float longitude = atof(scanf("%f", &longitude));

    // Calculate temperature and wind speed
    float temperature = calculateTemperature(latitude, longitude);
    float windSpeed = calculateWindSpeed(latitude, longitude);

    // Add random noise to temperature and wind speed
    float temperatureNoise = simulateNoise(0.1);
    float windSpeedNoise = simulateNoise(0.2);

    // Print the weather simulation
    printf("Temperature: %.2f degrees Celsius\n", temperature + temperatureNoise);
    printf("Wind Speed: %.2f meters per second\n", windSpeed + windSpeedNoise);

    return 0;
}