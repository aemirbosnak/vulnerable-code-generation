//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int choice;
    printf("Welcome to the Time Travel Simulator!\n");
    printf("1. Travel to the past\n2. Travel to the future\n3. Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        {
            printf("Enter the year you want to travel back to (between 1900 and 2021): ");
            int year;
            scanf("%d",&year);
            if(year>=1900 && year<=2021)
            {
                printf("You have successfully traveled back to the year %d!",year);
            }
            else
            {
                printf("Invalid year! Please try again.");
            }
            break;
        }
        case 2:
        {
            printf("Enter the year you want to travel to (between 2021 and 2100): ");
            int year;
            scanf("%d",&year);
            if(year>=2021 && year<=2100)
            {
                printf("You have successfully traveled to the year %d!",year);
            }
            else
            {
                printf("Invalid year! Please try again.");
            }
            break;
        }
        case 3:
        {
            printf("Exiting program...\n");
            exit(0);
        }
        default:
        {
            printf("Invalid choice! Please try again.");
        }
    }
    return 0;
}