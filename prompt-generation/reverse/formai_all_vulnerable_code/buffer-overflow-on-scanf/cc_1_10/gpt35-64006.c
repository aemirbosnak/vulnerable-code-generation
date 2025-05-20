//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Constants for time travel details
#define TRAVEL_RATE 60    // In seconds
#define MAX_TRAVEL 100    // In years
#define MIN_TRAVEL 10     // In years
#define CURRENT_YEAR 2021 // The current year

// Function to get the user's year of birth
int getYearOfBirth() {
    int year;
    printf("Enter your year of birth: ");
    scanf("%d", &year);
    return year;
}

// Function to check if the user's year of birth is valid
bool isValidYearOfBirth(int yearOfBirth) {
    if (yearOfBirth < (CURRENT_YEAR - 100) || yearOfBirth > CURRENT_YEAR) {
        // Assuming nobody over 100 is using this program, and no time travelers from the future
        printf("Invalid year of birth! Please enter a valid year between %d and %d.\n", CURRENT_YEAR-100, CURRENT_YEAR);
        return false;
    }
    return true;
}

// Function to simulate time travel based on user input
void travelThroughTime(int yearOfBirth) {
    printf("You can travel through time for a maximum of %d years.\n", MAX_TRAVEL);
    printf("How many years would you like to travel through time? (Minimum %d years): ", MIN_TRAVEL);
    int yearsToTravel;
    bool isValidInput = false;
    while (!isValidInput) { // Validate user input
        scanf("%d", &yearsToTravel);
        if (yearsToTravel < MIN_TRAVEL || yearsToTravel > MAX_TRAVEL) {
            printf("Invalid input! Please enter a number between %d and %d: ", MIN_TRAVEL, MAX_TRAVEL);
        } else {
            isValidInput = true;
        }
    }
    // Do the time travel simulation
    time_t currentTime = time(NULL);
    struct tm *now = localtime(&currentTime);
    now->tm_year = yearOfBirth - 1900;  // Set the year to the user's input birth year
    time_t birthTime = mktime(now);
    now->tm_year = yearOfBirth + yearsToTravel - 1900;  // Set the year to the user's new birth year
    time_t futureTime = mktime(now);
    double travelTime = difftime(futureTime, birthTime);

    // Display the time travel details
    printf("Time travel complete! You traveled %d years into the future.\n", yearsToTravel);
    printf("You left on %s", asctime(now));
    printf("You have now arrived in the year %d.\n", yearOfBirth+yearsToTravel);
    printf("The time travel simulation took %.2lf seconds in real time.\n", travelTime/TRAVEL_RATE);
}

// Main function
int main() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("This program takes your birth year as input and simulates travel through time.\n");
    int yearOfBirth;
    bool isValid = false;
    while (!isValid) { // Keep asking for user's year of birth until it's valid
        yearOfBirth = getYearOfBirth();
        isValid = isValidYearOfBirth(yearOfBirth);
    }
    travelThroughTime(yearOfBirth);
    printf("Thank you for using the Time Travel Simulator. Goodbye!\n");
    return 0;
}