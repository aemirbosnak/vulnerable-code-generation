//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        // Encrypt uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        }
    }
}

void decrypt(char *text, int shift) {
    // Decryption is basically the reverse shift
    encrypt(text, 26 - shift); // Adjusting the shift to decrypt
}

int main() {
    char text[MAX_LEN];
    int shift;
    int choice;

    printf("===========================================\n");
    printf("         Caesar Cipher Encryption          \n");
    printf("===========================================\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Encrypt text\n");
        printf("2. Decrypt text\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the text (max %d characters): ", MAX_LEN - 1);
                getchar(); // to consume newline character after choice input
                fgets(text, MAX_LEN, stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline character

                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);

                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please use a value between 1 and 25.\n");
                } else {
                    encrypt(text, shift);
                    printf("Encrypted text: %s\n", text);
                }
                break;

            case 2:
                printf("Enter the text (max %d characters): ", MAX_LEN - 1);
                getchar(); // to consume newline character after choice input
                fgets(text, MAX_LEN, stdin);
                text[strcspn(text, "\n")] = 0; // Remove newline character

                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);

                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please use a value between 1 and 25.\n");
                } else {
                    decrypt(text, shift);
                    printf("Decrypted text: %s\n", text);
                }
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}