//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

Time currentTime() {
    Time t;
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    t.year = local->tm_year + 1900;
    t.month = local->tm_mon + 1;
    t.day = local->tm_mday;
    t.hour = local->tm_hour;
    t.minute = local->tm_min;
    t.second = local->tm_sec;
    return t;
}

void printTime(Time t) {
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", t.year, t.month, t.day, t.hour, t.minute, t.second);
}

int main() {
    Time startTime = currentTime();
    printf("Starting time: ");
    printTime(startTime);

    int destinationYear, destinationMonth, destinationDay, destinationHour, destinationMinute, destinationSecond;
    printf("Enter destination time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%d-%d-%d %d:%d:%d", &destinationYear, &destinationMonth, &destinationDay, &destinationHour, &destinationMinute, &destinationSecond);

    Time destinationTime;
    destinationTime.year = destinationYear;
    destinationTime.month = destinationMonth;
    destinationTime.day = destinationDay;
    destinationTime.hour = destinationHour;
    destinationTime.minute = destinationMinute;
    destinationTime.second = destinationSecond;

    while (currentTime().second!= destinationTime.second || currentTime().minute!= destinationTime.minute || currentTime().hour!= destinationTime.hour || currentTime().day!= destinationTime.day || currentTime().month!= destinationTime.month || currentTime().year!= destinationTime.year) {
        currentTime();
        printTime(currentTime());
    }

    printf("Arrived at destination time: ");
    printTime(destinationTime);

    return 0;
}