//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 10
#define MAX_DAYS 365
#define MIN_TEMP -50
#define MAX_TEMP 50

struct city {
    char name[20];
    int temperature[MAX_DAYS];
    int precipitation[MAX_DAYS];
};

void generate_weather(struct city *cities, int num_cities, int year) {
    srand(time(NULL));

    for (int i = 0; i < num_cities; i++) {
        for (int j = 0; j < MAX_DAYS; j++) {
            int temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
            int precip = rand() % 101;

            cities[i].temperature[j] = temp;
            cities[i].precipitation[j] = precip;
        }
    }
}

void print_weather(struct city *cities, int num_cities, int day) {
    for (int i = 0; i < num_cities; i++) {
        printf("City: %s\n", cities[i].name);
        printf("Temperature: %d\n", cities[i].temperature[day]);
        printf("Precipitation: %d\n\n", cities[i].precipitation[day]);
    }
}

int main() {
    struct city cities[MAX_CITIES];
    int num_cities = 0;

    printf("Enter the names of cities (up to %d):\n", MAX_CITIES - 1);
    scanf("%s", cities[num_cities].name);
    num_cities++;

    while (num_cities < MAX_CITIES) {
        printf("Enter another city name? (y/n): ");
        char choice;
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y') {
            printf("Enter the name of the city:\n");
            scanf("%s", cities[num_cities].name);
            num_cities++;
        } else {
            break;
        }
    }

    int year;
    printf("Enter the year to simulate weather for: ");
    scanf("%d", &year);

    generate_weather(cities, num_cities, year);

    int day;
    printf("Enter the day to display weather for: ");
    scanf("%d", &day);

    print_weather(cities, num_cities, day);

    return 0;
}