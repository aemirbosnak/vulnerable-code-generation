//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_ENTRIES 1000

typedef struct {
    int steps;
    float distance; // in kilometers
    float calories; // burned calories
} FitnessData;

typedef struct {
    char name[MAX_NAME_LENGTH];
    FitnessData data[MAX_ENTRIES];
    int entry_count;
} User;

User users[MAX_USERS];
int user_count = 0;

void register_user() {
    if (user_count >= MAX_USERS) {
        printf("User limit reached. Cannot register more users.\n");
        return;
    }
    
    User new_user;
    printf("Enter your name: ");
    scanf("%s", new_user.name);
    new_user.entry_count = 0;
    
    users[user_count++] = new_user;
    printf("User %s registered successfully!\n", new_user.name);
}

User* find_user(const char* name) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].name, name) == 0) {
            return &users[i];
        }
    }
    return NULL;
}

void log_fitness_data(User* user) {
    if (user->entry_count >= MAX_ENTRIES) {
        printf("Entry limit reached for %s. Cannot log more data.\n", user->name);
        return;
    }
    
    FitnessData new_data;
    printf("Enter the number of steps: ");
    scanf("%d", &new_data.steps);
    printf("Enter distance in kilometers: ");
    scanf("%f", &new_data.distance);
    printf("Enter calories burned: ");
    scanf("%f", &new_data.calories);
    
    user->data[user->entry_count++] = new_data;
    printf("Fitness data logged for %s successfully!\n", user->name);
}

void display_fitness_data(User* user) {
    if (user->entry_count == 0) {
        printf("No fitness data recorded for %s.\n", user->name);
        return;
    }
    
    printf("\nFitness Data for %s:\n", user->name);
    printf("%-10s %-10s %-10s %-10s\n", "Entry", "Steps", "Distance", "Calories");
    for (int i = 0; i < user->entry_count; i++) {
        printf("%-10d %-10d %-10.2f %-10.2f\n", i+1, user->data[i].steps, user->data[i].distance, user->data[i].calories);
    }
}

void fitness_tracker_menu() {
    int choice;
    char name[MAX_NAME_LENGTH];
    
    while (1) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Register User\n");
        printf("2. Log Fitness Data\n");
        printf("3. Display Fitness Data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                printf("Enter user name: ");
                scanf("%s", name);
                User* user = find_user(name);
                if (user) {
                    log_fitness_data(user);
                } else {
                    printf("User %s not found.\n", name);
                }
                break;
            case 3:
                printf("Enter user name: ");
                scanf("%s", name);
                user = find_user(name);
                if (user) {
                    display_fitness_data(user);
                } else {
                    printf("User %s not found.\n", name);
                }
                break;
            case 4:
                printf("Exiting Fitness Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
}

int main() {
    fitness_tracker_menu();
    return 0;
}