//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 6

int main()
{
    char plain_text[20];
    char key[20];

    printf("Enter plain text: ");
    scanf("%s", plain_text);

    printf("Enter key: ");
    scanf("%s", key);

    // Encryption
    int length = strlen(plain_text);
    char cipher_text[length];
    srand(time(NULL));
    for(int i=0; i<length; i++)
    {
        cipher_text[i] = plain_text[i] ^ key[i % strlen(key)] ^ rand() % 256;
    }
    cipher_text[length] = '\0';

    printf("Encrypted message: %s\n", cipher_text);

    // Decryption
    char decrypted[length];
    srand(time(NULL));
    for(int i=0; i<length; i++)
    {
        decrypted[i] = cipher_text[i] ^ key[i % strlen(key)] ^ rand() % 256;
    }
    decrypted[length] = '\0';

    printf("Decrypted message: %s\n", decrypted);

    // Multiplayer mode
    char players[MAX_PLAYERS][20];
    int num_players;
    printf("Enter number of players (max 6): ");
    scanf("%d", &num_players);
    if(num_players > MAX_PLAYERS)
    {
        printf("Too many players!\n");
        return 1;
    }
    for(int i=0; i<num_players; i++)
    {
        printf("Enter name of player %d: ", i+1);
        scanf("%s", players[i]);
    }

    printf("Starting multiplayer mode...\n");
    for(int i=0; i<num_players; i++)
    {
        printf("\nPlayer %s's turn\n", players[i]);
        printf("Enter guess for key: ");
        char guess[20];
        scanf("%s", guess);

        if(strcmp(guess, key) == 0)
        {
            printf("Correct key! Player %s wins!\n", players[i]);
            return 0;
        }
        else
        {
            printf("Incorrect key! Player %s is out of the game.\n", players[i]);
        }
    }

    printf("No player guessed the correct key. Game over.\n");
    return 0;
}