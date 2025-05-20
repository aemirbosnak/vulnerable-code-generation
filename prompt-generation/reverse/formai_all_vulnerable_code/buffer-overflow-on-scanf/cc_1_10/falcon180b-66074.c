//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void start_game(void);
void play_game(void);
void end_game(int score);

int main() {
    srand(time(NULL));
    start_game();
    return 0;
}

// Start the game
void start_game(void) {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest to find the lost treasure.\n");
    printf("Are you ready to begin your journey? (y/n) ");
    char choice;
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y') {
        play_game();
    } else {
        printf("Thank you for playing.\n");
        exit(0);
    }
}

// Play the game
void play_game(void) {
    int score = 0;
    int room = 1;
    char choice;

    while (room <= 5) {
        printf("\nYou are in room %d.\n", room);
        printf("What would you like to do?\n");
        printf("1. Look around\n");
        printf("2. Move forward\n");
        printf("3. Turn back\n");
        printf("4. Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                printf("You look around and see a shiny object on the ground.\n");
                printf("Do you want to pick it up? (y/n) ");
                char pick;
                scanf("%c", &pick);
                if (pick == 'y' || pick == 'Y') {
                    printf("You picked up the object and gained 10 points!\n");
                    score += 10;
                } else {
                    printf("You left the object behind.\n");
                }
                break;
            case '2':
                room++;
                printf("You moved forward to room %d.\n", room);
                break;
            case '3':
                room--;
                printf("You turned back to room %d.\n", room);
                break;
            case '4':
                end_game(score);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
}

// End the game
void end_game(int score) {
    printf("\nGame over! You scored %d points.\n", score);
    printf("Thank you for playing.\n");
    exit(0);
}