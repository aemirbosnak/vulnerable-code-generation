//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

struct {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char encrypted[MAX_MESSAGE_LENGTH];
    char decrypted[MAX_MESSAGE_LENGTH];
} program;

void generate_key(char* key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        program.key[i] = tolower(key[i]);
    }
}

void encrypt(char* message) {
    int i, j, key_index;
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            program.encrypted[j++] = message[i] + program.key[key_index % strlen(program.key)];
            key_index++;
        } else {
            program.encrypted[j++] = message[i];
        }
    }
}

void decrypt(char* encrypted) {
    int i, j, key_index;
    for (i = 0, j = 0; i < strlen(encrypted); i++) {
        if (isalpha(encrypted[i])) {
            program.decrypted[j++] = encrypted[i] - program.key[key_index % strlen(program.key)];
            key_index++;
        } else {
            program.decrypted[j++] = encrypted[i];
        }
    }
}

int main() {
    printf("Enter the message to encrypt: ");
    scanf("%s", program.message);
    printf("Enter the key: ");
    scanf("%s", program.key);
    generate_key(program.key);
    encrypt(program.message);
    printf("Encrypted message: %s\n", program.encrypted);
    decrypt(program.encrypted);
    printf("Decrypted message: %s\n", program.decrypted);
    return 0;
}