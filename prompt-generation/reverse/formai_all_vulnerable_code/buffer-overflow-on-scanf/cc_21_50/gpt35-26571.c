//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice, year;
    int event_years[5] = {1066, 1776, 1969, 2001, 2020};
    char event_names[5][100] = {"The Battle of Hastings", "The American Revolution", "The Moon Landing", "9/11 Attacks", "COVID-19 Pandemic"};
    
    srand(time(0)); // To generate a random value

    printf("Welcome to the time travel simulator!\n\n");
    printf("Choose an option:\n");
    printf("1) Travel to a random year\n");
    printf("2) Choose a specific year\n");
    printf("3) Exit\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            year = rand() % 2022; // To generate a random year between 0-2022
            printf("\nTravelling to the year %d\n", year);
            if(year < event_years[0])
            {
                printf("You have travelled back to a time when the concept of recorded history hadn't even been discovered yet!\n");
            }
            else if(year >= event_years[0] && year < event_years[1])
            {
                printf("You have travelled back to the %d's when the world was a very different place.", event_years[0]);
            }
            else if(year >= event_years[1] && year < event_years[2])
            {
                printf("You have travelled back to the year %d when the United States declared independence from Great Britain.", event_years[1]);
            }
            else if(year >= event_years[2] && year < event_years[3])
            {
                printf("You have travelled back to the year %d when Neil Armstrong and Buzz Aldrin became the first humans to land on the moon.", event_years[2]);
            }
            else if(year >= event_years[3] && year < event_years[4])
            {
                printf("You have travelled back to the year %d, a year that will forever be remembered as a dark day in history.", event_years[3]);
            }
            else
            {
                printf("You have travelled back to the year %d, a year when the world was gripped by a deadly pandemic.", event_years[4]);
            }
            break;
        
        case 2:
            printf("\nEnter a year between 0-2021: ");
            scanf("%d", &year);
            printf("\nTravelling to the year %d\n", year);
            if(year < event_years[0])
            {
                printf("You have travelled back to a time when the concept of recorded history hadn't even been discovered yet!\n");
            }
            else if(year >= event_years[0] && year < event_years[1])
            {
                printf("You have travelled back to the %d's when the world was a very different place.", event_years[0]);
            }
            else if(year >= event_years[1] && year < event_years[2])
            {
                printf("You have travelled back to the year %d when the United States declared independence from Great Britain.", event_years[1]);
            }
            else if(year >= event_years[2] && year < event_years[3])
            {
                printf("You have travelled back to the year %d when Neil Armstrong and Buzz Aldrin became the first humans to land on the moon.", event_years[2]);
            }
            else if(year >= event_years[3] && year < event_years[4])
            {
                printf("You have travelled back to the year %d, a year that will forever be remembered as a dark day in history.", event_years[3]);
            }
            else
            {
                printf("You have travelled back to the year %d, a year when the world was gripped by a deadly pandemic.", event_years[4]);
            }
            break;
            
        case 3:
            printf("\nThank you for using the time travel simulator!\n");
            exit(0);
        
        default:
            printf("\nInvalid choice! Please try again.\n");
            break;
    }
    return 0;
}