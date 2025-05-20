//FormAI DATASET v1.0 Category: Modern Encryption ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to encrypt using XOR cipher
char* encrypt(char* msg, char* key)
{
    int msgLen = strlen(msg), keyLen = strlen(key), i;
    char* res = (char*)calloc(msgLen + 1, sizeof(char));

    for (i = 0; i < msgLen; i++)
        res[i] = msg[i] ^ key[i % keyLen];
    res[i] = '\0';

    return res;
}

// Function to decrypt using XOR cipher
char* decrypt(char* msg, char* key)
{
    int msgLen = strlen(msg), keyLen = strlen(key), i;
    char* res = (char*)calloc(msgLen + 1, sizeof(char));

    for (i = 0; i < msgLen; i++)
        res[i] = msg[i] ^ key[i % keyLen];
    res[i] = '\0';

    return res;
}

// Main function
int main()
{
    int numPlayers;
    char message[100], key[100], **encryptedMessages, **decryptedMessages;
    int i, j;

    // Get number of players
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);

    // Allocate memory for encrypted and decrypted messages
    encryptedMessages = (char**)calloc(numPlayers, sizeof(char*));
    decryptedMessages = (char**)calloc(numPlayers, sizeof(char*));
    for (i = 0; i < numPlayers; i++) {
        encryptedMessages[i] = (char*)calloc(100, sizeof(char));
        decryptedMessages[i] = (char*)calloc(100, sizeof(char));
    }

    // Get message and key from sender
    printf("Enter message from sender: ");
    scanf("%s", message);
    printf("Enter key: ");
    scanf("%s", key);

    // Encrypt message using key
    char* encryptedMsg = encrypt(message, key);

    // Distribute encrypted message to all players
    srand(time(0));
    for (i = 0; i < numPlayers; i++) {
        // Add some random characters to message to make it unique
        char randChars[10];
        for (j = 0; j < 5; j++)
            randChars[j] = 'a' + (rand() % 26);
        randChars[j] = '\0';

        sprintf(encryptedMessages[i], "%s%s", encryptedMsg, randChars);
    }

    // Each player decrypts message using their key and sends it to sender
    for (i = 0; i < numPlayers; i++) {
        char playerKey[100];
        printf("Enter key for player %d: ", i + 1);
        scanf("%s", playerKey);

        char* decryptedMsg = decrypt(encryptedMessages[i], playerKey);
        strcpy(decryptedMessages[i], decryptedMsg);
    }

    // Sender receives messages and decrypts them using their key
    for (i = 0; i < numPlayers; i++) {
        printf("Message from player %d: %s\n", i + 1, decryptedMessages[i]);
    }

    char* finalMessage = decrypt(encryptedMsg, key);
    printf("Sender received message: %s\n", finalMessage);

    // Free allocated memory
    free(encryptedMsg);
    for (i = 0; i < numPlayers; i++) {
        free(encryptedMessages[i]);
        free(decryptedMessages[i]);
    }
    free(encryptedMessages);
    free(decryptedMessages);
    return 0;
}