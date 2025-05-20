//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: multiplayer
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PLAYERS 4
#define MAX_MESSAGE_LENGTH 256

typedef struct {
    char name[20];
    char message[MAX_MESSAGE_LENGTH];
} Player;

void compress(char *input, char *output) {
    int count;
    char current;

    while (*input) {
        current = *input;
        count = 1;
        while (*(input + 1) == current) {
            count++;
            input++;
        }
        sprintf(output, "%c%d", current, count);
        output += strlen(output);
        input++;
    }
    *output = '\0'; // Null terminate the compressed string
}

void decompress(char *input, char *output) {
    char current;
    int count;

    while (*input) {
        current = *input++;
        count = 0;
        
        // Get the numeric count
        while (*input >= '0' && *input <= '9') {
            count = count * 10 + (*input - '0');
            input++;
        }

        for (int i = 0; i < count; i++) {
            *output++ = current;
        }
    }
    *output = '\0'; // Null terminate the decompressed string
}

void displayPlayerMessages(Player players[], int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        printf("Player %s sent: %s\n", players[i].name, players[i].message);
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int playerCount = 0;

    printf("Welcome to the Multiplayer Compression Game!\n");
    printf("You can have up to %d players.\n", MAX_PLAYERS);

    while (playerCount < MAX_PLAYERS) {
        printf("Enter player name (or type 'exit' to finish): ");
        scanf("%s", players[playerCount].name);

        if (strcmp(players[playerCount].name, "exit") == 0) {
            break;
        }

        printf("Enter a message for player %s: ", players[playerCount].name);
        scanf("%s", players[playerCount].message);

        // Compress the player's message
        char compressedMessage[MAX_MESSAGE_LENGTH];
        compress(players[playerCount].message, compressedMessage);
        printf("Compressed message: %s\n", compressedMessage);

        // Decompress the message back to original
        char decompressedMessage[MAX_MESSAGE_LENGTH];
        decompress(compressedMessage, decompressedMessage);
        printf("Decompressed message: %s\n", decompressedMessage);

        playerCount++;
    }

    printf("\nAll Player Messages:\n");
    displayPlayerMessages(players, playerCount);

    return 0;
}