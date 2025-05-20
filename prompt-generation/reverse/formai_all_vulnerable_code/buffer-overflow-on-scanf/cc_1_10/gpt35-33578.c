//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 100

// Function declarations
void encrypt(char* message, char* key);
void decrypt(char* message, char* key);

int main() {
    char message[MAX_LEN], key[MAX_LEN];
    int choice;

    while (1) {
        printf("Enter 1 to encrypt a message, 2 to decrypt a message, or 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter message to encrypt: ");
                getchar();
                fgets(message, MAX_LEN, stdin);
                printf("Enter key: ");
                fgets(key, MAX_LEN, stdin);
                encrypt(message, key);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter message to decrypt: ");
                getchar();
                fgets(message, MAX_LEN, stdin);
                printf("Enter key: ");
                fgets(key, MAX_LEN, stdin);
                decrypt(message, key);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

// Function to encrypt the message using the key
void encrypt(char* message, char* key) {
    srand(time(0));
    int keyLen = strlen(key);
    int messageLen = strlen(message);
    int i, j;

    for (i = 0, j = 0; i < messageLen; ++i, ++j) {
        if (j == keyLen) {
            j = 0;
        }

        message[i] = ((message[i] + key[j] - 2 * 'a') % 26) + 'a';
    }
}

// Function to decrypt the message using the key
void decrypt(char* message, char* key) {
    srand(time(0));
    int keyLen = strlen(key);
    int messageLen = strlen(message);
    int i, j;

    for (i = 0, j = 0; i < messageLen; ++i, ++j) {
        if (j == keyLen) {
            j = 0;
        }

        message[i] = ((message[i] - key[j] + 26) % 26) + 'a';
    }
}