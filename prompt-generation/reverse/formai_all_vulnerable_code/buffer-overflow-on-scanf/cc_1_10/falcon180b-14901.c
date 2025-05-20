//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARDS 100
#define MAX_PLAYERS 10
#define MAX_NUMBERS 75

typedef struct {
    char name[20];
    int card[MAX_CARDS];
} Player;

void generateCard(Player *player) {
    int i;
    for(i=0;i<MAX_CARDS;i++) {
        player->card[i] = rand() % MAX_NUMBERS;
    }
}

void printCard(Player player) {
    int i;
    for(i=0;i<MAX_CARDS;i++) {
        printf("%d ", player.card[i]);
    }
    printf("\n");
}

void checkWin(Player player) {
    int i, j;
    for(i=0;i<MAX_CARDS;i++) {
        for(j=i+1;j<MAX_CARDS;j++) {
            if(player.card[i] == player.card[j]) {
                printf("%s wins!\n", player.name);
                exit(0);
            }
        }
    }
}

int main() {
    int i;
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    char name[20];
    int choice;
    do {
        printf("Welcome to Bingo Simulator!\n");
        printf("How many players would you like to have? ");
        scanf("%d", &choice);
        if(choice < 1 || choice > MAX_PLAYERS) {
            printf("Invalid number of players.\n");
        }
    } while(choice < 1 || choice > MAX_PLAYERS);
    for(i=0;i<choice;i++) {
        printf("Enter player %d's name: ", i+1);
        scanf("%s", name);
        strcpy(players[i].name, name);
        generateCard(&players[i]);
    }
    int calledNumbers[MAX_NUMBERS];
    int numCalled = 0;
    int numPlayersLeft = choice;
    int currentPlayer = 0;
    while(numPlayersLeft > 0) {
        int number = rand() % MAX_NUMBERS;
        if(numCalled == MAX_NUMBERS) {
            printf("Game over! No winner.\n");
            break;
        }
        if(numCalled == 0) {
            printf("First number: %d\n", number);
        }
        calledNumbers[numCalled] = number;
        numCalled++;
        currentPlayer = (currentPlayer + 1) % choice;
        if(currentPlayer == 0) {
            printf("Next round!\n");
        }
        checkWin(players[currentPlayer]);
        numPlayersLeft--;
    }
    return 0;
}