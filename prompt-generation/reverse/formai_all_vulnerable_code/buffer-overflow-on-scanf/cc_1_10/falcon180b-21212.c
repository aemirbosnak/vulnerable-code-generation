//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365
#define MIN_TEMP -20
#define MAX_TEMP 40

struct day {
    int temperature;
    char weather[20];
};

void generate_weather(struct day *weather_data, int num_days) {
    srand(time(NULL));
    for (int i = 0; i < num_days; i++) {
        weather_data[i].temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        if (weather_data[i].temperature >= 0 && weather_data[i].temperature <= 10) {
            strcpy(weather_data[i].weather, "Freezing");
        } else if (weather_data[i].temperature >= 10 && weather_data[i].temperature <= 20) {
            strcpy(weather_data[i].weather, "Cold");
        } else if (weather_data[i].temperature >= 20 && weather_data[i].temperature <= 30) {
            strcpy(weather_data[i].weather, "Mild");
        } else if (weather_data[i].temperature >= 30 && weather_data[i].temperature <= 40) {
            strcpy(weather_data[i].weather, "Warm");
        } else {
            strcpy(weather_data[i].weather, "Hot");
        }
    }
}

void print_weather(struct day *weather_data, int num_days) {
    printf("Weather forecast for the next %d days:\n", num_days);
    for (int i = 0; i < num_days; i++) {
        printf("%d: %s, %d degrees Celsius\n", i + 1, weather_data[i].weather, weather_data[i].temperature);
    }
}

int main() {
    int num_days;
    printf("Enter the number of days you want to simulate the weather for: ");
    scanf("%d", &num_days);

    if (num_days > MAX_DAYS || num_days <= 0) {
        printf("Invalid number of days. Please enter a number between 1 and %d.\n", MAX_DAYS);
        return 1;
    }

    struct day weather_data[num_days];
    generate_weather(weather_data, num_days);
    print_weather(weather_data, num_days);

    return 0;
}