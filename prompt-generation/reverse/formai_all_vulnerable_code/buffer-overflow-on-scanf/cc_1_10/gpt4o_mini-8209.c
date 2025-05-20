//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 5 // Encryption key

// Function to encrypt the text
void encrypt(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] += KEY;
    }
}

// Function to decrypt the text
void decrypt(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] -= KEY;
    }
}

// Function to display menu
void display_menu() {
    printf("************************\n");
    printf("*    C Encryption App   *\n");
    printf("************************\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("************************\n");
    printf("Choose an option: ");
}

// Function to get input from user
void get_input(char *buffer, size_t size) {
    printf("Enter your message (max %zu characters): ", size - 1);
    fgets(buffer, size, stdin);
    // Remove newline character if present
    buffer[strcspn(buffer, "\n")] = 0;
}

int main() {
    char message[256];
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // Consume newline left in buffer

        switch (choice) {
            case 1:
                get_input(message, sizeof(message));
                encrypt(message);
                printf("Encrypted Message: %s\n", message);
                break;

            case 2:
                get_input(message, sizeof(message));
                decrypt(message);
                printf("Decrypted Message: %s\n", message);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}