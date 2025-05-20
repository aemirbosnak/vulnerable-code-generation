//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int steps;
    float calories;
    float weight;
} User;

User users[MAX_USERS];
int userCount = 0;

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }

    printf("Enter user name: ");
    scanf("%s", users[userCount].name);

    users[userCount].steps = 0;
    users[userCount].calories = 0.0;
    users[userCount].weight = 0.0;

    userCount++;
    printf("User %s added successfully!\n", users[userCount - 1].name);
}

void updateFitnessData() {
    char name[NAME_LENGTH];
    printf("Enter user name to update data: ");
    scanf("%s", name);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("Enter steps: ");
            scanf("%d", &users[i].steps);
            printf("Enter calories burnt: ");
            scanf("%f", &users[i].calories);
            printf("Enter weight: ");
            scanf("%f", &users[i].weight);
            printf("Data updated for user %s.\n", users[i].name);
            return;
        }
    }
    
    printf("User not found!\n");
}

void displayUserData() {
    char name[NAME_LENGTH];
    printf("Enter user name to display data: ");
    scanf("%s", name);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("User: %s\n", users[i].name);
            printf("Steps: %d\n", users[i].steps);
            printf("Calories burnt: %.2f\n", users[i].calories);
            printf("Weight: %.2f\n", users[i].weight);
            return;
        }
    }
    
    printf("User not found!\n");
}

void saveDataToFile() {
    FILE *file = fopen("fitness_data.txt", "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%s,%d,%.2f,%.2f\n", users[i].name, users[i].steps, users[i].calories, users[i].weight);
    }
    fclose(file);
    printf("Data saved to fitness_data.txt!\n");
}

void loadDataFromFile() {
    FILE *file = fopen("fitness_data.txt", "r");
    if (!file) {
        printf("Error opening file for reading, starting with empty data.\n");
        return;
    }

    while (fscanf(file, "%[^,],%d,%f,%f\n", users[userCount].name, &users[userCount].steps, 
                  &users[userCount].calories, &users[userCount].weight) == 4) {
        userCount++;
    }
    
    fclose(file);
    printf("Data loaded! %d users found.\n", userCount);
}

void displayMenu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add User\n");
    printf("2. Update User Data\n");
    printf("3. Display User Data\n");
    printf("4. Save Data to File\n");
    printf("5. Load Data from File\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    
    loadDataFromFile();

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                addUser();
                break;
            case 2: 
                updateFitnessData();
                break;
            case 3: 
                displayUserData();
                break;
            case 4: 
                saveDataToFile();
                break;
            case 5: 
                loadDataFromFile();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}