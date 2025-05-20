//FormAI DATASET v1.0 Category: Memory Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declarations of Functions
void delay(int seconds);
void clear_screen();
void print_cards(int cards[], int size);
void shuffle(int cards[], int size);
int check_match(int cards[], int index1, int index2);

// Constants
#define SIZE 16
#define MAX_NUM 8

int main() {
    int cards[SIZE];
    int i, j, index1, index2, matches = 0;
    srand(time(NULL));

    // Initialize cards
    for (i = 0; i < SIZE; i++) {
        cards[i] = i % MAX_NUM + 1;
    }

    // Shuffle cards
    shuffle(cards, SIZE);

    // Game loop
    while (matches < MAX_NUM) {
        clear_screen();
        print_cards(cards, SIZE);

        // Get user input
        printf("Choose two cards (0-15):\n");
        scanf("%d %d", &index1, &index2);

        if (index1 == index2 || index1 < 0 || index1 >= SIZE || index2 < 0 || index2 >= SIZE) {
            printf("Invalid input, try again.\n");
            delay(2);
            continue;
        }

        // Check match
        if (check_match(cards, index1, index2)) {
            matches++;
            printf("Match found!\n");
            delay(2);
        } else {
            printf("No match.\n");
            delay(2);

            // Flip cards back
            cards[index1] = 0;
            cards[index2] = 0;
        }
    }

    // End game
    clear_screen();
    print_cards(cards, SIZE);
    printf("Congratulations, you won!\n");

    return 0;
}

// Function Definitions

void delay(int seconds) {
    clock_t endwait;
    endwait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait);
}

void clear_screen() {
    system("cls || clear");
}

void print_cards(int cards[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (cards[i] == 0) {
            printf("| %2d |", i);
        } else {
            printf("| %2d |", cards[i]);
        }

        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void shuffle(int cards[], int size) {
    int i, j, tmp;
    for (i = size - 1; i >= 0; i--) {
        j = rand() % (i + 1);
        tmp = cards[i];
        cards[i] = cards[j];
        cards[j] = tmp;
    }
}

int check_match(int cards[], int index1, int index2) {
    if (cards[index1] == cards[index2]) {
        cards[index1] = 0;
        cards[index2] = 0;
        return 1;
    } else {
        return 0;
    }
}