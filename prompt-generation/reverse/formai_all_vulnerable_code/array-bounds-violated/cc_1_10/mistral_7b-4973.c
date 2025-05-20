//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define KEY_LENGTH 32
#define MAX_INPUT_LENGTH 100
#define KEY "Roses are red,\nViolets are blue,\nSugar is sweet,\nAnd so are you."

void encrypt(char *message, char *key) {
    int i, j, k;
    char temp;

    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            for (j = 0; j < strlen(KEY); j++) {
                if (isalpha(key[j])) {
                    k = (toupper(message[i]) - 'A' + (toupper(key[j]) - 'A')) % 26;
                    message[i] = (char) ((message[i] + k - 'A') % 26 + 'A');
                    break;
                }
            }
        }
    }

    for (i = 0; i < strlen(message); i += 2) {
        if (i + 1 < strlen(message)) {
            temp = message[i];
            message[i] = message[i + 1];
            message[i + 1] = temp;
        }
    }
}

int main() {
    char message[MAX_INPUT_LENGTH], encrypted_message[MAX_INPUT_LENGTH];
    char *key = KEY;
    int len;

    printf("Enter your message: ");
    scanf("%s", message);
    len = strlen(message);

    // Allocate memory for encrypted_message
    encrypted_message[len] = '\0';
    encrypted_message[len - 1] = '\0';

    // Seed the random number generator with current time
    srand(time(NULL));

    // XOR the first character with a random number
    encrypted_message[0] = (char) (message[0] ^ (rand() % 256));

    encrypt(message, key);
    strcat(encrypted_message, message);

    // Encrypt the last character with a random number
    encrypted_message[len + 1] = (char) (encrypted_message[len] ^ (rand() % 256));
    encrypted_message[len + 2] = '\0';

    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_message);

    return 0;
}