//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int presentYear, targetYear, option;
    time_t t = time(NULL);
    struct tm *timePointer = localtime(&t);
    presentYear = timePointer->tm_year + 1900;

    printf("Welcome to Time Travel Simulator!\n\n");
    
    do
    {
        printf("Enter target year: ");
        scanf("%d", &targetYear);

        if (targetYear < presentYear)
            printf("We're sorry, we cannot travel back in time.\n\n");
    } while (targetYear < presentYear);

    printf("\nYou have selected the year %d.\n\n", targetYear);

    printf("Please choose a time of day:\n1. Morning\n2. Afternoon\n3. Evening\n");
    scanf("%d", &option);

    switch (option)
    {
        case 1:
            printf("\nYou have arrived in the year %d, in the morning.\n\n", targetYear);
            break;
        
        case 2:
            printf("\nYou have arrived in the year %d, in the afternoon.\n\n", targetYear);
            break;
        
        case 3:
            printf("\nYou have arrived in the year %d, in the evening.\n\n", targetYear);
            break;

        default:
            printf("\nInvalid option. You have arrived in the year %d, at an unknown time of day.\n\n", targetYear);
            break;  
    }
    
    printf("Thank you for using Time Travel Simulator!\n");

    return 0;
}