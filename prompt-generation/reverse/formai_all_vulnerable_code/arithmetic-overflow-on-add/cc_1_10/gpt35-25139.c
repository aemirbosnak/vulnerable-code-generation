//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: rigorous
/* Time Travel Simulator */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Function to get current year
int getCurrentYear() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    return tm->tm_year + 1900;
}

// Function to get a random year between 1900 and the current year
int getRandomYear() {
    int currentYear = getCurrentYear();
    return (rand() % (currentYear - 1900 + 1)) + 1900;
}

// Function to get a random month between 1 and 12
int getRandomMonth() {
    return (rand() % 12) + 1;
}

// Function to get a random day based on the month and year
int getRandomDay(int year, int month) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int numDays = daysInMonth[month - 1];
    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        numDays = 29;
    }
    return (rand() % numDays) + 1;
}

// Function to print the date in a nice format
void printDate(int day, int month, int year) {
    char *monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("%d %s %d\n", day, monthNames[month - 1], year);
}

// Main function to generate time travel simulations
int main() {
    srand(time(NULL));
    int startYear = getRandomYear();
    int startMonth = getRandomMonth();
    int startDay = getRandomDay(startYear, startMonth);
    int endYear = getRandomYear();
    int endMonth = getRandomMonth();
    int endDay = getRandomDay(endYear, endMonth);

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("You have been randomly selected to travel back in time from ");
    printDate(endDay, endMonth, endYear);
    printf("to ");
    printDate(startDay, startMonth, startYear);
    printf("Please enjoy your journey!\n");

    // Simulation loop
    int currentYear = endYear;
    int currentMonth = endMonth;
    int currentDay = endDay;
    while (currentYear < startYear || (currentYear == startYear && (currentMonth < startMonth || (currentMonth == startMonth && currentDay < startDay)))) {
        printf("\n\nOn ");
        printDate(currentDay, currentMonth, currentYear);

        // Simulate random events
        int event = rand() % 3;
        if (event == 0) {
            printf("You witness a historic event!\n");
        } else if (event == 1) {
            printf("You meet a famous person!\n");
        } else {
            printf("You narrowly escape a dangerous situation!\n");
        }

        // Advance to the next day
        currentDay++;
        if (currentDay > getRandomDay(currentYear, currentMonth)) {
            currentDay = 1;
            currentMonth++;
            if (currentMonth > 12) {
                currentMonth = 1;
                currentYear++;
            }
        }
    }

    printf("\n\nYour journey through time has ended. Welcome back to the present day!\n");

    return 0;
}