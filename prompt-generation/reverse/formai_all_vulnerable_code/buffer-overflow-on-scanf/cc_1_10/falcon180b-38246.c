//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

struct City {
    char name[50];
    int temperature;
    int humidity;
};

int main() {
    int num_cities, i, j;
    struct City cities[MAX_CITIES];
    char input_file[50];
    FILE *fp;
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int year = tm_struct->tm_year + 1900;
    int month = tm_struct->tm_mon + 1;
    int day = tm_struct->tm_mday;
    int weather_type = rand() % 4; // 0 = sunny, 1 = cloudy, 2 = rainy, 3 = snowy
    printf("Weather Simulation for %d-%02d-%02d\n", year, month, day);

    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    printf("Enter the names of the cities:\n");
    for (i = 0; i < num_cities; i++) {
        scanf("%s", cities[i].name);
    }

    printf("Enter the temperature for each city:\n");
    for (i = 0; i < num_cities; i++) {
        scanf("%d", &cities[i].temperature);
    }

    printf("Enter the humidity for each city:\n");
    for (i = 0; i < num_cities; i++) {
        scanf("%d", &cities[i].humidity);
    }

    sprintf(input_file, "weather_data_%d-%02d-%02d.txt", year, month, day);
    fp = fopen(input_file, "w");

    fprintf(fp, "Weather data for %d-%02d-%02d:\n", year, month, day);

    for (i = 0; i < num_cities; i++) {
        fprintf(fp, "City: %s\n", cities[i].name);
        fprintf(fp, "Temperature: %d\n", cities[i].temperature);
        fprintf(fp, "Humidity: %d\n", cities[i].humidity);
        fprintf(fp, "Weather type: ");

        switch (weather_type) {
            case 0:
                fprintf(fp, "Sunny\n");
                break;
            case 1:
                fprintf(fp, "Cloudy\n");
                break;
            case 2:
                fprintf(fp, "Rainy\n");
                break;
            case 3:
                fprintf(fp, "Snowy\n");
                break;
        }
    }

    fclose(fp);

    printf("Weather data saved to file: %s\n", input_file);

    return 0;
}