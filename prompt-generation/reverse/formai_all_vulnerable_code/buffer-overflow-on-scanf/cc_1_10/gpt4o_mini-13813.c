//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a star in the galaxy
typedef struct Star {
    char name[30];
    struct Star* next;
} Star;

// Function to create a new star
Star* createStar(const char* name) {
    Star* newStar = (Star*)malloc(sizeof(Star));
    if (!newStar) {
        printf("The cosmos is dark... memory allocation failed!\n");
        return NULL;
    }
    strcpy(newStar->name, name);
    newStar->next = NULL;
    return newStar;
}

// Function to add a star to the galaxy
void addStar(Star** galaxy, const char* name) {
    Star* newStar = createStar(name);
    if (!newStar) return;

    // Insert at the beginning for simplicity
    newStar->next = *galaxy;
    *galaxy = newStar;
    printf("A new star, %s, has been born into the galaxy!\n", name);
}

// Function to view all stars in the galaxy
void viewStars(Star* galaxy) {
    if (!galaxy) {
        printf("The galaxy is empty... no stars to behold.\n");
        return;
    }

    printf("Gazing into the galaxy...\n");
    Star* current = galaxy;
    while (current) {
        printf("Star: %s\n", current->name);
        current = current->next;
    }
}

// Function to delete a star by name
void deleteStar(Star** galaxy, const char* name) {
    Star* current = *galaxy;
    Star* previous = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Star %s not found in the galaxy.\n", name);
        return;
    }

    if (previous == NULL) {
        *galaxy = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("The star %s has vanished from the galaxy...\n", name);
}

// Function to free all stars in the galaxy
void freeGalaxy(Star* galaxy) {
    while (galaxy) {
        Star* temp = galaxy;
        galaxy = galaxy->next;
        free(temp);
    }
    printf("The cosmos is empty now... all stars have returned to stardust.\n");
}

// Main function to run the galaxy program
int main() {
    Star* galaxy = NULL;
    int choice;
    char starName[30];

    printf("Welcome to the Celestial Galaxy Manager!\n");

    do {
        printf("\nChoose an operation:\n");
        printf("1. Add a Star\n");
        printf("2. View Stars\n");
        printf("3. Delete a Star\n");
        printf("4. Free Galaxy Resources\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter the name of the star: ");
                fgets(starName, sizeof(starName), stdin);
                starName[strcspn(starName, "\n")] = 0; // remove newline
                addStar(&galaxy, starName);
                break;
            case 2:
                viewStars(galaxy);
                break;
            case 3:
                printf("Enter the name of the star to delete: ");
                fgets(starName, sizeof(starName), stdin);
                starName[strcspn(starName, "\n")] = 0; // remove newline
                deleteStar(&galaxy, starName);
                break;
            case 4:
                freeGalaxy(galaxy);
                galaxy = NULL; // set to NULL after freeing
                break;
            case 5:
                if (galaxy) {
                    freeGalaxy(galaxy);
                }
                printf("The Celestial Galaxy Manager is now shutting down... Goodbye!\n");
                break;
            default:
                printf("A phantom choice, please select a valid option.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}