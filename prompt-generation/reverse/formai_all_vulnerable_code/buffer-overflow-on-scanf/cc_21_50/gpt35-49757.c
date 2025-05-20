//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: funny
#include <stdio.h>

int main() {
    int num_discs = 0;
    printf("Welcome to the Tower of Hanoi Game - the most mind-boggling puzzle ever known to humankind!\n");
    printf("But don't worry, I'm here to guide you through it.\n");
    printf("But first, how many discs are you feeling brave enough to tackle today? (Enter a number between 1 and 8)\n");

    // Getting the number of discs
    scanf("%d", &num_discs);
    if (num_discs < 1 || num_discs > 8) {
        printf("I said between 1 and 8, you silly human!\n");
        printf("Trying to break my program, eh? Well, try again with a number in that range!\n");
        return 0;
    }
    printf("Alright, let's get started then!\n");
    printf("Here's your initial setup:\n\n");

    // Initializing the Towers
    char tower_a[num_discs], tower_b[num_discs], tower_c[num_discs];
    for (int i = 0; i < num_discs; i++) {
        tower_a[i] = 'A';
        tower_b[i] = ' ';
        tower_c[i] = ' ';
        for (int j = 0; j < i; j++) {
            tower_a[i] = tower_a[j] + 1;
        }
    }

    // Printing the initial setup
    for (int i = num_discs - 1; i >= 0; i--) {
        printf("%c  %c  %c\n", tower_a[i], tower_b[i], tower_c[i]);
    }
    printf("A  B  C\n");

    // Starting the game
    printf("Your mission, should you choose to accept it, is to move all the discs from Tower A to Tower C.\n");
    printf("But there are some rules, oh yes, there are rules:\n");
    printf("Rule #1: You can only move one disc at a time.\n");
    printf("Rule #2: You can only move the top disc of any given tower.\n");
    printf("Rule #3: A larger disc cannot be placed on top of a smaller one.\n");
    printf("Now, go forth and conquer!\n");

    int moves = 0;
    while (tower_c[0] != 'A') {
        printf("Enter your move: (in the format [from tower][to tower], e.g. AB for move from Tower A to Tower B)\n");
        
        // Getting the player's move
        char from_tower, to_tower;
        scanf(" %c%c", &from_tower, &to_tower);
        if ((from_tower != 'A' && from_tower != 'B' && from_tower != 'C') ||
                (to_tower != 'A' && to_tower != 'B' && to_tower != 'C')) {
            printf("Invalid move! You must choose two towers from A, B, and C (e.g. AB, BC)\n");
            continue;
        }
        if (from_tower == to_tower) {
            printf("You can't move a disc to the same tower, genius!\n");
            continue;
        }

        // Checking if move is valid
        int from_idx = -1, to_idx = -1;
        for (int i = 0; i < num_discs; i++) {
            if (tower_a[i] == from_tower && from_idx == -1) {
                from_idx = i;
            }
            if (tower_a[i] == to_tower && to_idx == -1) {
                to_idx = i;
            }
        }
        if (from_idx == -1 || (to_idx != num_discs - 1 && tower_a[to_idx + 1] != ' ' && tower_a[from_idx] > tower_a[to_idx + 1])) {
            printf("Invalid move! You can't put a larger disc on top of a smaller one.\n");
            continue;
        }

        // Moving the disc
        tower_a[from_idx] = ' ';
        for (int i = num_discs - 1; i >= 0; i--) {
            if (tower_c[i] == ' ') {
                tower_c[i] = from_tower;
                break;
            }
        }

        // Printing the new setup
        moves++;
        printf("Move #%d:\n\n", moves);
        for (int i = num_discs - 1; i >= 0; i--) {
            printf("%c  %c  %c\n", tower_a[i], tower_b[i], tower_c[i]);
        }
        printf("A  B  C\n");
    }

    // Winning the game
    printf("Congratulations, you won the game in %d moves! You are a true Tower of Hanoi Master.\n", moves);
    printf("I bow down to your superior intellect and problem-solving skills.\n");
    printf("But don't get too cocky, you still have %d more levels to beat!\n", 7 - num_discs);
    return 0;
}