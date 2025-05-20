//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void encrypt(char *str, int key);

void decrypt(char *str, int key);

int main() {
    char message[MAX_SIZE];
    int key;

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter a key value: ");
    scanf("%d", &key);

    encrypt(message, key);

    printf("\nEncrypted message: %s\n", message);

    decrypt(message, key);

    printf("\nDecrypted message: %s\n", message);

    return 0;
}

void encrypt(char *str, int key) {
    if (*str == '\0')
        return;

    if (*str >= 'A' && *str <= 'Z')
        *str = (*str + key - 'A') % 26 + 'A';
    else if (*str >= 'a' && *str <= 'z')
        *str = (*str + key - 'a') % 26 + 'a';

    encrypt(str + 1, key);
}

void decrypt(char *str, int key) {
    if (*str == '\0')
        return;

    if (*str >= 'A' && *str <= 'Z')
        *str = (*str - key - 'A' + 26) % 26 + 'A';
    else if (*str >= 'a' && *str <= 'z')
        *str = (*str - key - 'a' + 26) % 26 + 'a';

    decrypt(str + 1, key);
}