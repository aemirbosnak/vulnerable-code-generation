//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void shuffle_deck(int deck[]);
int deal_card(int deck[], int card_size, int* card_count);
void print_hand(int hand[], int hand_size);
void print_table(int table[], int table_size);
int compute_score(int hand[], int hand_size);
int main(int argc, char *argv[]) {
    srand(time(NULL));
    int deck[52];
    shuffle_deck(deck);
    
    int hand[5];
    int table[5];
    int card_size = sizeof(deck);
    int card_count = 0;
    int player_score = 0;
    int computer_score = 0;
    int round = 1;
    int game_over = 0;
    
    while (game_over == 0) {
        printf("Round %d\n", round);
        printf("Dealing cards...\n");
        card_count = deal_card(deck, card_size, &card_count);
        if (card_count == 0) {
            printf("Game over, player wins!\n");
            game_over = 1;
        } else {
            printf("Player's hand: ");
            print_hand(hand, 5);
            printf("\nComputer's hand: ");
            print_hand(table, 5);
            printf("\nComputing scores...\n");
            player_score = compute_score(hand, 5);
            computer_score = compute_score(table, 5);
            printf("Player's score: %d\n", player_score);
            printf("Computer's score: %d\n", computer_score);
            printf("Round %d over\n", round);
            round++;
        }
    }
    
    printf("Game over, computer wins!\n");
    
    return 0;
}

void shuffle_deck(int deck[]) {
    int i, j;
    for (i = 0; i < 52; i++) {
        int temp = deck[i];
        for (j = i + 1; j < 52; j++) {
            deck[j] = deck[j + 1];
        }
        deck[j] = temp;
    }
}

int deal_card(int deck[], int card_size, int* card_count) {
    int i, j;
    int card;
    for (i = 0; i < *card_count; i++) {
        card = rand() % 52 + 1;
        for (j = 0; j < 5; j++) {
            if (deck[card] == 0) {
                deck[card] = 1;
                *card_count = *card_count + 1;
                break;
            }
        }
    }
    return *card_count;
}

void print_hand(int hand[], int hand_size) {
    int i;
    for (i = 0; i < hand_size; i++) {
        if (hand[i] == 0) {
            printf(" ");
        } else {
            printf("%d ", hand[i]);
        }
    }
    printf("\n");
}

void print_table(int table[], int table_size) {
    int i;
    for (i = 0; i < table_size; i++) {
        if (table[i] == 0) {
            printf(" ");
        } else {
            printf("%d ", table[i]);
        }
    }
    printf("\n");
}

int compute_score(int hand[], int hand_size) {
    int i, j;
    int score = 0;
    for (i = 0; i < hand_size; i++) {
        if (hand[i] == 0) {
            score = score + 5;
        } else if (hand[i] == 1) {
            score = score + 10;
        } else if (hand[i] == 2) {
            score = score + 15;
        } else if (hand[i] == 3) {
            score = score + 20;
        } else if (hand[i] == 4) {
            score = score + 25;
        } else if (hand[i] == 5) {
            score = score + 30;
        } else if (hand[i] == 6) {
            score = score + 35;
        } else if (hand[i] == 7) {
            score = score + 40;
        } else if (hand[i] == 8) {
            score = score + 45;
        } else if (hand[i] == 9) {
            score = score + 50;
        } else if (hand[i] == 10) {
            score = score + 55;
        } else if (hand[i] == 11) {
            score = score + 60;
        } else if (hand[i] == 12) {
            score = score + 65;
        } else if (hand[i] == 13) {
            score = score + 70;
        } else if (hand[i] == 14) {
            score = score + 75;
        } else if (hand[i] == 15) {
            score = score + 80;
        } else if (hand[i] == 16) {
            score = score + 85;
        } else if (hand[i] == 17) {
            score = score + 90;
        } else if (hand[i] == 18) {
            score = score + 95;
        } else if (hand[i] == 19) {
            score = score + 100;
        } else if (hand[i] == 20) {
            score = score + 105;
        } else if (hand[i] == 21) {
            score = score + 110;
        } else if (hand[i] == 22) {
            score = score + 115;
        } else if (hand[i] == 23) {
            score = score + 120;
        } else if (hand[i] == 24) {
            score = score + 125;
        } else if (hand[i] == 25) {
            score = score + 130;
        } else if (hand[i] == 26) {
            score = score + 135;
        } else if (hand[i] == 27) {
            score = score + 140;
        } else if (hand[i] == 28) {
            score = score + 145;
        } else if (hand[i] == 29) {
            score = score + 150;
        } else if (hand[i] == 30) {
            score = score + 155;
        } else if (hand[i] == 31) {
            score = score + 160;
        } else if (hand[i] == 32) {
            score = score + 165;
        } else if (hand[i] == 33) {
            score = score + 170;
        } else if (hand[i] == 34) {
            score = score + 175;
        } else if (hand[i] == 35) {
            score = score + 180;
        } else if (hand[i] == 36) {
            score = score + 185;
        } else if (hand[i] == 37) {
            score = score + 190;
        } else if (hand[i] == 38) {
            score = score + 195;
        } else if (hand[i] == 39) {
            score = score + 200;
        } else if (hand[i] == 40) {
            score = score + 205;
        } else if (hand[i] == 41) {
            score = score + 210;
        } else if (hand[i] == 42) {
            score = score + 215;
        } else if (hand[i] == 43) {
            score = score + 220;
        } else if (hand[i] == 44) {
            score = score + 225;
        } else if (hand[i] == 45) {
            score = score + 230;
        } else if (hand[i] == 46) {
            score = score + 235;
        } else if (hand[i] == 47) {
            score = score + 240;
        } else if (hand[i] == 48) {
            score = score + 245;
        } else if (hand[i] == 49) {
            score = score + 250;
        } else if (hand[i] == 50) {
            score = score + 255;
        } else if (hand[i] == 51) {
            score = score + 260;
        } else if (hand[i] == 52) {
            score = score + 265;
        }
    }
    return score;
}