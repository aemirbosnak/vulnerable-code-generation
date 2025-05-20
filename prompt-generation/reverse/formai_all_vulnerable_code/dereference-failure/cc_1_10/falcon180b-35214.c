//Falcon-180B DATASET v1.0 Category: Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

void encrypt(char *message, char *key) {
    int i, j, k;
    char *result = malloc(MAX_SIZE);
    memset(result, 0, MAX_SIZE);

    for (i = 0; message[i]!= '\0'; i++) {
        result[i] = message[i];
    }

    int key_length = strlen(key);
    int message_length = strlen(result);

    for (i = 0; i < message_length; i++) {
        for (j = 0; j < key_length; j++) {
            k = (i + j) % key_length;
            result[i] = tolower(result[i]) ^ tolower(key[k]);
        }
    }

    printf("Encrypted message: %s\n", result);
}

void decrypt(char *message, char *key) {
    int i, j, k;
    char *result = malloc(MAX_SIZE);
    memset(result, 0, MAX_SIZE);

    for (i = 0; message[i]!= '\0'; i++) {
        result[i] = message[i];
    }

    int key_length = strlen(key);
    int message_length = strlen(result);

    for (i = 0; i < message_length; i++) {
        for (j = 0; j < key_length; j++) {
            k = (i + j) % key_length;
            result[i] = tolower(result[i]) ^ tolower(key[k]);
        }
    }

    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[MAX_SIZE];
    char key[MAX_SIZE];

    printf("Enter a message: ");
    scanf("%s", message);

    printf("Enter a key: ");
    scanf("%s", key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}