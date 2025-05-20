//GPT-4o-mini DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <pthread.h>

#define MAX_EXPRESSION_LENGTH 100
#define MAX_PLAYERS 5

typedef struct {
    int player_id;
    char expression[MAX_EXPRESSION_LENGTH];
} Player;

Player players[MAX_PLAYERS];

void *calculate(void *arg) {
    Player *p = (Player *)arg;
    double result;
    
    // Convert expression into a valid C expression
    // Note: Here we strictly evaluate basic calculations for simplicity
    // Ideally, you should use a parser for complex expressions
    if (sscanf(p->expression, "%lf", &result) == 0) {
        printf("Player %d: Could not parse expression %s\n", p->player_id, p->expression);
        pthread_exit(NULL);
    }
    
    // Example of hardcoded operations based on input, can be modified for more operations
    if (strstr(p->expression, "sqrt") != NULL) {
        result = sqrt(result);
    } else if (strstr(p->expression, "pow") != NULL) {
        double exponent;
        sscanf(strchr(p->expression, ',')+1, "%lf", &exponent);
        result = pow(result, exponent);
    } else if (strstr(p->expression, "sin") != NULL) {
        result = sin(result);
    } else if (strstr(p->expression, "cos") != NULL) {
        result = cos(result);
    } else if (strstr(p->expression, "tan") != NULL) {
        result = tan(result);
    } else {
        printf("Player %d: Invalid expression %s\n", p->player_id, p->expression);
        pthread_exit(NULL);
    }
    
    printf("Player %d: Result of '%s' is %.2f\n", p->player_id, p->expression, result);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_PLAYERS];
    int i, num_players;

    printf("Welcome to the Multiplayer Scientific Calculator!\n");
    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    if (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players! Exiting.\n");
        return 1;
    }

    // Gather input for each player
    for (i = 0; i < num_players; i++) {
        players[i].player_id = i + 1;
        printf("Player %d, enter your expression (e.g., sqrt(9), pow(2,3), sin(30)): ", players[i].player_id);
        scanf(" %[^\n]", players[i].expression);
    }

    // Create threads for each player to calculate their expression
    for (i = 0; i < num_players; i++) {
        if (pthread_create(&threads[i], NULL, calculate, (void *)&players[i]) != 0) {
            printf("Error creating thread for player %d\n", players[i].player_id);
            return 1;
        }
    }

    // Wait for all threads to finish
    for (i = 0; i < num_players; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All calculations are done!\n");
    return 0;
}