//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024 // For the sake of clarity
#define SHIFT 4 // Simplistic Caesar Cipher Shift
#define FILE_NAME "encrypted.txt"

void encrypt_decrypt(char *input, char *output, int shift);
void read_file(const char *filename, char *buffer);
void write_file(const char *filename, const char *buffer);
void display_menu();
void handle_choice(int choice);

int main() {
    int choice = 0;
    while (choice != 3) {
        display_menu();
        printf("Choose an option (1-3): ");
        scanf("%d", &choice);
        handle_choice(choice);
    }
    return 0;
}

void display_menu() {
    printf("\n======= C Encryption Program =======\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("=====================================\n");
}

void handle_choice(int choice) {
    switch (choice) {
        case 1: {
            char message[BUFFER_SIZE];
            printf("Enter the message to encrypt: ");
            getchar(); // Clear newline
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = 0; // Remove newline
            char encrypted[BUFFER_SIZE];
            encrypt_decrypt(message, encrypted, SHIFT);
            write_file(FILE_NAME, encrypted);
            printf("Message encrypted and saved to %s\n", FILE_NAME);
            break;
        }
        case 2: {
            char decrypted[BUFFER_SIZE];
            read_file(FILE_NAME, decrypted);
            char original[BUFFER_SIZE];
            encrypt_decrypt(decrypted, original, -SHIFT);
            printf("Decrypted message: %s\n", original);
            break;
        }
        case 3:
            printf("Exiting program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void encrypt_decrypt(char *input, char *output, int shift) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        // Encrypting only alphabet characters
        if (ch >= 'a' && ch <= 'z') { // Lowercase letters
            ch = ((ch - 'a' + shift) % 26 + 26) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') { // Uppercase letters
            ch = ((ch - 'A' + shift) % 26 + 26) % 26 + 'A';
        }
        output[i] = ch; // Output encrypted/decrypted character
    }
    output[i] = '\0'; // Null-terminate the string
}

void read_file(const char *filename, char *buffer) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fgets(buffer, BUFFER_SIZE, file);
    fclose(file);
}

void write_file(const char *filename, const char *buffer) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fputs(buffer, file);
    fclose(file);
}