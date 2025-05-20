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
    int num1;
    int num2;
    char operator;
} question;

// Function to generate a random question
question generate_question() {
    question q;
    q.num1 = rand() % 100;
    q.num2 = rand() % 100;
    q.operator = "+-*/"[rand() % 4];
    return q;
}

// Function to check if a player's answer is correct
int check_answer(question q, int answer) {
    int correct_answer;
    switch (q.operator) {
        case '+':
            correct_answer = q.num1 + q.num2;
            break;
        case '-':
            correct_answer = q.num1 - q.num2;
            break;
        case '*':
            correct_answer = q.num1 * q.num2;
            break;
        case '/':
            correct_answer = q.num1 / q.num2;
            break;
    }
    return answer == correct_answer;
}

// Function to play the game
void play_game() {
    // Initialize players and questions
    player players[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    question questions[MAX_QUESTIONS];
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        questions[i] = generate_question();
    }

    // Play the game
    int current_player = 0;
    int current_question = 0;
    while (current_question < MAX_QUESTIONS) {
        // Get the current player's answer
        question q = questions[current_question];
        printf("%s, what is %d %c %d? ", players[current_player].name, q.num1, q.operator, q.num2);
        int answer;
        scanf("%d", &answer);

        // Check the answer
        if (check_answer(q, answer)) {
            // Increment the player's score
            players[current_player].score++;
            printf("Correct! Your score is now %d.\n", players[current_player].score);
        } else {
            printf("Incorrect. The correct answer is %d.\n", q.num1 + q.num2);
        }

        // Move to the next player and question
        current_player = (current_player + 1) % MAX_PLAYERS;
        current_question++;
    }

    // Print the final scores
    printf("Final scores:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}