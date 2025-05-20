//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to calculate the time travel distance
double calculateDistance(int year, int month, int day, int hour, int minute, int second) {
    time_t now = time(NULL);
    struct tm current = *localtime(&now);
    time_t then = mktime(&current);
    current.tm_year = year - 1900;
    current.tm_mon = month - 1;
    current.tm_mday = day;
    current.tm_hour = hour;
    current.tm_min = minute;
    current.tm_sec = second;
    time_t destination = mktime(&current);
    return difftime(destination, then);
}

// Function to check if a year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0 && year % 100!= 0) {
        return 1;
    } else if (year % 400 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int year, month, day, hour, minute, second;
    int leapYear = 0;
    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the month: ");
    scanf("%d", &month);
    printf("Enter the day: ");
    scanf("%d", &day);
    printf("Enter the hour: ");
    scanf("%d", &hour);
    printf("Enter the minute: ");
    scanf("%d", &minute);
    printf("Enter the second: ");
    scanf("%d", &second);
    if (isLeapYear(year)) {
        leapYear = 1;
    }
    double distance = calculateDistance(year, month, day, hour, minute, second);
    printf("You are about to travel %lf seconds into the future.\n", distance);
    if (leapYear) {
        printf("Please note that you are traveling into a leap year.\n");
    }
    printf("Are you sure you want to proceed? (y/n): ");
    char answer;
    scanf(" %c", &answer);
    if (answer == 'y') {
        printf("Traveling...\n");
        sleep(distance);
        printf("You have arrived in the future!\n");
    } else {
        printf("Aborting time travel.\n");
    }
    return 0;
}