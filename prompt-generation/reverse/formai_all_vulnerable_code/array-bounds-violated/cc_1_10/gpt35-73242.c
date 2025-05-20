//FormAI DATASET v1.0 Category: modern Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char message[1000];
    char key[1000];
    int keyLength;
    int messageLength;
    int i, j;

    // Get input from user
    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters from input
    messageLength = strlen(message) - 1;
    if (message[messageLength] == '\n') {
        message[messageLength] = '\0';
    }

    keyLength = strlen(key) - 1;
    if (key[keyLength] == '\n') {
        key[keyLength] = '\0';
    }

    // Generate random seed for srand function
    srand(time(NULL));

    // Generate random permutation of numbers 0 to messageLength - 1
    int permutation[messageLength];
    for (i = 0; i < messageLength; i++) {
        permutation[i] = i;
    }
    for (i = messageLength - 1; i >= 1; i--) {
        j = rand() % (i+1);
        int temp = permutation[i];
        permutation[i] = permutation[j];
        permutation[j] = temp;
    }

    // Print permutation for reference
    printf("Permutation: ");
    for (i = 0; i < messageLength; i++) {
        printf("%d ", permutation[i]);
    }
    printf("\n");

    // Encrypt message using permutation and key
    char encrypted[messageLength+1];
    for (i = 0; i < messageLength; i++) {
        int index = permutation[i];
        int keyValue = key[i % keyLength];
        encrypted[index] = message[i] + keyValue;
    }
    encrypted[messageLength] = '\0';

    // Print encrypted message
    printf("Encrypted message: %s\n", encrypted);

    return 0;
}