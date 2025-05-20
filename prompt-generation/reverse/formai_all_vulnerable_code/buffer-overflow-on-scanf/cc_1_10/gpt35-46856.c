//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// function prototypes
void print_menu();
void travel_backwards_in_time();
void travel_forwards_in_time();

int main()
{
    // initialize current time variable
    time_t current_time = time(NULL);

    // display welcome message
    printf("\nWelcome to the Time Travel Simulator\n");
    printf("====================================\n");

    // loop until user decides to exit
    bool exit = false;
    while (!exit)
    {
        // display menu
        print_menu();

        // get user input
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // perform action based on user choice
        switch (choice)
        {
            case 1:
                travel_backwards_in_time(&current_time);
                break;
            case 2:
                travel_forwards_in_time(&current_time);
                break;
            case 3:
                exit = true;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    printf("Thank you for using the Time Travel Simulator!\n");

    return 0;
}

// function to display menu
void print_menu()
{
    printf("\nMAIN MENU\n");
    printf("=========  ========================\n");
    printf("1. Backwards in Time  2. Forwards in Time\n");
    printf("3. Exit               \n");
    printf("====================================\n");
}

// function to travel backwards in time
void travel_backwards_in_time(time_t *current_time)
{
    // get time travel input from user
    int years, months, days;
    printf("\nBACKWARDS IN TIME\n");
    printf("=================\n");
    printf("Enter number of years to travel back: ");
    scanf("%d", &years);
    printf("Enter number of months to travel back: ");
    scanf("%d", &months);
    printf("Enter number of days to travel back: ");
    scanf("%d", &days);

    // calculate new time
    struct tm *new_time = localtime(current_time);
    new_time->tm_year -= years;
    new_time->tm_mon -= months;
    new_time->tm_mday -= days;
    time_t new_time_t = mktime(new_time);

    // display new time
    printf("\nYou have traveled back in time to:\n");
    printf("%s", ctime(&new_time_t));

    // update current time
    *current_time = new_time_t;
}

// function to travel forwards in time
void travel_forwards_in_time(time_t *current_time)
{
    // get time travel input from user
    int years, months, days;
    printf("\nFORWARDS IN TIME\n");
    printf("=================\n");
    printf("Enter number of years to travel forward: ");
    scanf("%d", &years);
    printf("Enter number of months to travel forward: ");
    scanf("%d", &months);
    printf("Enter number of days to travel forward: ");
    scanf("%d", &days);

    // calculate new time
    struct tm *new_time = localtime(current_time);
    new_time->tm_year += years;
    new_time->tm_mon += months;
    new_time->tm_mday += days;
    time_t new_time_t = mktime(new_time);

    // display new time
    printf("\nYou have traveled forward in time to:\n");
    printf("%s", ctime(&new_time_t));

    // update current time
    *current_time = new_time_t;
}