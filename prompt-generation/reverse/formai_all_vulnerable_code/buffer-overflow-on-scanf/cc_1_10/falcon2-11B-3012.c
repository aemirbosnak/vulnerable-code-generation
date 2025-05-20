//Falcon2-11B DATASET v1.0 Category: Weather simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Define the maximum temperature and minimum temperature for each day
int maxTemp[] = {20, 25, 28, 30, 32, 34, 36, 38, 40, 42};
int minTemp[] = {10, 15, 18, 20, 22, 24, 26, 28, 30, 32};
// Define the starting day and hour
int startDay = 1;
int startHour = 6;
// Define the location and current temperature
char location[100];
float currentTemp = 25.0;
// Define the output format
char outputFormat[] = "%s %d-%d %s: %.2f\n";

// Function to generate a random temperature for the current day and hour
float generateTemp() {
    int hour = startHour;
    int day = startDay;
    float maxTemp = currentTemp;
    while (day <= 10) {
        int random = rand() % 100;
        if (random <= 50) {
            maxTemp = maxTemp + (rand() % 5) + 1;
        } else {
            maxTemp = maxTemp - (rand() % 5) - 1;
        }
        hour = hour + 1;
        if (hour >= 24) {
            hour = 0;
            day = day + 1;
        }
    }
    return maxTemp;
}

// Function to print the current temperature and time
void printTemp() {
    printf(outputFormat, location, startDay, startDay, "Day", currentTemp);
}

// Function to calculate and print the temperature for the next 10 days
void simulateTemp() {
    float currentTemp = generateTemp();
    printf("Current temperature: %.2f\n", currentTemp);
    for (int i = 0; i < 10; i++) {
        currentTemp = currentTemp + (rand() % 10) + 1;
        printf(outputFormat, location, startDay, i+1, "Day", currentTemp);
        if (i!= 9) {
            printf("\n");
        }
    }
}

// Function to get the location from the user
void getLocation() {
    printf("Enter the location: ");
    scanf("%s", location);
}

// Main function
int main() {
    // Get the location from the user
    getLocation();
    // Print the current temperature
    printTemp();
    // Simulate the temperature for the next 10 days
    simulateTemp();
    return 0;
}