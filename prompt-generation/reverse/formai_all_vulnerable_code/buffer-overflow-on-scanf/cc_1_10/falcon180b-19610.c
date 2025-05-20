//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365
#define MAX_HOURS 24
#define MAX_MINUTES 60
#define MAX_SECONDS 60
#define MAX_TEMP 50

int main() {
    int days = 0;
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    int temp = 0;
    int max_temp = 0;
    int min_temp = MAX_TEMP;
    char choice;

    srand(time(NULL));

    do {
        system("clear");
        printf("Weather Simulation\n");
        printf("=================\n");
        printf("Day %d\n", days+1);
        printf("Temperature: %d°C\n", temp);
        printf("Max Temperature: %d°C\n", max_temp);
        printf("Min Temperature: %d°C\n", min_temp);
        printf("=================\n");
        printf("Press any key to continue...\n");
        scanf("%c", &choice);
        getchar();

        if (temp >= MAX_TEMP) {
            temp = MAX_TEMP;
        } else if (temp <= 0) {
            temp = 0;
        }

        if (temp > max_temp) {
            max_temp = temp;
        } else if (temp < min_temp) {
            min_temp = temp;
        }

        if (days == MAX_DAYS) {
            days = 0;
            hours += 24;
        } else if (hours == MAX_HOURS) {
            hours = 0;
            minutes += 60;
        } else if (minutes == MAX_MINUTES) {
            minutes = 0;
            seconds += 60;
        } else if (seconds == MAX_SECONDS) {
            seconds = 0;
            temp += rand() % 5 - 2;
        } else {
            seconds++;
        }

        days++;
    } while (choice!= 'q');

    return 0;
}