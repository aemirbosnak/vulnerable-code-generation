//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16

void encrypt(char* message, char* key) {
    int i, j;
    char result[strlen(message)];
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = (c >= 'a'? c + 'A' - 'a' : c + 'a' - 'A');
            c = (c + key[j] - 'A' + 26) % 26 + 'A';
            result[j++] = c;
            if (j == KEY_LENGTH) j = 0;
        } else {
            result[j++] = c;
        }
    }
    result[j] = '\0';
    strcpy(message, result);
}

void decrypt(char* message, char* key) {
    int i, j;
    char result[strlen(message)];
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        char c = message[i];
        if (isalpha(c)) {
            c = (c >= 'A'? c + 'a' - 'A' : c + 'A' - 'a');
            c = (c - key[j] - 'A' + 26) % 26 + 'A';
            result[j++] = c;
            if (j == KEY_LENGTH) j = 0;
        } else {
            result[j++] = c;
        }
    }
    result[j] = '\0';
    strcpy(message, result);
}

int main() {
    char message[1000], key[KEY_LENGTH+1];
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter encryption key: ");
    scanf("%s", key);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}