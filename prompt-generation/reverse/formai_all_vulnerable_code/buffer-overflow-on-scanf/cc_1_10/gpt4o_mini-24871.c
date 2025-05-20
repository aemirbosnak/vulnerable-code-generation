//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold survivor information
typedef struct {
    char name[50];
    int age;
    int supplies;
} Survivor;

// Function to display the survivors
void displaySurvivors(Survivor* survivors, int count) {
    printf("SURVIVORS LIST:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s | Age: %d | Supplies: %d\n", 
               survivors[i].name, survivors[i].age, survivors[i].supplies);
    }
}

// Function to find a survivor by name
int findSurvivor(Survivor* survivors, int count, const char* name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(survivors[i].name, name) == 0) {
            return i; // Return index if found
        }
    }
    return -1; // Not found
}

// Function to add a survivor
void addSurvivor(Survivor* survivors, int* count) {
    if (*count < 100) { // Arbitrary limit of 100 survivors
        printf("Enter name: ");
        scanf("%s", survivors[*count].name);
        printf("Enter age: ");
        scanf("%d", &survivors[*count].age);
        printf("Enter amount of supplies: ");
        scanf("%d", &survivors[*count].supplies);
        
        (*count)++;
        printf("Survivor added.\n");
    } else {
        printf("Survivor limit reached! Unable to add more.\n");
    }
}

// Function to update supplies of a survivor
void updateSupplies(Survivor* survivors, int count) {
    char name[50];
    printf("Enter survivor name to update supplies: ");
    scanf("%s", name);
    
    int index = findSurvivor(survivors, count, name);
    if (index != -1) {
        int newSupplies;
        printf("Current supplies for %s: %d\n", 
               survivors[index].name, survivors[index].supplies);
        printf("Enter new supplies amount: ");
        scanf("%d", &newSupplies);
        
        survivors[index].supplies = newSupplies;
        printf("Supplies updated.\n");
    } else {
        printf("Survivor not found.\n");
    }
}

// Function to sort survivors by supplies
void sortSurvivors(Survivor* survivors, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (survivors[j].supplies < survivors[j + 1].supplies) {
                Survivor temp = survivors[j];
                survivors[j] = survivors[j + 1];
                survivors[j + 1] = temp;
            }
        }
    }
}

// Main function for the terminal-based survivor registry
int main() {
    Survivor survivors[100]; // Array of survivors
    int count = 0; // Current count of survivors
    int choice;
    
    printf("Welcome to the Post-Apocalyptic Survivor Registry!\n");
    
    do {
        printf("\n1. Add Survivor\n");
        printf("2. Display Survivors\n");
        printf("3. Update Supplies\n");
        printf("4. Sort Survivors by Supplies\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addSurvivor(survivors, &count);
                break;
            case 2:
                displaySurvivors(survivors, count);
                break;
            case 3:
                updateSupplies(survivors, count);
                break;
            case 4:
                sortSurvivors(survivors, count);
                printf("Survivors sorted by supplies successfully.\n");
                break;
            case 0:
                printf("Exiting the registry. Stay safe out there!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}