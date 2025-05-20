//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle_deck(int deck[], int n);
int compare_cards(int card1, int card2);
void play_game(int deck[], int n);

int main() {
    int n;
    printf("Enter the number of cards: ");
    scanf("%d", &n);
    int deck[n];

    // Initialize the deck with numbers 1 to n
    for (int i = 0; i < n; i++) {
        deck[i] = i + 1;
    }

    // Shuffle the deck
    shuffle_deck(deck, n);

    // Play the game
    play_game(deck, n);

    return 0;
}

void shuffle_deck(int deck[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int compare_cards(int card1, int card2) {
    if (card1 == card2) {
        return 0;
    } else if (card1 > card2) {
        return 1;
    } else {
        return -1;
    }
}

void play_game(int deck[], int n) {
    int num_matches = 0;
    int num_tries = 0;
    int num_pairs = 0;
    int current_card1 = 0;
    int current_card2 = 0;
    int current_tries = 0;
    int current_matches = 0;
    int current_pairs = 0;

    while (num_matches < n) {
        num_tries = 0;
        num_pairs = 0;
        while (num_pairs < n) {
            current_card1 = deck[current_tries];
            current_card2 = deck[current_tries + 1];
            current_matches = 0;
            current_tries += 2;

            while ((current_card1!= current_card2) && (current_matches < 3)) {
                int result = compare_cards(current_card1, current_card2);
                if (result == 0) {
                    current_matches++;
                } else if (result == 1) {
                    current_card1 = deck[current_tries];
                    current_tries += 2;
                } else {
                    current_card2 = deck[current_tries];
                    current_tries += 2;
                }
            }

            if (current_matches == 3) {
                num_pairs++;
            } else {
                num_tries++;
            }
        }
        num_matches += num_pairs;
        printf("You made %d matches in %d tries.\n", num_matches, num_tries);
    }
}