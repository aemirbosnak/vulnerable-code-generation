//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

/*
    This program simulates a haunted house experience. The user has to navigate through several rooms and complete various
    tasks to escape the house. However, there are some obstacles and spooky surprises along the way.
*/

// Function to delay execution
void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

// Function to print out the room description
void printRoom(int roomNumber) {
    switch(roomNumber) {
        case 1: printf("You find yourself in a dimly lit hallway. There are cobwebs covering the walls and the air is musty.\n"); break;
        case 2: printf("You enter a room that looks like it hasn't been used in years. The furniture is covered in dust and there's a foul odor in the air.\n"); break;
        case 3: printf("You walk into a room that's lit by candlelight. The room is filled with various occult objects and the air feels heavy.\n"); break;
        case 4: printf("You find yourself in a spacious lounge with high ceilings. There's a fireplace in the corner and an old piano in the center of the room.\n"); break;
        case 5: printf("You enter a room that's pitch black. You can't see anything, but you can hear faint whispers in the darkness.\n"); break;
    }
}

// Function to perform a task in the room
bool performTask(int roomNumber) {
    switch(roomNumber) {
        case 1:
            printf("You notice a key hidden under a loose floorboard. Do you take it?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                printf("You took the key!\n");
                return true;
            }
            else {
                printf("You decided not to take the key.\n");
                return false;
            }
            break;
        case 2:
            printf("There's something written on the wall in blood. It says 'Get out while you can'.\n");
            return false;
            break;
        case 3:
            printf("There's a book on a pedestal. Do you open it?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            int openBook;
            scanf("%d", &openBook);
            if (openBook == 1) {
                printf("You open the book and find a clue inside that leads you to the next room.\n");
                return true;
            }
            else {
                printf("You leave the book alone.\n");
                return false;
            }
            break;
        case 4:
            printf("You notice a lever hidden behind the piano. Do you pull it?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            int pullLever;
            scanf("%d", &pullLever);
            if (pullLever == 1) {
                printf("You pull the lever and a secret door opens behind the fireplace.\n");
                return true;
            }
            else {
                printf("You leave the lever alone.\n");
                return false;
            }
            break;
        case 5:
            printf("You bump into something in the darkness. Do you investigate?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            int investigate;
            scanf("%d", &investigate);
            if (investigate == 1) {
                printf("You found a lantern and can now see your way through the darkness.\n");
                return true;
            }
            else {
                printf("You decide not to investigate and remain in the darkness.\n");
                delay(2000); // Wait for 2 seconds to simulate being lost in the darkness
                printf("You can feel yourself being surrounded by something... Something that's not quite human.\n");
                return false;
            }
            break;
    }
}

int main() {
    // Variable to keep track of progress
    int roomNumber = 1;
    bool hasKey = false;
    bool hasEscaped = false;
    
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You find yourself standing in front of an old, decrepit house. It looks like it hasn't been lived in for years.\n");
    printf("You're not exactly sure how you got here, but you know that you need to get out as soon as possible.\n");
    printf("You take a deep breath and walk inside...\n\n");
    
    while (!hasEscaped) {
        printRoom(roomNumber);
        bool completedTask = performTask(roomNumber);
        if (completedTask) {
            if (roomNumber == 5 && !hasKey) {
                printf("You can hear something chasing you through the darkness. You run back to the previous room and lock the door.\n");
            }
            else if (roomNumber == 5 && hasKey) {
                printf("You use the key to unlock the door and escape the house! Congratulations, you made it out alive!\n");
                hasEscaped = true;
            }
            else {
                roomNumber++;
                printf("You unlocked the door and proceed to the next room.\n");
            }
        }
        else {
            printf("You're unable to complete the task and are forced to stay in the room.\n");
        }
        printf("\n");
    }
    
    return 0;
}