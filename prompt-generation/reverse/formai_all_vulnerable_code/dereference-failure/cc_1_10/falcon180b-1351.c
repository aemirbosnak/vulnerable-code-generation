//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_CARDS 100

// Function to print out the bingo card
void print_card(int card[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        printf("%d ", card[i]);
    }
    printf("\n");
}

// Function to generate a random bingo card
void generate_card(int card[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        card[i] = rand() % 75 + 1;
    }
}

// Function to check if a card has a bingo
int check_bingo(int card[MAX_CARDS]) {
    for (int i = 0; i < MAX_CARDS; i++) {
        if (card[i] == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to mark a number on the card
void mark_number(int card[MAX_CARDS], int number) {
    for (int i = 0; i < MAX_CARDS; i++) {
        if (card[i] == number) {
            card[i] = 0;
        }
    }
}

int main() {
    srand(time(NULL));
    int cards[MAX_CARDS];
    int num_cards = 0;
    int winner = 0;
    int num_called = 0;
    int called_nums[75];
    int j = 0;
    int k = 0;

    // Loop until there is a winner
    while (winner == 0) {
        // Generate a random card
        generate_card(cards[num_cards]);
        num_cards++;

        // Print out the card
        printf("Card %d:\n", num_cards - 1);
        print_card(cards[num_cards - 1]);

        // Call a number
        int num = rand() % 75 + 1;
        called_nums[j] = num;
        printf("Number called: %d\n", num);
        j++;

        // Check for a winner
        for (int i = 0; i < num_cards; i++) {
            if (check_bingo(cards[i]) == 1) {
                winner = 1;
                break;
            }
        }

        // Check if all numbers have been called
        if (j == 75) {
            winner = 1;
        }
    }

    // Print out the winning card
    printf("Winning card:\n");
    print_card(cards[k]);

    // Print out the called numbers
    printf("\nCalled numbers:\n");
    for (int i = 0; i < 75; i++) {
        printf("%d ", called_nums[i]);
    }

    return 0;
}