//Falcon-180B DATASET v1.0 Category: Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char message[100];
    char key[10];
    int mode;
    printf("Enter message to encrypt: ");
    scanf("%[^\n]", message);
    printf("Enter encryption mode (1: Caesar cipher, 2: Vigenere cipher): ");
    scanf("%d", &mode);
    printf("Enter key: ");
    scanf("%s", key);

    if (mode == 1) {
        int key_int = key[0] - '0';
        int shift = key_int % 26;
        for (int i = 0; i < strlen(message); i++) {
            if (message[i] >= 'a' && message[i] <= 'z') {
                message[i] = message[i] + shift;
                if (message[i] > 'z') {
                    message[i] = message[i] - 26;
                }
            } else if (message[i] >= 'A' && message[i] <= 'Z') {
                message[i] = message[i] + shift;
                if (message[i] > 'Z') {
                    message[i] = message[i] - 26;
                }
            }
        }
        printf("Encrypted message: %s\n", message);
    } else if (mode == 2) {
        int key_int = key[0] - '0';
        int key_length = strlen(key);
        char key_char[key_length];
        strcpy(key_char, key);
        for (int i = 0; i < strlen(message); i++) {
            if (message[i] >= 'a' && message[i] <= 'z') {
                message[i] = message[i] + key_char[i % key_length] - 'a';
                if (message[i] > 'z') {
                    message[i] = message[i] - 26;
                }
            } else if (message[i] >= 'A' && message[i] <= 'Z') {
                message[i] = message[i] + key_char[i % key_length] - 'A';
                if (message[i] > 'Z') {
                    message[i] = message[i] - 26;
                }
            }
        }
        printf("Encrypted message: %s\n", message);
    } else {
        printf("Invalid encryption mode.\n");
    }

    return 0;
}