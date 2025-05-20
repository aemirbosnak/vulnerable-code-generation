//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printIntroduction() {
    printf("\n\nWelcome to the Haunted House Simulator!\n");
    printf("You are now standing in front of a spooky old house.\n");
    printf("You hear strange noises and see shadows moving in the windows.\n");
    printf("Do you dare to enter and explore the house?\n\n");
}

int getRandomNumber(int min, int max) {
    srand(time(0));
    return (rand() % (max - min + 1)) + min;
}

void exploreTheHouse() {
    printf("You enter the house and hear the door slam shut.\n");
    printf("The room is dark and damp, and the air is heavy with the smell of decay.\n");
    printf("You see a staircase leading up and a doorway to your left.\n");
    printf("Which way do you want to go? (1: Upstairs, 2: Left Door): ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You climb up the stairs and reach the second floor.\n");
        printf("The hallway is long and there are doors on both sides.\n");
        printf("You hear creaking sounds and footsteps coming from the end of the hallway.\n");
        printf("Do you want to explore the rooms? (1: Yes, 2: No): ");
        scanf("%d", &choice);

        if (choice == 1) {
            int ghostsFound = getRandomNumber(1, 4);
            printf("You enter a room and see a ghost hovering over the bed.\n");
            printf("You run out of the room and try another one.\n");

            if (ghostsFound > 1) {
                printf("You find more ghosts in the other rooms.\n");
            }
            else {
                printf("You escape from the haunted house without encountering any more ghosts!\n");
            }
        }
        else {
            printf("You exit the house without exploring the upper floor.\n");
        }
    }
    else {
        printf("You enter a room and see a coffin in the center.\n");
        printf("You hear a voice saying 'Welcome to your doom'.\n");
        printf("A skeleton jumps out of the coffin and chases you.\n");
        printf("You evade the skeleton and run out of the haunted house!\n");
    }
}

int main() {
    printIntroduction();
    exploreTheHouse();
    return 0;
}