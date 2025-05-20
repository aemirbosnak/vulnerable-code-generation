//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

typedef struct {
    char name[50];
    int temperature[MAX_DAYS];
    int precipitation[MAX_DAYS];
} City;

void generate_weather(City* city) {
    for (int i = 0; i < MAX_DAYS; i++) {
        city->temperature[i] = rand() % 50 + 10;
        city->precipitation[i] = rand() % 10 + 1;
    }
}

void print_weather(City* city) {
    printf("Weather for %s:\n", city->name);
    for (int i = 0; i < MAX_DAYS; i++) {
        printf("%d: %d°C, %dmm precipitation\n", i+1, city->temperature[i], city->precipitation[i]);
    }
}

int main() {
    srand(time(NULL));

    City cities[MAX_CITIES];

    int num_cities = rand() % MAX_CITIES;

    for (int i = 0; i < num_cities; i++) {
        strcpy(cities[i].name, "City ");
        int len = rand() % 10 + 1;
        for (int j = 0; j < len; j++) {
            cities[i].name[j] = rand() % 26 + 'a';
        }
        cities[i].name[len] = '\0';
        generate_weather(&cities[i]);
    }

    int choice;
    do {
        printf("Enter city number (1-%d): ", num_cities);
        scanf("%d", &choice);
        if (choice >= 1 && choice <= num_cities) {
            print_weather(&cities[choice-1]);
        } else {
            printf("Invalid choice.\n");
        }
        printf("Press any key to continue...\n");
        getchar();
    } while (1);

    return 0;
}