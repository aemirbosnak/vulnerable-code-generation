//GEMINI-pro DATASET v1.0 Category: Weather simulation ; Style: future-proof
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
#define FORECAST_DAYS 7
#define MAX_CITY_NAME_LENGTH 32

typedef struct {
    char name[MAX_CITY_NAME_LENGTH];
    double latitude;
    double longitude;
} City;

typedef struct {
    City* cities;
    size_t num_cities;
} CityDatabase;

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    double temperature;
    double humidity;
    double wind_speed;
    char* description;
} WeatherData;

typedef struct {
    Date date;
    WeatherData weather_data;
} WeatherForecast;

CityDatabase load_city_database(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    CityDatabase city_database;
    fscanf(file, "%zu\n", &city_database.num_cities);
    city_database.cities = malloc(sizeof(City) * city_database.num_cities);
    for (size_t i = 0; i < city_database.num_cities; i++) {
        fscanf(file, "%s %lf %lf\n", city_database.cities[i].name, &city_database.cities[i].latitude,
               &city_database.cities[i].longitude);
    }
    fclose(file);

    return city_database;
}

WeatherForecast* generate_weather_forecast(const City* city, const Date* start_date) {
    WeatherForecast* weather_forecast = malloc(sizeof(WeatherForecast) * FORECAST_DAYS);
    for (int i = 0; i < FORECAST_DAYS; i++) {
        weather_forecast[i].date.day = start_date->day + i;
        weather_forecast[i].date.month = start_date->month;
        weather_forecast[i].date.year = start_date->year;
        weather_forecast[i].weather_data.temperature = 20.0 + 10.0 * sin(i * 0.5);
        weather_forecast[i].weather_data.humidity = 50.0 + 20.0 * cos(i * 0.3);
        weather_forecast[i].weather_data.wind_speed = 5.0 + 5.0 * sin(i * 0.7);
        weather_forecast[i].weather_data.description = "Sunny";
    }
    return weather_forecast;
}

void print_weather_forecast(const WeatherForecast* weather_forecast) {
    for (int i = 0; i < FORECAST_DAYS; i++) {
        printf("Date: %d/%d/%d\n", weather_forecast[i].date.day, weather_forecast[i].date.month,
               weather_forecast[i].date.year);
        printf("Temperature: %.2f degrees Celsius\n", weather_forecast[i].weather_data.temperature);
        printf("Humidity: %.2f%%\n", weather_forecast[i].weather_data.humidity);
        printf("Wind speed: %.2f m/s\n", weather_forecast[i].weather_data.wind_speed);
        printf("Description: %s\n", weather_forecast[i].weather_data.description);
        printf("\n");
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <city_database_file> <start_date>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    CityDatabase city_database = load_city_database(argv[1]);
    Date start_date;
    sscanf(argv[2], "%d/%d/%d", &start_date.day, &start_date.month, &start_date.year);

    for (size_t i = 0; i < city_database.num_cities; i++) {
        WeatherForecast* weather_forecast = generate_weather_forecast(&city_database.cities[i], &start_date);
        printf("Weather forecast for %s:\n", city_database.cities[i].name);
        print_weather_forecast(weather_forecast);
        free(weather_forecast);
    }

    free(city_database.cities);
    return EXIT_SUCCESS;
}