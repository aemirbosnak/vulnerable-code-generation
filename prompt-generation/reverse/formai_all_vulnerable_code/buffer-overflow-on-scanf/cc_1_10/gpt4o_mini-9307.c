//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 8 // Number of distinct cards (pairs)
#define SIZE (CARDS * 2) // Total number of cards

void shuffle(char *cards) {
    for (int i = 0; i < SIZE; i++) {
        int r = rand() % SIZE;
        char temp = cards[i];
        cards[i] = cards[r];
        cards[r] = temp;
    }
}

void print_board(char *board, int *revealed) {
    printf("\nCurrent board:\n");
    for (int i = 0; i < SIZE; i++) {
        if (revealed[i]) {
            printf("[%c] ", board[i]);
        } else {
            printf("[ ] ");
        }
        if ((i + 1) % 4 == 0) printf("\n");
    }
}

int check_for_match(char *board, int first, int second) {
    return board[first] == board[second];
}

void play_game() {
    char cards[SIZE];
    char board[SIZE];
    int revealed[SIZE] = {0}; // Tracks revealed cards
    int pairs_found = 0;

    // Initialize cards (A-H)
    for (int i = 0; i < CARDS; i++) {
        cards[i] = 'A' + i;
        cards[i + CARDS] = 'A' + i;
    }

    shuffle(cards);
    
    while (pairs_found < CARDS) {
        print_board(cards, revealed);
        
        int first_choice, second_choice;

        // Select first card
        printf("Pick your first card (0-%d): ", SIZE - 1);
        scanf("%d", &first_choice);

        if (first_choice < 0 || first_choice >= SIZE || revealed[first_choice]) {
            printf("Invalid selection. Try again.\n");
            continue;
        }
        revealed[first_choice] = 1;

        print_board(cards, revealed);

        // Select second card
        printf("Pick your second card (0-%d): ", SIZE - 1);
        scanf("%d", &second_choice);

        if (second_choice < 0 || second_choice >= SIZE || revealed[second_choice] || second_choice == first_choice) {
            printf("Invalid selection. Try again.\n");
            revealed[first_choice] = 0; // revert first choice
            continue;
        }
        revealed[second_choice] = 1;

        print_board(cards, revealed);
        
        if (check_for_match(cards, first_choice, second_choice)) {
            printf("It's a match! You've found a pair!\n");
            pairs_found++;
        } else {
            printf("Not a match. Try again.\n");
            // Pause for a moment
            printf("You have 2 seconds to memorize your choices...\n");
            sleep(2);
            revealed[first_choice] = 0;
            revealed[second_choice] = 0;
        }
    }
    
    printf("Congratulations! You've matched all pairs!\n");
}

int main() {
    srand((unsigned int)time(NULL)); // Seed for randomness
    printf("Welcome to the Memory Game!\n");
    printf("You will be shown a board of cards. Try to match the pairs!\n");
    
    play_game();
    
    printf("Thank you for playing! How did you find the experience?\n");
    // Reflection for the user could be implemented here
    return 0;
}