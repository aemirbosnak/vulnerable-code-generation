//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

struct city {
    char name[50];
    int temperature[MAX_DAYS];
    int precipitation[MAX_DAYS];
};

void generate_weather(struct city *cities, int num_cities, int start_day, int end_day) {
    srand(time(NULL));

    for (int i = 0; i < num_cities; i++) {
        for (int j = start_day; j <= end_day; j++) {
            int temp = rand() % 101 - 50;
            int precip = rand() % 101;

            cities[i].temperature[j] = temp;
            cities[i].precipitation[j] = precip;
        }
    }
}

void print_weather(struct city *cities, int num_cities, int start_day, int end_day) {
    for (int i = 0; i < num_cities; i++) {
        printf("Weather for %s:\n", cities[i].name);

        for (int j = start_day; j <= end_day; j++) {
            printf("%d: %d°C, %dmm precipitation\n", j + 1, cities[i].temperature[j], cities[i].precipitation[j]);
        }

        printf("\n");
    }
}

int main() {
    struct city cities[MAX_CITIES];
    int num_cities;

    printf("How many cities do you want to simulate? ");
    scanf("%d", &num_cities);

    for (int i = 0; i < num_cities; i++) {
        printf("Enter city name: ");
        scanf(" %[^\n]s", cities[i].name);
    }

    int start_day, end_day;

    printf("Enter start day (1-365): ");
    scanf("%d", &start_day);

    printf("Enter end day (1-365): ");
    scanf("%d", &end_day);

    generate_weather(cities, num_cities, start_day, end_day);
    print_weather(cities, num_cities, start_day, end_day);

    return 0;
}