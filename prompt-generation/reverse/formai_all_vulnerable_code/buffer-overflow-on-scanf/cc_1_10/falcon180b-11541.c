//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_YEAR 9999
#define MIN_YEAR 0
#define MIN_MONTH 1
#define MAX_MONTH 12
#define MIN_DAY 1
#define MAX_DAY 31

struct Date {
    int year;
    int month;
    int day;
};

struct TimeMachine {
    struct Date currentDate;
    struct Date targetDate;
};

void initDate(struct Date* date) {
    date->year = 1900;
    date->month = 1;
    date->day = 1;
}

void printDate(struct Date date) {
    printf("%04d-%02d-%02d\n", date.year, date.month, date.day);
}

int isValidDate(struct Date date) {
    if (date.month < MIN_MONTH || date.month > MAX_MONTH) {
        return 0;
    }

    switch (date.month) {
        case 2:
            if (date.day > 29 &&!(date.year % 4 == 0 && (date.year % 100!= 0 || date.year % 400 == 0))) {
                return 0;
            }
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            if (date.day > 30) {
                return 0;
            }
            break;

        default:
            if (date.day > 31) {
                return 0;
            }
            break;
    }

    return 1;
}

void setTargetDate(struct TimeMachine* timeMachine) {
    printf("Enter target date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &timeMachine->targetDate.year, &timeMachine->targetDate.month, &timeMachine->targetDate.day);

    if (!isValidDate(timeMachine->targetDate)) {
        printf("Invalid date.\n");
        exit(1);
    }
}

void timeTravel(struct TimeMachine* timeMachine) {
    time_t currentTime;
    time_t targetTime;

    time(&currentTime);
    mktime(&timeMachine->currentDate);
    targetTime = mktime(&timeMachine->targetDate);

    if (difftime(targetTime, currentTime) < 0) {
        printf("You cannot travel back in time.\n");
        exit(1);
    }

    printf("Time travel initiated...\n");
    sleep(3);
    printf("Arrived at %s.\n", ctime(&targetTime));
}

int main() {
    struct TimeMachine timeMachine;

    initDate(&timeMachine.currentDate);
    setTargetDate(&timeMachine);
    timeTravel(&timeMachine);

    return 0;
}