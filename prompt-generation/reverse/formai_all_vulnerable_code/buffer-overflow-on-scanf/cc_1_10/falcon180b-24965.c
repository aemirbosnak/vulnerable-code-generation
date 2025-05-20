//Falcon-180B DATASET v1.0 Category: Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void game_init(void);
void game_loop(void);
void game_end(void);

int main(void) {
    srand(time(NULL)); // Seed the random number generator
    game_init(); // Initialize the game
    game_loop(); // Start the game loop
    game_end(); // End the game
    return 0;
}

void game_init(void) {
    printf("Welcome to the game!\n");
}

void game_loop(void) {
    int player_score = 0;
    int computer_score = 0;
    char choice;

    while (player_score < 5 && computer_score < 5) {
        printf("Your score: %d\n", player_score);
        printf("Computer score: %d\n", computer_score);
        printf("Choose rock, paper, or scissors: ");
        scanf(" %c", &choice);

        if (choice == 'r' || choice == 'R') {
            printf("You chose rock.\n");
            if (rand() % 2 == 0) {
                printf("Computer chose scissors.\n");
                computer_score++;
            } else {
                printf("Computer chose paper.\n");
                player_score++;
            }
        } else if (choice == 'p' || choice == 'P') {
            printf("You chose paper.\n");
            if (rand() % 2 == 0) {
                printf("Computer chose rock.\n");
                computer_score++;
            } else {
                printf("Computer chose scissors.\n");
                player_score++;
            }
        } else if (choice =='s' || choice == 'S') {
            printf("You chose scissors.\n");
            if (rand() % 2 == 0) {
                printf("Computer chose paper.\n");
                computer_score++;
            } else {
                printf("Computer chose rock.\n");
                player_score++;
            }
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    if (player_score == 5) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
}

void game_end(void) {
    printf("Thanks for playing!\n");
}