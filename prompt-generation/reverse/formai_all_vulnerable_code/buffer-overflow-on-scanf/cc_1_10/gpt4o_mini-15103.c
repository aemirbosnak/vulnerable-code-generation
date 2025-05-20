//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256
#define SHIFT_AMOUNT 3

void neonGlow(const char* text) {
    printf("\033[1;36m%s\033[0m", text); // Cyan glow effect
}

void encrypt(char* input, int shift) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = (input[i] - 'A' + shift) % 26 + 'A';
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = (input[i] - 'a' + shift) % 26 + 'a';
        }
    }
}

void decrypt(char* input, int shift) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = (input[i] - 'A' - shift + 26) % 26 + 'A';
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = (input[i] - 'a' - shift + 26) % 26 + 'a';
        }
    }
}

void displayMenu() {
    neonGlow("==== Cyberpunk Data Encryptor ====\n");
    printf("1. Encrypt Data\n");
    printf("2. Decrypt Data\n");
    printf("3. Exit\n");
    printf("==================================\n");
}

int main() {
    char buffer[BUFFER_SIZE];
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clear the newline character left by scanf
        while ((getchar()) != '\n');

        switch (choice) {
            case 1:
                neonGlow("Enter data to encrypt: ");
                fgets(buffer, BUFFER_SIZE, stdin);
                buffer[strcspn(buffer, "\n")] = 0; // Remove newline
                neonGlow("Encrypting...\n");
                encrypt(buffer, SHIFT_AMOUNT);
                neonGlow("Encrypted Data: ");
                printf("%s\n", buffer);
                break;

            case 2:
                neonGlow("Enter data to decrypt: ");
                fgets(buffer, BUFFER_SIZE, stdin);
                buffer[strcspn(buffer, "\n")] = 0; // Remove newline
                neonGlow("Decrypting...\n");
                decrypt(buffer, SHIFT_AMOUNT);
                neonGlow("Decrypted Data: ");
                printf("%s\n", buffer);
                break;

            case 3:
                neonGlow("Shutting down...\n");
                exit(0);

            default:
                neonGlow("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}