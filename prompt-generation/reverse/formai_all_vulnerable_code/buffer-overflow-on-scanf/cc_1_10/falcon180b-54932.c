//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30

typedef struct {
    char name[20];
    int x, y;
    int temperature;
} City;

void generate_weather(City cities[], int num_cities, int day) {
    srand(time(NULL));

    for (int i = 0; i < num_cities; i++) {
        int temp_change = rand() % 10 - 5;
        cities[i].temperature += temp_change;

        if (cities[i].temperature < 0) {
            cities[i].temperature = 0;
        } else if (cities[i].temperature > 40) {
            cities[i].temperature = 40;
        }
    }
}

void print_weather(City cities[], int num_cities) {
    for (int i = 0; i < num_cities; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Temperature: %d°C\n", cities[i].temperature);
        printf("\n");
    }
}

int main() {
    City cities[MAX_CITIES];
    int num_cities = 0;

    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter the name of city %d: ", i+1);
        scanf("%s", cities[i].name);

        printf("Enter the coordinates of city %d (x y): ", i+1);
        scanf("%d %d", &cities[i].x, &cities[i].y);
    }

    int num_days;
    printf("Enter the number of days to simulate: ");
    scanf("%d", &num_days);

    for (int day = 1; day <= num_days; day++) {
        generate_weather(cities, num_cities, day);
        print_weather(cities, num_cities);
    }

    return 0;
}