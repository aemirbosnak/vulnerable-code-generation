//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 20
#define MAX_TEMP_RANGE 50

struct City {
    char name[20];
    int temperature;
    int humidity;
    int pressure;
};

struct City cities[MAX_CITIES];
int num_cities;

void generate_random_city() {
    cities[num_cities].temperature = rand() % MAX_TEMP_RANGE + 1;
    cities[num_cities].humidity = rand() % 101;
    cities[num_cities].pressure = rand() % 101;
    sprintf(cities[num_cities].name, "City %d", num_cities + 1);
    num_cities++;
}

void generate_cities() {
    srand(time(NULL));
    num_cities = 0;
    for (int i = 0; i < MAX_CITIES; i++) {
        generate_random_city();
    }
}

void print_city(int index) {
    printf("City: %s\n", cities[index].name);
    printf("Temperature: %d\n", cities[index].temperature);
    printf("Humidity: %d%\n", cities[index].humidity);
    printf("Pressure: %d hPa\n\n", cities[index].pressure);
}

int main() {
    generate_cities();
    int choice;
    do {
        printf("Enter 1 to print a random city or 0 to exit: ");
        scanf("%d", &choice);
        if (choice == 1) {
            int index = rand() % num_cities;
            print_city(index);
        }
    } while (choice!= 0);
    return 0;
}