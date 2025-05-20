//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to check if the given date is valid
int isValidDate(int dd, int mm, int yyyy)
{
    // Check if year is valid
    if (yyyy < 1900 || yyyy > 9999)
        return 0;
    
    // Check if month is valid
    if (mm < 1 || mm > 12)
        return 0;

    // Check if day is valid
    if (dd < 1 || dd > 31)
        return 0;
    
    // Check for February month
    if (mm == 2)
    {
        // Check for leap year
        if (yyyy % 400 == 0 || (yyyy % 100 != 0 && yyyy % 4 == 0))
        {
            if (dd > 29)
                return 0;
        }
        else
        {
            if (dd > 28)
                return 0;
        }
    }

    // Check for April, June, September and November months
    if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
    {
        if (dd > 30)
            return 0;
    }

    return 1;
}

// Function to display current date and time
void displayDateTime()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Current date and time: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

int main()
{
    int dd, mm, yyyy;
    char name[100], email[100], mobile[100];
    int option;

    printf("Welcome to the Surrealist Appointment Scheduler!\n");

    while (1)
    {
        printf("\nWhat would you like to do?\n");
        printf("1. Schedule an appointment\n");
        printf("2. Quit\n");

        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("\nEnter your name: ");
                scanf("%s", name);

                printf("Enter your email: ");
                scanf("%s", email);

                printf("Enter your mobile number: ");
                scanf("%s", mobile);

                printf("Enter the date of your appointment (dd mm yyyy): ");
                scanf("%d %d %d", &dd, &mm, &yyyy);

                if (!isValidDate(dd, mm, yyyy))
                {
                    printf("Invalid date! Please try again.\n");
                    break;
                }

                printf("\nCongratulations, %s! Your appointment has been scheduled for %d-%02d-%02d.\n", name, yyyy, mm, dd);
                printf("We will send you an email reminder at %s and a text message at %s.\n", email, mobile);
                displayDateTime();
                break;

            case 2:
                printf("\nThank you for using the Surrealist Appointment Scheduler!\n");
                return 0;

            default:
                printf("\nInvalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}