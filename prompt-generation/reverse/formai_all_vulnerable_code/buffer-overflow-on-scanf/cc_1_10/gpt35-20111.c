//FormAI DATASET v1.0 Category: Modern Encryption ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_LENGTH 100

// Function to generate a random key of given length
void generate_key(int key[], int length) {
    srand(time(NULL));
    for(int i = 0; i < length; i++) {
        key[i] = rand() % 26;
    }
}

// Function to encrypt a given message using the key
void encrypt(char message[], int key[], int length) {
    for(int i = 0; i < length; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = 'a' + (message[i] - 'a' + key[i % MAX_LENGTH]) % 26;
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'A' + (message[i] - 'A' + key[i % MAX_LENGTH]) % 26;
        }
    }
}

// Function to decrypt a given message using the key
void decrypt(char message[], int key[], int length) {
    for(int i = 0; i < length; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = 'a' + (message[i] - 'a' - key[i % MAX_LENGTH] + 26) % 26;
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = 'A' + (message[i] - 'A' - key[i % MAX_LENGTH] + 26) % 26;
        }
    }
}

int main() {
    int key[MAX_LENGTH];
    char message[MAX_LENGTH];
    int choice, length;

    printf("Enter the message: ");
    scanf("%[^\n]", message);
    getchar();

    length = strlen(message);

    generate_key(key, length);

    printf("\n1. Encrypt the message\n");
    printf("2. Decrypt the message\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        // Encryption
        case 1: encrypt(message, key, length);
                printf("\nEncrypted message: %s\n", message);
                break;
        // Decryption
        case 2: decrypt(message, key, length);
                printf("\nDecrypted message: %s\n", message);
                break;
        default: printf("\nInvalid Choice!\n");
    }

    return 0;
}