//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void intro(void);
void game(void);
void playAgain(void);

int main() {
    srand(time(NULL));
    intro();
    game();
    playAgain();

    return 0;
}

// Print the introduction
void intro() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer, exploring a mysterious dungeon.\n");
    printf("Your goal is to find the treasure and escape alive.\n");
    printf("Are you ready to begin your quest? (y/n)\n");
    char choice;
    scanf("%c", &choice);
    if (choice!= 'y') {
        printf("Exiting program...\n");
        exit(0);
    }
}

// The game loop
void game() {
    int health = 100;
    int treasureFound = 0;
    int currentRoom = 1;

    while (health > 0 &&!treasureFound) {
        printf("\nYou are in room %d.\n", currentRoom);

        int choice;
        printf("What would you like to do?\n");
        printf("1. Search for treasure\n");
        printf("2. Rest and regain health\n");
        printf("3. Move to the next room\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (treasureFound) {
                printf("You have already found the treasure!\n");
            } else if (currentRoom == 5) {
                printf("You have found the treasure!\n");
                treasureFound = 1;
            } else {
                printf("You search the room but find nothing.\n");
            }
            break;
        case 2:
            printf("You rest and regain some health.\n");
            health += rand() % 10 + 1;
            break;
        case 3:
            currentRoom++;
            if (currentRoom > 5) {
                printf("You have reached the end of the dungeon.\n");
                printf("Congratulations! You have found the treasure and escaped alive!\n");
            } else {
                printf("You move to the next room.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    if (treasureFound) {
        printf("\nYou have found the treasure and escaped alive!\n");
    } else {
        printf("\nYou have been defeated by the dungeon.\n");
    }
}

// Ask the player if they want to play again
void playAgain() {
    char choice;
    printf("\nDo you want to play again? (y/n)\n");
    scanf("%c", &choice);
    if (choice == 'y') {
        main();
    } else {
        printf("Exiting program...\n");
        exit(0);
    }
}