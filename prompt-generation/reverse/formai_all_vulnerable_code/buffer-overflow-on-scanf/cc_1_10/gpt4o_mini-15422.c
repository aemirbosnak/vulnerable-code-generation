//GPT-4o-mini DATASET v1.0 Category: Bingo Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_PLAYERS 10

typedef struct {
    int size;
    int range;
    int **card;
} BingoCard;

typedef struct {
    char name[50];
    BingoCard bingoCard;
    bool *marked;
} Player;

void generateBingoCard(BingoCard *card) {
    card->card = (int **)malloc(card->size * sizeof(int *));
    for (int i = 0; i < card->size; i++) {
        card->card[i] = (int *)malloc(card->size * sizeof(int));
    }

    int *numbers = (int *)malloc(card->range * sizeof(int));
    for (int i = 0; i < card->range; i++) {
        numbers[i] = i + 1;
    }

    for (int i = 0; i < card->size * card->size; i++) {
        int r = rand() % card->range;
        card->card[i / card->size][i % card->size] = numbers[r];
        numbers[r] = numbers[--card->range];
    }

    free(numbers);
}

void printBingoCard(BingoCard *card) {
    for (int i = 0; i < card->size; i++) {
        for (int j = 0; j < card->size; j++) {
            printf("%2d ", card->card[i][j]);
        }
        printf("\n");
    }
}

void markNumber(Player *player, int number) {
    for (int i = 0; i < player->bingoCard.size; i++) {
        for (int j = 0; j < player->bingoCard.size; j++) {
            if (player->bingoCard.card[i][j] == number) {
                player->marked[i * player->bingoCard.size + j] = true;
            }
        }
    }
}

bool checkWinner(Player *player) {
    for (int i = 0; i < player->bingoCard.size; i++) {
        bool rowComplete = true;
        bool colComplete = true;
        for (int j = 0; j < player->bingoCard.size; j++) {
            if (!player->marked[i * player->bingoCard.size + j]) {
                rowComplete = false;
            }
            if (!player->marked[j * player->bingoCard.size + i]) {
                colComplete = false;
            }
        }
        if (rowComplete || colComplete) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(NULL));
    
    int numPlayers;
    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &numPlayers);

    if (numPlayers > MAX_PLAYERS) {
        printf("Exceeds maximum number of players!\n");
        return 1;
    }

    Player *players = (Player *)malloc(numPlayers * sizeof(Player));

    int cardSize, numberRange;
    printf("Enter Bingo card size and number range (e.g., 5 75): ");
    scanf("%d %d", &cardSize, &numberRange);

    for (int i = 0; i < numPlayers; i++) {
        printf("Enter name for Player %d: ", i + 1);
        scanf("%s", players[i].name);
        players[i].bingoCard.size = cardSize;
        players[i].bingoCard.range = numberRange;
        players[i].marked = (bool *)calloc(cardSize * cardSize, sizeof(bool));
        
        generateBingoCard(&players[i].bingoCard);
        printf("Bingo Card for %s:\n", players[i].name);
        printBingoCard(&players[i].bingoCard);
    }

    printf("Starting the Bingo game!\n");

    int drawnNumber;
    while (true) {
        printf("Enter drawn number (or -1 to exit): ");
        scanf("%d", &drawnNumber);
        
        if (drawnNumber == -1) {
            printf("Exiting the game.\n");
            break;
        }

        for (int i = 0; i < numPlayers; i++) {
            markNumber(&players[i], drawnNumber);
            if (checkWinner(&players[i])) {
                printf("%s wins with the number %d!\n", players[i].name, drawnNumber);
                free(players[i].marked);
                for (int j = 0; j < players[i].bingoCard.size; j++) {
                    free(players[i].bingoCard.card[j]);
                }
                free(players[i].bingoCard.card);
                free(players);
                return 0;
            }
        }
    }

    for (int i = 0; i < numPlayers; i++) {
        free(players[i].marked);
        for (int j = 0; j < players[i].bingoCard.size; j++) {
            free(players[i].bingoCard.card[j]);
        }
        free(players[i].bingoCard.card);
    }
    free(players);
    return 0;
}