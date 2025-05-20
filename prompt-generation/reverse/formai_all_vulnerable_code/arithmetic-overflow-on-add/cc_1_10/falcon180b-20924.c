//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the current date and time
void printDateTime() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    printf("Current date and time: %s", asctime(t));
}

// Function to simulate time travel
void timeTravel(int years) {
    time_t seconds = years * 365 * 24 * 60 * 60;
    time_t targetTime = time(NULL) + seconds;
    char targetString[20];
    strftime(targetString, 20, "%Y-%m-%d %H:%M:%S", localtime(&targetTime));
    printf("Time travel initiated. Destination: %s\n", targetString);
}

// Main function
int main() {
    printDateTime();
    int choice;
    do {
        printf("\n");
        printf("1. Print current date and time\n");
        printf("2. Time travel\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printDateTime();
                break;
            case 2:
                printf("Enter the number of years you want to travel: ");
                int years;
                scanf("%d", &years);
                timeTravel(years);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 3);
    return 0;
}