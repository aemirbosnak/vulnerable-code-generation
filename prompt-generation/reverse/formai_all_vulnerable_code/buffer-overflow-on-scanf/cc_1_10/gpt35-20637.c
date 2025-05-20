//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate random numbers
int generateRandomNumber(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

// Function to generate a random date
void generateRandomDate(char date[]) {
    int year = generateRandomNumber(2020, 2021);
    int month = generateRandomNumber(1, 12);
    int day = generateRandomNumber(1, 28); // Limiting to 28 days to avoid leap year complications
    sprintf(date, "%d-%02d-%02d", year, month, day);
}

int main() {
    srand(time(0)); // Seed for random number generation
    
    // Variables for user information
    char name[20];
    int age;
    char gender[10];
    
    // Gathering user information
    printf("Welcome to CyberFit! Please enter your information:\n");
    printf("Name: ");
    scanf("%s", name);
    printf("Age: ");
    scanf("%d", &age);
    printf("Gender (male/female): ");
    scanf("%s", gender);
    
    // Variables for fitness tracker data
    float distance = 0;
    int steps = 0;
    int caloriesBurned = 0;
    char date[11];
    
    // Generating random fitness data for the past 7 days
    printf("\nGenerating fitness data for the past 7 days...\n\n");
    for (int i = 0; i < 7; i++) {
        generateRandomDate(date);
        steps = generateRandomNumber(2500, 15000);
        distance = steps / 1320.0;
        caloriesBurned = generateRandomNumber(100, 700);
        printf("%-15sSteps: %5d   Distance (miles): %0.2f   Calories Burned: %4d\n", date, steps, distance, caloriesBurned);
    }
    
    printf("\n\n");

    return 0;
}