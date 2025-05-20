//GPT-4o-mini DATASET v1.0 Category: Weather simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LOCATIONS 10
#define MAX_WEATHER_TYPES 5

typedef struct Weather {
    char type[30];
    float temperature; // in degrees Celsius
    float humidity; // percentage
    float windSpeed; // in km/h
} Weather;

typedef struct Location {
    char name[50];
    Weather currentWeather;
} Location;

void initializeWeatherTypes(char weatherTypes[MAX_WEATHER_TYPES][30]) {
    strcpy(weatherTypes[0], "Sunny");
    strcpy(weatherTypes[1], "Rainy");
    strcpy(weatherTypes[2], "Cloudy");
    strcpy(weatherTypes[3], "Stormy");
    strcpy(weatherTypes[4], "Snowy");
}

void generateWeather(Weather *weather) {
    char weatherTypes[MAX_WEATHER_TYPES][30];
    initializeWeatherTypes(weatherTypes);

    int weatherIndex = rand() % MAX_WEATHER_TYPES;
    strcpy(weather->type, weatherTypes[weatherIndex]);
    weather->temperature = (rand() % 301 - 100) / 10.0; // Temperature between -10 to 30 degrees Celsius
    weather->humidity = rand() % 101; // Humidity between 0 to 100%
    weather->windSpeed = (rand() % 201) / 2.0; // Wind speed between 0 to 100 km/h
}

void simulateWeather(Location locations[], int numLocations) {
    for (int i = 0; i < numLocations; i++) {
        generateWeather(&locations[i].currentWeather);
    }
}

void printWeatherReport(const Location locations[], int numLocations) {
    printf("\nWeather Report:\n");
    printf("=========================\n");
    for (int i = 0; i < numLocations; i++) {
        printf("Location: %s\n", locations[i].name);
        printf("Weather Type: %s\n", locations[i].currentWeather.type);
        printf("Temperature: %.1f °C\n", locations[i].currentWeather.temperature);
        printf("Humidity: %.1f%%\n", locations[i].currentWeather.humidity);
        printf("Wind Speed: %.1f km/h\n", locations[i].currentWeather.windSpeed);
        printf("-------------------------\n");
    }
}

void getInputLocations(Location locations[], int *numLocations) {
    printf("Enter the number of locations (maximum %d): ", MAX_LOCATIONS);
    scanf("%d", numLocations);
    if (*numLocations > MAX_LOCATIONS) {
        *numLocations = MAX_LOCATIONS;
    }
    for (int i = 0; i < *numLocations; i++) {
        printf("Enter name for location %d: ", i + 1);
        scanf("%s", locations[i].name);
    }
}

void saveWeatherReportToFile(const Location locations[], int numLocations, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    for (int i = 0; i < numLocations; i++) {
        fprintf(file, "Location: %s\n", locations[i].name);
        fprintf(file, "Weather Type: %s\n", locations[i].currentWeather.type);
        fprintf(file, "Temperature: %.1f °C\n", locations[i].currentWeather.temperature);
        fprintf(file, "Humidity: %.1f%%\n", locations[i].currentWeather.humidity);
        fprintf(file, "Wind Speed: %.1f km/h\n", locations[i].currentWeather.windSpeed);
        fprintf(file, "-------------------------\n");
    }
    
    fclose(file);
    printf("Weather report saved to %s\n", filename);
}

int main() {
    srand(time(NULL));

    Location locations[MAX_LOCATIONS];
    int numLocations = 0;

    getInputLocations(locations, &numLocations);
    simulateWeather(locations, numLocations);
    printWeatherReport(locations, numLocations);
    
    char filename[100];
    printf("Enter filename to save the weather report: ");
    scanf("%s", filename);
    saveWeatherReportToFile(locations, numLocations, filename);

    return 0;
}