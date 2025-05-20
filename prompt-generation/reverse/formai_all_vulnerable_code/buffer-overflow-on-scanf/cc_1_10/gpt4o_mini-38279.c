//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_NAME_LENGTH 50
#define MAX_ENTRIES 100

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    int steps;
    float distance; // in kilometers
    int calories; // burned
} FitnessEntry;

typedef struct {
    char name[MAX_NAME_LENGTH];
    FitnessEntry entries[MAX_ENTRIES];
    int entryCount;
} User;

User users[MAX_USERS];
int userCount = 0;

void addUser();
void recordEntry();
void displayUserEntries();
void displayAllUsers();
void calculateStatistics();
void clearBuffer();

int main() {
    int choice;

    do {
        printf("\n=== Fitness Tracker ===\n");
        printf("1. Add User\n");
        printf("2. Record Fitness Entry\n");
        printf("3. Display User Entries\n");
        printf("4. Display All Users\n");
        printf("5. Calculate Statistics\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1: addUser(); break;
            case 2: recordEntry(); break;
            case 3: displayUserEntries(); break;
            case 4: displayAllUsers(); break;
            case 5: calculateStatistics(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached. Cannot add more users.\n");
        return;
    }
    
    printf("Enter the name of the user: ");
    fgets(users[userCount].name, MAX_NAME_LENGTH, stdin);
    users[userCount].name[strcspn(users[userCount].name, "\n")] = 0; // Remove newline
    users[userCount].entryCount = 0;
    userCount++;
    printf("User added successfully!\n");
}

void recordEntry() {
    char name[MAX_NAME_LENGTH];
    int i;

    printf("Enter user name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            if (users[i].entryCount >= MAX_ENTRIES) {
                printf("Entry limit reached for this user.\n");
                return;
            }
            FitnessEntry *entry = &users[i].entries[users[i].entryCount];
            printf("Enter date (YYYY-MM-DD): ");
            fgets(entry->date, 11, stdin);
            entry->date[strcspn(entry->date, "\n")] = 0; // Remove newline

            printf("Enter steps: ");
            scanf("%d", &entry->steps);
            clearBuffer();

            printf("Enter distance (in kilometers): ");
            scanf("%f", &entry->distance);
            clearBuffer();

            printf("Enter calories burned: ");
            scanf("%d", &entry->calories);
            clearBuffer();

            users[i].entryCount++;
            printf("Entry recorded successfully!\n");
            return;
        }
    }
    printf("User not found.\n");
}

void displayUserEntries() {
    char name[MAX_NAME_LENGTH];
    int i, j;

    printf("Enter user name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("Entries for %s:\n", users[i].name);
            for (j = 0; j < users[i].entryCount; j++) {
                FitnessEntry *entry = &users[i].entries[j];
                printf("Date: %s, Steps: %d, Distance: %.2f km, Calories: %d\n",
                        entry->date, entry->steps, entry->distance, entry->calories);
            }
            return;
        }
    }
    printf("User not found.\n");
}

void displayAllUsers() {
    printf("List of Users:\n");
    for (int i = 0; i < userCount; i++) {
        printf("%s\n", users[i].name);
    }
}

void calculateStatistics() {
    char name[MAX_NAME_LENGTH];
    int i, j;
    int totalSteps = 0, totalCalories = 0;
    float totalDistance = 0;

    printf("Enter user name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline

    for (i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            for (j = 0; j < users[i].entryCount; j++) {
                totalSteps += users[i].entries[j].steps;
                totalDistance += users[i].entries[j].distance;
                totalCalories += users[i].entries[j].calories;
            }
            printf("Statistics for %s:\n", users[i].name);
            printf("Total Steps: %d\n", totalSteps);
            printf("Total Distance: %.2f km\n", totalDistance);
            printf("Total Calories Burned: %d\n", totalCalories);
            return;
        }
    }
    printf("User not found.\n");
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}