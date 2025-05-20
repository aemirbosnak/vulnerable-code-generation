//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEASANTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Peasant;

void findPeasant(Peasant peasants[], int count, char *searchName) {
    printf("\nThe wise wizard seeks out Peasants bearing the name of %s...\n", searchName);
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(peasants[i].name, searchName) == 0) {
            printf("Hark! Found %s, aged %d.\n", peasants[i].name, peasants[i].age);
            found = 1;
        }
    }

    if (!found) {
        printf("Alas! No Peasant by the name of %s could be found in these lands.\n", searchName);
    }
}

void displayPeasants(Peasant peasants[], int count) {
    printf("\nGather 'round, villagers! Behold the list of honorable peasants:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s, Age: %d\n", i + 1, peasants[i].name, peasants[i].age);
    }
}

int main() {
    Peasant peasants[MAX_PEASANTS];
    int count = 0;
    
    // The Grand Festival of Peasants
    printf("Welcome to the Grand Festival of Peasants!\n");
    printf("Please tell me how many peasants are to be accounted for: ");
    scanf("%d", &count);

    if (count < 1 || count > MAX_PEASANTS) {
        printf("A tragic error occurred! Choose a number of peasants between 1 and %d.\n", MAX_PEASANTS);
        return 1;
    }

    // Enter Peasant Details
    for (int i = 0; i < count; i++) {
        printf("\nEnter the name of Peasant %d: ", i + 1);
        scanf("%s", peasants[i].name);
        printf("Enter the age of Peasant %d: ", i + 1);
        scanf("%d", &peasants[i].age);
    }

    // Display all peasants
    displayPeasants(peasants, count);

    // Search for a specific peasant
    char searchName[MAX_NAME_LENGTH];
    printf("\nThe wise wizard requests the name of the Peasant to seek: ");
    scanf("%s", searchName);

    findPeasant(peasants, count, searchName);
    
    // The Enchanted Departure 
    printf("\nThe festival draws to a close, and the peasants return to their fields...\n");
    return 0;
}