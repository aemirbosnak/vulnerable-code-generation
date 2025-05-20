//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: calm
#include <stdio.h>

int main() {
    int month, day, year, num_days = 0;
    char c;

    printf("Please enter a date in natural language (month day year): ");
    scanf("%d %d %d", &month, &day, &year);

    // Check for leap year
    int is_leap_year = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    // Calculate number of days in previous months
    switch(month) {
        case 1:
            num_days = 0;
            break;
        case 2:
            num_days = 31;
            break;
        case 3:
            num_days = 59;
            break;
        case 4:
            num_days = 90;
            break;
        case 5:
            num_days = 120;
            break;
        case 6:
            num_days = 151;
            break;
        case 7:
            num_days = 181;
            break;
        case 8:
            num_days = 212;
            break;
        case 9:
            num_days = 243;
            break;
        case 10:
            num_days = 273;
            break;
        case 11:
            num_days = 304;
            break;
        case 12:
            num_days = 334;
            break;
        default:
            printf("Invalid month.\n");
            return 0;
    }

    // Add days in current month
    num_days += day;

    // If it's a leap year and after February, add 1 day
    if(is_leap_year && month > 2) {
        num_days++;
    }

    // Print the number of days
    printf("The date %d/%d/%d is the %dth day of the year.\n", month, day, year, num_days);

    return 0;
}