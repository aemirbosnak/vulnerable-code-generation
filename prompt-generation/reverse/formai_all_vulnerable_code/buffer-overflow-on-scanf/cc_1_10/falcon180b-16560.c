//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DAYS_IN_WEEK 7
#define HOURS_IN_DAY 24
#define MINUTES_IN_HOUR 60
#define SECONDS_IN_MINUTE 60

// Function to print the current weather condition
void print_weather(int condition) {
    switch (condition) {
        case 0:
            printf("Sunny\n");
            break;
        case 1:
            printf("Cloudy\n");
            break;
        case 2:
            printf("Rainy\n");
            break;
        case 3:
            printf("Stormy\n");
            break;
    }
}

// Function to generate a random weather condition
int generate_weather() {
    int condition = rand() % 4;
    return condition;
}

// Function to print the weather forecast for the next few days
void print_forecast(int condition, int days) {
    printf("The weather for the next %d days will be ", days);
    switch (condition) {
        case 0:
            printf("sunny.\n");
            break;
        case 1:
            printf("cloudy.\n");
            break;
        case 2:
            printf("rainy.\n");
            break;
        case 3:
            printf("stormy.\n");
            break;
    }
}

// Function to simulate the weather for a given number of days
void simulate_weather(int days) {
    int i;
    for (i = 0; i <= days; i++) {
        int condition = generate_weather();
        print_weather(condition);
        if (i % DAYS_IN_WEEK == 0) {
            print_forecast(condition, DAYS_IN_WEEK);
        }
    }
}

int main() {
    int num_days;
    printf("Enter the number of days to simulate the weather: ");
    scanf("%d", &num_days);
    srand(time(NULL));
    simulate_weather(num_days);
    return 0;
}