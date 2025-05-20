//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display room description
void displayRoom(int roomNum) {
    switch (roomNum) {
        case 1:
            printf("You enter a dark foyer with a large door leading to the main living area.\n");
            break;
        case 2:
            printf("You step into the main living area with old, ratty furniture lining the room.\n");
            break;
        case 3:
            printf("You find yourself in the abandoned kitchen with old pots and pans scattered everywhere.\n");
            break;
        case 4:
            printf("You enter the bloodstained dining room. You can hear strange noises coming from the next room.\n");
            break;
        case 5:
            printf("You step into the creepy library with bookshelves full of dusty, old books towering over you.\n");
            break;
        case 6:
            printf("You enter a hallway with several doors leading to unknown areas of the haunted house.\n");
            break;
        case 7:
            printf("You cautiously open the door to a dimly lit bedroom with a tattered bed.\n");
            break;
        case 8:
            printf("You dare to enter the mysterious basement, shrouded in complete darkness.\n");
            break;
        default:
            printf("You seem to be lost in the haunted house. You can't find your way out.\n");
            break;
    }
}

// Function to generate random room number
int generateRoomNum() {
    int roomNum;
    srand(time(0));
    roomNum = rand() % 8 + 1; // roomNum will be between 1 and 8
    return roomNum;
}

int main() {
    int currentRoom = generateRoomNum(); // initialize current room as a randomly generated number
    int choice;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself standing in the entranceway of a creepy old house.\n");
    displayRoom(currentRoom); // display initial room description

    do {
        printf("What would you like to do?\n");
        printf("1. Move to another room.\n");
        printf("2. Investigate the current room.\n");
        printf("3. Exit the Haunted House Simulator.\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                currentRoom = generateRoomNum(); // change current room to a random new room
                printf("You have moved to a new room.\n");
                displayRoom(currentRoom); // display new room description
                break;
            case 2:
                printf("You look around the room more carefully and realize... it is haunted!\n");
                break;
            case 3:
                printf("Thank you for playing the Haunted House Simulator!\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}