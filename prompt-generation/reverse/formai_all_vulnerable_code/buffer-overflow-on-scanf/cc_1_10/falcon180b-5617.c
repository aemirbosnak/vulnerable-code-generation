//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1024

// Function to generate random prime number
int is_prime(int num) {
    int i;
    for(i=2; i<=num/2; i++) {
        if(num%i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to generate random prime numbers for public and private keys
void generate_keys(int *public_key, int *private_key) {
    int i;
    srand(time(NULL));

    // Generate random prime number for public key
    do {
        *public_key = rand()%MAX_SIZE + 1;
    } while(!is_prime(*public_key));

    // Generate random prime number for private key
    do {
        *private_key = rand()%MAX_SIZE + 1;
    } while(!is_prime(*private_key));
}

// Function to encrypt message using public key
void encrypt(int public_key, char *message, char *encrypted_message) {
    int i, j;
    for(i=0, j=0; message[i]!='\0'; i++) {
        encrypted_message[j] = message[i] ^ public_key;
        j++;
        if(j>=strlen(message)) {
            break;
        }
    }
    encrypted_message[j] = '\0';
}

// Function to decrypt message using private key
void decrypt(int private_key, char *encrypted_message, char *decrypted_message) {
    int i, j;
    for(i=0, j=0; encrypted_message[i]!='\0'; i++) {
        decrypted_message[j] = encrypted_message[i] ^ private_key;
        j++;
        if(j>=strlen(encrypted_message)) {
            break;
        }
    }
    decrypted_message[j] = '\0';
}

int main() {
    int public_key, private_key;
    char message[MAX_SIZE], encrypted_message[MAX_SIZE], decrypted_message[MAX_SIZE];

    // Generate public and private keys
    generate_keys(&public_key, &private_key);

    // Get message from user
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    // Encrypt message using public key
    encrypt(public_key, message, encrypted_message);

    // Decrypt message using private key
    decrypt(private_key, encrypted_message, decrypted_message);

    // Print original and decrypted messages
    printf("Original message: %s\n", message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}