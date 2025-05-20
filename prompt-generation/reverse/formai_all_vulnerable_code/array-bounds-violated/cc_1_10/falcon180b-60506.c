//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PLAYERS 4
#define MAX_VIRUSES 5

typedef struct {
    char name[20];
    int score;
} Player;

typedef struct {
    char name[20];
    int strength;
} Virus;

void initPlayers(Player players[]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "Player");
        players[i].name[6] += i + 1;
        players[i].score = 0;
    }
}

void initViruses(Virus viruses[]) {
    for (int i = 0; i < MAX_VIRUSES; i++) {
        strcpy(viruses[i].name, "Virus");
        viruses[i].name[5] += i + 1;
        viruses[i].strength = i * 10;
    }
}

void printPlayers(Player players[]) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d\n", players[i].name, players[i].score);
    }
}

void printViruses(Virus viruses[]) {
    for (int i = 0; i < MAX_VIRUSES; i++) {
        printf("%s: %d\n", viruses[i].name, viruses[i].strength);
    }
}

void fight(Player player, Virus virus) {
    if (player.score >= virus.strength) {
        virus.strength = 0;
        player.score -= virus.strength;
    } else {
        player.score = 0;
    }
}

int main() {
    Player players[MAX_PLAYERS];
    initPlayers(players);

    Virus viruses[MAX_VIRUSES];
    initViruses(viruses);

    char choice;

    while (true) {
        printf("Choose an option:\n");
        printf("1. Fight a virus\n");
        printf("2. Print scores\n");
        printf("3. Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                {
                    int virusIndex;
                    printf("Choose a virus to fight:\n");
                    for (int i = 0; i < MAX_VIRUSES; i++) {
                        printf("%d. %s\n", i + 1, viruses[i].name);
                    }
                    scanf("%d", &virusIndex);
                    fight(players[0], viruses[virusIndex - 1]);
                    break;
                }
            case '2':
                printPlayers(players);
                printViruses(viruses);
                break;
            case '3':
                return 0;
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}