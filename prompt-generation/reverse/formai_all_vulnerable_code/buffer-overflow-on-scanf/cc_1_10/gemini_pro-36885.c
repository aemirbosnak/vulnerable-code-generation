//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PLAYERS 4  // Maximum number of players
#define MAX_OPERATIONS 10  // Maximum number of operations per player

typedef struct {
    char name[20];
    int score;
    int operations[MAX_OPERATIONS];  // Array to store the operations performed by the player
} Player;

// Function to get a random number between min and max
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random operation
int generate_operation() {
    return get_random_number(1, 4);  // 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division
}

// Function to perform an operation on two numbers
int perform_operation(int operation, int num1, int num2) {
    switch (operation) {
        case 1:
            return num1 + num2;
        case 2:
            return num1 - num2;
        case 3:
            return num1 * num2;
        case 4:
            if (num2 == 0) {
                return 0;  // Division by zero is not allowed
            }
            return num1 / num2;
        default:
            return 0;  // Invalid operation
    }
}

// Function to play the game for a single player
void play_game(Player *player) {
    int i;
    printf("%s's turn:\n", player->name);

    // Generate random operations for the player
    for (i = 0; i < MAX_OPERATIONS; i++) {
        player->operations[i] = generate_operation();
    }

    // Perform the operations and calculate the score
    int score = 0;
    int num1, num2;
    for (i = 0; i < MAX_OPERATIONS; i++) {
        // Generate random numbers
        num1 = get_random_number(1, 10);
        num2 = get_random_number(1, 10);

        // Perform the operation
        int result = perform_operation(player->operations[i], num1, num2);

        // Check if the player's answer is correct
        int answer;
        printf("What is %d %s %d?\n", num1, (player->operations[i] == 1 ? "+" : (player->operations[i] == 2 ? "-" : (player->operations[i] == 3 ? "*" : "/"))), num2);
        scanf("%d", &answer);
        if (answer == result) {
            score += 10;  // Correct answer
        } else {
            score -= 5;  // Incorrect answer
        }

        printf("Your score is now %d\n", score);
    }

    // Update the player's score
    player->score = score;
}

int main() {
    // Initialize the players
    Player players[MAX_PLAYERS];
    int i;
    for (i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        players[i].score = 0;
    }

    // Play the game
    for (i = 0; i < MAX_PLAYERS; i++) {
        play_game(&players[i]);
    }

    // Display the results
    printf("\nResults:\n");
    for (i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }

    return 0;
}