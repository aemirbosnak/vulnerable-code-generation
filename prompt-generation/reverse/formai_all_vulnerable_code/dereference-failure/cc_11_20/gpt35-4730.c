//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t currentTime;
    struct tm *timeinfo;
    int year, month, day;

    // Get current time
    time(&currentTime);
    timeinfo = localtime(&currentTime);

    // Get current year, month and day
    year = timeinfo->tm_year + 1900;
    month = timeinfo->tm_mon + 1;
    day = timeinfo->tm_mday;

    // Print current date
    printf("Current date: %d-%d-%d\n", year, month, day);

    // Obtain user input
    int futureYear, futureMonth, futureDay;
    printf("Enter a future year: ");
    scanf("%d", &futureYear);
    printf("Enter a future month (1-12): ");
    scanf("%d", &futureMonth);
    printf("Enter a future day (1-31): ");
    scanf("%d", &futureDay);

    // Check if future date is valid
    if(futureYear < year || (futureYear == year && futureMonth < month) || (futureYear == year && futureMonth == month && futureDay <= day)) {
        printf("Invalid date! Please enter a future date.\n");
        return 0;
    }

    // Calculate years, months and days between current date and future date
    int years = futureYear - year;
    int months = futureMonth - month;
    int days = futureDay - day;
    if(days < 0) {
        months--;
        int numberOfDaysInPreviousMonth;
        switch(month) {
            case 2:
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
                    numberOfDaysInPreviousMonth = 29;
                } else {
                    numberOfDaysInPreviousMonth = 28;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                numberOfDaysInPreviousMonth = 30;
                break;
            default:
                numberOfDaysInPreviousMonth = 31;
        }
        days += numberOfDaysInPreviousMonth;
    }
    if(months < 0) {
        years--;
        months += 12;
    }

    // Print time travel summary
    printf("\nTime travel summary:\n\n");
    printf("Current date: %d-%d-%d\n", year, month, day);
    printf("Future date: %d-%d-%d\n", futureYear, futureMonth, futureDay);
    printf("Years travelled: %d\n", years);
    printf("Months travelled: %d\n", months);
    printf("Days travelled: %d\n", days);

    return 0;
}