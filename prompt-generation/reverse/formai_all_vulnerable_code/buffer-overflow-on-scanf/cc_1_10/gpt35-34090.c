//FormAI DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 20

void shuffle_cards(int cards[], int num_cards);
int get_input(char prompt[], int min, int max);
int game_over(int cards[], int num_cards);
void print_cards(int cards[], int num_cards);
void check_pair(int cards[], int pos1, int pos2, int* num_pairs);

int main() {
    int cards[MAX_CARDS];
    int num_cards;
    int num_pairs = 0;
    int pos1, pos2;
    
    printf("Welcome to the memory game!\n");
    num_cards = get_input("Enter number of cards (even number between 4 to 20): ", 4, 20);
    
    // Initialize cards
    for (int i = 1; i <= num_cards/2; i++) {
        cards[2*i-2] = i;
        cards[2*i-1] = i;
    }
    
    // Shuffle cards
    srand(time(NULL));
    shuffle_cards(cards, num_cards);
    
    // Start game
    while (!game_over(cards, num_cards)) {
        print_cards(cards, num_cards);
        
        pos1 = get_input("Enter first card number: ", 1, num_cards) - 1;     // Subtract 1 to make input 0-based
        pos2 = get_input("Enter second card number: ", 1, num_cards) - 1;    // Subtract 1 to make input 0-based
        
        if (cards[pos1] == cards[pos2]) {
            printf("Match found!\n\n");
            check_pair(cards, pos1, pos2, &num_pairs);
        } else {
            printf("Not a match. Try again.\n\n");
        }
    }
    
    printf("Congratulations! You found all the pairs.\n");
    printf("You took %d turns.\n", num_pairs);
    
    return 0;
}

/*
 * Shuffles an array of integers using Fisher-Yates shuffle algorithm.
 * Time complexity: O(n)
 */
void shuffle_cards(int cards[], int num_cards) {
    int temp, rand_pos;
    
    for (int i = num_cards - 1; i > 0; i--) {
        rand_pos = rand() % (i + 1);
        temp = cards[i];
        cards[i] = cards[rand_pos];
        cards[rand_pos] = temp;
    }
}

/*
 * Gets user input with a prompt and validates that it is within a specified range.
 */
int get_input(char prompt[], int min, int max) {
    int input;
    do {
        printf("%s", prompt);
        scanf("%d", &input);
        if (input < min || input > max) {
            printf("Invalid input. Please enter a number between %d and %d.\n", min, max);
        }
    } while (input < min || input > max);
    printf("\n");
    return input;
}

/*
 * Checks if all cards have been matched.
 */
int game_over(int cards[], int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        if (cards[i] != -1) {
            return 0;
        }
    }
    return 1;
}

/*
 * Prints all cards with X's for already matched cards.
 */
void print_cards(int cards[], int num_cards) {
    printf("Cards:\n");
    for (int i = 0; i < num_cards; i++) {
        if (cards[i] == -1) {
            printf("X  ");
        } else {
            printf("%d  ", cards[i]);
        }
    }
    printf("\n");
}

/*
 * Marks a pair of matched cards and increments the number of pairs found.
 */
void check_pair(int cards[], int pos1, int pos2, int* num_pairs) {
    cards[pos1] = -1;
    cards[pos2] = -1;
    (*num_pairs)++;
}