//FormAI DATASET v1.0 Category: Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 5  // Maximum number of players
#define MAX_MSG_LENGTH 100  // Maximum length of each message
#define MAX_NAME_LENGTH 20  // Maximum length of player names

void encrypt(char *message, int key);  // Function prototype for encryption
void decrypt(char *message, int key);  // Function prototype for decryption

int main() {
    char messages[MAX_PLAYERS][MAX_MSG_LENGTH];  // Array to store messages
    int keys[MAX_PLAYERS];  // Array to store encryption keys
    char names[MAX_PLAYERS][MAX_NAME_LENGTH];  // Array to store player names
    int num_players, i;

    printf("Enter number of players (maximum %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);
    getchar();  // consume newline character

    if (num_players > MAX_PLAYERS) {
        printf("Maximum number of players exceeded.\n");
        exit(1);
    }

    // Get player names and keys
    for (i = 0; i < num_players; i++) {
        printf("Enter name of player %d: ", i + 1);
        fgets(names[i], MAX_NAME_LENGTH, stdin);
        names[i][strcspn(names[i], "\n")] = '\0';  // remove newline character

        printf("Enter encryption key for player %d: ", i + 1);
        scanf("%d", &keys[i]);
        getchar();  // consume newline character

        printf("\n");
    }

    // Multiplayer chat
    while (1) {
        printf("Enter message (maximum %d characters):\n", MAX_MSG_LENGTH);
        fgets(messages[0], MAX_MSG_LENGTH, stdin);
        messages[0][strcspn(messages[0], "\n")] = '\0';  // remove newline character

        // Encrypt message for each player
        for (i = 0; i < num_players; i++) {
            strcpy(messages[i + 1], messages[0]);  // copy original message to array
            encrypt(messages[i + 1], keys[i]);  // encrypt message
        }

        // Display encrypted messages and prompt for decryption
        for (i = 0; i < num_players; i++) {
            printf("%s: %s\n", names[i], messages[i + 1]);
            printf("Do you want to decrypt this message? (Y/N): ");

            char response;
            scanf("%c", &response);
            getchar();  // consume newline character

            if (response == 'Y' || response == 'y') {
                decrypt(messages[i + 1], keys[i]);
                printf("Decrypted message: %s\n", messages[i + 1]);
            }
        }

        printf("\n");
    }

    return 0;
}

void encrypt(char *message, int key) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        message[i] = message[i] + key;
    }
}

void decrypt(char *message, int key) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        message[i] = message[i] - key;
    }
}