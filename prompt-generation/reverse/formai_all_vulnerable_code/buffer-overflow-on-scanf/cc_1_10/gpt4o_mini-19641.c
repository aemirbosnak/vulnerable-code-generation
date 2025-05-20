//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4
#define QUESTIONS 5

void clearScreen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the console
}

int generateQuestion(int *answer) {
    int num1 = rand() % 20;
    int num2 = rand() % 20;
    char operators[] = {'+', '-', '*'};
    char op = operators[rand() % 3];

    if (op == '+') {
        *answer = num1 + num2;
    } else if (op == '-') {
        *answer = num1 - num2;
    } else if (op == '*') {
        *answer = num1 * num2;
    }

    printf("What is %d %c %d? ", num1, op, num2);
    return 0; // Success
}

int main() {
    int numPlayers, scores[MAX_PLAYERS] = {0};
    char names[MAX_PLAYERS][20];
    srand(time(0));

    clearScreen();
    printf("Welcome to the Multiplayer Arithmetic Game!\n");
    printf("Enter the number of players (2 - %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    if (numPlayers < 2 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players. Exiting...\n");
        return 1;
    }

    // Get player names
    for(int i = 0; i < numPlayers; i++) {
        printf("Enter name for player %d: ", i + 1);
        scanf("%s", names[i]);
    }

    for (int i = 0; i < QUESTIONS; i++) {
        clearScreen();
        printf("Question round %d\n\n", i + 1);
        
        for (int j = 0; j < numPlayers; j++) {
            int answer, playerAnswer;
            generateQuestion(&answer);
            printf("%s, your turn: ", names[j]);
            scanf("%d", &playerAnswer);

            // Check answer
            if (playerAnswer == answer) {
                printf("Correct!\n");
                scores[j]++;
            } else {
                printf("Incorrect! The correct answer was %d.\n", answer);
            }

            printf("\n");
        }
        printf("Scores after round %d:\n", i + 1);
        for (int k = 0; k < numPlayers; k++) {
            printf("%s: %d\n", names[k], scores[k]);
        }

        printf("Press Enter to continue to the next round...\n");
        while ((getchar()) != '\n'); // Clear input buffer
        getchar(); // Wait for Enter key
    }

    // Determine the winner
    clearScreen();
    int maxScore = 0, winnerIndex = -1;
    for (int j = 0; j < numPlayers; j++) {
        if (scores[j] > maxScore) {
            maxScore = scores[j];
            winnerIndex = j;
        }
    }

    printf("Final Scores:\n");
    for (int k = 0; k < numPlayers; k++) {
        printf("%s: %d\n", names[k], scores[k]);
    }
    
    if (winnerIndex != -1) {
        printf("Congratulations %s! You are the champion with %d points!\n", names[winnerIndex], maxScore);
    }

    return 0;
}