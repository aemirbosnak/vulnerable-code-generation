//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    float weight;        // in kg
    float height;        // in m
    float steps;
    float distance;      // in km
    float calories;      // burned calories
    time_t last_update;  // track last update time
} User;

void displayWelcomeMessage() {
    printf("Welcome to the Enchanted Fitness Tracker!\n");
    printf("Love yourself enough to lead a healthy lifestyle.\n\n");
}

void getUserInput(User *user) {
    printf("Please, the name of your beloved: ");
    fgets(user->name, sizeof(user->name), stdin);
    user->name[strcspn(user->name, "\n")] = 0; // Remove newline

    printf("Age of your darling: ");
    scanf("%d", &user->age);
    
    printf("Weight of your beloved (in kg): ");
    scanf("%f", &user->weight);
    
    printf("Height of your cherished (in meters): ");
    scanf("%f", &user->height);

    user->steps = 0;
    user->distance = 0.0;
    user->calories = 0.0;
    user->last_update = time(NULL);
}

void displayUserInfo(User *user) {
    printf("\n--------------------------\n");
    printf("Cherished one: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Weight: %.2f kg\n", user->weight);
    printf("Height: %.2f m\n", user->height);
    printf("Steps taken: %.0f\n", user->steps);
    printf("Distance covered: %.2f km\n", user->distance);
    printf("Calories burned: %.2f\n", user->calories);
    printf("Last updated: %s", ctime(&user->last_update));
    printf("--------------------------\n\n");
}

void updateFitness(User *user) {
    float additional_steps, step_length = 0.8; // Assume average step length is 0.8m
    printf("How many steps your darling has taken today? ");
    scanf("%f", &additional_steps);
    
    user->steps += additional_steps;
    user->distance += (additional_steps * step_length) / 1000; // convert to km
    user->calories += additional_steps * 0.05; // Assume 0.05 calories per step
    user->last_update = time(NULL);
}

void displayGoodbyeMessage() {
    printf("Thank you for using the Enchanted Fitness Tracker. \n");
    printf("May love guide you on your journey to health and fitness.\n");
}

int main() {
    User beloved;
    int choice;

    displayWelcomeMessage();
    getUserInput(&beloved);

    do {
        printf("Please choose an action: \n");
        printf("1. Display information about your beloved\n");
        printf("2. Update fitness activity\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayUserInfo(&beloved);
                break;
            case 2:
                updateFitness(&beloved);
                break;
            case 3:
                displayGoodbyeMessage();
                break;
            default:
                printf("Please choose a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}