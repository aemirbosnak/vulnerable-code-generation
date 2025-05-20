//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SURVIVORS 100
#define MAX_NAME_LENGTH 30

typedef struct Survivor {
    char name[MAX_NAME_LENGTH];
    int age;
    int health;
    int resources; // Resources like food, water, etc.
} Survivor;

typedef struct SurvivorGroup {
    Survivor survivors[MAX_SURVIVORS];
    int count;
} SurvivorGroup;

void initializeGroup(SurvivorGroup *group) {
    group->count = 0;
}

void addSurvivor(SurvivorGroup *group, char *name, int age, int health, int resources) {
    if (group->count < MAX_SURVIVORS) {
        Survivor newSurvivor;
        strncpy(newSurvivor.name, name, MAX_NAME_LENGTH);
        newSurvivor.age = age;
        newSurvivor.health = health;
        newSurvivor.resources = resources;
        group->survivors[group->count] = newSurvivor;
        group->count++;
    } else {
        printf("Survivor group is full! Can't add more survivors.\n");
    }
}

void displaySurvivors(SurvivorGroup *group) {
    printf("\nSurvivor Group:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < group->count; i++) {
        Survivor s = group->survivors[i];
        printf("Name: %s | Age: %d | Health: %d | Resources: %d\n", s.name, s.age, s.health, s.resources);
    }
    printf("--------------------------------------------------\n");
}

void survivalStatus(SurvivorGroup *group) {
    printf("\nSurvivor Health Status:\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < group->count; i++) {
        Survivor s = group->survivors[i];
        if (s.health < 50) {
            printf("%s requires medical assistance!\n", s.name);
        } else {
            printf("%s is healthy.\n", s.name);
        }
    }
    printf("--------------------------------------------------\n");
}

void manageResources(SurvivorGroup *group) {
    int totalResources = 0;
    for (int i = 0; i < group->count; i++) {
        totalResources += group->survivors[i].resources;
    }
    printf("\nTotal Resources Available: %d\n", totalResources);
    printf("It is essential to ration these resources wisely.\n");
}

void simulateEclipse(SurvivorGroup *group) {
    printf("\nWarning! A solar eclipse is happening. Energy levels will decrease by 20%%!\n");
    for (int i = 0; i < group->count; i++) {
        group->survivors[i].health -= group->survivors[i].health * 0.2;
        if (group->survivors[i].health < 0) {
            group->survivors[i].health = 0; // Ensure health doesn't go negative
        }
    }
    printf("Survivor health has been affected by the eclipse.\n");
}

void menu() {
    printf("\n=== Post-Apocalyptic Survivor Management ===\n");
    printf("1. Add Survivor\n");
    printf("2. Display Survivors\n");
    printf("3. Check Survival Status\n");
    printf("4. Manage Resources\n");
    printf("5. Simulate Solar Eclipse\n");
    printf("6. Exit\n");
    printf("=============================================\n");
    printf("Select an option: ");
}

int main() {
    SurvivorGroup group;
    initializeGroup(&group);
    int choice;
    
    do {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                int age, health, resources;
                
                printf("Enter survivor's name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                printf("Enter health (1-100): ");
                scanf("%d", &health);
                printf("Enter resources: ");
                scanf("%d", &resources);
                
                addSurvivor(&group, name, age, health, resources);
                break;
            }
            case 2:
                displaySurvivors(&group);
                break;
            case 3:
                survivalStatus(&group);
                break;
            case 4:
                manageResources(&group);
                break;
            case 5:
                simulateEclipse(&group);
                break;
            case 6:
                printf("Preparing to leave the surviving camp...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    printf("Game Over! You survived the apocalypse.\n");
    return 0;
}