//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "ThisIsMySecretKey"

void encrypt(char *message, char *encrypted_message) {
    int i, j, key_index = 0;
    char *key = malloc(strlen(KEY) + 1);
    strcpy(key, KEY);
    
    for (i = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            encrypted_message[i] = (char) (((int) message[i] + (int) key[key_index]) % 26 + 65);
            key_index = (key_index + 1) % strlen(KEY);
        } else {
            encrypted_message[i] = message[i];
        }
    }
    
    encrypted_message[i] = '\0';
}

void decrypt(char *encrypted_message, char *decrypted_message) {
    int i, j, key_index = 0;
    char *key = malloc(strlen(KEY) + 1);
    strcpy(key, KEY);
    
    for (i = 0; encrypted_message[i]!= '\0'; i++) {
        if (isalpha(encrypted_message[i])) {
            decrypted_message[i] = (char) (((int) encrypted_message[i] - (int) key[key_index]) % 26 + 65);
            key_index = (key_index + 1) % strlen(KEY);
        } else {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    
    decrypted_message[i] = '\0';
}

int main() {
    char message[1000], encrypted_message[1000], decrypted_message[1000];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    
    encrypt(message, encrypted_message);
    printf("Encrypted message: %s\n", encrypted_message);
    
    decrypt(encrypted_message, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);
    
    return 0;
}