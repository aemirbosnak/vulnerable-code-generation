//Falcon2-11B DATASET v1.0 Category: Time Travel Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int currentTime = time(0);
    printf("Current time: %d\n", currentTime);

    int desiredTime;
    char desiredAction;

    printf("Please enter a time to travel to (between 0 and %d): ", currentTime);
    scanf("%d", &desiredTime);

    printf("Please enter an action to take in that time (A, B, C, D, E, F, G, H): ");
    scanf(" %c", &desiredAction);

    printf("\n");

    switch (desiredAction) {
        case 'A':
            printf("You have traveled to the year %d\n", desiredTime);
            break;
        case 'B':
            printf("You have traveled to the year %d\n", desiredTime);
            break;
        case 'C':
            printf("You have traveled to the year %d\n", desiredTime);
            break;
        case 'D':
            printf("You have traveled to the year %d\n", desiredTime);
            break;
        case 'E':
            printf("You have traveled to the year %d\n", desiredTime);
            break;
        case 'F':
            printf("You have traveled to the year %d\n", desiredTime);
            break;
        case 'G':
            printf("You have traveled to the year %d\n", desiredTime);
            break;
        case 'H':
            printf("You have traveled to the year %d\n", desiredTime);
            break;
        default:
            printf("Invalid action. Please try again.\n");
            break;
    }

    printf("Do you want to travel to another time? (Y/N)");
    char response;
    scanf(" %c", &response);
    if (response == 'Y') {
        printf("Enter a new time to travel to: ");
        scanf("%d", &desiredTime);
        printf("Enter an action to take in that time: ");
        scanf(" %c", &desiredAction);
    } else {
        printf("Thank you for using the Time Travel Simulator.\n");
    }

    return 0;
}