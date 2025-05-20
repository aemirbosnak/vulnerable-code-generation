//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    int year, month, day;
    int destinationYear, destinationMonth, destinationDay;
    int timeTravelDuration;
    int currentYear = 2021;
    int currentMonth = 1;
    int currentDay = 1;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please choose a destination:\n");
    printf("1. Ancient Egypt\n");
    printf("2. Medieval Europe\n");
    printf("3. The Future\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You have chosen Ancient Egypt.\n");
            destinationYear = 2500;
            destinationMonth = 1;
            destinationDay = 1;
            printf("Enter the duration of your time travel (in days): ");
            scanf("%d", &timeTravelDuration);
            break;
        case 2:
            printf("You have chosen Medieval Europe.\n");
            destinationYear = 1500;
            destinationMonth = 1;
            destinationDay = 1;
            printf("Enter the duration of your time travel (in days): ");
            scanf("%d", &timeTravelDuration);
            break;
        case 3:
            printf("You have chosen The Future.\n");
            destinationYear = 3000;
            destinationMonth = 1;
            destinationDay = 1;
            printf("Enter the duration of your time travel (in days): ");
            scanf("%d", &timeTravelDuration);
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }

    for(int i=0; i<timeTravelDuration; i++) {
        currentYear += 1;
        currentMonth += 1;
        if(currentMonth == 13) {
            currentMonth = 1;
            currentYear += 1;
        }
        currentDay += 1;
        if(currentDay > 28 && currentMonth!= 2) {
            currentDay = 1;
            currentMonth += 1;
        }
        if(currentMonth == 2 && currentDay > 28) {
            currentDay = 1;
            currentMonth += 1;
            if(currentMonth == 13) {
                currentMonth = 1;
                currentYear += 1;
            }
        }
        printf("%d-%d-%d\n", currentYear, currentMonth, currentDay);
    }

    printf("You have arrived in the year %d.\n", destinationYear);
    printf("Enjoy your stay!\n");

    return 0;
}