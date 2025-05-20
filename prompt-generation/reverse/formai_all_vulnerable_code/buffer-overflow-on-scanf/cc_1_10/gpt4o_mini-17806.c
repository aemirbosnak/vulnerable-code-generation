//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>

#define MAX_ENTRIES 100

typedef struct {
    int steps;
    float distance; // in kilometers
    float calories; // in kilocalories
} Activity;

Activity activities[MAX_ENTRIES];
int totalActivities = 0;

void displayMenu();
void addActivity();
void displayActivities(int index);
void calculateTotalStats();

int main() {
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addActivity();
                break;
            case 2:
                calculateTotalStats();
                break;
            case 3:
                displayActivities(0);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}

void displayMenu() {
    printf("\n** Fitness Tracker **\n");
    printf("1. Add Activity\n");
    printf("2. Display Total Stats\n");
    printf("3. Display All Activities\n");
    printf("0. Exit\n");
}

void addActivity() {
    if (totalActivities >= MAX_ENTRIES) {
        printf("Maximum number of activities reached. Cannot add more.\n");
        return;
    }
    
    Activity newActivity;
    printf("Enter steps: ");
    scanf("%d", &newActivity.steps);
    printf("Enter distance (km): ");
    scanf("%f", &newActivity.distance);
    printf("Enter calories burned: ");
    scanf("%f", &newActivity.calories);
    
    activities[totalActivities] = newActivity;
    totalActivities++;
    printf("Activity added successfully!\n");
}

void displayActivities(int index) {
    if (index >= totalActivities) {
        return;
    }
    
    printf("\nActivity %d:\n", index + 1);
    printf("Steps: %d\n", activities[index].steps);
    printf("Distance: %.2f km\n", activities[index].distance);
    printf("Calories: %.2f kcal\n", activities[index].calories);
    
    displayActivities(index + 1);
}

void calculateTotalStats() {
    int totalSteps = 0;
    float totalDistance = 0.0f;
    float totalCalories = 0.0f;
    
    for (int i = 0; i < totalActivities; i++) {
        totalSteps += activities[i].steps;
        totalDistance += activities[i].distance;
        totalCalories += activities[i].calories;
    }
    
    printf("\n** Total Stats **\n");
    printf("Total Steps: %d\n", totalSteps);
    printf("Total Distance: %.2f km\n", totalDistance);
    printf("Total Calories: %.2f kcal\n", totalCalories);
}