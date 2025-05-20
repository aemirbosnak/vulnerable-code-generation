//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt(char *message, char *key) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] + (key[j] - 'a');
            j = (j + 1) % KEY_SIZE;
        } else {
            message[i] = message[i];
        }
    }
}

void decrypt(char *encrypted_message, char *key) {
    int i, j;
    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            encrypted_message[i] = encrypted_message[i] - (key[j] - 'a');
            j = (j + 1) % KEY_SIZE;
        } else {
            encrypted_message[i] = encrypted_message[i];
        }
    }
}

int main() {
    char message[100], encrypted_message[100], key[KEY_SIZE + 1];
    srand(time(NULL));
    generate_key(key);
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}