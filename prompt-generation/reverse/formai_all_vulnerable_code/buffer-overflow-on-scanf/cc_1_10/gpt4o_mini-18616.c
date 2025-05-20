//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>

void displayEvent(int year) {
    switch (year) {
        case 1969:
            printf("You are in 1969! Witness the first Moon landing!\n");
            break;
        case 1776:
            printf("You are in 1776! Experience the signing of the Declaration of Independence!\n");
            break;
        case 1989:
            printf("You are in 1989! See the fall of the Berlin Wall!\n");
            break;
        case 2001:
            printf("You are in 2001! Understand the impact of September 11 on the world!\n");
            break;
        case 2020:
            printf("You are in 2020! Navigate through a pandemic that changed the world!\n");
            break;
        case 2500:
            printf("You are in 2500! Look at how technology has revolutionized life!\n");
            break;
        default:
            printf("The year %d has no significant event recorded in this simulator.\n", year);
            break;
    }
}

void timeTravel(int year) {
    if (year < 1900) {
        printf("This simulation does not support years before 1900.\n");
        return;
    } else if (year > 2500) {
        printf("This simulation does not support years beyond 2500.\n");
        return;
    }

    printf("Initiating time travel...\n");
    displayEvent(year);
    printf("You have experienced an event in year %d!\n", year);

    // Ask if the user wants to go to another year
    int newYear;
    printf("Enter another year to visit (or 0 to exit): ");
    scanf("%d", &newYear);
    if (newYear != 0) {
        timeTravel(newYear);
    } else {
        printf("Thank you for using the Time Travel Simulator! Goodbye!\n");
    }
}

int main() {
    int initialYear;
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter a year between 1900 and 2500 to begin your journey: ");
    scanf("%d", &initialYear);
    
    // Start the time travel simulation
    timeTravel(initialYear);

    return 0;
}