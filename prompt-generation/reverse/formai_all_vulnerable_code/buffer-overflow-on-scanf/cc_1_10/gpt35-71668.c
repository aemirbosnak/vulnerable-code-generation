//FormAI DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPTION_KEY 42
#define MAX_LENGTH 100

void encrypt(char* message);
void decrypt(char* message);

int main() {
    char message[MAX_LENGTH];
    int choice;

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_LENGTH, stdin);

    printf("\nEnter 1 to encrypt the message and 2 to decrypt the message: ");
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        printf("\nEncrypted message: ");
        encrypt(message);
        printf("%s", message);
    } else if (choice == 2) {
        printf("\nDecrypted message: ");
        decrypt(message);
        printf("%s", message);
    } else {
        printf("\nInvalid choice! Exiting.");
        exit(0);
    }

    return 0;
}

void encrypt(char* message) {
    int length = strlen(message);
    for (int i = 0; i < length; ++i) {
        message[i] = (message[i] + ENCRYPTION_KEY) % 256;
    }
}

void decrypt(char* message) {
    int length = strlen(message);
    for (int i = 0; i < length; ++i) {
        message[i] = (message[i] - ENCRYPTION_KEY) % 256;
        if (message[i] < 0) message[i] += 256;
    }
}