//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MENU_OPTIONS 5
#define MAX_ATTEMPTS 3

typedef struct {
    char name[50];
    float survivalChance;
} Survivor;

typedef struct {
    char alienType[50];
    float invasionProbability;
} Alien;

void displayMenu() {
    printf("========================================\n");
    printf("  POST-APOCALYPTIC ALIEN INVASION PROBABILITY CALCULATOR\n");
    printf("========================================\n");
    printf("1. Calculate Invasion Probability\n");
    printf("2. Register Survivor\n");
    printf("3. List Survivors\n");
    printf("4. Exit\n");
    printf("========================================\n");
    printf("Choose an option: ");
}

void calculateInvasionProbability(Alien aliens[], int alienCount) {
    int index = rand() % alienCount;
    printf("Alien Type: %s\n", aliens[index].alienType);
    printf("Invasion Probability: %.2f%%\n", aliens[index].invasionProbability);
}

void registerSurvivor(Survivor survivors[], int *survivorCount) {
    if (*survivorCount >= 50) {
        printf("Survivor list is full!\n");
        return;
    }

    printf("Enter the name of the survivor: ");
    scanf(" %[^\n]%*c", survivors[*survivorCount].name);
    printf("Enter survival chance (0.0 - 100.0): ");
    scanf("%f", &survivors[*survivorCount].survivalChance);
    
    if(survivors[*survivorCount].survivalChance < 0 || survivors[*survivorCount].survivalChance > 100) {
        printf("Invalid survival chance! Setting to 0.\n");
        survivors[*survivorCount].survivalChance = 0;
    }

    (*survivorCount)++;
    printf("Survivor registered successfully!\n");
}

void listSurvivors(Survivor survivors[], int survivorCount) {
    if (survivorCount == 0) {
        printf("No survivors registered yet!\n");
        return;
    }

    printf("Registered Survivors:\n");
    for (int i = 0; i < survivorCount; i++) {
        printf("%d: %s - Survival Chance: %.2f%%\n", i + 1, survivors[i].name, survivors[i].survivalChance);
    }
}

int main() {
    srand(time(0));
    Survivor survivors[50];
    Alien aliens[] = {
        {"Xenomorph", 76.5},
        {"Kryptonian", 82.1},
        {"Zergling", 54.8},
        {"Martian", 60.3},
        {"Predator", 90.2}
    };
    int alienCount = 5, survivorCount = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                calculateInvasionProbability(aliens, alienCount);
                break;
            case 2:
                registerSurvivor(survivors, &survivorCount);
                break;
            case 3:
                listSurvivors(survivors, survivorCount);
                break;
            case 4:
                printf("Preparing for potential invasion...\n");
                return 0;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    }

    return 0;
}