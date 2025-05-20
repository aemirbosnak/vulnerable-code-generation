//Falcon-180B DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16 // 128-bit key

void generate_key(char* key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256; // generate a random key
    }
}

void encrypt(char* message, char* key) {
    int i, j;
    char encrypted_message[strlen(message)];
    for (i = 0, j = 0; message[i]!= '\0'; i++, j++) {
        if (j == KEY_SIZE) {
            generate_key(key); // generate a new key after every KEY_SIZE characters
            j = 0;
        }
        encrypted_message[i] = (message[i] ^ key[j]) % 256; // XOR encryption
    }
    encrypted_message[i] = '\0';
    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt(char* encrypted_message, char* key) {
    int i, j;
    char decrypted_message[strlen(encrypted_message)];
    for (i = 0, j = 0; encrypted_message[i]!= '\0'; i++, j++) {
        if (j == KEY_SIZE) {
            generate_key(key); // generate a new key after every KEY_SIZE characters
            j = 0;
        }
        decrypted_message[i] = (encrypted_message[i] ^ key[j]) % 256; // XOR decryption
    }
    decrypted_message[i] = '\0';
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[1000];
    char key[KEY_SIZE];

    printf("Enter the message to be encrypted: ");
    fgets(message, 1000, stdin); // read the message from the user

    generate_key(key); // generate the initial key

    printf("Encrypted message: ");
    encrypt(message, key);

    printf("Enter the encrypted message to be decrypted: ");
    fgets(message, 1000, stdin); // read the encrypted message from the user

    printf("Decrypted message: ");
    decrypt(message, key);

    return 0;
}