//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

void introduction();
int room1();
void room1Options();
int room2();
void room2Options();
int room3();
void room3Options();
void endGame();

int main() {
    introduction();
    room1();
    return 0;
}

void introduction() {
    printf("Welcome to the Adventure Game!\n");
    printf("You are stranded on an island and must find a way to escape.\n");
    printf("You come across a strange cave, do you want to enter it? (Y/N): ");
    char choice;
    scanf("%c", &choice);
    getchar();
    if (choice == 'N' || choice == 'n') {
        printf("\nYou decide not to enter the cave, but eventually come back to it later.\n");
        room1();
    }
    printf("\nYou enter the cave and find yourself in a dark room.");
    printf(" There are three doors in front of you.\n");
    room1Options();
}

int room1() {
    printf("\nWhich door do you choose? (1/2/3): ");
    int choice;
    scanf("%d", &choice);
    getchar();
    switch (choice) {
        case 1: return room2();
        case 2: return room3();
        case 3: printf("\nYou open the third door and a trap door opens underneath you. You fall to your death. Game Over."); exit(0);
        default: printf("\nInvalid choice. Try Again."); room1();
    }
    return 0;
}

void room1Options() {
    printf("Door 1: A faint light can be seen, perhaps a way out?\n");
    printf("Door 2: Noise can be heard, but it's difficult to make out what it is.\n");
    printf("Door 3: This one seems a bit too old, should you still try to open it?\n");
}

int room2() {
    printf("\nYou open the first door and find yourself in a small room with a torch.\n");
    printf("What do you do? (1/2):\n");
    printf("1. Take the torch and leave.\n");
    printf("2. Look for more things in the room.\n");
    int choice;
    scanf("%d", &choice);
    getchar();
    if (choice == 1) {
        printf("\nYou take the torch and leave the room.");
        return room3();
    }
    else if (choice == 2) {
        printf("\nYou search the room and find a map. Maybe it will help you.");
        printf(" You take it and leave the room.");
        return room3();
    }
    else {
        printf("\nInvalid choice. Try Again.");
        return room2();
    }
}

void room2Options() {
    printf("\nYou have already visited this room. Which door do you want to go through? (2/3):");
}

int room3() {
    printf("\nYou enter a large room with a lake in the middle.");
    printf(" On the other side, there is a boat.");
    printf("What do you want to do? (1/2):\n");
    printf("1. Walk around the lake to the boat.\n");
    printf("2. Swim across the lake to the boat.\n");
    int choice;
    scanf("%d", &choice);
    getchar();
    if (choice == 1) {
        printf("\nYou walk around the lake and reach the other side.");
        printf(" You get on the boat and start rowing.");
        endGame();
    }
    else if (choice == 2) {
        printf("\nYou try to swim across the lake, but the water is too deep and you drown. Game Over.");
        exit(0);
    }
    else {
        printf("\nInvalid choice. Try Again.");
        return room3();
    }
    return 0;
}

void room3Options() {
    printf("\nYou have already visited this room. What do you want to do? (2/3):");
}

void endGame() {
    printf("\nCongratulations! You escaped the island.");
    exit(0);
}