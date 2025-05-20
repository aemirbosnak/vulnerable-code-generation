//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 10
#define MAX_KEY_SIZE 32

char private_keys[MAX_PLAYERS][MAX_KEY_SIZE]; // Store private keys for each player
char public_keys[MAX_PLAYERS][MAX_KEY_SIZE]; // Store public keys for each player
char session_keys[MAX_PLAYERS][MAX_KEY_SIZE]; // Store session keys for each player

// Generate a random key of length key_len
void generate_key(char* key, int key_len) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    srand(time(NULL));
    for (int i = 0; i < key_len; i++) {
        key[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    key[key_len] = '\0';
}

// Generate private and public keys for a player
void generate_keys(int player_index) {
    generate_key(private_keys[player_index], MAX_KEY_SIZE);
    printf("Player %d private key: %s\n", player_index, private_keys[player_index]);
    generate_key(public_keys[player_index], MAX_KEY_SIZE);
    printf("Player %d public key: %s\n", player_index, public_keys[player_index]);
}

// Generate session keys for all players using public keys
void generate_session_keys(int player_count) {
    for (int i = 0; i < player_count; i++) {
        for (int j = i+1; j < player_count; j++) {
            // XOR the public keys of two players to create a session key
            for (int k = 0; k < MAX_KEY_SIZE; k++) {
                session_keys[i][k] = public_keys[i][k] ^ public_keys[j][k];
            }
            printf("Session key between Player %d and Player %d: %s\n", i, j, session_keys[i]);
            // XOR the session key with the players' private keys to create a final key
            for (int k = 0; k < MAX_KEY_SIZE; k++) {
                session_keys[i][k] = session_keys[i][k] ^ private_keys[i][k];
            }
            for (int k = 0; k < MAX_KEY_SIZE; k++) {
                session_keys[i][k] = session_keys[i][k] ^ private_keys[j][k];
            }
            printf("Final key between Player %d and Player %d: %s\n", i, j, session_keys[i]);
        }
    }
}

int main() {
    int player_count;
    printf("Enter number of players (max %d): ", MAX_PLAYERS);
    scanf("%d", &player_count);
    printf("\n");
    if (player_count > MAX_PLAYERS) {
        printf("Too many players!\n");
        return 1;
    }
    for (int i = 0; i < player_count; i++) {
        generate_keys(i);
        printf("\n");
    }
    generate_session_keys(player_count);
    return 0;
}