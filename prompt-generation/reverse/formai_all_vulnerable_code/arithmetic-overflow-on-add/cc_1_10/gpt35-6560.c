//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to display the menu
void displayMenu() {
    printf("\n--- Time Travel Simulator ---\n");
    printf("1. Time travel to the future\n");
    printf("2. Time travel to the past\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
}

// function to get a random year between 2021 and 2121
int getRandomYear() {
    return (rand() % 101) + 2021;
}

// function to travel to the future
void travelToFuture() {
    // get the current time
    time_t currentTime = time(NULL);

    // add 10 years to the current time
    currentTime += (10 * 365 * 24 * 60 * 60);

    // get the year of the future time
    struct tm *futureTime = localtime(&currentTime);
    int year = futureTime->tm_year + 1900;

    // display the future year
    printf("You have time traveled to the year %d.\n", year);
}

// function to travel to the past
void travelToPast() {
    // get a random year between 2021 and 2121
    int year = getRandomYear();

    // convert the year to a timestamp
    struct tm timeData = {0};
    timeData.tm_year = year - 1900;
    timeData.tm_mday = 1;
    time_t pastTime = mktime(&timeData);

    // get the year of the past time
    struct tm *pastTimeInfo = localtime(&pastTime);
    year = pastTimeInfo->tm_year + 1900;

    // display the past year
    printf("You have time traveled to the year %d.\n", year);
}

// main function
int main() {
    int choice;

    // seed the random number generator with the current time
    srand(time(NULL));

    // welcome message
    printf("Welcome to the Time Travel Simulator!\n");

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                travelToFuture();
                break;
            case 2:
                travelToPast();
                break;
            case 3:
                printf("Thank you for using the Time Travel Simulator!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}