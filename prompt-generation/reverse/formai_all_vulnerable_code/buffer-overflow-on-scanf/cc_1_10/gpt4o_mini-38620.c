//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *text, int shift) {
    int i;
    for (i = 0; text[i] != '\0'; ++i) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' + shift) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' + shift) % 26 + 'A';
        }
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, 26 - (shift % 26));  // Reverse the encryption process
}

int main() {
    char text[100];
    int shift;
    int option;

    while (1) {
        printf("Simple Caesar Cipher\n");
        printf("1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        if (option == 3) break;

        printf("Enter text: ");
        scanf(" %[^\n]s", text);  // Read string with spaces

        printf("Enter shift (1-25): ");
        scanf("%d", &shift);

        if (shift < 1 || shift > 25) {
            printf("Invalid shift. Please use a value between 1 and 25.\n");
            continue;
        }

        switch (option) {
            case 1:
                encrypt(text, shift);
                printf("Encrypted text: %s\n", text);
                break;
            case 2:
                decrypt(text, shift);
                printf("Decrypted text: %s\n", text);
                break;
            default:
                printf("Invalid option. Try again.\n");
                break;
        }

        printf("\n");
    }

    printf("Exiting. Have a nice day!\n");
    return 0;
}