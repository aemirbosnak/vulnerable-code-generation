//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number between min and max
int generateRandom(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL)); // initialize random seed with current time

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have entered a creepy old house with creaky floors and flickering lights.\n");
    printf("You feel a sense of dread as you explore the house...\n\n");

    int currentRoom = 1; // start in room 1

    while (currentRoom != 6) { // loop while not in final room
        switch (currentRoom) {
            case 1:
                printf("You are in the foyer.\n");
                printf("There are stairs to your left and a closed door in front of you.\n");
                printf("What do you want to do? (1 = go upstairs, 2 = open door): ");
                int choice1;
                scanf("%d", &choice1);
                if (choice1 == 1) {
                    currentRoom = 2;
                } else {
                    printf("The door won't budge.\n");
                }
                break;

            case 2:
                printf("You are in the upstairs hallway.\n");
                printf("There are three doors: one on your left, one straight ahead, and one on your right.\n");
                printf("Which door do you want to open? (1 = left, 2 = straight, 3 = right): ");
                int choice2;
                scanf("%d", &choice2);
                if (choice2 == 1) {
                    currentRoom = 3;
                } else if (choice2 == 2) {
                    currentRoom = 4;
                } else {
                    currentRoom = 5;
                }
                break;

            case 3:
                printf("You are in a dusty old bedroom.\n");
                printf("There is nothing of interest here.\n");
                printf("You leave the bedroom and go back to the hallway.\n");
                currentRoom = 2;
                break;

            case 4:
                printf("You are in a dark and spooky bathroom.\n");
                printf("The mirror on the wall suddenly shatters into a million pieces!\n");
                printf("You hear a faint whisper saying 'get out'...\n");
                printf("You run out of the bathroom and back to the hallway.\n");
                currentRoom = 2;
                break;

            case 5:
                printf("You are in a musty old library.\n");
                printf("You notice a book with a strange symbol on the cover.\n");
                printf("Do you want to read the book? (1 = yes, 2 = no): ");
                int choice3;
                scanf("%d", &choice3);
                if (choice3 == 1) {
                    printf("You open the book and start reading.\n");
                    printf("Suddenly, the candles on the walls go out and you hear a faint cackle in the distance...\n");
                    printf("You quickly put the book back and leave the library in a hurry!\n");
                } else {
                    printf("You leave the library and go back to the hallway.\n");
                }
                currentRoom = 2;
                break;
        }
    }

    printf("\nYou have reached the final room!\n");
    printf("You find a chest with a note on top that reads: 'Congratulations, you have survived the Haunted House Simulator!'\n");
    printf("You open the chest and find a candy bar inside.\n");
    printf("You eat the candy bar and leave the house feeling relieved!\n");

    return 0;
}