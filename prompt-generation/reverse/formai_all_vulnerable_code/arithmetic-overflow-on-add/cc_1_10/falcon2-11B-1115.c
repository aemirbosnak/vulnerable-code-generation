//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARDS 100
#define MAX_NAME_LEN 10
#define MAX_MEMORY 10

typedef struct {
    char name[MAX_NAME_LEN];
    int value;
    int memory[MAX_MEMORY];
} card_t;

void shuffle(card_t *cards, int n) {
    int i, j;
    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        card_t temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void print_card(card_t *card) {
    printf("%s - %d\n", card->name, card->value);
}

void play_memory(card_t *cards, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        print_card(cards + i);
        printf("Press any key to continue...\n");
        getchar();
    }
}

int main() {
    card_t cards[MAX_CARDS];
    int n = 0;
    int i;

    printf("Enter the number of cards: ");
    scanf("%d", &n);
    if (n > MAX_CARDS) {
        printf("Error: Too many cards.\n");
        return 1;
    }

    printf("Enter the names and values of the cards: ");
    for (i = 0; i < n; i++) {
        fflush(stdin);
        printf("Card %d name: ", i + 1);
        fgets(cards[i].name, MAX_NAME_LEN, stdin);
        cards[i].name[strcspn(cards[i].name, "\n")] = '\0';
        printf("Card %d value: ", i + 1);
        scanf("%d", &cards[i].value);
    }

    shuffle(cards, n);

    play_memory(cards, n);

    return 0;
}