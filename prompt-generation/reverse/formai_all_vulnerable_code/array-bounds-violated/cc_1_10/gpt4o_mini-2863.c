//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define MAX_CARDS (SIZE * SIZE)

typedef struct {
    char symbol;
    int isRevealed;
} Card;

void initDeck(Card deck[MAX_CARDS]);
void shuffleDeck(Card deck[MAX_CARDS]);
void printBoard(Card deck[MAX_CARDS]);
int makeMove(Card deck[MAX_CARDS]);
int isGameWon(Card deck[MAX_CARDS]);

int main() {
    Card deck[MAX_CARDS];
    int moves = 0;
    srand(time(NULL));

    initDeck(deck);
    shuffleDeck(deck);

    printf("Welcome, noble player, to the Memoria Magnifica!\n");
    printf("May your memory not falter - match the pairs of symbols!\n");

    while (!isGameWon(deck)) {
        printBoard(deck);
        moves += makeMove(deck);
        printf("Total Moves: %d\n\n", moves);
    }

    printf("Congratulations, valiant hero! You have matched all pairs!\n");
    return 0;
}

void initDeck(Card deck[MAX_CARDS]) {
    char symbols[] = {'K', 'D', 'T', 'S', 'K', 'D', 'T', 'S'}; // K=Knight, D=Dragon, T=Treasure, S=Scroll
    for (int i = 0; i < MAX_CARDS; i++) {
        deck[i].symbol = symbols[i];
        deck[i].isRevealed = 0; // Set cards as unrevealed
    }
}

void shuffleDeck(Card deck[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        int j = rand() % MAX_CARDS;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printBoard(Card deck[MAX_CARDS]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int index = i * SIZE + j;
            if (deck[index].isRevealed) {
                printf("[%c] ", deck[index].symbol);
            } else {
                printf("[ ] "); // Unrevealed card
            }
        }
        printf("\n");
    }
}

int makeMove(Card deck[MAX_CARDS]) {
    int first, second;
    printf("Choose the indices of two cards to reveal (0-%d, enter indices separated by space): ", MAX_CARDS - 1);
    if (scanf("%d %d", &first, &second) != 2 || first < 0 || first >= MAX_CARDS || second < 0 || second >= MAX_CARDS || first == second) {
        printf("Invalid choice. Choose unique indices between 0 and %d.\n", MAX_CARDS - 1);
        return 0;
    }

    if (!deck[first].isRevealed && !deck[second].isRevealed) {
        deck[first].isRevealed = 1;
        deck[second].isRevealed = 1;
        printBoard(deck);

        if (deck[first].symbol == deck[second].symbol) {
            printf("Huzzah! You found a matching pair!\n");
            return 1;
        } else {
            printf("Alas! No match...\n");
            deck[first].isRevealed = 0;
            deck[second].isRevealed = 0;
            return 1;
        }
    } else {
        printf("One or both of the cards are already revealed. Choose again.\n");
        return 0;
    }
}

int isGameWon(Card deck[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        if (!deck[i].isRevealed) {
            return 0;
        }
    }
    return 1;
}