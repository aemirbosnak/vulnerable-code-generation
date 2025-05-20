//FormAI DATASET v1.0 Category: Weather simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char weather[5][15] = {"Sunny", "Rainy", "Thunderstorm", "Snowy", "Hail"};
    int temperature[12][2] = {{-5, 15}, {10, 25}, {20, 35}, {28, 42}, {30, 45}, {35, 50},
                             {32, 45}, {25, 38}, {15, 30}, {5, 20}, {-5, 10}, {-10, 5}};
    int month, max_temp, min_temp, current_temp, avg_temp, weather_choice; 

    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    if (month < 1 || month > 12) {
        printf("Invalid month. Please try again.\n");
        return 0;
    }

    srand(time(NULL));

    max_temp = temperature[month - 1][1];
    min_temp = temperature[month - 1][0];
    current_temp = rand() % (max_temp - min_temp + 1) + min_temp;
    avg_temp = (max_temp + min_temp) / 2;
    weather_choice = rand() % 5;

    printf("Weather simulation for month %d:\n\n", month);
    printf("Current temperature: %d°C\n", current_temp);
    printf("Average temperature: %d°C\n", avg_temp);
    printf("Weather: %s\n", weather[weather_choice]);

    if (current_temp > avg_temp) {
        printf("It's warmer than average. Don't forget to stay hydrated!\n");
    } else if (current_temp < avg_temp) {
        printf("It's cooler than average. Don't forget to bundle up!\n");
    } else {
        printf("It's about average temperature. Enjoy your day!\n");
    }

    switch (weather_choice) {
        case 0:
            printf("Time to enjoy some sunshine!\n");
            break;

        case 1:
            printf("Better bring an umbrella with you!\n");
            break;

        case 2:
            printf("Stay indoors! Thunderstorms can be dangerous.\n");
            break;

        case 3:
            printf("Build a snowman or enjoy some hot chocolate!\n");
            break;

        case 4:
            printf("Watch out for hailstones! They can do some damage.\n");
            break;

        default:
            printf("Oops, something went wrong. Please try again.\n");
    }

    return 0;
}