//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MAX_CARDS 16
#define MAX_TURNS 10

typedef struct {
    int id;
    char name[20];
    int score;
} player;

typedef struct {
    int value;
    int state; // 0 = hidden, 1 = revealed, 2 = matched
} card;

void print_board(card *board) {
    for (int i = 0; i < MAX_CARDS; i++) {
        if (board[i].state == 0) {
            printf("[] ");
        } else if (board[i].state == 1) {
            printf("[%d] ", board[i].value);
        } else {
            printf("  ");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Create players
    player players[MAX_PLAYERS];
    for (int i = 0; i < MAX_PLAYERS; i++) {
        players[i].id = i + 1;
        sprintf(players[i].name, "Player %d", i + 1);
        players[i].score = 0;
    }

    // Create board
    card board[MAX_CARDS];
    for (int i = 0; i < MAX_CARDS; i++) {
        board[i].value = (i / 2) + 1;
        board[i].state = 0;
    }

    // Shuffle board
    for (int i = 0; i < MAX_CARDS; i++) {
        int j = rand() % MAX_CARDS;
        card temp = board[i];
        board[i] = board[j];
        board[j] = temp;
    }

    // Game loop
    int turn = 0;
    int current_player = 0;
    int cards_matched = 0;
    while (turn < MAX_TURNS && cards_matched < MAX_CARDS) {
        // Print board
        print_board(board);

        // Get player input
        int card1, card2;
        printf("Player %s, select two cards (e.g. 1 5): ", players[current_player].name);
        scanf("%d %d", &card1, &card2);

        // Check if cards are valid
        if (card1 < 1 || card1 > MAX_CARDS || card2 < 1 || card2 > MAX_CARDS || card1 == card2 || board[card1 - 1].state != 0 || board[card2 - 1].state != 0) {
            printf("Invalid input. Please select two different hidden cards.\n");
            continue;
        }

        // Reveal cards
        board[card1 - 1].state = 1;
        board[card2 - 1].state = 1;

        // Check if cards match
        if (board[card1 - 1].value == board[card2 - 1].value) {
            printf("Cards match!\n");
            players[current_player].score += 2;
            board[card1 - 1].state = 2;
            board[card2 - 1].state = 2;
            cards_matched += 2;
        } else {
            printf("Cards don't match.\n");
            board[card1 - 1].state = 0;
            board[card2 - 1].state = 0;
        }

        // Next turn
        turn++;
        current_player = (current_player + 1) % MAX_PLAYERS;
    }

    // Print results
    printf("\nGame over!\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d points\n", players[i].name, players[i].score);
    }

    return 0;
}