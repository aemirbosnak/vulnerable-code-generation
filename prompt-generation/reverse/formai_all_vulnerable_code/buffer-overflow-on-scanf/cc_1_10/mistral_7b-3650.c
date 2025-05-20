//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to generate random keys
int* random_keys(int key_length) {
    int* key = (int*)calloc(key_length, sizeof(int));

    if (key == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26;
    }

    return key;
}

// Function to encrypt a message using Caesar Cipher
char* encrypt_message(char* message, int* key, int key_length) {
    int len = strlen(message);

    char* encrypted_message = (char*)calloc(len + 1, sizeof(char));

    for (int i = 0; i < len; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted_message[i] = ((int)message[i] + key[i % key_length] + 26) % 26 + 'A';
            } else {
                encrypted_message[i] = ((int)message[i] + key[i % key_length] + 26) % 26 + 'a';
            }
        } else {
            encrypted_message[i] = message[i];
        }
    }

    return encrypted_message;
}

int main() {
    char input_message[MAX_LENGTH];
    int key_length;

    printf("Enter a message to encrypt: ");
    fgets(input_message, sizeof(input_message), stdin);
    input_message[strcspn(input_message, "\n")] = '\0';

    printf("Enter the length of the encryption key: ");
    scanf("%d", &key_length);

    int* key = random_keys(key_length);

    char* encrypted_message = encrypt_message(input_message, key, key_length);

    printf("Encrypted message: %s\n", encrypted_message);
    printf("Key: [");
    for (int i = 0; i < key_length; i++) {
        printf("%d, ", key[i]);
    }
    printf("]\n");

    free(encrypted_message);
    free(key);

    return 0;
}