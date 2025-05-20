//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

// Function declaration
bool is_leap_year(int year);
int number_of_days_in_month(int month, int year);
void print_date(int day, int month, int year);

int main()
{
    int current_day, current_month, current_year;
    printf("Enter the current date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &current_day, &current_month, &current_year);
    printf("\n");

    int days_to_travel;
    printf("Enter the number of days to travel: ");
    scanf("%d", &days_to_travel);
    printf("\n");

    // Travel in Time!
    for (int i = 0; i < days_to_travel; i++)
    {
        current_day++;
        // Check if current day exceeds number of days in current month
        int days_in_current_month = number_of_days_in_month(current_month, current_year);
        if (current_day > days_in_current_month)
        {
            current_day = 1;
            current_month++;
            // Check if current month exceeds 12 (December)
            if (current_month > 12)
            {
                current_month = 1;
                current_year++;
            }
        }
    }

    printf("You have travelled in time by %d days.\n", days_to_travel);
    print_date(current_day, current_month, current_year);
    printf("\n");

    return 0;
}

// Function to check if a given year is a leap year or not
bool is_leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Function to return number of days in a given month and year
int number_of_days_in_month(int month, int year)
{
    switch (month)
    {
        case 1:
            return 31;
        case 2:
            if (is_leap_year(year))
            {
                return 29;
            }
            else
            {
                return 28;
            }
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return 0;
    }
}

// Function to print the given date in DD/MM/YYYY format
void print_date(int day, int month, int year)
{
    printf("The date after time travel is: %02d/%02d/%04d\n", day, month, year);
}