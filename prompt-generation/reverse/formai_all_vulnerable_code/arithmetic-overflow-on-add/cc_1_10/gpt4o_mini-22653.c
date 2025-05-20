//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRAVELS 100

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

// Function Prototypes
void showCurrentTime();
void travelToFuture(Time *t, int years);
void travelToPast(Time *t, int years);
void eventDisplay(const Time *t);
void getUserTravelChoice(Time *t);

int main() {
    Time currentTime;
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);

    // Initialize current time
    currentTime.year = tm_info->tm_year + 1900; // tm_year is years since 1900
    currentTime.month = tm_info->tm_mon + 1;    // tm_mon is months since January
    currentTime.day = tm_info->tm_mday;
    currentTime.hour = tm_info->tm_hour;
    currentTime.minute = tm_info->tm_min;
    currentTime.second = tm_info->tm_sec;

    printf("Welcome to the Time Travel Simulator!\n");
    
    while (1) {
        showCurrentTime(&currentTime);
        getUserTravelChoice(&currentTime);
    }

    return 0;
}

void showCurrentTime(const Time *t) {
    printf("\nCurrent Date and Time:\n");
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", 
           t->year, t->month, t->day, t->hour, t->minute, t->second);
}

void travelToFuture(Time *t, int years) {
    t->year += years;
    printf("Time traveled to the future: %d years ahead!\n", years);
}

void travelToPast(Time *t, int years) {
    t->year -= years;
    printf("Time traveled to the past: %d years back!\n", years);
}

void eventDisplay(const Time *t) {
    // Random event generation based on year
    int eventNum = (t->year % 5);
    switch (eventNum) {
        case 0:
            printf("You witness the signing of a peace treaty in %d!\n", t->year);
            break;
        case 1:
            printf("You attend the first moon landing in %d!\n", t->year);
            break;
        case 2:
            printf("You see the invention of the printing press in %d!\n", t->year);
            break;
        case 3:
            printf("You experience the fall of the Berlin Wall in %d!\n", t->year);
            break;
        case 4:
            printf("You meet a famous scientist in %d!\n", t->year);
            break;
    }
}

void getUserTravelChoice(Time *t) {
    int choice;
    int years;

    printf("1. Travel to the future\n");
    printf("2. Travel to the past\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    if (choice == 1 || choice == 2) {
        printf("Enter number of years: ");
        scanf("%d", &years);
        if (years < 0 || years > MAX_TRAVELS) {
            printf("Invalid number! Please specify between 1 and %d.\n", MAX_TRAVELS);
            return;
        }
    
        if (choice == 1) {
            travelToFuture(t, years);
        } else {
            travelToPast(t, years);
        }
        eventDisplay(t);
    } else if (choice == 3) {
        printf("Exiting the simulator. Until next time!\n");
        exit(0);
    } else {
        printf("Invalid choice! Please try again.\n");
    }
}