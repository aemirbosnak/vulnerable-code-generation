//FormAI DATASET v1.0 Category: Funny ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 50

int encrypt(char* input, char* key, char* output);
int decrypt(char* input, char* key, char* output);

int main() {
    char input[MAX_INPUT_LENGTH];
    char key[MAX_INPUT_LENGTH];
    char output[MAX_INPUT_LENGTH];
    int choice = 0;

    printf("Welcome to the encryption/decryption program!\n");
    printf("Enter 1 to encrypt a message, 2 to decrypt a message: ");
    scanf("%d", &choice);
    getchar(); // clear input buffer

    if(choice == 1) {
        printf("Enter the message to encrypt (max %d characters): ", MAX_INPUT_LENGTH);
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // remove newline character

        printf("Enter the encryption key (max %d characters): ", MAX_INPUT_LENGTH);
        fgets(key, MAX_INPUT_LENGTH, stdin);
        key[strcspn(key, "\n")] = 0; // remove newline character

        if(encrypt(input, key, output)) {
            printf("Encrypted message: %s\n", output);
        } else {
            printf("Encryption failed!\n");
        }
    } else if(choice == 2) {
        printf("Enter the message to decrypt (max %d characters): ", MAX_INPUT_LENGTH);
        fgets(input, MAX_INPUT_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // remove newline character

        printf("Enter the decryption key (max %d characters): ", MAX_INPUT_LENGTH);
        fgets(key, MAX_INPUT_LENGTH, stdin);
        key[strcspn(key, "\n")] = 0; // remove newline character

        if(decrypt(input, key, output)) {
            printf("Decrypted message: %s\n", output);
        } else {
            printf("Decryption failed!\n");
        }
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}

int encrypt(char* input, char* key, char* output) {
    int input_len = strlen(input);
    int key_len = strlen(key);

    if(input_len > MAX_INPUT_LENGTH || key_len > MAX_INPUT_LENGTH) {
        return 0;
    }

    for(int i = 0; i < input_len; i++) {
        output[i] = input[i] ^ key[i % key_len];
    }

    return 1;
}

int decrypt(char* input, char* key, char* output) {
    int input_len = strlen(input);
    int key_len = strlen(key);

    if(input_len > MAX_INPUT_LENGTH || key_len > MAX_INPUT_LENGTH) {
        return 0;
    }

    for(int i = 0; i < input_len; i++) {
        output[i] = input[i] ^ key[i % key_len];
    }

    return 1;
}