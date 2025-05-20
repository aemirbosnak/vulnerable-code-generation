//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shape shift
void shapeShift(int year){
    switch(year){

        case 2021:
            printf("\nWelcome to the present year %d!\n", year);
            break;
        
        case 1969:
            printf("\nWow, you time travelled back to 1969!\n");
            printf("The Beatles' 'Abbey Road' was just released and Woodstock was happening soon.\n");
            printf("What do you want to do in this time period? (1) Attend Woodstock or (2) Meet The Beatles? \n");
            int choice;
            scanf("%d", &choice);
            if (choice == 1){
                printf("\nAwesome! You're at Woodstock and enjoying the music. \n");
            } else {
                printf("\nYou're backstage meeting The Beatles! \n");
            }
            break;
        
        case 2038:
            printf("\nYou've time travelled to 2038!\n");
            printf("The world is quite different now. We have flying cars and robots everywhere. \n");
            printf("What would you like to see? (1) A flying car show or (2) a robotics convention? \n");
            scanf("%d", &choice);
            if (choice == 1){
                printf("\nYou're at the World Flying Car championships!\n");
            } else {
                printf("\nYou're at the International Robotics Convention!\n");
            }
            break;
        
        case 1492:
            printf("\nYou've travelled back to 1492!\n");
            printf("Columbus just discovered America and Europe is in for some big changes. \n");
            printf("What would you like to do? (1) Explore Americas with Columbus or (2) Meet the Spanish king?\n");
            scanf("%d", &choice);
            if (choice == 1){
                printf("\nAdventure awaits! You're with Christopher Columbus on his first voyage to America. \n");
            } else {
                printf("\nYou're meeting the powerful Spanish King Ferdinand and Queen Isabella!\n");
            }
            break;
        default:
            printf("\nInvalid year entered!\n");
            break;
    }
}

// Main Function
int main(){
    time_t current_time;
    current_time = time(NULL);
    struct tm *tm_ptr;
    tm_ptr = localtime(&current_time);

    // Getting Current Year
    int currYear = tm_ptr->tm_year + 1900;
    printf("Welcome to the Time Travel Simulator!\n");
    printf("You are currently in the year %d. \nEnter a year to time travel to: ", currYear);

    // Getting Year to Time Travel
    int year;
    scanf("%d", &year);

    // Shapeshifting
    shapeShift(year);

    return 0;
}