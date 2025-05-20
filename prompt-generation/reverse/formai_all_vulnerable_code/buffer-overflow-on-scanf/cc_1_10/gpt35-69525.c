//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Function prototypes */
void display_menu();
int get_choice();
void travel_forward(int *year, int *month, int *day);
void travel_backward(int *year, int *month, int *day);
bool is_leap_year(int year);
int get_days_in_month(int month, bool leap_year);

int main()
{
    int year = 2021, month = 9, day = 15;
    
    display_menu();
    int choice = get_choice();
    
    while(choice != 3)
    {
        switch(choice)
        {
            case 1:
                travel_forward(&year, &month, &day);
                break;
            case 2:
                travel_backward(&year, &month, &day);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        display_menu();
        choice = get_choice();
    }
    
    printf("Goodbye!\n");
    return 0;
}

/* Displays the menu */
void display_menu()
{
    printf("\n====== Time Travel Simulator ======\n");
    printf("1. Travel forward in time\n");
    printf("2. Travel backward in time\n");
    printf("3. Exit\n");
}

/* Gets the user's menu choice */
int get_choice()
{
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

/* Advances the date by one day */
void travel_forward(int *year, int *month, int *day)
{
    int days_in_month = get_days_in_month(*month, is_leap_year(*year));
    
    if(*day < days_in_month)
    {
        (*day)++;
    }
    else
    {
        *day = 1;
        if(*month == 12)
        {
            *month = 1;
            (*year)++;
        }
        else
        {
            (*month)++;
        }
    }
    
    printf("\nTraveled one day forward.\n");
    printf("New date: %02d/%02d/%d\n", *month, *day, *year);
}

/* Reverses the date by one day */
void travel_backward(int *year, int *month, int *day)
{
    if(*day > 1)
    {
        (*day)--;
    }
    else
    {
        if(*month == 1)
        {
            *month = 12;
            (*year)--;
        }
        else
        {
            (*month)--;
        }
        
        int days_in_month = get_days_in_month(*month, is_leap_year(*year));
        *day = days_in_month;
    }
    
    printf("\nTraveled one day backward.\n");
    printf("New date: %02d/%02d/%d\n", *month, *day, *year);
}

/* Determines whether a year is a leap year */
bool is_leap_year(int year)
{
    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if(year % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

/* Gets the number of days in a given month */
int get_days_in_month(int month, bool leap_year)
{
    switch(month)
    {
        case 1:
            return 31;
        case 2:
            if(leap_year)
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