//Code Llama-13B DATASET v1.0 Category: Memory Game ; Style: rigorous
/*
 * A unique C Memory Game example program in a rigorous style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants
#define MAX_CARDS 16
#define MAX_TURNS 10

// Structures
typedef struct {
    int value;
    int suit;
} Card;

// Function prototypes
void print_card(Card card);
void print_board(Card board[MAX_CARDS]);
void print_menu();
int input_number();
void generate_cards(Card cards[MAX_CARDS]);
void shuffle_cards(Card cards[MAX_CARDS]);
void reveal_cards(Card board[MAX_CARDS]);
int find_match(Card board[MAX_CARDS], int index1, int index2);
void turn_over(Card board[MAX_CARDS], int index);
void game_over(int matches);

// Main function
int main() {
    // Initialize game variables
    Card board[MAX_CARDS];
    int turns = 0;
    int matches = 0;

    // Generate and shuffle cards
    generate_cards(board);
    shuffle_cards(board);

    // Print game board and menu
    print_board(board);
    print_menu();

    // Game loop
    while (turns < MAX_TURNS) {
        // Ask for user input
        int input = input_number();

        // Check if input is valid
        if (input >= 0 && input < MAX_CARDS) {
            // Turn over card
            turn_over(board, input);

            // Check for match
            matches = find_match(board, input, input);

            // Print game board and menu
            print_board(board);
            print_menu();

            // Check if game is over
            if (matches == MAX_CARDS / 2) {
                game_over(matches);
                break;
            }
        } else {
            printf("Invalid input. Try again.\n");
        }

        // Increment turns
        turns++;
    }

    // Print game over message
    if (turns == MAX_TURNS) {
        printf("Game over. You did not find all matches in %d turns.\n", turns);
    }

    return 0;
}

// Function definitions
void print_card(Card card) {
    switch (card.suit) {
        case 1: printf("Heart"); break;
        case 2: printf("Diamond"); break;
        case 3: printf("Club"); break;
        case 4: printf("Spade"); break;
        default: printf("Invalid suit"); break;
    }
    printf(" %d", card.value);
}

void print_board(Card board[MAX_CARDS]) {
    printf("  ");
    for (int i = 0; i < MAX_CARDS; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < MAX_CARDS; i++) {
        print_card(board[i]);
        if (i % 4 == 3) {
            printf("\n");
        } else {
            printf("  ");
        }
    }
    printf("\n");
}

void print_menu() {
    printf("Enter a number to turn over a card, or 'q' to quit: ");
}

int input_number() {
    int input;
    scanf("%d", &input);
    return input;
}

void generate_cards(Card cards[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        cards[i].value = i + 1;
        cards[i].suit = rand() % 4 + 1;
    }
}

void shuffle_cards(Card cards[MAX_CARDS]) {
    int temp;
    for (int i = 0; i < MAX_CARDS; i++) {
        temp = rand() % MAX_CARDS;
        cards[i].value = cards[temp].value;
        cards[i].suit = cards[temp].suit;
    }
}

void reveal_cards(Card board[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        board[i].value = -1;
    }
}

int find_match(Card board[MAX_CARDS], int index1, int index2) {
    if (index1 == index2) {
        return 0;
    } else if (board[index1].value == board[index2].value) {
        board[index1].value = -1;
        board[index2].value = -1;
        return 1;
    } else {
        return 0;
    }
}

void turn_over(Card board[MAX_CARDS], int index) {
    if (board[index].value != -1) {
        board[index].value = -1;
    }
}

void game_over(int matches) {
    printf("Game over. You found all matches in %d turns.\n", matches);
}