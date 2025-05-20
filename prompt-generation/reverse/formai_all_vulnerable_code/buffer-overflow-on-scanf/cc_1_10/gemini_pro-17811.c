//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_QUESTIONS 10

struct player {
    char name[32];
    int score;
};

struct question {
    int a;
    int b;
    int answer;
};

void generate_question(struct question *q) {
    q->a = rand() % 100;
    q->b = rand() % 100;
    q->answer = q->a + q->b;
}

int main() {
    struct player players[MAX_PLAYERS];
    struct question questions[MAX_QUESTIONS];

    // Initialize players
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    // Generate questions
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        generate_question(&questions[i]);
    }

    // Play the game
    int current_question = 0;
    while (current_question < MAX_QUESTIONS) {
        // Display the question
        struct question q = questions[current_question];
        printf("Question %d: %d + %d = ?\n", current_question + 1, q.a, q.b);

        // Get player answers
        int answers[MAX_PLAYERS];
        for (int i = 0; i < MAX_PLAYERS; i++) {
            printf("%s's answer: ", players[i].name);
            scanf("%d", &answers[i]);
        }

        // Check answers
        for (int i = 0; i < MAX_PLAYERS; i++) {
            if (answers[i] == q.answer) {
                players[i].score++;
            }
        }

        current_question++;
    }

    // Display the results
    printf("Scores:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}