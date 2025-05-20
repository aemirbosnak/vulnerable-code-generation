//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16
#define ROUNDS 1000

void expand_key(char *key, char *expanded_key) {
    int i, j = 0;
    for (i = 0; i < strlen(key); i++) {
        expanded_key[i] = key[i];
        if (i % 2 == 0) {
            j++;
            if (j % 2 == 0) {
                expanded_key[i + j] = 'a';
            } else {
                expanded_key[i + j] = 'b';
            }
        }
    }
}

void encrypt(char *message, char *expanded_key) {
    int i, j = 0;
    char encrypted_message[SIZE];
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = expanded_key[i + j];
            } else {
                encrypted_message[i] = expanded_key[i + j + 26];
            }
        } else {
            encrypted_message[i] = message[i];
        }
        j++;
        if (j == strlen(expanded_key)) {
            j = 0;
        }
    }
    printf("Encrypted message: %s\n", encrypted_message);
}

int main() {
    char key[SIZE];
    printf("Enter the key: ");
    scanf("%s", key);
    char expanded_key[SIZE];
    expand_key(key, expanded_key);
    char message[SIZE];
    printf("Enter the message: ");
    scanf("%s", message);
    encrypt(message, expanded_key);
    return 0;
}