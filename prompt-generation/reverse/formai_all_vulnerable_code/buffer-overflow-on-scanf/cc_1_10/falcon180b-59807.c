//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEY "ROMEO AND JULIET"
#define BLOCK_SIZE 8

void encrypt(char *message, int length) {
    int i, j, k;
    for (i = 0, j = 0; i < length; i++) {
        if (isalpha(message[i])) {
            message[j++] = toupper(message[i]);
        } else {
            message[j++] = message[i];
        }
    }
    message[j] = '\0';
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            for (k = 0; k < strlen(KEY); k++) {
                if (isalpha(KEY[k])) {
                    if (tolower(message[i]) == tolower(KEY[k])) {
                        message[i] = KEY[k];
                        break;
                    }
                }
            }
        }
    }
}

void decrypt(char *message, int length) {
    int i, j, k;
    for (i = 0, j = 0; i < length; i++) {
        if (isalpha(message[i])) {
            for (k = 0; k < strlen(KEY); k++) {
                if (isalpha(KEY[k])) {
                    if (tolower(message[i]) == tolower(KEY[k])) {
                        message[i] = tolower(message[i]);
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    char message[1000];
    printf("Enter your message: ");
    scanf("%s", message);
    int length = strlen(message);
    encrypt(message, length);
    printf("Encrypted message: %s\n", message);
    decrypt(message, length);
    printf("Decrypted message: %s\n", message);
    return 0;
}