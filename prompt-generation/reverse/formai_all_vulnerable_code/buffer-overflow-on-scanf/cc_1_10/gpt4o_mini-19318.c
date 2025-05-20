//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: recursive
#include <stdio.h>
#include <string.h>

#define SHIFT 4

void encrypt(char *plainText, char *cipherText, int index);
void decrypt(char *cipherText, char *decryptedText, int index);
void displayMenu();
void processOption(int option);

int main() {
    int option;

    do {
        displayMenu();
        printf("Choose an option (1-3): ");
        scanf("%d", &option);
        processOption(option);
    } while(option != 3);

    return 0;
}

void displayMenu() {
    printf("\n--- Encryption/Decryption Program ---\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
}

void processOption(int option) {
    char input[256];
    char output[256];

    switch(option) {
        case 1:
            printf("Enter text to encrypt: ");
            getchar();  // to consume newline from previous input
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;  // Remove trailing newline
            encrypt(input, output, 0);
            printf("Encrypted text: %s\n", output);
            break;
        case 2:
            printf("Enter text to decrypt: ");
            getchar();  // to consume newline from previous input
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0;  // Remove trailing newline
            decrypt(input, output, 0);
            printf("Decrypted text: %s\n", output);
            break;
        case 3:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
    }
}

void encrypt(char *plainText, char *cipherText, int index) {
    if (plainText[index] == '\0') {
        cipherText[index] = '\0';  // Null-terminate the string
        return;
    }
    char ch = plainText[index];
    if (ch >= 'a' && ch <= 'z') {
        cipherText[index] = (ch - 'a' + SHIFT) % 26 + 'a';
    } else if (ch >= 'A' && ch <= 'Z') {
        cipherText[index] = (ch - 'A' + SHIFT) % 26 + 'A';
    } else {
        cipherText[index] = ch;  // Non-alphabetical characters stay the same
    }
    
    encrypt(plainText, cipherText, index + 1);
}

void decrypt(char *cipherText, char *decryptedText, int index) {
    if (cipherText[index] == '\0') {
        decryptedText[index] = '\0';  // Null-terminate the string
        return;
    }
    char ch = cipherText[index];
    if (ch >= 'a' && ch <= 'z') {
        decryptedText[index] = (ch - 'a' - SHIFT + 26) % 26 + 'a';
    } else if (ch >= 'A' && ch <= 'Z') {
        decryptedText[index] = (ch - 'A' - SHIFT + 26) % 26 + 'A';
    } else {
        decryptedText[index] = ch;  // Non-alphabetical characters stay the same
    }
    
    decrypt(cipherText, decryptedText, index + 1);
}