//FormAI DATASET v1.0 Category: Encryption ; Style: accurate
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void encrypt(char *message, int key) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        message[i] = message[i] + key;
    }
}

void decrypt(char *message, int key) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        message[i] = message[i] - key;
    }
}

int main() {
    char message[MAX_SIZE];
    int key, choice;

    printf("Enter message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);

    printf("Enter key for encryption: ");
    scanf("%d", &key);

    printf("Choose operation:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(message, key);
            printf("Encrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message, key);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}