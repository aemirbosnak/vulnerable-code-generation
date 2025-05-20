//Falcon-180B DATASET v1.0 Category: Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 16
#define MAX_MESSAGE_LENGTH 256

// Function to encrypt message using Caesar cipher
void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    int i, j;

    // Check if key is valid
    for(i=0; i<key_length; i++) {
        if(!isalpha(key[i])) {
            printf("Error: Invalid key. Key must contain only alphabets.\n");
            exit(1);
        }
    }

    // Encrypt message
    for(i=0, j=0; i<message_length; i++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                encrypted_message[j++] = (char)(((int)message[i] + (int)key[i%key_length]) % 26 + 65);
            } else {
                encrypted_message[j++] = (char)(((int)message[i] + (int)key[i%key_length]) % 26 + 97);
            }
        } else {
            encrypted_message[j++] = message[i];
        }
    }
    encrypted_message[j] = '\0';
}

// Function to decrypt message using Caesar cipher
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_message_length = strlen(encrypted_message);
    int key_length = strlen(key);
    int i, j;

    // Check if key is valid
    for(i=0; i<key_length; i++) {
        if(!isalpha(key[i])) {
            printf("Error: Invalid key. Key must contain only alphabets.\n");
            exit(1);
        }
    }

    // Decrypt message
    for(i=0, j=0; i<encrypted_message_length; i++) {
        if(isalpha(encrypted_message[i])) {
            if(isupper(encrypted_message[i])) {
                decrypted_message[j++] = (char)(((int)encrypted_message[i] - (int)key[i%key_length] + 26) % 26 + 65);
            } else {
                decrypted_message[j++] = (char)(((int)encrypted_message[i] - (int)key[i%key_length] + 26) % 26 + 97);
            }
        } else {
            decrypted_message[j++] = encrypted_message[i];
        }
    }
    decrypted_message[j] = '\0';
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
    char decrypted_message[MAX_MESSAGE_LENGTH];

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(message, key, encrypted_message);

    printf("Encrypted message: %s\n", encrypted_message);

    printf("Enter decryption key: ");
    scanf("%s", key);

    decrypt(encrypted_message, key, decrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}