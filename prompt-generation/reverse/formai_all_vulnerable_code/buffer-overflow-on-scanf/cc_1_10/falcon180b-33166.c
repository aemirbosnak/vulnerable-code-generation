//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16
#define DATA_LENGTH 64

void generate_key(char *key) {
    int i;
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
}

void encrypt(char *key, char *data) {
    int i, j;
    char encrypted_data[DATA_LENGTH];
    for (i = 0, j = 0; i < strlen(data); i++) {
        if (isalpha(data[i])) {
            encrypted_data[j++] = data[i] ^ key[i % KEY_LENGTH];
        } else {
            encrypted_data[j++] = data[i];
        }
    }
    encrypted_data[j] = '\0';
    strcpy(data, encrypted_data);
}

void decrypt(char *key, char *data) {
    int i, j;
    char decrypted_data[DATA_LENGTH];
    for (i = 0, j = 0; i < strlen(data); i++) {
        if (isalpha(data[i])) {
            decrypted_data[j++] = data[i] ^ key[i % KEY_LENGTH];
        } else {
            decrypted_data[j++] = data[i];
        }
    }
    decrypted_data[j] = '\0';
    strcpy(data, decrypted_data);
}

int main() {
    char key[KEY_LENGTH];
    char data[DATA_LENGTH];
    generate_key(key);
    printf("Enter the data to be encrypted: ");
    scanf("%s", data);
    encrypt(key, data);
    printf("Encrypted data: %s\n", data);
    decrypt(key, data);
    printf("Decrypted data: %s\n", data);
    return 0;
}