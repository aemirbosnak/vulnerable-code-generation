//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PLAYERS 10
#define MAX_MESSAGE_LENGTH 1000
#define PUBLIC_KEY_LENGTH 1000
#define PRIVATE_KEY_LENGTH 2000

typedef struct {
    char name[50];
    int public_key[PUBLIC_KEY_LENGTH];
    int private_key[PRIVATE_KEY_LENGTH];
} Player;

void generate_public_key(int public_key[PUBLIC_KEY_LENGTH]) {
    int a, b, n;
    printf("Enter two prime numbers: ");
    scanf("%d %d", &a, &b);
    n = a * b;
    for (int i = 0; i < PUBLIC_KEY_LENGTH; i++) {
        public_key[i] = rand() % n;
    }
}

void generate_private_key(int public_key[PUBLIC_KEY_LENGTH], int private_key[PRIVATE_KEY_LENGTH]) {
    int a, b, n;
    printf("Enter two prime numbers: ");
    scanf("%d %d", &a, &b);
    n = a * b;
    for (int i = 0; i < PRIVATE_KEY_LENGTH; i++) {
        private_key[i] = rand() % n;
    }
    for (int i = 0; i < PUBLIC_KEY_LENGTH; i++) {
        private_key[i] = (private_key[i] * public_key[i]) % n;
    }
}

void encrypt_message(int public_key[PUBLIC_KEY_LENGTH], char message[MAX_MESSAGE_LENGTH]) {
    int n = strlen(message);
    char encrypted_message[MAX_MESSAGE_LENGTH];
    for (int i = 0; i < n; i++) {
        encrypted_message[i] = message[i] ^ public_key[i % PUBLIC_KEY_LENGTH];
    }
    strcpy(message, encrypted_message);
}

void decrypt_message(int private_key[PRIVATE_KEY_LENGTH], char message[MAX_MESSAGE_LENGTH]) {
    int n = strlen(message);
    char decrypted_message[MAX_MESSAGE_LENGTH];
    for (int i = 0; i < n; i++) {
        decrypted_message[i] = message[i] ^ private_key[i % PRIVATE_KEY_LENGTH];
    }
    strcpy(message, decrypted_message);
}

void send_message(Player* players, int sender_id, char message[MAX_MESSAGE_LENGTH]) {
    printf("Player %d sent message: %s\n", sender_id, message);
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (i!= sender_id) {
            encrypt_message(players[i].public_key, message);
            printf("Player %d received message: %s\n", i, message);
        }
    }
}

int main() {
    Player players[MAX_PLAYERS];
    int n;

    printf("Enter number of players: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter player name: ");
        scanf("%s", players[i].name);
        generate_public_key(players[i].public_key);
        generate_private_key(players[i].public_key, players[i].private_key);
    }

    int sender_id;
    char message[MAX_MESSAGE_LENGTH];

    while (1) {
        printf("Enter message to send: ");
        scanf("%s", message);
        send_message(players, sender_id, message);
    }

    return 0;
}