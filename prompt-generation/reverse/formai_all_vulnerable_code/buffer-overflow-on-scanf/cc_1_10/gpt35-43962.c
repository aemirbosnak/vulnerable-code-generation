//FormAI DATASET v1.0 Category: Poker Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4

// Define Card struct
typedef struct Card {
    int rank;
    int suit;
} Card;

// Define Hand struct
typedef struct Hand {
    Card* cards;
    int size;
} Hand;

// Define Deck struct
typedef struct Deck {
    Card cards[NUM_CARDS];
    int dealt;
} Deck;

// Display the menu options
void display_menu(void) {
    printf("1. Deal New Hand\n2. Exit\n");
}

// Shuffle the deck of cards
void shuffle_deck(Deck* deck) {
    Card temp;
    int rand_index;

    srand(time(NULL));

    for (int i = 0; i < NUM_CARDS; i++) {
        rand_index = rand() % NUM_CARDS;
        temp = deck->cards[i];
        deck->cards[i] = deck->cards[rand_index];
        deck->cards[rand_index] = temp;
    }

    deck->dealt = 0;
}

// Initialize the deck of cards
void init_deck(Deck* deck) {
    for (int i = 0; i < NUM_RANKS; i++) {
        for (int j = 0; j < NUM_SUITS; j++) {
            deck->cards[i * NUM_SUITS + j].rank = i;
            deck->cards[i * NUM_SUITS + j].suit = j;
        }
    }

    deck->dealt = 0;
}

// Print a card
void print_card(Card card) {
    const char* ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    const char* suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    printf("%s of %s", ranks[card.rank], suits[card.suit]);
}

// Initialize the hand
void init_hand(Hand* hand) {
    hand->cards = NULL;
    hand->size = 0;
}

// Add a card to the hand
void add_card_to_hand(Hand* hand, Card card) {
    hand->cards = realloc(hand->cards, (hand->size + 1) * sizeof(Card));
    hand->cards[hand->size++] = card;
}

// Print the hand
void print_hand(Hand* hand) {
    for (int i = 0; i < hand->size; i++) {
        print_card(hand->cards[i]);
        printf("\n");
    }
}

// Deal a hand
void deal_hand(Deck* deck, Hand* hand) {
    // Shuffle the deck
    shuffle_deck(deck);

    // Initialize the hand
    init_hand(hand);

    // Deal 5 cards to the hand
    for (int i = 0; i < 5; i++) {
        add_card_to_hand(hand, deck->cards[deck->dealt++]);
    }
}

int main() {
    // Initialize the deck of cards
    Deck deck;
    init_deck(&deck);

    // Initialize the player's hand
    Hand hand;
    init_hand(&hand);

    int choice;

    do {
        // Display the menu
        display_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Deal a new hand
                deal_hand(&deck, &hand);
                printf("\nYour Hand:\n");
                print_hand(&hand);
                break;
            case 2:
                // Exit
                printf("Thanks for playing!\n");
                exit(0);
            default:
                printf("Invalid Choice\n");
                break;
        }
    } while (1);

    return 0;
}