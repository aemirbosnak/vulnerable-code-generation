//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// Define structure for user data
typedef struct {
    char name[50];
    int age;
    float height; // in meters
    float weight; // in kg
    int stepCount;
} User;

void displayWelcomeMessage() {
    printf("Welcome to the C Fitness Tracker!\n");
    printf("Track your fitness and stay healthy!\n");
    printf("--------------------------------------\n");
}

void inputUserData(User *user) {
    printf("Enter your name: ");
    fgets(user->name, sizeof(user->name), stdin);
    user->name[strcspn(user->name, "\n")] = 0; // Remove newline character
    
    printf("Enter your age: ");
    scanf("%d", &user->age);
    
    printf("Enter your height in meters: ");
    scanf("%f", &user->height);
    
    printf("Enter your weight in kg: ");
    scanf("%f", &user->weight);
    
    user->stepCount = 0; // Initialize step count to 0
}

void displayUserData(const User *user) {
    printf("\n--- User Information ---\n");
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Height: %.2f m\n", user->height);
    printf("Weight: %.2f kg\n", user->weight);
    printf("Step Count: %d steps\n", user->stepCount);
    printf("------------------------\n");
}

void logSteps(User *user) {
    int steps;
    printf("Enter the number of steps taken today: ");
    scanf("%d", &steps);
    user->stepCount += steps; // Update step count
    printf("Steps logged! Total steps: %d\n", user->stepCount);
}

void calculateBMI(const User *user) {
    if (user->weight > 0) { // Check to avoid division by zero
        float bmi = user->weight / (user->height * user->height);
        printf("Your BMI is: %.2f\n", bmi);
        
        // Determine BMI category
        if (bmi < 18.5) {
            printf("You are underweight.\n");
        } else if (bmi < 24.9) {
            printf("You have a healthy weight.\n");
        } else if (bmi < 29.9) {
            printf("You are overweight.\n");
        } else {
            printf("You are obese.\n");
        }
    } else {
        printf("Weight must be greater than zero to calculate BMI.\n");
    }
}

int main() {
    User user;
    int choice;
    
    displayWelcomeMessage();
    
    inputUserData(&user);
    
    do {
        printf("\n--- Fitness Tracker Menu ---\n");
        printf("1. Display User Information\n");
        printf("2. Log Steps\n");
        printf("3. Calculate BMI\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                displayUserData(&user);
                break;
            case 2:
                logSteps(&user);
                break;
            case 3:
                calculateBMI(&user);
                break;
            case 4:
                printf("Exiting the program. Stay fit!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while(choice != 4);
    
    return 0;
}