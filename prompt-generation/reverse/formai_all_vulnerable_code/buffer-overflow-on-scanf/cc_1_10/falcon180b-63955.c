//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365
#define MIN_TEMP -50
#define MAX_TEMP 50
#define STEP 5

typedef struct {
    int day;
    int temp;
} Weather;

void generate_weather(Weather* weather, int seed) {
    srand(seed);

    for (int i = 0; i < MAX_DAYS; i++) {
        weather[i].day = i + 1;
        weather[i].temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    }
}

void print_weather(Weather* weather, int day) {
    int index = day - 1;

    if (index >= 0 && index < MAX_DAYS) {
        printf("On day %d, the temperature will be %d degrees Celsius.\n", weather[index].day, weather[index].temp);
    } else {
        printf("Invalid day.\n");
    }
}

int main() {
    Weather weather[MAX_DAYS];
    int seed;

    printf("Enter a seed for the random number generator: ");
    scanf("%d", &seed);

    generate_weather(weather, seed);

    int choice;
    do {
        printf("\nWeather Forecast\n");
        printf("--------------------\n");
        printf("1. Print weather for a specific day\n");
        printf("2. Print weather for the next 7 days\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the day: ");
                scanf("%d", &seed);
                print_weather(weather, seed);
                break;
            case 2:
                for (int i = 0; i < 7; i++) {
                    print_weather(weather, i + 1);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}