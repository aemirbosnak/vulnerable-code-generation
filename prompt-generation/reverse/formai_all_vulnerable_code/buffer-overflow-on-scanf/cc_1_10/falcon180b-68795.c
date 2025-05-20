//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_TEMP 50
#define MAX_HUM 100
#define MAX_WIND 100
#define MAX_CLOUD 100

typedef struct {
    char name[20];
    int temp;
    int hum;
    int wind;
    int cloud;
} City;

void init_city(City *city) {
    city->temp = rand() % MAX_TEMP;
    city->hum = rand() % MAX_HUM;
    city->wind = rand() % MAX_WIND;
    city->cloud = rand() % MAX_CLOUD;
}

void print_city(City *city) {
    printf("%s: %d°C, %d%% humidity, %d km/h wind, %d%% cloud cover\n", city->name, city->temp, city->hum, city->wind, city->cloud);
}

int main() {
    City cities[MAX_CITIES];
    int num_cities = 0;

    srand(time(NULL));

    while (num_cities < MAX_CITIES) {
        printf("Enter the name of a city (or type 'done' to finish): ");
        scanf("%s", cities[num_cities].name);

        if (strcmp(cities[num_cities].name, "done") == 0) {
            break;
        }

        init_city(&cities[num_cities]);
        num_cities++;
    }

    int choice;
    do {
        printf("\n1. Print current weather\n2. Simulate weather changes\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < num_cities; i++) {
                    print_city(&cities[i]);
                }
                break;
            case 2:
                // Simulate weather changes
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 3);

    return 0;
}