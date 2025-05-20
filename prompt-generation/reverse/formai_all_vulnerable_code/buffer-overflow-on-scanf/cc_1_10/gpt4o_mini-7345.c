//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exploreRoom(int roomNumber);
void displayIntro();
int randomEvent();

int main() {
    int choice = 0;

    // Seed for random number generation
    srand(time(NULL));

    displayIntro();

    while (choice != 4) {
        printf("\nChoose a room to explore:\n");
        printf("1. The Dark Hallway\n");
        printf("2. The Spooky Library\n");
        printf("3. The Creepy Basement\n");
        printf("4. Exit the Haunted House\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                exploreRoom(1);
                break;
            case 2:
                exploreRoom(2);
                break;
            case 3:
                exploreRoom(3);
                break;
            case 4:
                printf("You have exited the haunted house. Hope you enjoyed your visit!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

void displayIntro() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Prepare yourself for some thrills and chills as you explore various eerie rooms...\n");
}

void exploreRoom(int roomNumber) {
    printf("\nYou enter room number %d...\n", roomNumber);
    int event = randomEvent();
    
    switch (event) {
        case 0:
            printf("It's eerily quiet here. You feel a chill down your spine.\n");
            break;
        case 1:
            printf("Suddenly, a ghost appears and lets out a terrifying scream!\n");
            printf("You ran away in terror!\n");
            break;
        case 2:
            printf("You find an old, dusty book that seems to shimmer in the dim light.\n");
            printf("You gained a mysterious item!\n");
            break;
        case 3:
            printf("A loud noise startles you, and you turn to find a skeleton!\n");
            printf("You bravely confront it and manage to escape!\n");
            break;
        case 4:
            printf("You discover a hidden treasure chest full of gold coins!\n");
            printf("You've become rich!\n");
            break;
        default:
            printf("Nothing happens, just silence.\n");
            break;
    }
}

int randomEvent() {
    // Generate a random event number
    return rand() % 5; // Generates a number between 0 and 4
}