//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define EASY_LEVEL 1
#define HARD_LEVEL 2

typedef struct {
    char card1[10];
    char card2[10];
    int score;
} MemoryCard;

int main() {
    int level = EASY_LEVEL;
    MemoryCard cards[16];
    int num_cards = 0;
    int score = 0;

    srand(time(NULL));

    // Shuffle the deck of cards
    for (int i = 0; i < 16; i++) {
        cards[i].card1[0] = 'A';
        cards[i].card2[0] = 'A';
        cards[i].score = 0;
        cards[i].card1[1] = rand() % 10 + '0';
        cards[i].card2[1] = rand() % 10 + '0';
        cards[i].card1[2] = '-';
        cards[i].card2[2] = '-';
        cards[i].card1[3] = '-';
        cards[i].card2[3] = '-';
        cards[i].card1[4] = '-';
        cards[i].card2[4] = '-';
        cards[i].card1[5] = '-';
        cards[i].card2[5] = '-';
        cards[i].card1[6] = '-';
        cards[i].card2[6] = '-';
        cards[i].card1[7] = '-';
        cards[i].card2[7] = '-';
        cards[i].card1[8] = '-';
        cards[i].card2[8] = '-';
        cards[i].card1[9] = '-';
        cards[i].card2[9] = '-';
        cards[i].card1[10] = '-';
        cards[i].card2[10] = '-';

        if (level == HARD_LEVEL) {
            for (int j = 0; j < 10; j++) {
                cards[i].card1[j] = rand() % 10 + '0';
                cards[i].card2[j] = rand() % 10 + '0';
            }
        }

        num_cards++;
    }

    // Display the deck of cards
    printf("Deck of Cards:\n");
    for (int i = 0; i < num_cards; i++) {
        printf("%s ", cards[i].card1);
        printf("%s\n", cards[i].card2);
    }

    // Flip two cards at a time
    while (score < 10) {
        int card1_index = rand() % num_cards;
        int card2_index = rand() % num_cards;

        int card1_num = atoi(cards[card1_index].card1);
        int card2_num = atoi(cards[card2_index].card2);

        if (card1_num == card2_num) {
            printf("Correct Match!\n");
            cards[card1_index].score++;
            cards[card2_index].score++;
            score++;
        } else {
            printf("Incorrect Match!\n");
        }

        printf("Score: %d\n", score);

        if (level == HARD_LEVEL) {
            printf("Difficulty: Hard\n");
        } else {
            printf("Difficulty: Easy\n");
        }

        printf("Deck of Cards:\n");
        for (int i = 0; i < num_cards; i++) {
            printf("%s ", cards[i].card1);
            printf("%s\n", cards[i].card2);
        }

        printf("\n");
    }

    // Save the game progress
    printf("Game Over! Your score is: %d\n", score);
    printf("Save game progress? (Y/N): ");
    char save_game_choice;
    scanf(" %c", &save_game_choice);

    if (save_game_choice == 'Y') {
        FILE *fp = fopen("game_progress.txt", "w");
        if (fp!= NULL) {
            fwrite(&score, sizeof(int), 1, fp);
            fclose(fp);
            printf("Game progress saved successfully!\n");
        } else {
            printf("Error saving game progress!\n");
        }
    } else {
        printf("Game progress not saved.\n");
    }

    // Reset the game
    printf("Reset game? (Y/N): ");
    char reset_game_choice;
    scanf(" %c", &reset_game_choice);

    if (reset_game_choice == 'Y') {
        for (int i = 0; i < num_cards; i++) {
            strcpy(cards[i].card1, "00");
            strcpy(cards[i].card2, "00");
            cards[i].score = 0;
        }

        printf("Game reset successfully!\n");
    } else {
        printf("Game not reset.\n");
    }

    return 0;
}