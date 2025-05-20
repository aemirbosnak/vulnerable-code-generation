//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MAX_MSG_LEN 256

void encrypt(char *msg, int key) {
    for(int i = 0; i < strlen(msg); i++) {
        msg[i] = ((msg[i] - 'a' + key) % 26) + 'a'; // simple Caesar cipher
    }
}

void decrypt(char *msg, int key) {
    for(int i = 0; i < strlen(msg); i++) {
        msg[i] = ((msg[i] - 'a' - key + 26) % 26) + 'a'; // inverse of Caesar cipher
    }
}

int main() {
    char messages[MAX_PLAYERS][MAX_MSG_LEN];
    int keys[MAX_PLAYERS];
    int num_players;

    // read number of players
    printf("Enter number of players (maximum %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    if(num_players < 2 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players!\n");
        return 1;
    }

    // read messages
    for(int i = 0; i < num_players; i++) {
        printf("Player %d, enter your message: ", i+1);
        scanf("%s", messages[i]);
    }

    // generate random keys
    for(int i = 0; i < num_players; i++) {
        keys[i] = rand() % 26;
        printf("Player %d, your key is %d.\n", i+1, keys[i]);
    }

    // encrypt messages with keys
    for(int i = 0; i < num_players; i++) {
        encrypt(messages[i], keys[i]);
    }

    // print encrypted messages
    printf("Encrypted messages:\n");
    for(int i = 0; i < num_players; i++) {
        printf("Player %d: %s\n", i+1, messages[i]);
    }

    // decrypt messages with keys
    for(int i = 0; i < num_players; i++) {
        decrypt(messages[i], keys[i]);
    }

    // print decrypted messages
    printf("Decrypted messages:\n");
    for(int i = 0; i < num_players; i++) {
        printf("Player %d: %s\n", i+1, messages[i]);
    }

    return 0;
}