//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to clear the screen
void clear_screen() {
    system("clear");
}

// Function to generate a random number between min and max
int generate_random_number(int min, int max) {
    srand(time(NULL));
    int number = rand() % (max - min + 1) + min;
    return number;
}

int main() {
    int player_score = 0;
    int computer_score = 0;
    int round_number = 1;
    int max_rounds = 5;

    clear_screen();

    printf("\n=== WELCOME TO MIND-BENDING CHALLENGE ===\n\n");

    printf("In this game, you will face off against the computer in a series of mind-bending challenges.\n");
    printf("Each challenge will require you to solve a complex equation or puzzle before the computer does.\n");
    printf("You will earn a point for each challenge you win, and the player with the most points after %d rounds wins.\n", max_rounds);

    printf("\nGood luck!\n\n");

    // Loop through each round
    while (round_number <= max_rounds) {
        printf("=== ROUND %d ===\n", round_number);

        // Generate a random problem
        int num1 = generate_random_number(1, 10);
        int num2 = generate_random_number(1, 10);
        char operator = generate_random_number(0, 1) == 0 ? '+' : '-';
        int answer = operator == '+' ? num1 + num2 : num1 - num2;

        // Display the problem
        printf("What is %d %c %d?\n", num1, operator, num2);

        // Get the player's answer
        int player_answer;
        scanf("%d", &player_answer);

        // Check the player's answer
        if (player_answer == answer) {
            printf("Correct! You earn a point!\n");
            player_score++;
        } else {
            printf("Incorrect! The computer earns a point!\n");
            computer_score++;
        }

        round_number++;

        // Pause between rounds
        printf("\n");
        printf("Press enter to continue.\n");
        getchar();
        getchar();

        clear_screen();
    }

    // Determine the winner
    printf("=== GAME OVER ===\n\n");
    printf("Player score: %d\n", player_score);
    printf("Computer score: %d\n\n", computer_score);
    if (player_score > computer_score) {
        printf("Congratulations, you win!\n");
    } else if (computer_score > player_score) {
        printf("Sorry, you lose.\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}