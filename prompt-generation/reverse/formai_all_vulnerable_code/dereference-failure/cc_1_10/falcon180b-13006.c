//Falcon-180B DATASET v1.0 Category: Encryption ; Style: secure
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *message, char *key) {
    int len = strlen(message);
    int klen = strlen(key);
    char *result = malloc(len + 1);
    int i, j, n, c;
    for (i = 0, j = 0; i < len; i++) {
        if (isalpha(message[i])) {
            c = tolower(message[i]) - 97;
            n = (c + klen) % 26;
            if (isupper(message[i])) {
                result[j++] = (char) ((n + 65) % 26 + 65);
            } else {
                result[j++] = (char) ((n + 97) % 26 + 97);
            }
        } else {
            result[j++] = message[i];
        }
    }
    result[j] = '\0';
    printf("Encrypted message: %s\n", result);
}

void decrypt(char *message, char *key) {
    int len = strlen(message);
    int klen = strlen(key);
    char *result = malloc(len + 1);
    int i, j, n, c;
    for (i = 0, j = 0; i < len; i++) {
        if (isalpha(message[i])) {
            c = tolower(message[i]) - 97;
            n = (26 - c + klen) % 26;
            if (isupper(message[i])) {
                result[j++] = (char) ((n - 65) % 26 + 65);
            } else {
                result[j++] = (char) ((n - 97) % 26 + 97);
            }
        } else {
            result[j++] = message[i];
        }
    }
    result[j] = '\0';
    printf("Decrypted message: %s\n", result);
}

int main() {
    char message[100];
    char key[100];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    printf("Enter a key: ");
    scanf("%s", key);
    encrypt(message, key);
    decrypt(message, key);
    return 0;
}