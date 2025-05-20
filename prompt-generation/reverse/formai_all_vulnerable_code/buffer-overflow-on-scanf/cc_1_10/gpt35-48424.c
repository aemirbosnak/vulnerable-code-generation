//FormAI DATASET v1.0 Category: Modern Encryption ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LEN 1000
#define MAX_PASSWORD_LEN 20

// Function declarations
void encrypt(char* plaintext, char* password);
void decrypt(char* ciphertext, char* password);

int main() {
    char plaintext[MAX_STRING_LEN], password[MAX_PASSWORD_LEN];
    int choice;

    printf("Welcome to the Paranoid Encryption Program!\n\n");

    while(1) {
        printf("Enter 1 to encrypt a string\nEnter 2 to decrypt a string\nEnter 3 to exit\nChoice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter a string to encrypt (max length %d): ", MAX_STRING_LEN);
            scanf("%s", plaintext);

            printf("Enter a password (max length %d): ", MAX_PASSWORD_LEN);
            scanf("%s", password);

            encrypt(plaintext, password);

            printf("Encrypted Text: %s\n\n", plaintext);
        }

        else if(choice == 2) {
            printf("Enter a string to decrypt (max length %d): ", MAX_STRING_LEN);
            scanf("%s", plaintext);

            printf("Enter the password used to encrypt: ");
            scanf("%s", password);

            decrypt(plaintext, password);

            printf("Decrypted Text: %s\n\n", plaintext);
        }

        else if(choice == 3) {
            exit(0);
        }

        else {
            printf("Invalid choice. Please try again.\n\n");
        }
    }
}

void encrypt(char* plaintext, char* password) {
    int p_len = strlen(plaintext);
    int pass_len = strlen(password);

    for(int i=0;i<p_len;i++) {
        plaintext[i] = (plaintext[i] + password[i%pass_len])%127;
    }
}

void decrypt(char* ciphertext, char* password) {
    int c_len = strlen(ciphertext);
    int pass_len = strlen(password);

    for(int i=0;i<c_len;i++) {
        ciphertext[i] = (ciphertext[i] - password[i%pass_len] + 127)%127;
    }
}