//GPT-4o-mini DATASET v1.0 Category: Table Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random math question
void generate_question(int *num1, int *num2, char *operation) {
    *num1 = rand() % 10;  // Random number between 0 and 9
    *num2 = rand() % 10;  // Random number between 0 and 9
    int op = rand() % 3;  // Random operation (0: +, 1: -, 2: *)
    switch(op) {
        case 0:
            *operation = '+';
            break;
        case 1:
            *operation = '-';
            break;
        case 2:
            *operation = '*';
            break;
    }
}

// Function to calculate the answer based on the operation
int calculate_answer(int num1, int num2, char operation) {
    switch(operation) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        default: return 0; // Should not reach here
    }
}

// Function to play the Math Duel game
void play_game(int target_score) {
    int player1_score = 0;
    int player2_score = 0;
    int current_player = 1; // Player 1 starts
    int num1, num2, answer, user_answer;
    char operation;

    while (player1_score < target_score && player2_score < target_score) {
        generate_question(&num1, &num2, &operation);
        answer = calculate_answer(num1, num2, operation);
        
        printf("Player %d's turn:\n", current_player);
        printf("What is %d %c %d? ", num1, operation, num2);
        scanf("%d", &user_answer);

        if (user_answer == answer) {
            printf("Correct!\n");
            if (current_player == 1) {
                player1_score++;
            } else {
                player2_score++;
            }
        } else {
            printf("Wrong! The correct answer is %d.\n", answer);
        }

        printf("Scores: Player 1 - %d, Player 2 - %d\n\n", player1_score, player2_score);
        
        // Switch player turn
        current_player = (current_player == 1) ? 2 : 1;
    }

    // Declare the result
    if (player1_score >= target_score) {
        printf("Player 1 wins with a score of %d!\n", player1_score);
    } else {
        printf("Player 2 wins with a score of %d!\n", player2_score);
    }
}

int main() {
    srand(time(NULL)); // Seed for random number generation
    int target_score;

    printf("Welcome to Math Duel!\n");
    printf("Enter the target score to win: ");
    scanf("%d", &target_score);

    // Start the Math Duel game
    play_game(target_score);

    return 0;
}