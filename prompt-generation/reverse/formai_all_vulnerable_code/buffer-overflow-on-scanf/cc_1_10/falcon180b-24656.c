//Falcon-180B DATASET v1.0 Category: Game ; Style: random
#include <stdio.h>

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int player_score = 0, computer_score = 0;
    char choice;

    // Game loop
    while(1) {
        // Print scores
        printf("Player score: %d\n", player_score);
        printf("Computer score: %d\n", computer_score);

        // Ask player for choice
        printf("Enter your choice (r for rock, p for paper, s for scissors): ");
        scanf(" %c", &choice);

        // Generate computer's choice
        int computer_choice = rand_num(1, 3);
        if(computer_choice == 1) {
            printf("Computer chose rock.\n");
        } else if(computer_choice == 2) {
            printf("Computer chose paper.\n");
        } else {
            printf("Computer chose scissors.\n");
        }

        // Determine winner
        if(choice == 'r' && computer_choice == 2) {
            printf("Paper covers rock. Computer wins!\n");
            computer_score++;
        } else if(choice == 'p' && computer_choice == 1) {
            printf("Rock crushes paper. Player wins!\n");
            player_score++;
        } else if(choice =='s' && computer_choice == 3) {
            printf("Scissors cuts paper. Player wins!\n");
            player_score++;
        } else if(choice =='s' && computer_choice == 1) {
            printf("Rock crushes scissors. Computer wins!\n");
            computer_score++;
        } else if(choice == 'p' && computer_choice == 3) {
            printf("Scissors cuts paper. Computer wins!\n");
            computer_score++;
        } else {
            printf("It's a tie!\n");
        }

        // Check for game over
        if(player_score == 5 || computer_score == 5) {
            printf("Game over! Player wins with a score of %d to %d.\n", player_score, computer_score);
            break;
        }
    }

    return 0;
}