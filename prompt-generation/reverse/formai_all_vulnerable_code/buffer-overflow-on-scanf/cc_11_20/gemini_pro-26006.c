//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct player {
    char name[20];
    int score;
} player;

int main() {
    srand(time(NULL));

    // Create players
    player players[4];
    for (int i = 0; i < 4; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    // Game loop
    while (1) {
        // Generate random numbers
        int num1 = rand() % 10;
        int num2 = rand() % 10;
        int operator = rand() % 4;

        // Display question
        printf("Question: ");
        switch (operator) {
            case 0:
                printf("%d + %d", num1, num2);
                break;
            case 1:
                printf("%d - %d", num1, num2);
                break;
            case 2:
                printf("%d * %d", num1, num2);
                break;
            case 3:
                printf("%d / %d", num1, num2);
                break;
        }

        // Get answers
        int answers[4];
        for (int i = 0; i < 4; i++) {
            printf("\n%s's answer: ", players[i].name);
            scanf("%d", &answers[i]);
        }

        // Check answers
        int correct_answer = 0;
        switch (operator) {
            case 0:
                correct_answer = num1 + num2;
                break;
            case 1:
                correct_answer = num1 - num2;
                break;
            case 2:
                correct_answer = num1 * num2;
                break;
            case 3:
                if (num2 != 0) {
                    correct_answer = num1 / num2;
                }
                break;
        }

        // Update scores
        for (int i = 0; i < 4; i++) {
            if (answers[i] == correct_answer) {
                players[i].score++;
            }
        }

        // Display scores
        printf("\nScores:\n");
        for (int i = 0; i < 4; i++) {
            printf("%s: %d\n", players[i].name, players[i].score);
        }

        // Check for winner
        int winning_score = -1;
        char winning_name[20];
        for (int i = 0; i < 4; i++) {
            if (players[i].score > winning_score) {
                winning_score = players[i].score;
                strcpy(winning_name, players[i].name);
            }
        }

        if (winning_score != -1) {
            printf("\nCongratulations to %s for winning with a score of %d!\n", winning_name, winning_score);
            break;
        }
    }

    return 0;
}