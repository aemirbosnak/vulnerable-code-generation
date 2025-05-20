//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Function to generate a random number
int rand_num() {
    return rand() % 10;
}

// Function to encrypt the message
void encrypt(char message[], int key) {
    int i, j;
    for(i = 0; message[i]!= '\0'; i++) {
        if(isalpha(message[i])) {
            message[i] = message[i] + key;
            if(message[i] > 'z') {
                message[i] = message[i] - 26;
            } else if(message[i] < 'a') {
                message[i] = message[i] + 26;
            }
        }
    }
}

// Function to decrypt the message
void decrypt(char message[], int key) {
    int i, j;
    for(i = 0; message[i]!= '\0'; i++) {
        if(isalpha(message[i])) {
            message[i] = message[i] - key;
            if(message[i] < 'a') {
                message[i] = message[i] + 26;
            } else if(message[i] > 'z') {
                message[i] = message[i] - 26;
            }
        }
    }
}

// Function to generate a random key
void generate_key(int key[]) {
    int i;
    for(i = 0; i < 5; i++) {
        key[i] = rand_num();
    }
}

int main() {
    char message[100];
    int key[5];

    // Get message from user
    printf("Enter message: ");
    scanf("%s", message);

    // Generate random key
    generate_key(key);

    // Encrypt message
    printf("Encrypted message: ");
    encrypt(message, key[0]);
    printf("%s\n", message);

    // Decrypt message
    printf("Decrypted message: ");
    decrypt(message, key[0]);
    printf("%s\n", message);

    return 0;
}