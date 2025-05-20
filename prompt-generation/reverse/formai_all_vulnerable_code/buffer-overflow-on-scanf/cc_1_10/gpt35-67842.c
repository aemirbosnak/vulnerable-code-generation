//FormAI DATASET v1.0 Category: Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20
#define MAX_MESSAGE_LENGTH 100

void encrypt(char* message, int key) {
    int i;
    for (i = 0; i < strlen(message); i++) {
        message[i] ^= key; // bitwise XOR with key
    }
}

void printPlayers(char players[MAX_PLAYERS][MAX_NAME_LENGTH], int numPlayers) {
    printf("Players: ");
    int i;
    for (i = 0; i < numPlayers; i++) {
        printf("%s ", players[i]);
    }
    printf("\n");
}

int main() {
    char players[MAX_PLAYERS][MAX_NAME_LENGTH]; // array of player names
    int numPlayers = 0; // number of players currently in game
    int key = rand() % 256; // random encryption key between 0-255

    printf("Welcome to the encryption game!\n");
    printf("Enter your name to join: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    getchar(); // flush newline from input buffer

    // add first player to game
    strcpy(players[0], name);
    numPlayers++;

    // wait for more players to join
    char input[MAX_MESSAGE_LENGTH];
    while (numPlayers < MAX_PLAYERS) {
        printf("Waiting for players...\n");
        fgets(input, MAX_MESSAGE_LENGTH, stdin);
        if (strncmp(input, "/join", 5) == 0) {
            char newPlayer[MAX_NAME_LENGTH];
            sscanf(input + 6, "%s", newPlayer); // read name from input
            encrypt(newPlayer, key); // encrypt name
            strcpy(players[numPlayers], newPlayer); // add player to game
            numPlayers++;
            printPlayers(players, numPlayers); // show updated list of players
        }
    }

    // game starts!
    printf("Game starting with %d players.\n", numPlayers);
    int currentPlayer = rand() % numPlayers; // choose random player to start
    printf("%s's turn:\n", players[currentPlayer]);

    // start game loop
    while (1) {
        fgets(input, MAX_MESSAGE_LENGTH, stdin);
        if (strncmp(input, "/quit", 5) == 0) {
            printf("Quitting game.\n");
            break;
        }
        // encrypt and send message to next player
        int nextPlayer = (currentPlayer + 1) % numPlayers;
        encrypt(input, key);
        printf("Sending message to %s: %s", players[nextPlayer], input);

        // receive message from current player
        printf("%s's turn:\n", players[currentPlayer]);
        fgets(input, MAX_MESSAGE_LENGTH, stdin);
        encrypt(input, key); // decrypt message
        printf("%s says: %s", players[currentPlayer], input);

        currentPlayer = nextPlayer; // move to next player
    }

    return 0;
}