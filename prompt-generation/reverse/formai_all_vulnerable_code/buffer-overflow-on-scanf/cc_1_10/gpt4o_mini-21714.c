//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void display_intro() {
    printf("=======================================\n");
    printf("           Time Travel Simulator       \n");
    printf("            (Version 1.0)            \n");
    printf("=======================================\n");
    sleep(1);
    printf("Prepare for an adventure through time!\n");
    sleep(1);
}

void travel_to_year(int year) {
    sleep(1);
    printf("Initiating time travel...\n");
    sleep(2); // Dramatic pause
    printf("Aligning temporal coordinates...\n");
    sleep(2);
    printf("Warping through the space-time continuum...\n");
    sleep(2);
    printf("You have arrived in the year %d!\n", year);
}

void display_year_info(int year) {
    // Simulating year events
    if (year < 0) {
        printf("Oops! You have traveled to a time before recorded history!\n");
    } else if (year < 1000) {
        printf("Welcome to the Middle Ages! Knights and castles await you!\n");
    } else if (year < 1500) {
        printf("It's the Renaissance! Art and culture are booming!\n");
    } else if (year < 1800) {
        printf("Industrial Revolution is on the horizon. Be prepared for change!\n");
    } else if (year < 2000) {
        printf("Welcome to the modern era! Technology is advancing fast!\n");
    } else {
        printf("You've jumped into the future! What awaits in the unknown?\n");
    }
}

void display_farewell() {
    printf("Thank you for using the Time Travel Simulator!\n");
    printf("Remember: Time is of the essence!\n");
    sleep(1);
    printf("=======================================\n");
}

int main() {
    int year = 0;
    
    display_intro();

    printf("Enter the year you want to travel to: ");
    scanf("%d", &year);

    // Validate input
    if (year >= 0) {
        travel_to_year(year);
        display_year_info(year);
    } else {
        printf("Invalid year! Please enter a year greater than or equal to 0.\n");
    }

    display_farewell();
    return 0;
}