//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float height; // in cm
    float weight; // in kg
    int steps;
    float caloriesBurned;
} User;

typedef struct {
    User *users;
    int userCount;
    int capacity;
} FitnessTracker;

FitnessTracker* createTracker(int capacity) {
    FitnessTracker *tracker = (FitnessTracker*)malloc(sizeof(FitnessTracker));
    tracker->users = (User*)malloc(sizeof(User) * capacity);
    tracker->userCount = 0;
    tracker->capacity = capacity;
    return tracker;
}

void addUser(FitnessTracker *tracker) {
    if (tracker->userCount >= tracker->capacity) {
        tracker->capacity *= 2;
        tracker->users = (User*)realloc(tracker->users, sizeof(User) * tracker->capacity);
    }
    
    User newUser;
    printf("Enter user name: ");
    scanf("%s", newUser.name);
    
    printf("Enter age: ");
    scanf("%d", &newUser.age);
    
    printf("Enter height (cm): ");
    scanf("%f", &newUser.height);
    
    printf("Enter weight (kg): ");
    scanf("%f", &newUser.weight);
    
    newUser.steps = 0; // initialize steps
    newUser.caloriesBurned = 0; // initialize calories burned

    tracker->users[tracker->userCount++] = newUser;
    printf("User added successfully!\n\n");
}

void logActivity(FitnessTracker *tracker) {
    char name[50];
    printf("Enter user name to log activity: ");
    scanf("%s", name);

    for (int i = 0; i < tracker->userCount; i++) {
        if (strcmp(tracker->users[i].name, name) == 0) {
            int steps;
            printf("Enter steps taken: ");
            scanf("%d", &steps);
            
            tracker->users[i].steps += steps;
            tracker->users[i].caloriesBurned += (steps * 0.04); // Assuming 0.04 calories burned per step
            printf("Activity logged!\n\n");
            return;
        }
    }
    printf("User not found!\n\n");
}

void displayStats(FitnessTracker *tracker) {
    char name[50];
    printf("Enter user name to display stats: ");
    scanf("%s", name);
    
    for (int i = 0; i < tracker->userCount; i++) {
        if (strcmp(tracker->users[i].name, name) == 0) {
            printf("User: %s\n", tracker->users[i].name);
            printf("Age: %d\n", tracker->users[i].age);
            printf("Height: %.2f cm\n", tracker->users[i].height);
            printf("Weight: %.2f kg\n", tracker->users[i].weight);
            printf("Steps Taken: %d\n", tracker->users[i].steps);
            printf("Calories Burned: %.2f\n\n", tracker->users[i].caloriesBurned);
            return;
        }
    }
    printf("User not found!\n\n");
}

void freeTracker(FitnessTracker *tracker) {
    free(tracker->users);
    free(tracker);
}

int main() {
    FitnessTracker *tracker = createTracker(2);
    int choice;

    do {
        printf("1. Add User\n");
        printf("2. Log Activity\n");
        printf("3. Display User Statistics\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser(tracker);
                break;
            case 2:
                logActivity(tracker);
                break;
            case 3:
                displayStats(tracker);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    freeTracker(tracker);
    return 0;
}