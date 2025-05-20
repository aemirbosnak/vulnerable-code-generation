//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 1000
#define MAX_MSG_SIZE 1000000

// Function to generate a key
void generate_key(char* key, int key_size) {
    for(int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[key_size] = '\0';
}

// Function to encrypt a message using the key
void encrypt(char* msg, char* key, char* enc) {
    int msg_size = strlen(msg);
    int key_size = strlen(key);
    int enc_size = msg_size;

    for(int i = 0; i < msg_size; i++) {
        if(isalpha(msg[i])) {
            enc[i] = (toupper(msg[i]) + toupper(key[i % key_size]) - 2 * 'A') % 26 + 'A';
        } else {
            enc[i] = msg[i];
        }
    }
    enc[enc_size] = '\0';
}

// Function to decrypt a message using the key
void decrypt(char* enc, char* key, char* dec) {
    int enc_size = strlen(enc);
    int key_size = strlen(key);
    int dec_size = enc_size;

    for(int i = 0; i < enc_size; i++) {
        if(isalpha(enc[i])) {
            dec[i] = (toupper(enc[i]) - toupper(key[i % key_size]) + 26) % 26 + 'A';
        } else {
            dec[i] = enc[i];
        }
    }
    dec[dec_size] = '\0';
}

int main() {
    char key[MAX_KEY_SIZE];
    char msg[MAX_MSG_SIZE];
    char enc[MAX_MSG_SIZE];
    char dec[MAX_MSG_SIZE];
    int msg_size, enc_size, dec_size;

    // Generate a key
    generate_key(key, rand() % MAX_KEY_SIZE + 1);
    printf("Key: %s\n", key);

    // Read a message from the user
    printf("Enter a message: ");
    scanf("%s", msg);
    msg_size = strlen(msg);

    // Encrypt the message using the key
    encrypt(msg, key, enc);
    printf("Encrypted message: %s\n", enc);

    // Decrypt the encrypted message using the key
    decrypt(enc, key, dec);
    printf("Decrypted message: %s\n", dec);

    return 0;
}