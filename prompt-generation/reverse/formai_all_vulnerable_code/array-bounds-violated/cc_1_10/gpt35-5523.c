//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size of message and key
#define MAX_SIZE 1000

// Function to generate public-private key pair
void generate_keys(int p, int q, int *e, int *d, int *n)
{
    int phi = (p - 1) * (q - 1);
    int gcd;
    do {
        *e = rand() % phi;
        for (*d = 2; *d < phi; (*d)++) {
            gcd = 1;
            if (((*e * (*d)) % phi) == 1) {
                gcd = 0;
                break;
            }
        }
    } while (gcd);
    *n = p * q;
}

// Function to encrypt message
void encrypt(char *msg, int length, int e, int n, int *cipher)
{
    int i;
    for (i = 0; i < length; i++) {
        cipher[i] = msg[i];
        int j;
        for (j = 0; j < e - 1; j++) {
            cipher[i] *= msg[i];
            cipher[i] %= n;
        }
    }
}

// Function to decrypt cipher
void decrypt(int *cipher, int length, int d, int n, char *msg)
{
    int i;
    for (i = 0; i < length; i++) {
        msg[i] = cipher[i];
        int j;
        for (j = 0; j < d - 1; j++) {
            msg[i] *= cipher[i];
            msg[i] %= n;
        }
    }
}

int main()
{
    // Define variables
    int prime1, prime2, e, d, n;
    int cipher[MAX_SIZE];
    char msg[MAX_SIZE], msg_decrypted[MAX_SIZE];

    // Print greeting message
    printf("Hello there! Let's create our own Public-Key Algorithm!\n");

    // Set the prime numbers
    prime1 = 17;
    prime2 = 19;

    // Generate keys
    generate_keys(prime1, prime2, &e, &d, &n);

    // Print the keys
    printf("Public key: (%d,%d)\n", e, n);
    printf("Private key: (%d,%d)\n", d, n);

    // Ask for message
    printf("Please enter your message: ");
    fgets(msg, MAX_SIZE, stdin);

    // Remove trailing newline from input
    size_t length = strlen(msg);
    if (msg[length - 1] == '\n') {
        msg[--length] = '\0';
    }

    // Encrypt the message
    encrypt(msg, length, e, n, cipher);

    // Print the encrypted cipher
    printf("Encrypted message: ");
    int i;
    for (i = 0; i < length; i++) {
        printf("%d ", cipher[i]);
    }
    printf("\n");

    // Decrypt the cipher
    decrypt(cipher, length, d, n, msg_decrypted);

    // Print the decrypted message
    printf("Decrypted message: %s\n", msg_decrypted);

    // Say goodbye
    printf("Thanks for using our Public-Key Algorithm!\n");

    return 0;
}