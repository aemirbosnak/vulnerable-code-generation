//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("Welcome to the Time Travel Simulator! \n\n");
    printf("You have just made a time machine out of a toaster. \n");
    printf("Enter a year in the past to travel to: \n");

    int year;
    scanf("%d", &year);

    time_t current_time;
    struct tm * time_info;
    char time_string[50];

    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_string, 50, "%Y", time_info);

    int current_year = atoi(time_string);

    if(year > current_year) {
        printf("You can't travel to the future!\n");
        return 0;
    }
    else if(year < 0) {
        printf("You can't travel before the year 0!\n");
        return 0;
    }

    int difference = current_year - year;

    printf("\n\nYou activate the toaster and are transported ");
    printf("%d years into the past...\n\n", difference);

    printf("You find yourself in a strange land filled with surreal creatures. ");
    printf("There are trees with arms instead of branches and flowers that sing. ");
    printf("You look down and your body has transformed into a winged creature unlike anything you've ever seen. ");

    printf("\n\nYou fly over a rainbow and discover a city made entirely out of candy. ");
    printf("There are gingerbread houses and lollipop trees and everything smells like sugar. ");

    printf("\n\nIn the distance you see a giant clock made of ice. ");
    printf("It's frozen in time and you see people trapped inside trying to break free. ");

    printf("\n\nYou realize that you have the power to control time. ");
    printf("You snap your wings and time goes backwards. ");
    printf("The clock melts and the people are freed. ");

    printf("\n\nYou decide to stay in this surreal world forever, ");
    printf("flying amongst the candy clouds and exploring the strange landscapes. ");
    printf("You are the master of time and anything is possible. ");

    printf("\n\nThanks for using the Time Travel Simulator!\n");
    return 0;
}