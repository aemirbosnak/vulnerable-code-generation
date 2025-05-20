//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_CARDS 100

typedef struct {
    char name[20];
    int cards[MAX_CARDS];
} Player;

void generateCard(int* card) {
    *card = rand() % 15 + 1;
}

void printCard(int card) {
    switch(card) {
        case 1:
            printf("B1\n");
            break;
        case 2:
            printf("I2\n");
            break;
        case 3:
            printf("N3\n");
            break;
        case 4:
            printf("G4\n");
            break;
        case 5:
            printf("O5\n");
            break;
        default:
            printf("%d\n", card);
            break;
    }
}

void printCards(int cards[], int numCards) {
    for(int i=0; i<numCards; i++) {
        printCard(cards[i]);
    }
}

int compareCards(const void* a, const void* b) {
    int cardA = *(int*)a;
    int cardB = *(int*)b;

    if(cardA > cardB) {
        return 1;
    } else if(cardA < cardB) {
        return -1;
    } else {
        return 0;
    }
}

void sortCards(int cards[], int numCards) {
    qsort(cards, numCards, sizeof(int), compareCards);
}

int main() {
    srand(time(NULL));

    int numPlayers;
    printf("Enter number of players (1-10): ");
    scanf("%d", &numPlayers);

    if(numPlayers < 1 || numPlayers > MAX_PLAYERS) {
        printf("Invalid number of players.\n");
        return 1;
    }

    Player players[numPlayers];

    for(int i=0; i<numPlayers; i++) {
        printf("Enter name of player %d: ", i+1);
        scanf("%s", players[i].name);
    }

    int numCards = 5;
    int cards[numPlayers][numCards];

    for(int i=0; i<numPlayers; i++) {
        for(int j=0; j<numCards; j++) {
            generateCard(&cards[i][j]);
        }
    }

    printf("\n");

    for(int i=0; i<numPlayers; i++) {
        printf("%s's cards:\n", players[i].name);
        printCards(cards[i], numCards);
    }

    sortCards(cards[0], numCards);

    printf("\n\n");

    for(int i=0; i<numPlayers; i++) {
        printf("%s's sorted cards:\n", players[i].name);
        printCards(cards[i], numCards);
    }

    return 0;
}