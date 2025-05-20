//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 5
#define MAX_QUESTIONS 3

typedef struct {
    char name[50];
    int score;
} Player;

void askQuestion(int playerIndex, Player *player);
void displayScores(Player players[], int numPlayers);
void determineWinner(Player players[], int numPlayers);

int main() {
    int numPlayers, i;
    Player players[MAX_PLAYERS];

    printf("Welcome to the Multiplayer Arithmetic Game!\n");
    printf("Enter the number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);
    while(numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Please enter again (1 to %d): ", MAX_PLAYERS);
        scanf("%d", &numPlayers);
    }

    // Input player names
    for (i = 0; i < numPlayers; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0; // Initialize score to 0
    }

    // Seed random number generator
    srand(time(NULL));

    // Each player gets questions
    for (i = 0; i < numPlayers; i++) {
        for (int j = 0; j < MAX_QUESTIONS; j++) {
            askQuestion(i, &players[i]);
        }
    }

    // Display scores and determine winner
    displayScores(players, numPlayers);
    determineWinner(players, numPlayers);

    return 0;
}

void askQuestion(int playerIndex, Player *player) {
    int a = rand() % 100; // Random number between 0-99
    int b = rand() % 100; // Random number between 0-99
    char operators[4] = {'+', '-', '*', '/'};
    char operator = operators[rand() % 4];
    float correct_answer, player_answer;

    printf("\n%s, solve this question: %d %c %d = ", player->name, a, operator, b);
    
    switch (operator) {
        case '+':
            correct_answer = a + b;
            break;
        case '-':
            correct_answer = a - b;
            break;
        case '*':
            correct_answer = a * b;
            break;
        case '/':
            if (b != 0) {
                correct_answer = (float)a / b;
            } else {
                printf("Division by zero is not allowed, skipping this question.\n");
                return; // Skip this question if division by zero
            }
            break;
    }
    
    scanf("%f", &player_answer);

    // Check if the player's answer is correct
    if (fabs(player_answer - correct_answer) < 0.01) {
        printf("Correct!\n");
        player->score++;
    } else {
        printf("Wrong! The correct answer is %.2f.\n", correct_answer);
    }
}

void displayScores(Player players[], int numPlayers) {
    printf("\nScores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

void determineWinner(Player players[], int numPlayers) {
    int highestScore = -1;
    int winnerIndex = -1;

    for (int i = 0; i < numPlayers; i++) {
        if (players[i].score > highestScore) {
            highestScore = players[i].score;
            winnerIndex = i;
        }
    }

    printf("\nThe winner is %s with %d points!\n", players[winnerIndex].name, players[winnerIndex].score);
}