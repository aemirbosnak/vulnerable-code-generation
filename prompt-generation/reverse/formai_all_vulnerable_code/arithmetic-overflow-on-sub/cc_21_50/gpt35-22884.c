//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define YEAR 365
#define MONTH 30
#define DAY 24

int main()
{
    int currentYear, currentMonth, currentDay;
    int futureYear, futureMonth, futureDay;
    int currentDays, futureDays;
    int leapYear = 0;
    int totalDays = 0;
    int years = 0, months = 0, days = 0;

    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    currentYear = local->tm_year + 1900;
    currentMonth = local->tm_mon + 1;
    currentDay = local->tm_mday;

    printf("Welcome to the Time Travel Simulator\n\n");

    printf("Enter year you want to travel to: ");
    scanf("%d", &futureYear);
    printf("Enter month you want to travel to: ");
    scanf("%d", &futureMonth);
    printf("Enter day you want to travel to: ");
    scanf("%d", &futureDay);

    if (futureYear > currentYear) {
        years = futureYear - currentYear;
        currentDays = (YEAR - (currentMonth * MONTH) - currentDay);
        totalDays += currentDays;
        currentYear++;

        for (int i = 0; i < years; i++) {
            if ((currentYear % 4 == 0 && currentYear % 100 != 0) || (currentYear % 400 == 0)) {
                totalDays += 366;
                leapYear++;
            } else {
                totalDays += 365;
            }
            currentYear++;
        }
        totalDays += (futureMonth * MONTH) + futureDay;
    } else if (futureYear < currentYear) {
        years = currentYear - futureYear;
        futureDays = (YEAR - (futureMonth * MONTH) - futureDay);
        totalDays += futureDays;
        futureYear++;

        for (int i = 0; i < years; i++) {
            if ((futureYear % 4 == 0 && futureYear % 100 != 0) || (futureYear % 400 == 0)) {
                totalDays += 366;
                leapYear++;
            } else {
                totalDays += 365;
            }
            futureYear++;
        }
        totalDays -= ((13 - currentMonth) * MONTH) + currentDay;
    } else {
        if (futureMonth > currentMonth) {
            months = futureMonth - currentMonth;
            currentDays = (YEAR - (currentMonth * MONTH) - currentDay);
            totalDays += currentDays;

            for (int i = 1; i <= months; i++) {
                if (i == 2) {
                    if ((currentYear % 4 == 0 && currentYear % 100 != 0) || (currentYear % 400 == 0)) {
                        totalDays += 29;
                    } else {
                        totalDays += 28;
                    }
                } else if (i == 4 || i == 6 || i == 9 || i == 11) {
                    totalDays += 30;
                } else {
                    totalDays += 31;
                }
            }

            totalDays += futureDay;
        } else if (futureMonth < currentMonth) {
            months = currentMonth - futureMonth;
            futureDays = (YEAR - (futureMonth * MONTH) - futureDay);
            totalDays += futureDays;

            for (int i = 1; i <= months; i++) {
                if (currentMonth == 2) {
                    if ((currentYear % 4 == 0 && currentYear % 100 != 0) || (currentYear % 400 == 0)) {
                        totalDays += 29;
                    } else {
                        totalDays += 28;
                    }
                } else if (currentMonth == 4 || currentMonth == 6 || currentMonth == 9 || currentMonth == 11) {
                    totalDays += 30;
                } else {
                    totalDays += 31;
                }
                currentMonth--;
            }

            totalDays -= currentDay;
            totalDays += futureDay;
        } else {
            if (futureDay > currentDay) {
                totalDays += (futureDay - currentDay);
            } else {
                totalDays -= (currentDay - futureDay);
            }
        }
    }

    years = (totalDays - (totalDays % YEAR)) / YEAR;
    totalDays -= (years * YEAR);

    months = (totalDays - (totalDays % MONTH)) / MONTH;
    totalDays -= (months * MONTH);

    days = (totalDays - (totalDays % DAY)) / DAY;

    printf("You have travelled back or forward in time by: %d years, %d months, and %d days\n", years, months, days);
    printf("You travelled through %d leap years!\n", leapYear);

    return 0;
}