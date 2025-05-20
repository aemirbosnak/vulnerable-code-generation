//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the survivors' camp
typedef struct {
    char name[50];
    int id;
} Survivor;

// Function to create a sample of survivors
void createSurvivors(Survivor survivors[], int *size) {
    strcpy(survivors[0].name, "Alex");
    survivors[0].id = 1001;
    
    strcpy(survivors[1].name, "Maya");
    survivors[1].id = 1002;
    
    strcpy(survivors[2].name, "Kade");
    survivors[2].id = 1003;

    strcpy(survivors[3].name, "Lina");
    survivors[3].id = 1004;

    strcpy(survivors[4].name, "Jax");
    survivors[4].id = 1005;

    *size = 5; // Set the total number of survivors
}

// Linear search algorithm to find a survivor by ID
int searchSurvivorByID(Survivor survivors[], int size, int searchID) {
    for (int i = 0; i < size; i++) {
        if (survivors[i].id == searchID) {
            return i; // Return the index of the found survivor
        }
    }
    return -1; // Return -1 if not found
}

// Function to display survivors
void displaySurvivors(Survivor survivors[], int size) {
    printf("Survivors in our camp:\n");
    for (int i = 0; i < size; i++) {
        printf("ID: %d | Name: %s\n", survivors[i].id, survivors[i].name);
    }
    printf("\n");
}

// Function for the survivor search interaction
void survivorSearch(Survivor survivors[], int size) {
    int searchID;
    printf("In the ruins of our broken world, we must find our fellow survivors...\n");
    printf("Enter the ID of the survivor you wish to find: ");
    scanf("%d", &searchID);

    int result = searchSurvivorByID(survivors, size, searchID);
    if (result != -1) {
        printf("Survivor found: %s with ID %d\n", survivors[result].name, survivors[result].id);
    } else {
        printf("Alas, no survivor with ID %d could be found. Keep searching...\n", searchID);
    }
}

// Main function
int main() {
    Survivor survivors[10]; // Max size of survivors
    int size = 0;

    createSurvivors(survivors, &size);
    displaySurvivors(survivors, size);
    survivorSearch(survivors, size);

    return 0;
}