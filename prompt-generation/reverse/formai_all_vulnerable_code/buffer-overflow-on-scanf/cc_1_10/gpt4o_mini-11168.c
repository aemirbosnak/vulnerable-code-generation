//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: surprised
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int shift) {
    char ch;
    for (int i = 0; message[i] != '\0'; ++i) {
        ch = message[i];
        
        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + shift);
            if (ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
        }

        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch + shift);
            if (ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
        }
        message[i] = ch;
    }
}

void decrypt(char *message, int shift) {
    char ch;
    for (int i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - shift);
            if (ch < 'A') {
                ch = ch + 'Z' - 'A' + 1;
            }
        }

        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - shift);
            if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
            }
        }
        message[i] = ch;
    }
}

int main() {
    char message[100];
    int shift, option;

    printf("Welcome to the Surprising Caesar Cipher Encryption Program!\n");
    printf("Enter your secret message: ");
    fgets(message, sizeof(message), stdin);
    
    // To remove newline character from fgets
    message[strcspn(message, "\n")] = 0;

    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);

    // Ensure shift is within bounds
    if (shift < 1 || shift > 25) {
        printf("Wow! That shift value isn't valid! Let's try again.\n");
        return 1;
    }

    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            encrypt(message, shift);
            printf("Encrypted message: %s\n", message);
            break;
        case 2:
            decrypt(message, shift);
            printf("Decrypted message: %s\n", message);
            break;
        default:
            printf("Oops! That's not a valid option. Give it another shot!\n");
            return 1;
    }

    printf("Thank you for using the Surprising Caesar Cipher Program!\n");
    return 0;
}