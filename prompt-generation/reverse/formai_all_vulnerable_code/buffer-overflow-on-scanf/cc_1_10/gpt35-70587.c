//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: asynchronous
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define MAX_CHOICES 3 // Rock, Paper, Scissor
#define P1_SCORE_TO_WIN 5 // Minimum score to win the game

static int p1_score = 0, p2_score = 0; // Keep track of scores of both players
static int game_over = 0; // Flag to indicate if game is over

enum Choices {
    ROCK = 1,
    PAPER,
    SCISSOR
};

// Function to get player's choice
int get_player_choice()
{
    int choice;
    printf("Enter your choice (1. Rock / 2. Paper / 3. Scissor): ");
    scanf("%d", &choice);

    // Check if choice is valid
    if (choice < 1 || choice > MAX_CHOICES) {
        printf("Invalid choice!\n");
        return get_player_choice();
    }

    return choice;
}

// Function to get computer's choice
int get_computer_choice()
{
    srand(time(NULL)); // Initialize seed for random number generator
    return (rand() % MAX_CHOICES) + 1; // Generate a random number between 1 and max_choices
}

// Function to check who won the round
void check_winner(int p1_choice, int p2_choice)
{
    if (p1_choice == p2_choice) { // Draw
        printf("DRAW!\n");
        return;
    }
 
    if ((p1_choice == ROCK && p2_choice == SCISSOR) || 
        (p1_choice == PAPER && p2_choice == ROCK) ||
        (p1_choice == SCISSOR && p2_choice == PAPER)) { // Player 1 wins
        printf("Player 1 WINS this round!\n");
        p1_score++;
    } else { // Player 2 wins
        printf("Player 2 WINS this round!\n");
        p2_score++;
    }
}

// Function to check if game is over
void check_game_over()
{
    if (p1_score >= P1_SCORE_TO_WIN) {
        printf("Congratulations! Player 1 WINS the game!\n");
        game_over = 1;
    } else if (p2_score >= P1_SCORE_TO_WIN) {
        printf("Congratulations! Player 2 WINS the game!\n");
        game_over = 1;
    } else {
        printf("Score: Player 1 - %d / Player 2 - %d\n", p1_score, p2_score);
    }
}

int main() 
{
    printf("Welcome to Rock-Paper-Scissors!\n\n");

    do {
        int p1_choice = get_player_choice();
        int p2_choice = get_computer_choice();

        printf("Player 1 chose ");
        switch (p1_choice) {
            case ROCK:
                printf("ROCK ");
                break;
            case PAPER:
                printf("PAPER ");
                break;
            case SCISSOR:
                printf("SCISSOR ");
                break;
        }
        printf("and Player 2 chose ");
        switch (p2_choice) {
            case ROCK:
                printf("ROCK ");
                break;
            case PAPER:
                printf("PAPER ");
                break;
            case SCISSOR:
                printf("SCISSOR ");
                break;
        }
        printf("\n");

        check_winner(p1_choice, p2_choice);
        check_game_over();

    } while (!game_over);

    return 0; 
}