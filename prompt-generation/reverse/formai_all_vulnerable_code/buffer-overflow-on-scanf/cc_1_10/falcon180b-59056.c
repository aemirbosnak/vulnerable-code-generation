//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to print a message with a delay
void delay_print(char* message, int delay) {
    int i = 0;
    while (message[i]!= '\0') {
        printf("%c", message[i]);
        fflush(stdout);
        usleep(100000); // 100ms delay
        i++;
    }
    printf("\n");
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Initialize game variables
    int player_score = 0;
    int computer_score = 0;
    int round_number = 1;

    // Play the game
    while (player_score < 3 && computer_score < 3) {
        printf("Round %d\n", round_number);

        // Player's turn
        int player_choice = rand_num(1, 3);
        delay_print("Choose rock, paper, or scissors: ", 500);
        char player_move;
        scanf(" %c", &player_move);

        switch (player_move) {
            case 'r':
                player_choice = 1;
                break;
            case 'p':
                player_choice = 2;
                break;
            case's':
                player_choice = 3;
                break;
            default:
                printf("Invalid move. Computer wins this round.\n");
                computer_score++;
                break;
        }

        // Computer's turn
        int computer_choice = rand_num(1, 3);
        delay_print("Computer chooses: ", 500);
        printf("%c\n", 'r' + computer_choice - 1);

        // Determine the winner of the round
        if (player_choice == computer_choice) {
            printf("It's a tie!\n");
        } else if ((player_choice == 1 && computer_choice == 2) ||
                   (player_choice == 2 && computer_choice == 1) ||
                   (player_choice == 3 && computer_choice == 1)) {
            printf("You win this round!\n");
            player_score++;
        } else {
            printf("Computer wins this round.\n");
            computer_score++;
        }

        round_number++;
    }

    // Print the final score
    if (player_score == 3) {
        printf("You win the game!\n");
    } else if (computer_score == 3) {
        printf("You lose the game.\n");
    } else {
        printf("It's a tie.\n");
    }

    return 0;
}