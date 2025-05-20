//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_TEMP 100
#define MAX_HUMIDITY 100
#define MAX_WIND_SPEED 100

typedef struct {
    char name[50];
    int temp;
    int humidity;
    int wind_speed;
} city;

void generate_weather(city* cities, int num_cities) {
    srand(time(NULL));
    for (int i = 0; i < num_cities; i++) {
        cities[i].temp = rand() % MAX_TEMP;
        cities[i].humidity = rand() % MAX_HUMIDITY;
        cities[i].wind_speed = rand() % MAX_WIND_SPEED;
    }
}

void print_weather(city* cities, int num_cities) {
    printf("Weather report:\n");
    for (int i = 0; i < num_cities; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Temperature: %d\n", cities[i].temp);
        printf("Humidity: %d\n", cities[i].humidity);
        printf("Wind speed: %d\n", cities[i].wind_speed);
        printf("\n");
    }
}

int main() {
    city cities[MAX_CITIES];
    int num_cities;

    printf("How many cities do you want to simulate? (Max %d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    printf("Enter city names:\n");
    for (int i = 0; i < num_cities; i++) {
        scanf("%s", cities[i].name);
    }

    generate_weather(cities, num_cities);
    print_weather(cities, num_cities);

    return 0;
}