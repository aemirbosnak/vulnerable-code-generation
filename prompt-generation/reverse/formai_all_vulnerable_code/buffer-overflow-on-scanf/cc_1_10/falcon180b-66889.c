//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: authentic
#include <stdio.h>

// Function prototypes
void start();
void room1();
void room2();
void room3();

int main() {
    start();
    return 0;
}

// Start of game
void start() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You find yourself in a dark room with three doors.\n");
    printf("Which door do you choose? 1, 2 or 3: ");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            room1();
            break;
        case 2:
            room2();
            break;
        case 3:
            room3();
            break;
        default:
            printf("Invalid choice. Game over.\n");
            break;
    }
}

// Room 1
void room1() {
    printf("You enter Room 1.\n");
    printf("There is a table with a key on it.\n");
    printf("Do you take the key? (y/n): ");
    char answer;
    scanf(" %c", &answer);

    if(answer == 'y' || answer == 'Y') {
        printf("You take the key.\n");
    } else {
        printf("You leave the key.\n");
    }

    printf("Do you go back? (y/n): ");
    scanf(" %c", &answer);

    if(answer == 'y' || answer == 'Y') {
        start();
    } else {
        printf("Game over.\n");
    }
}

// Room 2
void room2() {
    printf("You enter Room 2.\n");
    printf("There is a locked chest.\n");
    printf("Do you use the key? (y/n): ");
    char answer;
    scanf(" %c", &answer);

    if(answer == 'y' || answer == 'Y') {
        printf("You unlock the chest and find a treasure!\n");
    } else {
        printf("You leave the chest locked.\n");
    }

    printf("Do you go back? (y/n): ");
    scanf(" %c", &answer);

    if(answer == 'y' || answer == 'Y') {
        start();
    } else {
        printf("Game over.\n");
    }
}

// Room 3
void room3() {
    printf("You enter Room 3.\n");
    printf("There is a door with a puzzle on it.\n");
    printf("Solve the puzzle to continue.\n");
    printf("The puzzle is: 2 + 2 =?\n");
    int answer;
    scanf("%d", &answer);

    if(answer == 4) {
        printf("You solve the puzzle and enter the next room.\n");
    } else {
        printf("You fail to solve the puzzle and the game is over.\n");
    }
}