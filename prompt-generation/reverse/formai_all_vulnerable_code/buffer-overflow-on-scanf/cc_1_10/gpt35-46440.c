//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FitnessTracker {
    char name[20];
    double weight;
    double height;
    double age;
    double goal;
};

void displayMenu() {
    printf("\nWelcome to the Fitness Tracker!\n");
    printf("-------------------------------\n");
    printf("1. Create a new user profile\n");
    printf("2. Update user profile\n");
    printf("3. Set user's weight/height goal\n");
    printf("4. Display user profile and goal progress\n");
    printf("5. Exit\n");
    printf("-------------------------------\n");
    printf("Please enter the number of your selection: ");
}

void createProfile(struct FitnessTracker *user) {
    printf("\nCreating new user profile...\n");
    printf("Please enter the following information:\n");

    printf("Name: ");
    scanf("%s", user->name);

    printf("Weight (in kg): ");
    scanf("%lf", &user->weight);

    printf("Height (in m): ");
    scanf("%lf", &user->height);

    printf("Age: ");
    scanf("%lf", &user->age);

    printf("\nUser profile created!\n");
}

void updateProfile(struct FitnessTracker *user) {
    int option;

    printf("\nUpdating user profile...\n");
    printf("Please select what you would like to update:\n");
    printf("1. Name\n");
    printf("2. Weight\n");
    printf("3. Height\n");
    printf("4. Age\n");
    printf("5. Cancel\n");
    printf("Please enter the number of your selection: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter new name: ");
            scanf("%s", user->name);
            printf("User profile updated!\n");
            break;
        case 2:
            printf("Enter new weight: ");
            scanf("%lf", &user->weight);
            printf("User profile updated!\n");
            break;
        case 3:
            printf("Enter new height: ");
            scanf("%lf", &user->height);
            printf("User profile updated!\n");
            break;
        case 4:
            printf("Enter new age: ");
            scanf("%lf", &user->age);
            printf("User profile updated!\n");
            break;
        case 5:
            printf("Returning to main menu...\n");
            break;
        default:
            printf("Invalid selection. Please try again.\n");
            break;
    }
}

void setGoal(struct FitnessTracker *user) {
    printf("\nSetting user's weight/height goal...\n");

    printf("Please enter your desired weight or height (in kg/m): ");
    scanf("%lf", &user->goal);

    printf("User's goal set to %.2lf!\n", user->goal);
}

void displayUser(struct FitnessTracker *user) {
    double BMI = user->weight / (user->height * user->height);

    printf("\nDisplaying user profile and goal progress...\n");
    printf("Name: %s\n", user->name);
    printf("Weight: %.2lf kg\n", user->weight);
    printf("Height: %.2lf m\n", user->height);
    printf("Age: %.0lf years\n", user->age);
    printf("BMI: %.2lf\n", BMI);

    if (user->goal > 0) {
        if (BMI < user->goal) {
            printf("You are currently %.2lf kg/m away from your goal of %.2lf kg/m.\n", user->goal - BMI, user->goal);
        } else if (BMI > user->goal) {
            printf("You have exceeded your goal of %.2lf kg/m by %.2lf kg/m.\n", user->goal, BMI - user->goal);
        } else {
            printf("You have met your goal of %.2lf kg/m. Keep up the good work!\n", user->goal);
        }
    } else {
        printf("No goal set.\n");
    }
}

int main() {
    struct FitnessTracker user = {"", 0, 0, 0, 0};

    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createProfile(&user);
                break;
            case 2:
                updateProfile(&user);
                break;
            case 3:
                setGoal(&user);
                break;
            case 4:
                displayUser(&user);
                break;
            case 5:
                printf("\nExiting. Goodbye!\n");
                return 0;
            default:
                printf("Invalid selection. Please try again.\n");
                break;
        }
    }
}