//FormAI DATASET v1.0 Category: Modern Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void encrypt(char *message, int key);
void decrypt(char *message, int key);

int main(void) {
    char message[MAX_SIZE];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);

    printf("Enter a key (1-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int key) {
    char *current = message;
    while (*current != '\0') {
        if (*current >= 'a' && *current <= 'z') {
            *current = ((*current - 'a') + key) % 26 + 'a';
        } else if (*current >= 'A' && *current <= 'Z') {
            *current = ((*current - 'A') + key) % 26 + 'A';
        }
        current++;
    }
}

void decrypt(char *message, int key) {
    char *current = message;
    while (*current != '\0') {
        if (*current >= 'a' && *current <= 'z') {
            *current = ((*current - 'a') - key + 26) % 26 + 'a';
        } else if (*current >= 'A' && *current <= 'Z') {
            *current = ((*current - 'A') - key + 26) % 26 + 'A';
        }
        current++;
    }
}