//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: immersive
#include <stdio.h>
#include <string.h>

#define MAX 1024

void encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' + key) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' + key) % 26 + 'A';
        }
    }
}

void decrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' - key + 26) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' - key + 26) % 26 + 'A';
        }
    }
}

void displayMenu() {
    printf("\n*** Caesar Cipher Program ***\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}

int main() {
    char text[MAX];
    int choice, key;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        printf("Enter the key (1-25): ");
        scanf("%d", &key);

        if (key < 1 || key > 25) {
            printf("Invalid key. Please enter a key between 1 and 25.\n");
            continue;
        }

        printf("Enter the message: ");
        getchar(); // To consume newline character after key entry
        fgets(text, MAX, stdin);
        text[strcspn(text, "\n")] = 0; // Remove trailing newline

        switch (choice) {
            case 1:
                encrypt(text, key);
                printf("Encrypted message: %s\n", text);
                break;
            case 2:
                decrypt(text, key);
                printf("Decrypted message: %s\n", text);
                break;
            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
                break;
        }
    }

    return 0;
}