//FormAI DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

char generateRandomChar() {   // Function to generate a random character
    char randomChar = rand() % 26 + 'a';
    return randomChar;
}

void encrypt(char* message, char* key) {     // Function to encrypt the message
    int i,j;
    for (i=0,j=0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
            message[i] = (message[i] - 'a' + key[j] - 'a') % 26 + 'a';   // Encryption formula
            j = (j+1) % strlen(key);    // Looping through the key if the message length is greater than key length
        }
    }
}

void decrypt(char* message, char* key) {     // Function to decrypt the message
    int i,j;
    for (i=0,j=0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = tolower(message[i]);
            message[i] = (message[i] - key[j] + 26) % 26 + 'a';      // Decryption formula
            j = (j+1) % strlen(key);    // Looping through the key if the message length is greater than key length
        }
    }
}

int main() {
    char message[MAX_LEN], key[MAX_LEN];
    int option;
    printf("Welcome to Modern Encryption!\n");
    printf("Please enter your message: ");
    fgets(message, MAX_LEN, stdin);
    message[strcspn(message, "\n")] = '\0';
    printf("Please enter your key (should be of minimum length 3): ");
    fgets(key, MAX_LEN, stdin);
    key[strcspn(key, "\n")] = '\0';
    while (strlen(key) < 3) {   // Ensuring the key is of minimum length 3
        printf("Key length is too short. Please enter a new key: ");
        fgets(key, MAX_LEN, stdin);
        key[strcspn(key, "\n")] = '\0';
    }
    do {
        printf("\nChoose an option:\n");
        printf("1. Encrypt the message\n");
        printf("2. Decrypt the message\n");
        printf("3. Generate a new random key\n");
        printf("4. Exit the program\n");
        printf("Option: ");
        scanf("%d", &option);
        getchar();   // To clear the input buffer
        switch(option) {
            case 1:
                encrypt(message, key);
                printf("\nEncrypted message: %s\n", message);
                break;
            case 2:
                decrypt(message, key);
                printf("\nDecrypted message: %s\n", message);
                break;
            case 3:
                printf("\nGenerating a new random key...\n");
                for (int i=0; i < strlen(key); i++) {
                    key[i] = generateRandomChar();   // Generating a new random key
                }
                printf("New key: %s\n", key);
                break;
            case 4:
                printf("\nThank you for using Modern Encryption!\n");
                exit(0);
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    } while (option != 4);

    return 0;
}