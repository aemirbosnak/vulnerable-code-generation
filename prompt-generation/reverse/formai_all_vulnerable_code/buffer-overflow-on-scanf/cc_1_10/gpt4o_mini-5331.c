//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *plaintext, char *ciphertext, int key) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
        } else {
            ciphertext[i] = plaintext[i]; // Non-alphabetical characters unchanged
        }
    }
    ciphertext[i] = '\0'; // null-terminate the ciphertext
}

void decrypt(char *ciphertext, char *plaintext, int key) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            plaintext[i] = ((ciphertext[i] - 'a' - key + 26) % 26) + 'a';
        } else if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            plaintext[i] = ((ciphertext[i] - 'A' - key + 26) % 26) + 'A';
        } else {
            plaintext[i] = ciphertext[i]; // Non-alphabetical characters unchanged
        }
    }
    plaintext[i] = '\0'; // null-terminate the plaintext
}

void print_menu() {
    printf("Encryption & Decryption Program\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char plaintext[256], ciphertext[256], decrypted_text[256];
    int key;
    int option;

    while (1) {
        print_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the plaintext to encrypt: ");
                getchar(); // to capture the newline character
                fgets(plaintext, sizeof(plaintext), stdin);
                plaintext[strcspn(plaintext, "\n")] = 0; // remove potential newline

                printf("Enter the encryption key (1-25): ");
                scanf("%d", &key);
                key = key % 26; // ensure key is within 0-25

                encrypt(plaintext, ciphertext, key);

                printf("Encrypted message: %s\n", ciphertext);
                break;

            case 2:
                printf("Enter the ciphertext to decrypt: ");
                getchar(); // to capture the newline character
                fgets(ciphertext, sizeof(ciphertext), stdin);
                ciphertext[strcspn(ciphertext, "\n")] = 0; // remove potential newline

                printf("Enter the decryption key (1-25): ");
                scanf("%d", &key);
                key = key % 26; // ensure key is within 0-25

                decrypt(ciphertext, decrypted_text, key);

                printf("Decrypted message: %s\n", decrypted_text);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option, please try again.\n");
        }
    }
    
    return 0;
}