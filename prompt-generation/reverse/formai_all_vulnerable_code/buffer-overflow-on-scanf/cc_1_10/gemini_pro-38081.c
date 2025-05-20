//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_QUESTIONS 10

typedef struct {
    char name[20];
    int score;
} player;

typedef struct {
    int question;
    int answer;
} question;

int main() {
    // Initialize the game state
    int num_players;
    player players[MAX_PLAYERS];
    question questions[MAX_QUESTIONS];
    int current_question = 0;
    int current_player = 0;

    // Get the number of players
    printf("How many players are playing? (1-4): ");
    scanf("%d", &num_players);

    // Get the player names
    for (int i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    // Generate the questions
    srand(time(NULL));
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        questions[i].question = rand() % 100;
        questions[i].answer = questions[i].question + rand() % 10;
    }

    // Start the game loop
    while (current_question < MAX_QUESTIONS) {
        // Get the current player's answer
        printf("%s, what is %d + %d? ", players[current_player].name, questions[current_question].question, questions[current_question].answer);
        int answer;
        scanf("%d", &answer);

        // Check if the answer is correct
        if (answer == questions[current_question].answer) {
            // Increment the player's score
            players[current_player].score++;
            printf("Correct! %s's score is now %d.\n", players[current_player].name, players[current_player].score);
        } else {
            // Print an error message
            printf("Incorrect. The correct answer is %d.\n", questions[current_question].answer);
        }

        // Move to the next question
        current_question++;

        // Move to the next player
        current_player = (current_player + 1) % num_players;
    }

    // Print the final scores
    printf("Final scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}