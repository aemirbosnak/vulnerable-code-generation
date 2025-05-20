//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_TEXT_SIZE 1024

void encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] + key;  // Simple character shifting
    }
}

void decrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] = text[i] - key;  // Reverse character shifting
    }
}

void printMenu() {
    printf("=== C Encryption Program ===\n");
    printf("1. Encrypt Text\n");
    printf("2. Decrypt Text\n");
    printf("3. Exit\n");
    printf("============================\n");
}

int main() {
    char text[MAX_TEXT_SIZE];
    int option;
    int key;

    while (1) {
        printMenu();
        printf("Choose an option: ");
        scanf("%d", &option);
        
        if (option == 3) break;

        printf("Enter the text (max %d characters): ", MAX_TEXT_SIZE - 1);
        getchar(); // To clear out the newline character from previous input
        fgets(text, MAX_TEXT_SIZE, stdin);        
        text[strcspn(text, "\n")] = 0; // Remove the newline character
        
        printf("Enter the encryption key (integer): ");
        scanf("%d", &key);

        switch (option) {
            case 1:
                encrypt(text, key);
                printf("Encrypted text: %s\n", text);
                break;
            
            case 2:
                decrypt(text, key);
                printf("Decrypted text: %s\n", text);
                break;
            
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    printf("Exiting the program. Thank you!\n");
    return 0;
}