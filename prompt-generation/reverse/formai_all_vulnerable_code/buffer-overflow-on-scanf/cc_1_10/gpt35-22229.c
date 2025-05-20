//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize random seed
    srand(time(NULL));

    // prompt user for year
    int currentYear, travelYear;
    printf("What is the current year? ");
    scanf("%d", &currentYear);
    printf("What year do you want to travel to? ");
    scanf("%d", &travelYear);

    // calculate time difference
    int timeDiff = abs(travelYear - currentYear);

    // check if time travel is possible
    if (travelYear < 0 || travelYear > 3000) {
        printf("Sorry, time travel is not possible.\n");
        return 0;
    }

    // determine if time travel is to the past or future
    if (travelYear < currentYear) {
        printf("You are traveling back in time...\n");
    } else {
        printf("You are traveling into the future...\n");
    }

    // set initial location
    char location[20] = "earth";

    // simulate time travel
    for (int i = 1; i <= timeDiff; i++) {

        // update year
        if (travelYear < currentYear) {
            currentYear--;
        } else {
            currentYear++;
        }

        // randomly change location
        int randNum = rand() % 3;
        if (randNum == 0) {
            strcpy(location, "mars");
        } else if (randNum == 1) {
            strcpy(location, "moon");
        } else {
            strcpy(location, "earth");
        }

        // print current status
        printf("Year: %d. Location: %s\n", currentYear, location);
    }

    return 0;
}