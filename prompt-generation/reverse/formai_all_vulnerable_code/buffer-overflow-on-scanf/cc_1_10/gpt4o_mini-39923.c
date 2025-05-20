//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 5
#define QUESTIONS 5

typedef struct {
    char name[100];
    int score;
} Player;

void ask_question(Player *player) {
    int num1, num2, answer, user_answer, operation;
    char op;

    // Randomly generate numbers and operator
    num1 = rand() % 100;
    num2 = rand() % 100;
    operation = rand() % 4; // 0: +, 1: -, 2: *, 3: /

    switch (operation) {
        case 0:
            op = '+';
            answer = num1 + num2;
            break;
        case 1:
            op = '-';
            answer = num1 - num2;
            break;
        case 2:
            op = '*';
            answer = num1 * num2;
            break;
        case 3:
            op = (num2 == 0) ? 1 : 0; // Prevent division by zero
            answer = (op) ? num1 / num2 : 0; // If op == 1 (div by zero), answer = 0
            break;
    }

    // Ask question
    if (operation == 3 && op == 1) {
        printf("%s, What is %d / %d? (Division by zero question.)\n", player->name, num1, num2);
    } else {
        printf("%s, What is %d %c %d?\n", player->name, num1, op, num2);
    }

    // Get user answer
    printf("Your answer: ");
    scanf("%d", &user_answer);

    // Check answer
    if (user_answer == answer) {
        printf("Correct!\n");
        player->score++;
    } else {
        printf("Incorrect! The correct answer was %d.\n", answer);
    }
}

void display_scores(Player players[], int player_count) {
    printf("\nScores:\n");
    for (int i = 0; i < player_count; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int player_count;

    srand(time(NULL)); // Seed for random number generation

    printf("Welcome to the Multiplayer Arithmetic Quiz!\n");
    printf("How many players (max %d)?: ", MAX_PLAYERS);
    scanf("%d", &player_count);

    // Input validation for player count
    if (player_count < 1 || player_count > MAX_PLAYERS) {
        printf("Invalid player count. Exiting.\n");
        return 1;
    }

    // Get players' names
    for (int i = 0; i < player_count; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    // Ask questions to each player
    for (int i = 0; i < QUESTIONS; i++) {
        for (int j = 0; j < player_count; j++) {
            ask_question(&players[j]);
        }
    }

    // Display final scores
    display_scores(players, player_count);

    // Determine winner
    int highest_score = 0;
    Player *winner;
    for (int i = 0; i < player_count; i++) {
        if (players[i].score > highest_score) {
            highest_score = players[i].score;
            winner = &players[i];
        }
    }

    printf("\nThe winner is %s with a score of %d!\n", winner->name, winner->score);

    return 0;
}