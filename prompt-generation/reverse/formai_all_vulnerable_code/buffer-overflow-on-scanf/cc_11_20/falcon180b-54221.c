//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 365
#define MIN_TEMP 0
#define MAX_TEMP 100

struct Day {
    int temperature;
    char weather[20];
};

int main() {
    int numDays;
    time_t now = time(NULL);
    struct tm *currentTime = localtime(&now);
    int currentMonth = currentTime->tm_mon + 1;
    int currentDay = currentTime->tm_mday;
    int currentYear = currentTime->tm_year + 1900;

    printf("Welcome to the Happy Weather Simulator!\n");
    printf("Today is %d/%d/%d\n", currentDay, currentMonth, currentYear);

    printf("How many days would you like to simulate? ");
    scanf("%d", &numDays);

    if (numDays < 1 || numDays > MAX_DAYS) {
        printf("Invalid number of days.\n");
        return 1;
    }

    struct Day days[numDays];

    for (int i = 0; i < numDays; i++) {
        days[i].temperature = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
        if (currentMonth == 12 || currentMonth == 1 || currentMonth == 2) {
            strcpy(days[i].weather, "Cold");
        } else if (currentMonth == 3 || currentMonth == 4 || currentMonth == 5) {
            strcpy(days[i].weather, "Cool");
        } else if (currentMonth == 6 || currentMonth == 7 || currentMonth == 8) {
            strcpy(days[i].weather, "Warm");
        } else {
            strcpy(days[i].weather, "Hot");
        }
        currentDay++;
        if (currentDay > currentTime->tm_mday) {
            currentMonth++;
            currentDay = 1;
        }
    }

    printf("\n%d-day weather forecast:\n", numDays);
    for (int i = 0; i < numDays; i++) {
        printf("%d: %d°C %s\n", i+1, days[i].temperature, days[i].weather);
    }

    return 0;
}