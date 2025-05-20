//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_SIZE 1024

void encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] + key - base) % 26 + base;
        }
    }
}

void decrypt(char *text, int key) {
    encrypt(text, 26 - (key % 26));  // Decrypting is just encrypting with 26-key
}

void promptUser(char *text, int *key) {
    printf("Enter the text you want to encrypt/decrypt: ");
    fgets(text, MAX_TEXT_SIZE, stdin);
    text[strcspn(text, "\n")] = 0;  // Remove newline character

    printf("Enter the key (1-25): ");
    scanf("%d", key);
    while (*key < 1 || *key > 25) {
        printf("Invalid key! Please enter a key (1-25): ");
        scanf("%d", key);
    }
}

void printMenu() {
    printf("\n### Simple Cipher Program ###\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    char text[MAX_TEXT_SIZE];
    int key;
    int option;

    do {
        printMenu();
        scanf("%d", &option);
        getchar(); // to consume the newline character left by scanf

        switch (option) {
            case 1:
                promptUser(text, &key);
                encrypt(text, key);
                printf("Encrypted Text: %s\n", text);
                break;
            case 2:
                promptUser(text, &key);
                decrypt(text, key);
                printf("Decrypted Text: %s\n", text);
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please choose a valid option.\n");
                break;
        }
    } while (option != 3);

    return 0;
}