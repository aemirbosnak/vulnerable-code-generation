//Falcon-180B DATASET v1.0 Category: Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to encrypt message
void encrypt(char* message, int key) {
    int i, j;
    for(i=0, j=0; message[i]!='\0'; i++, j++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = (message[i] + key - 65) % 26 + 65;
            }
            else {
                message[i] = (message[i] + key - 97) % 26 + 97;
            }
        }
        else {
            message[i] = message[i];
        }
    }
}

// Function to decrypt message
void decrypt(char* message, int key) {
    int i, j;
    for(i=0, j=0; message[i]!='\0'; i++, j++) {
        if(isalpha(message[i])) {
            if(isupper(message[i])) {
                message[i] = (message[i] - key - 65) % 26 + 65;
            }
            else {
                message[i] = (message[i] - key - 97) % 26 + 97;
            }
        }
        else {
            message[i] = message[i];
        }
    }
}

// Function to generate random key between 1 and 25
int generateKey() {
    return rand() % 26 + 1;
}

int main() {
    srand(time(0));
    char message[100];
    int key;

    // Get message from user
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    // Encrypt message using random key
    key = generateKey();
    encrypt(message, key);

    // Print encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt message using same key
    decrypt(message, key);

    // Print decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}