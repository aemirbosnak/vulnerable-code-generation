//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 16

void generate_key(char *key) {
    int i;
    for(i=0; i<SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[SIZE] = '\0';
}

void encrypt(char *message, char *key) {
    int i, j;
    char encrypted_message[100];
    for(i=0, j=0; message[i]!= '\0'; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                encrypted_message[j++] = (char)(((int)message[i] - 65 + (int)key[i % SIZE]) % 26 + 65);
            } else {
                encrypted_message[j++] = (char)(((int)message[i] - 97 + (int)key[i % SIZE]) % 26 + 97);
            }
        } else {
            encrypted_message[j++] = message[i];
        }
    }
    encrypted_message[j] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char *encrypted_message, char *key) {
    int i, j;
    char decrypted_message[100];
    for(i=0, j=0; encrypted_message[i]!= '\0'; i++) {
        if(isalpha(encrypted_message[i])) {
            if(isupper(encrypted_message[i])) {
                decrypted_message[j++] = (char)(((int)encrypted_message[i] - 65 - (int)key[i % SIZE]) % 26 + 65);
            } else {
                decrypted_message[j++] = (char)(((int)encrypted_message[i] - 97 - (int)key[i % SIZE]) % 26 + 97);
            }
        } else {
            decrypted_message[j++] = encrypted_message[i];
        }
    }
    decrypted_message[j] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[100], key[SIZE+1];
    generate_key(key);
    printf("Key: %s\n", key);
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    encrypt(message, key);
    printf("Enter encrypted message to decrypt: ");
    scanf("%s", message);
    decrypt(message, key);
    return 0;
}