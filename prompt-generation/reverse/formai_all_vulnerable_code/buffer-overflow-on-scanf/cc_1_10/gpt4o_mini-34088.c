//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PLAYERS 5
#define MAX_PROBLEMS 10

void generate_problem(int *num1, int *num2, char *operation) {
    *num1 = rand() % 100; // Random number between 0 and 99
    *num2 = rand() % 100; // Random number between 0 and 99
    int op = rand() % 4; // Choose an operation
    switch (op) {
        case 0:
            *operation = '+';
            break;
        case 1:
            *operation = '-';
            break;
        case 2:
            *operation = '*';
            break;
        case 3:
            *operation = '/';
            *num2 = (*num2 == 0) ? 1 : *num2; // To avoid division by zero
            break;
    }
}

int calculate_answer(int num1, int num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0;
    }
}

void display_scores(int scores[], int num_players) {
    printf("\nCurrent Scores:\n");
    for (int i = 0; i < num_players; i++) {
        printf("Player %d: %d\n", i + 1, scores[i]);
    }
}

int main() {
    int num_players;
    char player_names[MAX_PLAYERS][50];
    int scores[MAX_PLAYERS] = {0};
    
    printf("Enter the number of players (1 - %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    
    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }
    
    for (int i = 0; i < num_players; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", player_names[i]);
    }
    
    srand(time(NULL)); // Seed the random number generator

    for (int round = 1; round <= MAX_PROBLEMS; round++) {
        printf("\n--- Round %d ---\n", round);
        for (int i = 0; i < num_players; i++) {
            int num1, num2;
            char operation;
            generate_problem(&num1, &num2, &operation);
            
            int correct_answer = calculate_answer(num1, num2, operation);
            printf("%s, solve: %d %c %d = ?\n", player_names[i], num1, operation, num2);
            
            int player_answer;
            printf("Enter your answer: ");
            scanf("%d", &player_answer);
            
            if (player_answer == correct_answer) {
                printf("Correct!\n");
                scores[i]++;
            } else {
                printf("Wrong! The correct answer was %d.\n", correct_answer);
            }
            display_scores(scores, num_players);
        }
    }
    
    printf("\n--- Final Scores ---\n");
    display_scores(scores, num_players);
    int max_score = 0; 
    int winner_idx = 0;
    
    for (int i = 0; i < num_players; i++) {
        if (scores[i] > max_score) {
            max_score = scores[i];
            winner_idx = i;
        }
    }
    
    printf("Congratulations %s! You are the champion with %d points!\n", player_names[winner_idx], max_score);

    return 0;
}