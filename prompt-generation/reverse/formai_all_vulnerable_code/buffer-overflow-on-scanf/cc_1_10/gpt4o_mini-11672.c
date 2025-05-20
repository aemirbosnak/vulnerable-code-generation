//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void displayTimeline(int year) {
    switch(year) {
        case 2023:
            printf("Welcome to the year 2023! The age of technology and information.\n");
            printf("The current popular technologies include AI and machine learning.\n");
            break;
        case 2000:
            printf("Jumped to the year 2000! It's the dawn of a new millennium.\n");
            printf("Y2K bug fears have ended without incident!\n");
            break;
        case 1990:
            printf("Welcome to 1990! The world is witnessing the early rise of the internet.\n");
            printf("The Berlin Wall has just fallen, changing Europe!\n");
            break;
        case 1985:
            printf("You are in 1985! Big hair, arcade games, and the start of the VHS rental boom.\n");
            printf("Back to the Future has just been released!\n");
            break;
        case 1776:
            printf("Traveling back to 1776! The year of the American Revolution.\n");
            printf("The Declaration of Independence is just being signed!\n");
            break;
        case 1066:
            printf("In 1066, the Battle of Hastings changes the course of English history.\n");
            printf("William the Conqueror has just triumphed!\n");
            break;
        case 4000:
            printf("Welcome to the year 4000! Humanity has colonized Mars and beyond.\n");
            printf("Time travel technology is commonplace!\n");
            break;
        default:
            printf("The year %d is not currently accessible in our system.\n", year);
            break;
    }
}

int isValidYear(int year) {
    return (year >= 4000 || year <= 1066);
}

int main() {
    int year;
    char again;

    printf("=== Time Travel Simulator ===\n");

    do {
        printf("Enter the year you want to travel to (1066 - 4000): ");
        scanf("%d", &year);

        if (isValidYear(year)) {
            displayTimeline(year);
        } else {
            printf("Invalid year! Please try again.\n");
        }

        printf("Do you want to travel to another year? (y/n): ");
        scanf(" %c", &again); // Add a space before %c to consume any leftover newline

    } while (again == 'y' || again == 'Y');

    printf("Thank you for using the Time Travel Simulator! Safe travels!\n");
    return 0;
}