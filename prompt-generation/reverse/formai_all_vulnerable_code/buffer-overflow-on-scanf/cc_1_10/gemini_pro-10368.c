//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: puzzling
#include <stdio.h>
#include <time.h>

typedef struct {
    int year;
    int day;
} Date;

Date dates[] = {
    {2023, 21}, // Today
    {1985, 1}, // Birth of Bill Gates
    {1947, 7}, // Roswell UFO incident
    {1789, 7}, // French Revolution begins
    {1492, 10}, // Columbus discovers America
    {1066, 9}, // Battle of Hastings
};

int main() {
    int choice;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("------------------------------------\n");
    printf("Available destinations:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %d-%02d\n", i + 1, dates[i].year, dates[i].day);
    }
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 5) {
        printf("Invalid choice.\n");
        return 1;
    }

    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    tm_now->tm_year = dates[choice - 1].year - 1900;
    tm_now->tm_mon = dates[choice - 1].day - 1;
    tm_now->tm_mday = 15; // Arbitrary day within the month

    time_t then = mktime(tm_now);
    double difference = difftime(then, now);

    if (difference < 0) {
        printf("You cannot travel back to the future.\n");
        return 2;
    }

    printf("You have traveled %ld seconds to %d-%02d.\n", (long)difference, dates[choice - 1].year, dates[choice - 1].day);

    return 0;
}