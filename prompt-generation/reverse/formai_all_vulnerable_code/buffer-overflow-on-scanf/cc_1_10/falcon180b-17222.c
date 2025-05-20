//Falcon-180B DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PLAYERS 10
#define MAX_LINE 1000

typedef struct {
    char name[20];
    int score;
} Player;

void initPlayers(Player players[]) {
    int i;
    for(i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Player");
        players[i].score = 0;
    }
}

void printPlayers(Player players[]) {
    int i;
    printf("Players:\n");
    for(i = 0; i < MAX_PLAYERS; i++) {
        printf("%d. %s: %d\n", i+1, players[i].name, players[i].score);
    }
}

void playGame(Player players[]) {
    int i, j, k, len, score;
    char line[MAX_LINE];
    FILE *fp;

    srand(time(NULL));
    for(i = 0; i < 5; i++) {
        k = rand() % MAX_PLAYERS;
        players[k].score += rand() % 6 + 1;
    }

    printf("Game results:\n");
    for(i = 0; i < MAX_PLAYERS; i++) {
        printf("%d. %s: %d\n", i+1, players[i].name, players[i].score);
    }

    for(i = 0; i < MAX_PLAYERS; i++) {
        sprintf(line, "echo %d. %s: %d >> result.txt", i+1, players[i].name, players[i].score);
        system(line);
    }
}

int main() {
    int i, pid, status;
    char name[20];
    Player players[MAX_PLAYERS];

    initPlayers(players);

    for(i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter name for player %d: ", i+1);
        scanf("%s", name);
        strcpy(players[i].name, name);
    }

    for(i = 0; i < MAX_PLAYERS; i++) {
        pid = fork();
        if(pid == -1) {
            printf("Fork failed!\n");
            exit(1);
        } else if(pid == 0) {
            playGame(players);
            exit(0);
        }
    }

    for(i = 0; i < MAX_PLAYERS; i++) {
        waitpid(0, &status, 0);
    }

    printPlayers(players);

    return 0;
}