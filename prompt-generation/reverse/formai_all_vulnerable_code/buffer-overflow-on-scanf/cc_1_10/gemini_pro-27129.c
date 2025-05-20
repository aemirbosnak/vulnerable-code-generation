//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// User-defined data types
typedef struct {
    int steps;
    int distance;
    int calories;
} FitnessData;

// Function prototypes
void welcomeUser();
void displayMainMenu();
void collectFitnessData(FitnessData *fitnessData);
void displayFitnessData(const FitnessData *fitnessData);
void saveFitnessData(const FitnessData *fitnessData);
void loadFitnessData(FitnessData *fitnessData);
void generateRandomFitnessData(FitnessData *fitnessData);

// Global variables
FitnessData fitnessData;

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Welcome the user
    welcomeUser();

    // Display the main menu
    displayMainMenu();

    // Get the user's choice
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Handle the user's choice
    switch (choice) {
        case 1:
            // Collect fitness data
            collectFitnessData(&fitnessData);
            break;
        case 2:
            // Display fitness data
            displayFitnessData(&fitnessData);
            break;
        case 3:
            // Save fitness data
            saveFitnessData(&fitnessData);
            break;
        case 4:
            // Load fitness data
            loadFitnessData(&fitnessData);
            break;
        case 5:
            // Generate random fitness data
            generateRandomFitnessData(&fitnessData);
            break;
        default:
            // Invalid choice
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            break;
    }

    // Thank the user
    printf("Thank you for using the Fitness Tracker!\n");

    return 0;
}

void welcomeUser() {
    printf("Welcome to the Fitness Tracker!\n");
    printf("This app will help you track your fitness progress.\n");
}

void displayMainMenu() {
    printf("\nMain Menu\n");
    printf("1. Collect fitness data\n");
    printf("2. Display fitness data\n");
    printf("3. Save fitness data\n");
    printf("4. Load fitness data\n");
    printf("5. Generate random fitness data\n");
}

void collectFitnessData(FitnessData *fitnessData) {
    printf("\nEnter your fitness data:\n");

    // Get the steps
    printf("Steps: ");
    scanf("%d", &fitnessData->steps);

    // Get the distance
    printf("Distance (in miles): ");
    scanf("%d", &fitnessData->distance);

    // Get the calories
    printf("Calories: ");
    scanf("%d", &fitnessData->calories);
}

void displayFitnessData(const FitnessData *fitnessData) {
    printf("\nYour fitness data:\n");

    // Display the steps
    printf("Steps: %d\n", fitnessData->steps);

    // Display the distance
    printf("Distance (in miles): %d\n", fitnessData->distance);

    // Display the calories
    printf("Calories: %d\n", fitnessData->calories);
}

void saveFitnessData(const FitnessData *fitnessData) {
    // Open a file for writing
    FILE *fp = fopen("fitness_data.txt", "w");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Write the fitness data to the file
    fprintf(fp, "%d\n", fitnessData->steps);
    fprintf(fp, "%d\n", fitnessData->distance);
    fprintf(fp, "%d\n", fitnessData->calories);

    // Close the file
    fclose(fp);

    // Inform the user that the data was saved successfully
    printf("Fitness data saved successfully!\n");
}

void loadFitnessData(FitnessData *fitnessData) {
    // Open a file for reading
    FILE *fp = fopen("fitness_data.txt", "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    // Read the fitness data from the file
    fscanf(fp, "%d", &fitnessData->steps);
    fscanf(fp, "%d", &fitnessData->distance);
    fscanf(fp, "%d", &fitnessData->calories);

    // Close the file
    fclose(fp);

    // Inform the user that the data was loaded successfully
    printf("Fitness data loaded successfully!\n");
}

void generateRandomFitnessData(FitnessData *fitnessData) {
    // Generate a random number of steps
    fitnessData->steps = rand() % 10000;

    // Generate a random distance
    fitnessData->distance = rand() % 100;

    // Generate a random number of calories
    fitnessData->calories = rand() % 1000;

    // Inform the user that the data was generated successfully
    printf("Random fitness data generated successfully!\n");
}