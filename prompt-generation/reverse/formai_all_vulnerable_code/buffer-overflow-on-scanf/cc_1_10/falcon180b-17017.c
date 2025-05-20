//Falcon-180B DATASET v1.0 Category: Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 4
#define MESSAGE_LENGTH 100

typedef struct {
    char name[20];
    int score;
    char message[MESSAGE_LENGTH];
} Player;

void generate_key(char* key) {
    srand(time(NULL));
    for (int i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[strlen(key)] = '\0';
}

void encrypt_message(char* message, char* key) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - 'a' + (int)key[i % strlen(key)]) % 26 + 'a';
        }
    }
}

void decrypt_message(char* message, char* key) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - (int)key[i % strlen(key)] + 26) % 26 + 'a';
        }
    }
}

int main() {
    Player players[MAX_PLAYERS];
    char key[MAX_PLAYERS];

    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", players[i].name);
        generate_key(key + i * strlen(key));
        printf("Player %s's key: %s\n", players[i].name, key + i * strlen(key));
    }

    char message[MESSAGE_LENGTH];
    printf("Enter your message: ");
    scanf("%s", message);

    for (int i = 0; i < MAX_PLAYERS; i++) {
        encrypt_message(message, key + i * strlen(key));
        printf("Encrypted message for %s: %s\n", players[i].name, message);
    }

    return 0;
}