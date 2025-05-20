//Falcon2-11B DATASET v1.0 Category: Time Travel Simulator ; Style: peaceful
#include <stdio.h>
#include <time.h>

// Function to display a peaceful environment
void displayPeacefulEnvironment() {
    printf("You are surrounded by lush green trees and a gentle breeze blowing through them.\n");
    printf("The sun is shining brightly, casting a warm glow over the peaceful surroundings.\n");
    printf("You hear the sound of birds chirping and a nearby stream flowing gently.\n");
    printf("This is a peaceful time and a moment of tranquility.\n");
}

// Function to travel to a different point in time
void travelToTime(int year) {
    printf("You have traveled to the year %d.\n", year);
    printf("You are standing in a field of wildflowers, with a gentle breeze blowing through them.\n");
    printf("The sun is setting on the horizon, casting a warm orange glow over the peaceful surroundings.\n");
    printf("You hear the sound of crickets chirping and a nearby river flowing gently.\n");
    printf("This is a peaceful time and a moment of tranquility.\n");
}

// Function to interact with the environment
void interactWithEnvironment(int option) {
    if (option == 1) {
        printf("You walk towards the nearby stream and take a sip of the cool, refreshing water.\n");
    } else if (option == 2) {
        printf("You lie down on the soft grass and watch the clouds drift by in the clear blue sky.\n");
    } else if (option == 3) {
        printf("You climb up a nearby hill and enjoy the panoramic view of the peaceful surroundings.\n");
    } else if (option == 4) {
        printf("You listen to the birds singing and the sound of leaves rustling in the gentle breeze.\n");
    } else if (option == 5) {
        printf("You sit by the river and watch the water flow gently.\n");
    } else if (option == 6) {
        printf("You take a deep breath and appreciate the peaceful moment.\n");
    }
}

int main() {
    srand(time(0)); // Seed the random number generator

    // Display the peaceful environment
    printf("Welcome to the Peaceful Time Travel Simulator!\n");
    displayPeacefulEnvironment();

    // Travel to a different point in time
    int year = rand() % 1000 + 1000;
    printf("You are about to travel to the year %d.\n", year);
    printf("Please wait a moment while we prepare for your journey.\n");
    sleep(1); // Simulate travel time

    // Travel to the year
    printf("You have arrived in the year %d.\n", year);
    travelToTime(year);

    // Interact with the environment
    int option;
    printf("What would you like to do next?\n");
    printf("1. Drink from the nearby stream\n");
    printf("2. Lie down and watch the clouds\n");
    printf("3. Climb a nearby hill for a panoramic view\n");
    printf("4. Listen to the birds and the rustling leaves\n");
    printf("5. Sit by the river and watch the water flow\n");
    printf("6. Appreciate the peaceful moment\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &option);

    // Interact with the environment
    interactWithEnvironment(option);

    // Return to the original point in time
    printf("You have returned to the present.\n");
    sleep(1); // Simulate travel time

    // Display the peaceful environment
    displayPeacefulEnvironment();

    return 0;
}