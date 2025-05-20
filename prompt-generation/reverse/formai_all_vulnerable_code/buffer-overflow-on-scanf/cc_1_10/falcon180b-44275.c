//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void game_init();
void game_loop();
void game_end();

int main() {
    srand(time(NULL)); // Seed the random number generator
    game_init(); // Initialize the game
    game_loop(); // Run the game loop
    game_end(); // End the game
    return 0;
}

void game_init() {
    printf("Welcome to the game!\n");
    printf("Press enter to start.\n");
    getchar();
}

void game_loop() {
    int player_score = 0;
    int computer_score = 0;
    char choice;
    do {
        printf("Choose rock, paper, or scissors.\n");
        scanf(" %c", &choice);
        switch (choice) {
            case 'r':
                printf("You chose rock.\n");
                break;
            case 'p':
                printf("You chose paper.\n");
                break;
            case's':
                printf("You chose scissors.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        int computer_choice = rand() % 3; // Randomly choose rock, paper, or scissors
        if (computer_choice == 0) {
            printf("The computer chose rock.\n");
        } else if (computer_choice == 1) {
            printf("The computer chose paper.\n");
        } else {
            printf("The computer chose scissors.\n");
        }
        if ((computer_choice == 0 && choice =='s') ||
            (computer_choice == 1 && choice == 'r') ||
            (computer_choice == 2 && choice == 'p')) {
            printf("You win this round!\n");
            player_score++;
        } else if ((computer_choice == 0 && choice == 'r') ||
                   (computer_choice == 1 && choice == 'p') ||
                   (computer_choice == 2 && choice =='s')) {
            printf("The computer wins this round.\n");
            computer_score++;
        } else {
            printf("It's a tie.\n");
        }
    } while (player_score!= 5 && computer_score!= 5);
    if (player_score == 5) {
        printf("You win the game!\n");
    } else {
        printf("The computer wins the game.\n");
    }
}

void game_end() {
    printf("Thanks for playing!\n");
}