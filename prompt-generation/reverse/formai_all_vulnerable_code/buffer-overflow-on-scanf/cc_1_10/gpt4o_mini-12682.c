//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 256

void encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] += key;
    }
}

void decrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] -= key;
    }
}

void getInput(char *buffer, int size) {
    printf("Enter the text (max %d characters): ", size - 1);
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; // Remove the newline character
        }
    }
}

int main() {
    char text[MAX_TEXT_LENGTH];
    int key;
    int choice;

    printf("=== Simple C Encryption Program ===\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");

    while (1) {
        printf("Select an option: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        // Clear the newline character left in the input buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                getInput(text, MAX_TEXT_LENGTH);
                printf("Enter encryption key (integer): ");
                scanf("%d", &key);
                getchar(); // Clear the newline character from the buffer

                encrypt(text, key);
                printf("Encrypted text: %s\n", text);
                break;

            case 2:
                getInput(text, MAX_TEXT_LENGTH);
                printf("Enter decryption key (integer): ");
                scanf("%d", &key);
                getchar(); // Clear the newline character from the buffer

                decrypt(text, key);
                printf("Decrypted text: %s\n", text);
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }

        printf("\n");
    }

    return 0;
}