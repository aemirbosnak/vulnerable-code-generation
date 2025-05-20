//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to display the opening message
void openingMessage() {
    printf("***Welcome to Haunted House Simulator***\n");
    printf("You are about to enter a creepy old mansion that is rumored to be haunted.\n");
    printf("Are you brave enough to explore the house and uncover its secrets?\n");
    printf("Let's find out...\n\n");
}

// Function to randomly select a room in the house
int selectRoom() {
    srand(time(0));
    int room = rand() % 5 + 1;
    printf("Entering Room %d...\n", room);
    return room;
}

// Function to simulate a spooky event in the room
void spookyEvent(int room) {
    switch(room) {
        case 1: printf("You hear a faint whisper...\n");
                break;
        case 2: printf("You feel a cold breeze...\n");
                break;
        case 3: printf("You see a shadow move across the room...\n");
                break;
        case 4: printf("You smell a strange odor...\n");
                break;
        case 5: printf("You hear a loud creaking noise...\n");
                break;
    }
}

// Function to prompt the user for the next action
void nextAction() {
    printf("What would you like to do next?\n");
    printf("1. Search the room\n");
    printf("2. Leave the room\n");
}

// Function to process the user's choice of action
void processAction(int action, int room) {
    switch(action) {
        case 1: printf("You search the room and find nothing of interest.\n");
                spookyEvent(room);
                break;
        case 2: printf("You leave the room and enter the hallway.\n");
                break;
        default: printf("Invalid choice. Please try again.\n");
                 nextAction();
                 int nextActionChoice;
                 scanf("%d", &nextActionChoice);
                 processAction(nextActionChoice, room);
                 break;
    }
}

// Function to display the closing message
void closingMessage() {
    printf("\nYou have successfully explored the haunted house.\n");
    printf("Thank you for playing Haunted House Simulator!\n");
}

// Main function to run the program
int main() {
    openingMessage();
    int room = selectRoom();
    nextAction();
    int action;
    scanf("%d", &action);
    processAction(action, room);
    closingMessage();
    return 0;
}