//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 4
#define MESSAGE_LENGTH 256

void encrypt(char message[], int key);
void decrypt(char message[], int key);

int main() {
    char messages[MAX_PLAYERS][MESSAGE_LENGTH];
    int keys[MAX_PLAYERS];
    int num_players;

    printf("How many players are there? (maximum %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    if (num_players > MAX_PLAYERS) {
        printf("Error: maximum number of players is %d\n", MAX_PLAYERS);
        return 1;
    }

    for (int i = 0; i < num_players; i++) {
        printf("Enter player %d's message: ", i+1);
        fgets(messages[i], MESSAGE_LENGTH, stdin);
        fflush(stdin);

        printf("Enter player %d's encryption key: ", i+1);
        scanf("%d", &keys[i]);
    }

    printf("\n\n");

    // Encrypt messages
    for (int i = 0; i < num_players; i++) {
        encrypt(messages[i], keys[i]);
        printf("Player %d's encrypted message: %s\n", i+1, messages[i]);
    }

    printf("\n\n");

    // Decrypt messages
    for (int i = 0; i < num_players; i++) {
        decrypt(messages[i], keys[i]);
        printf("Player %d's decrypted message: %s\n", i+1, messages[i]);
    }

    return 0;
}

void encrypt(char message[], int key) {
    int len = strlen(message);

    for (int i = 0; i < len; i++) {
        message[i] = message[i] + key;
    }
}

void decrypt(char message[], int key) {
    int len = strlen(message);

    for (int i = 0; i < len; i++) {
        message[i] = message[i] - key;
    }
}