//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LENGTH 1024

void encrypt(const char *message, int shift, char *encrypted_msg) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            encrypted_msg[i] = (c - 'a' + shift) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            encrypted_msg[i] = (c - 'A' + shift) % 26 + 'A';
        } else {
            encrypted_msg[i] = c; // Non-alphabet characters remain unchanged
        }
    }
    encrypted_msg[i] = '\0'; // Null-terminate the string
}

void decrypt(const char *encrypted_msg, int shift, char *decrypted_msg) {
    int i;
    for (i = 0; encrypted_msg[i] != '\0'; i++) {
        char c = encrypted_msg[i];
        if (c >= 'a' && c <= 'z') {
            decrypted_msg[i] = (c - 'a' - shift + 26) % 26 + 'a'; // Adding 26 to avoid negative values
        } else if (c >= 'A' && c <= 'Z') {
            decrypted_msg[i] = (c - 'A' - shift + 26) % 26 + 'A';
        } else {
            decrypted_msg[i] = c; // Non-alphabet characters remain unchanged
        }
    }
    decrypted_msg[i] = '\0'; // Null-terminate the string
}

void get_shift_value(int *shift) {
    printf("Enter the shift value (1-25): ");
    while (scanf("%d", shift) != 1 || *shift < 1 || *shift > 25) {
        printf("Invalid value. Please enter a number between 1 and 25: ");
        while (getchar() != '\n'); // clear input buffer
    }
}

void get_message(char *message) {
    printf("Enter the message: ");
    getchar(); // To clear the newline character from previous input
    fgets(message, MAX_MSG_LENGTH, stdin);
    // Remove newline character if present
    message[strcspn(message, "\n")] = 0;
}

void display_results(const char *message, const char *result) {
    printf("Original Message: %s\n", message);
    printf("Processed Message: %s\n", result);
}

int main() {
    char message[MAX_MSG_LENGTH];
    char encrypted_msg[MAX_MSG_LENGTH];
    char decrypted_msg[MAX_MSG_LENGTH];
    int shift;

    printf("Welcome to the Simple Cryptography Program\n");
    printf("Choose an option:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    int option;
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            get_shift_value(&shift);
            get_message(message);
            encrypt(message, shift, encrypted_msg);
            display_results(message, encrypted_msg);
            break;
        case 2:
            get_shift_value(&shift);
            get_message(message);
            decrypt(message, shift, decrypted_msg);
            display_results(message, decrypted_msg);
            break;
        default:
            printf("Invalid option!\n");
            break;
    }

    return 0;
}