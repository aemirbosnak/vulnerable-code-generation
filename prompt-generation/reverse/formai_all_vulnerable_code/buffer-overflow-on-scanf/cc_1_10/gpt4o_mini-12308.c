//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SURVIVORS 100
#define NAME_LENGTH 50

typedef struct Survivor {
    char name[NAME_LENGTH];
    int age;
    int stamina;
} Survivor;

Survivor survivors[MAX_SURVIVORS];
int survivorCount = 0;

void addSurvivor() {
    if (survivorCount >= MAX_SURVIVORS) {
        printf("The colony is full! No more survivors can be added.\n");
        return;
    }

    Survivor newSurvivor;
    printf("Enter the name of the survivor: ");
    scanf(" %[^\n]", newSurvivor.name);
    printf("Enter the age of the survivor: ");
    scanf("%d", &newSurvivor.age);
    newSurvivor.stamina = 100; // Assign full stamina at start

    survivors[survivorCount++] = newSurvivor;
    printf("Survivor %s added to the colony.\n", newSurvivor.name);
}

void displaySurvivors(int index) {
    if (index < survivorCount) {
        printf("Survivor %d: Name: %s, Age: %d, Stamina: %d\n", 
               index + 1, survivors[index].name, survivors[index].age, survivors[index].stamina);
        displaySurvivors(index + 1); // Recursive call
    }
}

void forage(int index) {
    if (index < survivorCount) {
        printf("%s is foraging for resources...\n", survivors[index].name);
        int found = rand() % 50; // Random resources found between 0-49
        survivors[index].stamina -= (15 + (found/10)); // Decrease stamina
        printf("%s found %d resources. Stamina now at %d.\n", 
               survivors[index].name, found, survivors[index].stamina);
        forage(index + 1); // Recursive call
    }
}

void healSurvivor(int index) {
    if (index < survivorCount) {
        if (survivors[index].stamina < 100) {
            survivors[index].stamina += 20; // Heal stamina
            if (survivors[index].stamina > 100) 
                survivors[index].stamina = 100; // Cap stamina at 100
            printf("%s has been healed! Stamina is now %d.\n", 
                   survivors[index].name, survivors[index].stamina);
        } else {
            printf("%s is already at full stamina.\n", survivors[index].name);
        }
        healSurvivor(index + 1); // Recursive call
    }
}

void displayMenu() {
    printf("\n=== The Survival Colony ===\n");
    printf("1. Add Survivor\n");
    printf("2. Display Survivors\n");
    printf("3. Forage for Resources\n");
    printf("4. Heal Survivors\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    
    printf("Welcome to the post-apocalyptic survival colony.\n");
    srand(time(NULL)); // Seed for randomness

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSurvivor();
                break;
            case 2:
                printf("=== List of Survivors ===\n");
                if (survivorCount > 0) {
                    displaySurvivors(0); // Start recursive display
                } else {
                    printf("No survivors in the colony.\n");
                }
                break;
            case 3:
                if (survivorCount > 0) {
                    printf("=== Foraging Initiating ===\n");
                    forage(0); // Start recursive foraging
                } else {
                    printf("No survivors to forage.\n");
                }
                break;
            case 4:
                if (survivorCount > 0) {
                    printf("=== Healing Survivors ===\n");
                    healSurvivor(0); // Start recursive healing
                } else {
                    printf("No survivors to heal.\n");
                }
                break;
            case 5:
                printf("Exiting the colony.\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 5);

    printf("Stay safe out there, survivor!\n");
    return 0;
}