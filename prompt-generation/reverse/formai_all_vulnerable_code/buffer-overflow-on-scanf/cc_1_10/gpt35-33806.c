//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// function to capitalize first letter of a string
void capitalize(char *string)
{
    if(string[0] >= 'a' && string[0] <= 'z')
    {
        string[0] -= 32;   // ASCII value of 'a' is 97 and 'A' is 65, so subtract 32 to capitalize
    }
}

int main()
{
    int choice = 0;
    bool running = true;
    char name[20];
    char date[20];
    char time[20];
    char confirm[5];
    
    printf("Welcome to the Appointment Scheduler!\n");
    
    // run the program until user decides to quit
    while(running)
    {
        printf("\nWhat would you like to do?\n");
        printf("1. Schedule appointment\n");
        printf("2. View existing appointments\n");
        printf("3. Cancel appointment\n");
        printf("4. Quit\n");
        scanf("%d", &choice);
        
        // schedule appointment
        if(choice == 1)
        {
            printf("\nPlease enter your name: ");
            scanf("%s", name);
            capitalize(name);  // capitalize first letter of name
            
            printf("Please enter the date of your appointment (MM/DD/YYYY): ");
            scanf("%s", date);
            
            printf("Please enter the time of your appointment (HH:MM AM/PM): ");
            scanf("%s", time);
            
            printf("\nYour appointment has been scheduled for %s at %s on %s.\n", time, date, name);
            
            printf("\nWould you like to confirm your appointment? (Y/N): ");
            scanf("%s", confirm);
            capitalize(confirm);    // capitalize first letter of confirmation
            
            if(strcmp(confirm, "Y") == 0 || strcmp(confirm, "YES") == 0)
            {
                printf("Your appointment has been confirmed.\n");
            }
            else
            {
                printf("Your appointment has NOT been confirmed.\n");
            }
        }
        // view existing appointments
        else if(choice == 2)
        {
            printf("\nThese are the existing appointments:\n");
            printf("1. John Smith, 08/15/2021, 10:30 AM\n");
            printf("2. Jane Doe, 09/01/2021, 2:00 PM\n");
            printf("3. Bob Johnson, 09/15/2021, 11:15 AM\n");
        }
        // cancel appointment
        else if(choice == 3)
        {
            printf("\nPlease enter your name: ");
            scanf("%s", name);
            capitalize(name);    // capitalize first letter of name
            
            printf("Please enter the date of your appointment (MM/DD/YYYY): ");
            scanf("%s", date);
            
            printf("\nYour appointment on %s has been cancelled.\n", date);
        }
        // quit
        else if(choice == 4)
        {
            printf("\nThank you for using the Appointment Scheduler!\n");
            running = false;
        }
        // invalid input
        else
        {
            printf("\nInvalid input. Please try again.\n");
        }
    }
    
    return 0;
}