//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    // Initialize variables
    time_t t;
    char response;
    int year;
    struct tm *info;

    // A friendly welcome
    printf("Welcome to the Time Travel Simulator!\n");

    // Ask user for current year
    printf("What year is it currently? ");
    scanf("%d",&year);

    // Print the current year
    printf("The current year is %d.\n",year);

    // Ask user if they want to travel in time
    printf("Do you wish to travel in time? (Y/N) ");
    getchar(); // consume newline character
    scanf("%c",&response);

    if(response == 'Y' || response == 'y'){

        // Ask the user for the year they want to travel to
        printf("What year do you want to travel to? ");
        scanf("%d", &year);

        // Set the time struct to the new year
        info = localtime(&t);
        info->tm_year = year - 1900;
        info->tm_mon = 0;
        info->tm_mday = 1;
        info->tm_hour = 0;
        info->tm_min = 0;
        info->tm_sec = 0;
        info->tm_isdst = -1;

        // Set the new time
        t = mktime(info);

        // Check if the time travel was successful
        if(t == -1){
            printf("Error: invalid date entered.\n");
            exit(EXIT_FAILURE);
        }

        // Print the new year
        printf("The year is now %d.\n",year);

    }else if(response == 'N' || response == 'n'){
      
        // If the user does not want to time travel
        printf("Thank you for using the Time Travel Simulator!\n");

    }else{
      
        // If the user input is invalid
        printf("Error: invalid input entered.\n");
        exit(EXIT_FAILURE);

    }

    return 0;
}