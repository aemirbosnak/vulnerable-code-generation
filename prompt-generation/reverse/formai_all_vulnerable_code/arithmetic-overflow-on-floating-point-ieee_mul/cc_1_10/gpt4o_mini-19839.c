//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to hold user data
typedef struct {
    char name[50];
    int age;
    float weight;  // in kg
    float height;  // in cm
    int steps;
    int calories;
    float distance; // in km
} User;

// Function prototypes
void inputUserData(User *user);
void displayUserData(const User *user);
void updateFitnessData(User *user);
void calculateBMR(const User *user);
void saveToFile(const User *user);
void loadFromFile(User *user);
void displayMenu();

int main() {
    User user;
    int choice = 0;

    loadFromFile(&user); // Load existing user data

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputUserData(&user);
                break;
            case 2:
                updateFitnessData(&user);
                break;
            case 3:
                displayUserData(&user);
                break;
            case 4:
                calculateBMR(&user);
                break;
            case 5:
                saveToFile(&user);
                break;
            case 6:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }

    return 0;
}

void inputUserData(User *user) {
    printf("Enter your name: ");
    scanf("%s", user->name);
    printf("Enter your age: ");
    scanf("%d", &user->age);
    printf("Enter your weight (kg): ");
    scanf("%f", &user->weight);
    printf("Enter your height (cm): ");
    scanf("%f", &user->height);
    user->steps = 0; // Initialize steps
    user->calories = 0; // Initialize calories
    user->distance = 0.0; // Initialize distance
    printf("User data inputted successfully!\n");
}

void displayUserData(const User *user) {
    printf("User Profile:\n");
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Weight: %.2f kg\n", user->weight);
    printf("Height: %.2f cm\n", user->height);
    printf("Steps: %d\n", user->steps);
    printf("Calories burned: %d kcal\n", user->calories);
    printf("Distance traveled: %.2f km\n", user->distance);
}

void updateFitnessData(User *user) {
    int steps, calories;
    float distance;

    printf("Enter the number of steps taken: ");
    scanf("%d", &steps);
    printf("Enter calories burned: ");
    scanf("%d", &calories);
    printf("Enter distance traveled (km): ");
    scanf("%f", &distance);

    user->steps += steps; // Update steps
    user->calories += calories; // Update calories burned
    user->distance += distance; // Update distance
    printf("Fitness data updated successfully!\n");
}

void calculateBMR(const User *user) {
    float bmr;
    // Using Mifflin-St Jeor Equation for BMR Calculation
    // BMR for Men: BMR = 10 * weight(kg) + 6.25 * height(cm) - 5 * age + 5
    // BMR for Women: BMR = 10 * weight(kg) + 6.25 * height(cm) - 5 * age - 161

    if (user->age % 2 == 0) { // Assuming even age means male
        bmr = 10 * user->weight + 6.25 * user->height - 5 * user->age + 5;
    } else { // Odd age means female
        bmr = 10 * user->weight + 6.25 * user->height - 5 * user->age - 161;
    }

    printf("Your BMR is: %.2f kcal/day\n", bmr);
}

void saveToFile(const User *user) {
    FILE *file = fopen("user_data.txt", "w");
    if (file == NULL) {
        printf("Error saving data to file!\n");
        return;
    }
    fprintf(file, "%s\n", user->name);
    fprintf(file, "%d\n", user->age);
    fprintf(file, "%.2f\n", user->weight);
    fprintf(file, "%.2f\n", user->height);
    fprintf(file, "%d\n", user->steps);
    fprintf(file, "%d\n", user->calories);
    fprintf(file, "%.2f\n", user->distance);
    fclose(file);
    printf("User data saved successfully!\n");
}

void loadFromFile(User *user) {
    FILE *file = fopen("user_data.txt", "r");
    if (file != NULL) {
        fscanf(file, "%s", user->name);
        fscanf(file, "%d", &user->age);
        fscanf(file, "%f", &user->weight);
        fscanf(file, "%f", &user->height);
        fscanf(file, "%d", &user->steps);
        fscanf(file, "%d", &user->calories);
        fscanf(file, "%f", &user->distance);
        fclose(file);
        printf("User data loaded successfully!\n");
    } else {
        printf("No previous user data found.\n");
    }
}

void displayMenu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Input User Data\n");
    printf("2. Update Fitness Data\n");
    printf("3. Display User Data\n");
    printf("4. Calculate BMR\n");
    printf("5. Save User Data to File\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}