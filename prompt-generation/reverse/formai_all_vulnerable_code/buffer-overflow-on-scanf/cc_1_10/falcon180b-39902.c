//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_ALIENS 100
#define MIN_ALIENS 1

typedef struct {
    char name[20];
    int score;
} Player;

typedef struct {
    int x, y;
} Alien;

void initAliens(Alien aliens[], int numAliens) {
    for (int i = 0; i < numAliens; i++) {
        aliens[i].x = rand() % 20 + 1;
        aliens[i].y = rand() % 10 + 1;
    }
}

int countAliens(Alien aliens[], int numAliens) {
    int count = 0;
    for (int i = 0; i < numAliens; i++) {
        if (aliens[i].x == 1 && aliens[i].y == 1) {
            count++;
        }
    }
    return count;
}

void moveAliens(Alien aliens[], int numAliens) {
    for (int i = 0; i < numAliens; i++) {
        if (aliens[i].x > 1) {
            aliens[i].x--;
        } else if (aliens[i].y > 1) {
            aliens[i].y--;
        } else {
            aliens[i].x = rand() % 20 + 1;
            aliens[i].y = rand() % 10 + 1;
        }
    }
}

void drawBoard(Alien aliens[], int numAliens) {
    for (int i = 0; i < numAliens; i++) {
        if (aliens[i].x == 1 && aliens[i].y == 1) {
            printf("@");
        } else {
            printf(" ");
        }
    }
}

void printScores(Player players[], int numPlayers) {
    printf("\nScores:\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

int main() {
    srand(time(NULL));
    Player players[MAX_PLAYERS];
    Alien aliens[MAX_ALIENS];
    int numPlayers = 0, numAliens = 0, gameOver = 0;

    while (numPlayers < MAX_PLAYERS &&!gameOver) {
        printf("Enter your name: ");
        scanf("%s", players[numPlayers].name);
        numPlayers++;
    }

    while (numAliens < MIN_ALIENS &&!gameOver) {
        numAliens = rand() % (MAX_ALIENS - MIN_ALIENS + 1) + MIN_ALIENS;
    }

    initAliens(aliens, numAliens);
    while (!gameOver) {
        system("clear");
        printf("Aliens: %d\n", numAliens);
        drawBoard(aliens, numAliens);
        printScores(players, numPlayers);
        for (int i = 0; i < numPlayers; i++) {
            if (countAliens(aliens, numAliens) == 0) {
                players[i].score++;
                numAliens = rand() % (MAX_ALIENS - MIN_ALIENS + 1) + MIN_ALIENS;
                initAliens(aliens, numAliens);
            }
        }
        moveAliens(aliens, numAliens);
        if (countAliens(aliens, numAliens) == 0) {
            gameOver = 1;
        }
    }

    return 0;
}