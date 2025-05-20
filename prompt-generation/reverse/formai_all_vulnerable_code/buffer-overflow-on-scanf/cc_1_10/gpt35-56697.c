//FormAI DATASET v1.0 Category: Encryption ; Style: statistical
// Statistical C Encryption Program
// By Chatbot

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 1000
#define SHIFT_RANGE 10

void encryption(char* string);
void decryption(char* string);

int main() {
    char message[MAX_LENGTH];
    int option;

    printf("Welcome to the Statistical C Encryption Program!\n");
    printf("Please select an option:\n");
    printf("1) Encrypt a message\n");
    printf("2) Decrypt a message\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Please enter the message to encrypt: ");
            scanf("%s", message);
            encryption(message);
            printf("Encrypted message: %s\n", message);
            break;

        case 2:
            printf("Please enter the message to decrypt: ");
            scanf("%s", message);
            decryption(message);
            printf("Decrypted message: %s\n", message);
            break;

        default:
            printf("Invalid option selected.\n");
            break;
    }

    return 0;
}

void encryption(char* string) {
    int i, shift;
    srand((unsigned int) time(NULL));

    for (i = 0; i < strlen(string); i++) {
        shift = rand() % SHIFT_RANGE + 1;
        string[i] = string[i] + shift;
    }
}

void decryption(char* string) {
    int i, shift;

    for (i = 0; i < strlen(string); i++) {
        shift = rand() % SHIFT_RANGE + 1;
        string[i] = string[i] - shift;
    }
}