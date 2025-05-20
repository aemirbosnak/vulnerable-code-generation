//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30
#define MIN_TEMP -50
#define MAX_TEMP 50

struct city {
    char name[20];
    int x;
    int y;
    int temp;
};

void generate_cities(struct city* cities, int num_cities) {
    int i;
    for (i = 0; i < num_cities; i++) {
        cities[i].temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    }
}

void print_cities(struct city* cities, int num_cities) {
    int i;
    for (i = 0; i < num_cities; i++) {
        printf("%s: %d°C\n", cities[i].name, cities[i].temp);
    }
}

void simulate_weather(struct city* cities, int num_cities, int num_days) {
    int i, j;
    for (i = 0; i < num_days; i++) {
        for (j = 0; j < num_cities; j++) {
            cities[j].temp = (cities[j].temp + rand() % 5 - 2) % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        }
        printf("Day %d:\n", i + 1);
        print_cities(cities, num_cities);
        printf("\n");
    }
}

int main() {
    struct city cities[MAX_CITIES];
    int num_cities, num_days;

    printf("Enter the number of cities: ");
    scanf("%d", &num_cities);

    printf("Enter the names of the cities:\n");
    for (int i = 0; i < num_cities; i++) {
        scanf("%s", cities[i].name);
    }

    printf("Enter the coordinates of the cities:\n");
    for (int i = 0; i < num_cities; i++) {
        scanf("%d %d", &cities[i].x, &cities[i].y);
    }

    generate_cities(cities, num_cities);

    printf("Enter the number of days to simulate: ");
    scanf("%d", &num_days);

    simulate_weather(cities, num_cities, num_days);

    return 0;
}