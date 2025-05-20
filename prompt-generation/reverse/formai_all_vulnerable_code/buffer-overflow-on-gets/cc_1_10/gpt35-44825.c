//FormAI DATASET v1.0 Category: Encryption ; Style: Donald Knuth
/*
 * This program demonstrates a unique encryption algorithm that combines the brilliance of Donald Knuth
 * with the creativity of its developer. The program uses a series of bitwise operations to scramble the
 * data and protect against unauthorized access.
 */

#include <stdio.h>
#include <stdlib.h>

#define BASE_KEY 0x5A   // Base key used for encryption

// Function prototypes
void encrypt(char *data, int length);
void decrypt(char *data, int length);

int main(void) {
    char message[100];  // Plaintext message to be encrypted
    int choice;         // User choice

    printf("Enter plaintext message: ");
    gets(message);

    printf("\nEnter your choice:\n");
    printf("1: Encrypt the message\n");
    printf("2: Decrypt the message\n");
    printf("3: Exit\n");

    scanf("%d", &choice);
    getchar();

    switch (choice) {
        case 1:
            encrypt(message, strlen(message));
            printf("\nEncrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message, strlen(message));
            printf("\nDecrypted message: %s\n", message);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

void encrypt(char *data, int length) {
    int i, j, k;
    char key = BASE_KEY;

    for (i = 0; i < length; i++) {
        for (j = 0; j < 8; j++) {
            // Bitwise XOR operation with key
            data[i] ^= key;
            
            // Rotate key left by one bit
            key = (((key << 1) & 0xFE) | ((key >> 7) & 0x01));
            
            // Swap bits at positions i and j
            k = ((data[i] >> i) ^ (data[i] >> j)) & 1;
            data[i] ^= ((k << i) | (k << j));
        }
    }
}

void decrypt(char *data, int length) {
    int i, j, k;
    char key = BASE_KEY;

    for (i = 0; i < length; i++) {
        for (j = 7; j >= 0; j--) {
            // Swap bits at positions i and j
            k = ((data[i] >> i) ^ (data[i] >> j)) & 1;
            data[i] ^= ((k << i) | (k << j));

            // Rotate key right by one bit
            key = (((key >> 1) & 0x7F) | ((key << 7) & 0x80));

            // Bitwise XOR operation with key
            data[i] ^= key;
        }
    }
}