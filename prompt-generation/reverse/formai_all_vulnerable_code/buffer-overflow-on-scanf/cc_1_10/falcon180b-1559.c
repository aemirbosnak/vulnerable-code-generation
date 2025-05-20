//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void start_game();
void play_game();
void end_game();

int main() {
    srand(time(0)); // Seed the random number generator
    start_game();
    return 0;
}

// Start the game
void start_game() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer exploring a mysterious dungeon.\n");
    printf("Your goal is to find the treasure and escape alive.\n");
    printf("Are you ready to begin? (y/n)\n");
    char choice;
    scanf("%c", &choice);
    if (choice!= 'y') {
        printf("Thanks for playing!\n");
        return;
    }
    play_game();
}

// Play the game
void play_game() {
    int health = 100;
    int treasure_found = 0;
    int room = 1;
    char choice;
    printf("You are in room %d.\n", room);
    while (health > 0 &&!treasure_found) {
        printf("What do you want to do?\n");
        printf("1. Move forward\n");
        printf("2. Move backward\n");
        printf("3. Check the room\n");
        printf("4. Rest\n");
        printf("5. Quit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                if (room < 10) {
                    room++;
                    printf("You moved forward to room %d.\n", room);
                } else {
                    printf("You can't move forward anymore.\n");
                }
                break;
            case '2':
                if (room > 1) {
                    room--;
                    printf("You moved backward to room %d.\n", room);
                } else {
                    printf("You can't move backward anymore.\n");
                }
                break;
            case '3':
                printf("You carefully examine the room.\n");
                if (room == 5) {
                    printf("You found the treasure!\n");
                    treasure_found = 1;
                } else {
                    printf("You didn't find anything.\n");
                }
                break;
            case '4':
                printf("You take a short rest.\n");
                health += rand() % 10 + 1;
                if (health > 100) {
                    health = 100;
                }
                break;
            case '5':
                printf("Thanks for playing!\n");
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
    if (treasure_found) {
        printf("Congratulations! You found the treasure and escaped alive.\n");
    } else {
        printf("Game over. You didn't find the treasure in time.\n");
    }
    end_game();
}

// End the game
void end_game() {
    printf("Do you want to play again? (y/n)\n");
    char choice;
    scanf("%c", &choice);
    if (choice == 'y') {
        start_game();
    }
}