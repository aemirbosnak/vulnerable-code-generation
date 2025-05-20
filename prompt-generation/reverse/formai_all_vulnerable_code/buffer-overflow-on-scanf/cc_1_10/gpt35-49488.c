//FormAI DATASET v1.0 Category: Date and time ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void displayDateTime(struct tm* timeinfo);
void displayDate(struct tm* timeinfo);
void displayTime(struct tm* timeinfo);
void calculateDifference();

int main() {
    // get current time and date
    time_t currentTime;
    struct tm* timeinfo;
    time(&currentTime);
    timeinfo = localtime(&currentTime);

    // display date and time in various formats
    printf("Current Date and Time:\n");
    displayDateTime(timeinfo); // format: MMMM dd, yyyy hh:mm:ss AM/PM
    displayDate(timeinfo); // format: MM/dd/yyyy
    displayTime(timeinfo); // format: hh:mm:ss AM/PM

    // calculate difference between two dates and times
    printf("\nCalculate Difference Between Two Dates and Times:\n");
    calculateDifference();

    return 0;
}

// function to display date and time in MMMM dd, yyyy hh:mm:ss AM/PM format
void displayDateTime(struct tm* timeinfo) {
    char dateTime[50];
    strftime(dateTime, 50, "%B %d, %Y %I:%M:%S %p", timeinfo);
    printf("%s\n", dateTime);
}

// function to display date in MM/dd/yyyy format
void displayDate(struct tm* timeinfo) {
    char date[20];
    strftime(date, 20, "%m/%d/%Y", timeinfo);
    printf("Date: %s\n", date);
}

// function to display time in hh:mm:ss AM/PM format
void displayTime(struct tm* timeinfo) {
    char time[20];
    strftime(time, 20, "%I:%M:%S %p", timeinfo);
    printf("Time: %s\n", time);
}

// function to calculate difference between two dates and times
void calculateDifference() {
    // get input for first date and time
    int month1, day1, year1, hour1, minute1, second1;
    printf("Enter the first date and time (MM/dd/yyyy hh:mm:ss): ");
    scanf("%d/%d/%d %d:%d:%d", &month1, &day1, &year1, &hour1, &minute1, &second1);
    struct tm time1 = {0};
    time1.tm_year = year1 - 1900;
    time1.tm_mon = month1 - 1;
    time1.tm_mday = day1;
    time1.tm_hour = hour1;
    time1.tm_min = minute1;
    time1.tm_sec = second1;
    time_t time1_t = mktime(&time1);

    // get input for second date and time
    int month2, day2, year2, hour2, minute2, second2;
    printf("Enter the second date and time (MM/dd/yyyy hh:mm:ss): ");
    scanf("%d/%d/%d %d:%d:%d", &month2, &day2, &year2, &hour2, &minute2, &second2);
    struct tm time2 = {0};
    time2.tm_year = year2 - 1900;
    time2.tm_mon = month2 - 1;
    time2.tm_mday = day2;
    time2.tm_hour = hour2;
    time2.tm_min = minute2;
    time2.tm_sec = second2;
    time_t time2_t = mktime(&time2);

    // calculate difference in seconds
    double difference = difftime(time1_t, time2_t);

    // display difference in seconds, minutes, hours, and days
    printf("Difference:\n");
    printf("%.0f seconds\n", difference);
    printf("%.2f minutes\n", difference / 60);
    printf("%.2f hours\n", difference / 3600);
    printf("%.2f days\n", difference / 86400);
}