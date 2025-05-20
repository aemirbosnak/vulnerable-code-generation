//FormAI DATASET v1.0 Category: Memory Game ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 20 // the maximum number of cards in the game
#define TRUE 1
#define FALSE 0

// Struct representing a card of memory game
typedef struct {
    char symbol;
    int is_hidden;
} Card;

// Function that creates two identical decks of cards with symbols
void create_deck(char symbols[], int size, Card deck1[], Card deck2[]) {
    int i, j;
    srand(time(NULL));
    for(i = 0; i < size; i++) {
        deck1[i].is_hidden = TRUE;
        deck2[i].is_hidden = TRUE;
    }
    for(i = 0; i < size/2; i++) {
        char symbol = symbols[rand()%size];
        for(j = i*2; j <= (i*2)+1; j++) {
            deck1[j].symbol = symbol;
            deck2[j].symbol = symbol;
        }
    }
}

// Function that shuffles an array of cards
void shuffle_cards(Card array[], int size) {
    int i;
    for(i = size-1; i >= 1; i--) {
        int j = rand()%(i+1);
        Card temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

// Function that prints a card as hidden or visible
void print_card(Card card) {
    if(card.is_hidden)
        printf("[?]");
    else
        printf("[%c]", card.symbol);
}

// Function that prints all cards in a deck
void print_deck(Card deck[], int size) {
    int i;
    for(i = 0; i < size; i++)
        print_card(deck[i]);
    printf("\n");
}

// Function that checks if the game is over (all pairs have been uncovered)
int is_game_over(Card deck1[], Card deck2[], int size) {
    int i;
    for(i = 0; i < size; i++)
        if(deck1[i].is_hidden || deck2[i].is_hidden)
            return FALSE;
    return TRUE;
}

int main() {
    char symbols[] = {'?', '@', '#', '$', '%', '^', '&', '*', '+', '-', '/', '=', '~', ';', ':', '<', '>', '(', ')', '!'};
    Card deck1[MAX_NUM], deck2[MAX_NUM];
    int size, i, j, first_index, second_index, num_guesses = 0;
    printf("Welcome to the Surrealist Memory Game!\n");
    printf("How many pairs of cards do you want to play with?\n");
    scanf("%d", &size);
    if(size > MAX_NUM) {
        printf("Error: The maximum number of cards supported is %d.\n", MAX_NUM);
        return 1;
    }
    create_deck(symbols, size*2, deck1, deck2);
    shuffle_cards(deck1, size*2);
    shuffle_cards(deck2, size*2);
    printf("The game is starting!\n");
    while(!is_game_over(deck1, deck2, size*2)) {
        printf("Guess #%d: ", ++num_guesses);
        print_deck(deck1, size*2);
        printf("Choose two cards between 1 and %d: ", size*2);
        scanf("%d %d", &first_index, &second_index);
        if(first_index < 1 || second_index < 1 || first_index > size*2 || second_index > size*2) {
            printf("Invalid input.\n");
            continue;
        }
        if(!deck1[first_index-1].is_hidden || !deck2[second_index-1].is_hidden) {
            printf("One or both cards were already uncovered.\n");
            continue;
        }
        if(deck1[first_index-1].symbol != deck2[second_index-1].symbol) {
            printf("No match!\n");
        }
        deck1[first_index-1].is_hidden = FALSE;
        deck2[second_index-1].is_hidden = FALSE;
    }
    printf("Congratulations! You won in %d guesses!\n", num_guesses);
    return 0;
}