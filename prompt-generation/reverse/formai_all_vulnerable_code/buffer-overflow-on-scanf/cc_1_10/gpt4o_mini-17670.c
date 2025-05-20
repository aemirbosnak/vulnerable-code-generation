//GPT-4o-mini DATASET v1.0 Category: Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number
int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to ask a math question and return the result
int ask_question(int level) {
    int num1, num2, operator;
    char op_symbol;
    int answer;

    // Generate two random numbers based on level.
    if (level == 1) { // Easy
        num1 = generate_random_number(1, 10);
        num2 = generate_random_number(1, 10);
    } else if (level == 2) { // Medium
        num1 = generate_random_number(10, 50);
        num2 = generate_random_number(1, 20);
    } else { // Hard
        num1 = generate_random_number(50, 100);
        num2 = generate_random_number(20, 50);
    }

    // Randomly choose an operator
    operator = generate_random_number(1, 4);
    
    if (operator == 1) { // Addition
        op_symbol = '+';
        answer = num1 + num2;
    } else if (operator == 2) { // Subtraction
        op_symbol = '-';
        answer = num1 - num2;
    } else if (operator == 3) { // Multiplication
        op_symbol = '*';
        answer = num1 * num2;
    } else { // Division
        // Ensure division is valid
        num2 = (num2 == 0) ? 1 : num2; // Avoid division by zero
        op_symbol = '/';
        answer = num1 / num2;
    }

    // Ask the question
    printf("What is %d %c %d? ", num1, op_symbol, num2);
    return answer;
}

// Function to play a round of Math Duel
void play_round(int player) {
    int score = 0;
    int answer;

    printf("Player %d's turn!\n", player);
    for (int i = 0; i < 5; i++) { // Each player gets 5 questions
        int level = (player == 1) ? 1 : 2; // Easy for player 1, Medium for player 2
        answer = ask_question(level);

        int player_answer;
        printf("Your answer: ");
        scanf("%d", &player_answer);
        
        if (player_answer == answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer was %d.\n", answer);
        }
    }
    
    printf("Player %d's score: %d\n", player, score);
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation
    
    int player1_score = 0, player2_score = 0;
    int rounds_to_win = 3; // Players need to win 3 rounds
    int round = 1;

    printf("Welcome to Math Duel!\n");
    printf("First player to score %d in total wins!\n", rounds_to_win);
    
    while (player1_score < rounds_to_win && player2_score < rounds_to_win) {
        printf("\n--- Round %d ---\n", round);
        play_round(1);
        player1_score++;

        play_round(2);
        player2_score++;
        
        printf("Score after Round %d: Player 1: %d, Player 2: %d\n", round, player1_score, player2_score);
        round++;
    }

    // Announce the winner
    if (player1_score == rounds_to_win) {
        printf("Player 1 wins the game!\n");
    } else {
        printf("Player 2 wins the game!\n");
    }

    return 0;
}