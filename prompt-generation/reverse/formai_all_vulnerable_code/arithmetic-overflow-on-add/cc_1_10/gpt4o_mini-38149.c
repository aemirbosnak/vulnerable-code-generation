//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    int hour;
    int minute;
    int second;
} Time;

typedef struct {
    Date date;
    Time time;
} TimePoint;

void displayTimePoint(TimePoint tp) {
    printf("You are at: %04d-%02d-%02d %02d:%02d:%02d\n",
           tp.date.year, tp.date.month, tp.date.day,
           tp.time.hour, tp.time.minute, tp.time.second);
}

Date getCurrentDate() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    Date currentDate = {
        tm.tm_year + 1900,
        tm.tm_mon + 1,
        tm.tm_mday
    };

    return currentDate;
}

Time getCurrentTime() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    Time currentTime = {
        tm.tm_hour,
        tm.tm_min,
        tm.tm_sec
    };

    return currentTime;
}

TimePoint travelToFuture(int years, int months, int days, Date currentDate, Time currentTime) {
    TimePoint futureTP;
    futureTP.date = currentDate;
    futureTP.time = currentTime;

    futureTP.date.year += years;
    futureTP.date.month += months;

    if (futureTP.date.month > 12) {
        futureTP.date.year += futureTP.date.month / 12;
        futureTP.date.month = futureTP.date.month % 12;
    }

    futureTP.date.day += days;

    // Simple logic to handle overflow of days (not accounting for month lengths)
    if (futureTP.date.day > 30) {
        futureTP.date.month += futureTP.date.day / 30;
        futureTP.date.day = futureTP.date.day % 30;
    }
    
    if (futureTP.date.month > 12) {
        futureTP.date.year += futureTP.date.month / 12;
        futureTP.date.month = futureTP.date.month % 12;
    }

    return futureTP;
}

TimePoint travelToPast(int years, int months, int days, Date currentDate, Time currentTime) {
    TimePoint pastTP;
    pastTP.date = currentDate;
    pastTP.time = currentTime;

    pastTP.date.year -= years;
    pastTP.date.month -= months;

    if (pastTP.date.month < 1) {
        pastTP.date.year += (pastTP.date.month / 12) - 1;
        pastTP.date.month = 12 + (pastTP.date.month % 12);
    }

    pastTP.date.day -= days;

    // Simple logic to handle underflow of days (not accounting for month lengths)
    if (pastTP.date.day < 1) {
        pastTP.date.month -= 1;
        if (pastTP.date.month < 1) {
            pastTP.date.year -= 1;
            pastTP.date.month = 12;
        }
        pastTP.date.day += 30; // Assuming 30 days for simplicity
    }
    
    return pastTP;
}

int main() {
    Date currentDate = getCurrentDate();
    Time currentTime = getCurrentTime();
    
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Current date and time:\n");
    displayTimePoint((TimePoint){currentDate, currentTime});
    
    printf("\nTraveling to the future...\n");
    int years, months, days;
    printf("Enter years to travel forward: ");
    scanf("%d", &years);
    printf("Enter months to travel forward: ");
    scanf("%d", &months);
    printf("Enter days to travel forward: ");
    scanf("%d", &days);
    
    TimePoint futureTP = travelToFuture(years, months, days, currentDate, currentTime);
    printf("You have traveled to the future!\n");
    displayTimePoint(futureTP);
    
    printf("\nTraveling to the past...\n");
    printf("Enter years to travel back: ");
    scanf("%d", &years);
    printf("Enter months to travel back: ");
    scanf("%d", &months);
    printf("Enter days to travel back: ");
    scanf("%d", &days);
    
    TimePoint pastTP = travelToPast(years, months, days, currentDate, currentTime);
    printf("You have traveled to the past!\n");
    displayTimePoint(pastTP);
    
    printf("\nThank you for using the Time Travel Simulator!\n");
    return 0;
}