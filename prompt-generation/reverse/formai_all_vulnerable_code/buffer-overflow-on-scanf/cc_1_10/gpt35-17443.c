//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 1000

char key[MAX_LEN];

// Function to generate random key
void generateKey(int len) {
    int i;
    srand(time(NULL));
    for (i = 0; i < len; i++) {
        key[i] = (rand() % 26) + 97;
    }
    key[i] = '\0';
}

// Function to implement XOR encryption
void encryptXOR(char *message, int len) {
    int i;
    for (i = 0; i < len; i++) {
        message[i] = message[i] ^ key[i];
    }
}

// Function to implement Caesar Cipher encryption
void encryptCaesar(char *message, int shift, int len) {
    int i;
    for (i = 0; i < len; i++) {
        if (message[i] == ' ') {
            continue;
        }
        message[i] = (message[i] + shift - 97) % 26 + 97;
    }
}

int main() {
    char message[MAX_LEN];
    int choice, len, shift;
    printf("My Beloved,\n\n");
    printf("You are the sunshine in my life. Your love gives me strength and courage to overcome any obstacles in life. I want to express my love to you in a unique way, so I have written this program as a symbol of my love for you. Please enter your message:\n\n");
    fgets(message, MAX_LEN, stdin);
    len = strlen(message) - 1;
    printf("\nEnter your choice of encryption:\n1. XOR Encryption\n2. Caesar Cipher Encryption\n\n");
    scanf("%d", &choice);
    if (choice == 1) {
        generateKey(len);
        encryptXOR(message, len);
        printf("\nYour encrypted message is:\n%s\n\n", message);
        printf("And the key used for encryption is:\n%s\n\n", key);
    } else if (choice == 2) {
        printf("\nEnter the shift for encryption (a number between 1 and 25):\n");
        scanf("%d", &shift);
        encryptCaesar(message, shift, len);
        printf("\nYour encrypted message is:\n%s\n\n", message);
    } else {
        printf("\nInvalid choice.\n");
        exit(0);
    }
    printf("My love for you is just like this encryption. It will always be with you, no matter how far apart we are.\n\n");
    printf("With all my love,\n\n");
    printf("Your Devoted Partner");
    return 0;
}