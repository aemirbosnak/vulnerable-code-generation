//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_ENTRIES 100
#define DATE_LENGTH 11 

typedef struct {
    char date[DATE_LENGTH];
    int steps;
    float distance; // in kilometers
    float calories; // burned calories
} FitnessEntry;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    FitnessEntry entries[MAX_ENTRIES];
    int entry_count;
} User;

User users[MAX_USERS];
int user_count = 0;

void add_user() {
    if (user_count >= MAX_USERS) {
        printf("Maximum users reached! Cannot add more users.\n");
        return;
    }
    User new_user;
    printf("Enter your name: ");
    scanf("%s", new_user.name);
    printf("Enter your age: ");
    scanf("%d", &new_user.age);
    new_user.entry_count = 0;
    users[user_count++] = new_user;
    printf("User added successfully!\n");
}

void add_fitness_entry(User* user) {
    if (user->entry_count >= MAX_ENTRIES) {
        printf("Maximum entries reached for %s!\n", user->name);
        return;
    }
    
    FitnessEntry new_entry;
    printf("Enter date (DD-MM-YYYY): ");
    scanf("%s", new_entry.date);
    printf("Enter number of steps: ");
    scanf("%d", &new_entry.steps);
    printf("Enter distance (km): ");
    scanf("%f", &new_entry.distance);
    printf("Enter calories burned: ");
    scanf("%f", &new_entry.calories);
    
    user->entries[user->entry_count++] = new_entry;
    printf("Fitness entry added successfully for %s!\n", user->name);
}

void view_fitness_entries(User* user) {
    if (user->entry_count == 0) {
        printf("No fitness entries found for %s.\n", user->name);
        return;
    }
    
    printf("Fitness Entries for %s:\n", user->name);
    printf("Date       | Steps | Distance (km) | Calories\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < user->entry_count; i++) {
        printf("%s | %d | %.2f        | %.2f\n", user->entries[i].date, 
               user->entries[i].steps, user->entries[i].distance, 
               user->entries[i].calories);
    }
}

void menu() {
    int choice, user_index;
    
    while (1) {
        printf("\nFitness Tracker Menu:\n");
        printf("1. Add User\n");
        printf("2. Add Fitness Entry\n");
        printf("3. View Fitness Entries\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                add_user();
                break;
            case 2:
                printf("Select User (0 to %d): ", user_count-1);
                scanf("%d", &user_index);
                if (user_index >= 0 && user_index < user_count) {
                    add_fitness_entry(&users[user_index]);
                } else {
                    printf("Invalid user selection!\n");
                }
                break;
            case 3: 
                printf("Select User (0 to %d): ", user_count-1);
                scanf("%d", &user_index);
                if (user_index >= 0 && user_index < user_count) {
                    view_fitness_entries(&users[user_index]);
                } else {
                    printf("Invalid user selection!\n");
                }
                break;
            case 4:
                printf("Exiting... Have a healthy day!\n");
                exit(0);
            default: 
                printf("Invalid option. Please select again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}