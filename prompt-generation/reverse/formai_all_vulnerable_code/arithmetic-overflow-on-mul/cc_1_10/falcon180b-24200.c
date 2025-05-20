//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 10
#define PRIME_NUMBER 23

typedef struct {
    char name[20];
    int public_key;
    int private_key;
} Player;

void generate_keys(Player *player) {
    srand(time(NULL));
    player->public_key = rand() % PRIME_NUMBER;
    player->private_key = rand() % PRIME_NUMBER;
}

int encrypt(int message, int public_key) {
    return (message * public_key) % PRIME_NUMBER;
}

int decrypt(int encrypted_message, int private_key) {
    return encrypted_message * private_key % PRIME_NUMBER;
}

int main() {
    Player players[MAX_PLAYERS];
    int num_players, i;

    printf("Enter the number of players: ");
    scanf("%d", &num_players);

    for (i = 0; i < num_players; i++) {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i].name);
        generate_keys(&players[i]);
    }

    printf("\nPublic keys:\n");
    for (i = 0; i < num_players; i++) {
        printf("%s: %d\n", players[i].name, players[i].public_key);
    }

    printf("\n\nEnter the message to encrypt: ");
    int message;
    scanf("%d", &message);

    printf("\nEncrypted message: %d\n", encrypt(message, players[0].public_key));

    printf("\n\nEnter the encrypted message to decrypt: ");
    int encrypted_message;
    scanf("%d", &encrypted_message);

    printf("\nDecrypted message: %d\n", decrypt(encrypted_message, players[0].private_key));

    return 0;
}