//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set the seed for random number generation
    srand(time(NULL));

    // Define variables for travel through time
    int currentYear, targetYear, yearsTraveled;

    // Ask the user for the current year and target year
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please enter the current year: ");
    scanf("%d", &currentYear);
    printf("Please enter the target year: ");
    scanf("%d", &targetYear);

    // Calculate the number of years to travel
    yearsTraveled = abs(targetYear - currentYear);

    // Display the number of years to travel
    printf("You need to travel %d years in time to reach your destination.\n",
            yearsTraveled);

    // Travel through time!
    for (int i = 0; i < yearsTraveled; i++) {

        // Generate a random event
        int event = rand() % 10;

        // Display the event
        if (event == 0) {
            printf("You encounter a group of dinosaurs!\n");
        } else if (event == 1) {
            printf("You witness the construction of the Pyramids!\n");
        } else if (event == 2) {
            printf("You attend a performance of Shakespeare's Macbeth!\n");
        } else if (event == 3) {
            printf("You witness the signing of the US Constitution!\n");
        } else if (event == 4) {
            printf("You meet Leonardo da Vinci and see some of his work!\n");
        } else if (event == 5) {
            printf("You watch the first flight by the Wright brothers!\n");
        } else if (event == 6) {
            printf("You witness the fall of the Berlin Wall!\n");
        } else if (event == 7) {
            printf("You see a performance by the Beatles!\n");
        } else if (event == 8) {
            printf("You attend a speech by Martin Luther King Jr.!\n");
        } else {
            printf("You witness the birth of a new country!\n");
        }

        // Add one year to the current year
        if (currentYear < targetYear) {
            currentYear++;
        } else {
            currentYear--;
        }

        // Display the new year
        printf("The current year is now %d.\n", currentYear);
    }

    // Display the final year
    printf("You have arrived at your destination! The final year is %d.\n",
            currentYear);

    // Exit the program
    return 0;
}