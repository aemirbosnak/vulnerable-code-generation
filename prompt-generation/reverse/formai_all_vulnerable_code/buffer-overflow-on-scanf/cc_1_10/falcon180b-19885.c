//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 30

struct City {
    char name[20];
    int temperature;
};

void generate_weather(struct City *cities, int num_cities, int num_days) {
    for (int i = 0; i < num_cities; i++) {
        for (int j = 0; j < num_days; j++) {
            cities[i].temperature = rand() % 31 - 15;
        }
    }
}

void print_weather(struct City *cities, int num_cities, int num_days) {
    for (int i = 0; i < num_cities; i++) {
        printf("%s weather for the next %d days:\n", cities[i].name, num_days);
        for (int j = 0; j < num_days; j++) {
            printf("%d degrees Celsius\n", cities[i].temperature + j);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    struct City cities[MAX_CITIES];
    int num_cities, num_days;

    printf("Enter the number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &num_cities);

    printf("Enter the number of days to simulate (max %d): ", MAX_DAYS);
    scanf("%d", &num_days);

    printf("Enter the names of the cities:\n");
    for (int i = 0; i < num_cities; i++) {
        scanf("%s", cities[i].name);
    }

    generate_weather(cities, num_cities, num_days);
    print_weather(cities, num_cities, num_days);

    return 0;
}