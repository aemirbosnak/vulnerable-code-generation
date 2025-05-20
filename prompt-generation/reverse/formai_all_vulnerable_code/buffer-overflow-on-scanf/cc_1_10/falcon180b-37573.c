//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LEN 100

// Define the public keys
int g = 5;
int p = 11;

// Define the private keys
int x = 7;
int y = 9;

// Define the encryption function
void encrypt(int *msg, int *encrypted_msg, int n) {
    int i;
    for(i=0; i<n; i++) {
        encrypted_msg[i] = (msg[i] * g) % p;
    }
}

// Define the decryption function
void decrypt(int *encrypted_msg, int *decrypted_msg, int n) {
    int i;
    for(i=0; i<n; i++) {
        decrypted_msg[i] = (encrypted_msg[i] * x + y) % p;
    }
}

// Main function
int main() {
    int msg[MAX_MSG_LEN];
    int encrypted_msg[MAX_MSG_LEN];
    int decrypted_msg[MAX_MSG_LEN];
    int n;

    // Get message from user
    printf("Enter message (max %d characters): ", MAX_MSG_LEN-1);
    scanf("%s", msg);
    n = strlen(msg);

    // Encrypt message
    encrypt(msg, encrypted_msg, n);

    // Print encrypted message
    printf("Encrypted message: ");
    for(int i=0; i<n; i++) {
        printf("%d ", encrypted_msg[i]);
    }
    printf("\n");

    // Decrypt message
    decrypt(encrypted_msg, decrypted_msg, n);

    // Print decrypted message
    printf("Decrypted message: %s\n", decrypted_msg);

    return 0;
}