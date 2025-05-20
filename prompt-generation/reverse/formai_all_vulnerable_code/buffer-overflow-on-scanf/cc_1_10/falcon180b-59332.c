//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: careful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

struct City {
    char name[20];
    int temperature;
    int humidity;
    int wind_speed;
};

void generate_weather(struct City* city, int day) {
    int temperature = rand() % 40 + 1; // random temperature between 1 and 40 degrees Celsius
    int humidity = rand() % 100; // random humidity between 0 and 100 percent
    int wind_speed = rand() % 20 + 1; // random wind speed between 1 and 20 meters per second

    city->temperature = temperature;
    city->humidity = humidity;
    city->wind_speed = wind_speed;
}

void print_weather(struct City* city) {
    printf("City: %s\n", city->name);
    printf("Temperature: %d degrees Celsius\n", city->temperature);
    printf("Humidity: %d%%\n", city->humidity);
    printf("Wind Speed: %d meters per second\n", city->wind_speed);
}

int main() {
    struct City cities[MAX_CITIES];
    int num_cities;
    char input[100];

    srand(time(NULL)); // seed the random number generator with the current time

    printf("Enter the number of cities (up to %d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i+1);
        scanf("%s", cities[i].name);
    }

    int days = 0;
    while (days < MAX_DAYS) {
        for (int i = 0; i < num_cities; i++) {
            generate_weather(&cities[i], days);
            print_weather(&cities[i]);
        }
        days++;
        system("pause");
    }

    return 0;
}