//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return (int) (min + (rand() / (RAND_MAX + 1.0f) * (max - min + 1)));
}

// Function to generate a random bingo card with 24 numbers
void generate_bingo_card(int *card, int size) {
    int i;
    for (i = 0; i < size; i++) {
        card[i] = random_number(1, 75);
    }
}

// Function to check if a bingo card has won
int is_bingo(int *card, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (card[i] == card[j]) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to print the bingo card
void print_bingo_card(int *card, int size) {
    int i;
    printf("Bingo Card:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", card[i]);
        if ((i + 1) % 5 == 0) {
            printf("\n");
        }
    }
}

int main() {
    srand(time(0));
    int card[25];
    generate_bingo_card(card, 25);
    print_bingo_card(card, 25);
    int i, j;
    for (i = 0; i < 25; i++) {
        printf("Bingo Number %d: ", i + 1);
        scanf("%d", &j);
        if (j == card[i]) {
            printf("Bingo!\n");
            break;
        }
    }
    if (i == 25) {
        printf("No Bingo.\n");
    }
    return 0;
}