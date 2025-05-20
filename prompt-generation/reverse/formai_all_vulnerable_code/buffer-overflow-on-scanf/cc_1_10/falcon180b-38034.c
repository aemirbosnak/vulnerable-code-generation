//Falcon-180B DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPTION_KEY "mysecretkey"
#define NUM_ROUNDS 1000

void encrypt(char *message, char *key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    char *result = malloc(message_len + 1);
    int i, j, k;

    for (i = 0, j = 0; i < message_len; i++) {
        char c = toupper(message[i]);
        if (isalpha(c)) {
            c = (c + key[j % key_len] - 65) % 26 + 65;
            result[i] = c;
            j++;
        } else {
            result[i] = message[i];
        }
    }

    result[message_len] = '\0';

    printf("Encrypted message: %s\n", result);
}

void decrypt(char *message, char *key) {
    int message_len = strlen(message);
    int key_len = strlen(key);
    char *result = malloc(message_len + 1);
    int i, j, k;

    for (i = 0, j = 0; i < message_len; i++) {
        char c = toupper(message[i]);
        if (isalpha(c)) {
            c = (c - key[j % key_len] + 26) % 26 + 65;
            result[i] = c;
            j++;
        } else {
            result[i] = message[i];
        }
    }

    result[message_len] = '\0';

    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[1000];
    printf("Enter your message: ");
    scanf("%s", message);

    encrypt(message, ENCRYPTION_KEY);
    decrypt(message, ENCRYPTION_KEY);

    return 0;
}