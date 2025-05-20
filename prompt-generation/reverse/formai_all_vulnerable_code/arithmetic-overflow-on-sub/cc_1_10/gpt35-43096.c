//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //initialize time variables
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    int current_year = local->tm_year + 1900;
    
    //get user input for desired year
    int desired_year;
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the year you would like to travel to (must be a past year): ");
    scanf("%d", &desired_year);
    
    //check if desired year is valid and in the past
    if (desired_year >= current_year || desired_year < 0) {
        printf("Invalid year. You can only travel to a year in the past!\n");
        return 0;
    }
    
    //calculate time travel difference and set new time variables
    int time_diff = current_year - desired_year;
    struct tm travel_time = *local;
    travel_time.tm_year -= time_diff;
    time_t travel_time_t = mktime(&travel_time);
    
    //print time travel details
    printf("Time travel successful! You have traveled back %d years to the year %d.\n", time_diff, desired_year);
    printf("Here are some details about the time period:\n");
    printf("------------------------------------------------\n");
    printf("Year: %d\n", desired_year);
    printf("Number of years since AD 1: %d\n", desired_year - 1);
    printf("Number of years until the next Leap Year: %d\n", (4 - desired_year % 4) % 4);
    
    //generate random historical event
    srand(time(NULL)); //initialize random seed
    int event_num = rand() % 5;
    printf("Random historical event: ");
    switch(event_num) {
        case 0:
            printf("Julius Caesar is assassinated.\n");
            break;
        case 1:
            printf("Christopher Columbus discovers America.\n");
            break;
        case 2:
            printf("The Industrial Revolution begins.\n");
            break;
        case 3:
            printf("The American Civil War begins.\n");
            break;
        case 4:
            printf("The first successful airplane flight is made by the Wright Brothers.\n");
            break;
    }
    
    //return to present time
    printf("\nReturning to present time...\n");
    sleep(2); //pause for dramatic effect
    printf("You have returned to the present day. Thank you for using the Time Travel Simulator!\n");
    
    return 0;
}