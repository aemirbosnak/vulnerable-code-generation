//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declare function to generate a random prime number
int random_prime();

// Declare function to check if a number is prime
int is_prime(int);

// Declare function to generate public and private key
void generate_keys(int, int, int*, int*);

// Declare function to encrypt a message
void encrypt(int, int, int*, char*, int*);

// Declare function to decrypt a message
void decrypt(int, int, int*, int*, char*);

int main() {
    
    // Set the seed for random number generation
    srand(time(NULL));
    
    // Generate two prime numbers
    int p = random_prime();
    int q = random_prime();
    
    // Calculate the value of n
    int n = p * q;
    
    // Calculate the value of phi
    int phi = (p - 1) * (q - 1);
    
    // Declare variables to hold public and private keys
    int publicKey, privateKey;
    
    // Generate public and private keys
    generate_keys(n, phi, &publicKey, &privateKey);
    
    // Declare variables for the message and encrypted message
    char message[1000];
    int encryptedMessage[1000];
    
    // Declare variable for the length of the message
    int messageLength;
    
    // Ask the user for a message to encrypt
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    messageLength = strlen(message);
    message[messageLength - 1] = '\0';
    
    // Encrypt the message
    encrypt(publicKey, n, encryptedMessage, message, &messageLength);
    
    // Print the encrypted message
    printf("Encrypted message: ");
    for (int i = 0; i < messageLength; i++) {
        printf("%d ", encryptedMessage[i]);
    }
    printf("\n");
    
    // Declare variable for the decrypted message
    char decryptedMessage[1000];
    
    // Decrypt the message
    decrypt(privateKey, n, encryptedMessage, &messageLength, decryptedMessage);
    
    // Print the decrypted message
    printf("Decrypted message: %s\n", decryptedMessage);
    
    return 0;
}

int random_prime() {
    int num = rand() % 1000 + 1;
    while (!is_prime(num)) {
        num++;
    }
    return num;
}

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void generate_keys(int n, int phi, int *publicKey, int *privateKey) {
    int e;
    do {
        e = rand() % phi + 1;
    } while (e % phi == 0 || e == n);
    *publicKey = e;
    int d = 1;
    while (1) {
        if ((d * e) % phi == 1) {
            break;
        }
        d++;
    }
    *privateKey = d;
}

void encrypt(int publicKey, int n, int *encryptedMessage, char *message, int *messageLength) {
    for (int i = 0; i < *messageLength; i++) {
        int m = (int) message[i];
        int c = 1;
        for (int j = 0; j < publicKey; j++) {
            c = (c * m) % n;
        }
        encryptedMessage[i] = c;
    }
}

void decrypt(int privateKey, int n, int *encryptedMessage, int *messageLength, char *decryptedMessage) {
    for (int i = 0; i < *messageLength; i++) {
        int c = encryptedMessage[i];
        int m = 1;
        for (int j = 0; j < privateKey; j++) {
            m = (m * c) % n;
        }
        decryptedMessage[i] = (char) m;
    }
}