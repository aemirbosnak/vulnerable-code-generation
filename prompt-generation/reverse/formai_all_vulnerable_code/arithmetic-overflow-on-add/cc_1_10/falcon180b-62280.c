//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void encrypt(char* message, int key) {
    int i, j;
    char encrypted_message[MAX_LENGTH];
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            j = tolower(message[i]) - 'a';
            encrypted_message[i] = alphabet[(j + key) % 26];
        } else {
            encrypted_message[i] = message[i];
        }
    }

    encrypted_message[i] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* message, int key) {
    int i, j;
    char decrypted_message[MAX_LENGTH];
    char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            j = tolower(message[i]) - 'a';
            decrypted_message[i] = alphabet[(j - key + 26) % 26];
        } else {
            decrypted_message[i] = message[i];
        }
    }

    decrypted_message[i] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_LENGTH];
    int key;

    printf("Enter a message: ");
    fgets(message, MAX_LENGTH, stdin);

    printf("Enter a key (0-25): ");
    scanf("%d", &key);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}