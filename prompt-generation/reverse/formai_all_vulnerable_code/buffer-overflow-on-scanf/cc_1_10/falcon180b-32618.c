//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define NUM_CARDS 20

int deck[NUM_CARDS];
int card1, card2;
int num_matches = 0;
int num_attempts = 0;
int score = 0;

void init_deck() {
    int i;
    for(i = 0; i < NUM_CARDS; i++) {
        deck[i] = i + 1;
    }
}

void shuffle_deck() {
    int i, j;
    srand(time(NULL));
    for(i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_cards() {
    int i = 0;
    while(i < SIZE) {
        card1 = deck[i];
        i++;
        card2 = deck[i];
        i++;
    }
}

int check_match() {
    if(card1 == card2) {
        return 1;
    } else {
        return 0;
    }
}

void play_game() {
    init_deck();
    shuffle_deck();
    deal_cards();
    while(num_matches < SIZE) {
        printf("Card 1: %d\n", card1);
        printf("Card 2: %d\n", card2);
        printf("Do they match? (y/n): ");
        char response;
        scanf("%c", &response);
        if(response == 'y') {
            if(check_match()) {
                num_matches++;
                score += 10;
            } else {
                printf("Incorrect!\n");
            }
        } else if(response == 'n') {
            if(!check_match()) {
                num_matches++;
                score += 10;
            } else {
                printf("Incorrect!\n");
            }
        } else {
            printf("Invalid response!\n");
        }
        num_attempts++;
    }
    printf("You scored %d points in %d attempts!\n", score, num_attempts);
}

int main() {
    play_game();
    return 0;
}