//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: lively
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100
#define SHIFT 3

void encrypt(char *input, char *output) {
    int i, len = strlen(input);
    for (i = 0; i < len; i++) {
        // Only encrypt alphabets
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = ((input[i] - 'a' + SHIFT) % 26) + 'a';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = ((input[i] - 'A' + SHIFT) % 26) + 'A';
        } else {
            output[i] = input[i]; // Non-alphabetic characters remain the same
        }
    }
    output[len] = '\0'; // Null-terminate the string
}

void decrypt(char *input, char *output) {
    int i, len = strlen(input);
    for (i = 0; i < len; i++) {
        // Only decrypt alphabets
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = ((input[i] - 'a' - SHIFT + 26) % 26) + 'a';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = ((input[i] - 'A' - SHIFT + 26) % 26) + 'A';
        } else {
            output[i] = input[i]; // Non-alphabetic characters remain the same
        }
    }
    output[len] = '\0'; // Null-terminate the string
}

void printMenu() {
    printf("Welcome to the Lively Encryption Program!\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Please choose an option (1-3): ");
}

int main() {
    char input[MAX_LEN];
    char encrypted[MAX_LEN];
    char decrypted[MAX_LEN];
    int choice;
    
    while (1) {
        printMenu();
        scanf("%d", &choice);
        
        if (choice == 3) {
            printf("Thank you for using the Lively Encryption Program! Goodbye!\n");
            break;
        }
        
        printf("Please enter your message (max %d characters): ", MAX_LEN - 1);
        // Clear the input buffer
        getchar();
        fgets(input, MAX_LEN, stdin);
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;
        
        switch (choice) {
            case 1:
                encrypt(input, encrypted);
                printf("Encrypted message: %s\n", encrypted);
                break;
            case 2:
                decrypt(input, decrypted);
                printf("Decrypted message: %s\n", decrypted);
                break;
            default:
                printf("Invalid choice! Please select 1, 2, or 3.\n");
        }
    }
    
    return 0;
}