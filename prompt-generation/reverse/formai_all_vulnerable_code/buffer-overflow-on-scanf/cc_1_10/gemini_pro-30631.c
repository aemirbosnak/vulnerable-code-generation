//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the user's profile
struct Profile {
    char name[20];
    int age;
    int height;
    int weight;
};

// Define the fitness tracker's data
struct FitnessData {
    int steps;
    int calories;
    int distance;
    int heartRate;
};

// Function to get the user's profile
void getProfile(struct Profile *profile) {
    printf("What is your name? ");
    scanf("%s", profile->name);

    printf("How old are you? ");
    scanf("%d", &profile->age);

    printf("What is your height in inches? ");
    scanf("%d", &profile->height);

    printf("What is your weight in pounds? ");
    scanf("%d", &profile->weight);
}

// Function to get the fitness tracker's data
void getFitnessData(struct FitnessData *data) {
    printf("How many steps have you taken today? ");
    scanf("%d", &data->steps);

    printf("How many calories have you burned today? ");
    scanf("%d", &data->calories);

    printf("What is your distance traveled today? ");
    scanf("%d", &data->distance);

    printf("What is your heart rate? ");
    scanf("%d", &data->heartRate);
}

// Function to print the user's profile
void printProfile(struct Profile *profile) {
    printf("Name: %s\n", profile->name);
    printf("Age: %d\n", profile->age);
    printf("Height: %d inches\n", profile->height);
    printf("Weight: %d pounds\n", profile->weight);
}

// Function to print the fitness tracker's data
void printFitnessData(struct FitnessData *data) {
    printf("Steps: %d\n", data->steps);
    printf("Calories: %d\n", data->calories);
    printf("Distance: %d\n", data->distance);
    printf("Heart Rate: %d\n", data->heartRate);
}

// Main function
int main() {
    // Create a profile for the user
    struct Profile profile;
    getProfile(&profile);

    // Create a fitness tracker for the user
    struct FitnessData data;
    getFitnessData(&data);

    // Print the user's profile
    printf("My HeartBeats for You:\n");
    printProfile(&profile);

    // Print the fitness tracker's data
    printf("My Steps for You:\n");
    printFitnessData(&data);

    return 0;
}