//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define KEY_LENGTH 16
#define DATA_LENGTH 64

void generate_key(char* key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char* data, char* key) {
    for (int i = 0; i < strlen(data); i++) {
        data[i] = toupper(data[i]);
        if (isalpha(data[i])) {
            data[i] = (data[i] - 'A' + key[i % KEY_LENGTH]) % 26 + 'A';
        }
    }
}

void decrypt(char* data, char* key) {
    for (int i = 0; i < strlen(data); i++) {
        data[i] = toupper(data[i]);
        if (isalpha(data[i])) {
            data[i] = (data[i] - 'A' - key[i % KEY_LENGTH + KEY_LENGTH] + 26) % 26 + 'A';
        }
    }
}

int main() {
    char key[KEY_LENGTH];
    generate_key(key);

    char data[DATA_LENGTH];
    printf("Enter data to encrypt: ");
    scanf("%s", data);

    encrypt(data, key);
    printf("Encrypted data: %s\n", data);

    decrypt(data, key);
    printf("Decrypted data: %s\n", data);

    return 0;
}