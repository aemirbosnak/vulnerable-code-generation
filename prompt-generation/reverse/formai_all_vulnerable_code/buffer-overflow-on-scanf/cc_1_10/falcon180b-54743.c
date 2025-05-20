//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_TEMPERATURES 30

struct City {
    char name[20];
    int temperature[MAX_TEMPERATURES];
    int current_temperature;
};

void generate_weather(struct City *city) {
    srand(time(NULL));
    for (int i = 0; i < MAX_TEMPERATURES; i++) {
        city->temperature[i] = rand() % 30 + 1;
    }
}

void print_weather(struct City *city) {
    printf("City: %s\n", city->name);
    for (int i = 0; i < MAX_TEMPERATURES; i++) {
        printf("Day %d: %d degrees Celsius\n", i + 1, city->temperature[i]);
    }
}

int main() {
    struct City cities[MAX_CITIES];

    for (int i = 0; i < MAX_CITIES; i++) {
        printf("Enter city name: ");
        scanf("%s", cities[i].name);
        generate_weather(&cities[i]);
    }

    int choice;
    do {
        printf("\nSelect a city:\n");
        for (int i = 0; i < MAX_CITIES; i++) {
            printf("%d. %s\n", i + 1, cities[i].name);
        }
        scanf("%d", &choice);
        if (choice >= 1 && choice <= MAX_CITIES) {
            print_weather(&cities[choice - 1]);
        } else {
            printf("Invalid choice.\n");
        }
        printf("\nDo you want to check another city? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}