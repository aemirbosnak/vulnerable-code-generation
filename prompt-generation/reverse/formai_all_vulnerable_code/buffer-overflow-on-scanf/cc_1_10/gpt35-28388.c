//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_MESSAGE_SIZE 1000
#define KEY_SIZE 3

char* encrypt(char* message, int key[]);
char* decrypt(char* message, int key[]);
void print_message(char* message);

int main() {
    int num_players;
    int i = 0;
    char encrypted_message[MAX_MESSAGE_SIZE];
    char decrypted_message[MAX_MESSAGE_SIZE];
    char message[MAX_MESSAGE_SIZE];
    int key[KEY_SIZE] = {3, 4, 5};
    int player_id[MAX_PLAYERS];
    char player_name[MAX_PLAYERS][50];

    printf("Enter number of players (up to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    if (num_players > MAX_PLAYERS) {
        printf("Maximum number of players is %d. Exiting program...\n", MAX_PLAYERS);
        return 1;
    }

    // get player names
    printf("\nEnter player names:\n");
    for (i = 0; i < num_players; i++) {
        printf("Player %d: ", i + 1);
        scanf("%s", player_name[i]);
        player_id[i] = i + 1;
    }

    // get message to encrypt
    printf("\nEnter message to encrypt: ");
    scanf(" %[^\n]s", message);

    // encrypt message and send to all players
    for (i = 0; i < num_players; i++) {
        printf("\nMessage for %s (Player %d):\n", player_name[i], player_id[i]);
        strcpy(encrypted_message, encrypt(message, key));
        printf("%s\n", encrypted_message);
    }

    // get encrypted message from all players and decrypt
    printf("\n\n");
    for (i = 0; i < num_players; i++) {
        printf("Enter message from %s (Player %d): ", player_name[i], player_id[i]);
        scanf(" %[^\n]s", encrypted_message);
        strcpy(decrypted_message, decrypt(encrypted_message, key));
        printf("\n%s\n", decrypted_message);
    }

    return 0;
}

char* encrypt(char* message, int key[]) {
    static char encrypted[MAX_MESSAGE_SIZE];
    int len = strlen(message);
    int i;

    for (i = 0; i < len; i++) {
        encrypted[i] = (message[i] + key[i % KEY_SIZE]) % 256;
    }

    encrypted[i] = '\0';

    return encrypted;
}

char* decrypt(char* message, int key[]) {
    static char decrypted[MAX_MESSAGE_SIZE];
    int len = strlen(message);
    int i;

    for (i = 0; i < len; i++) {
        decrypted[i] = (message[i] - key[i % KEY_SIZE] + 256) % 256;
    }

    decrypted[i] = '\0';

    return decrypted;
}

void print_message(char* message) {
    printf("%s\n", message);
}