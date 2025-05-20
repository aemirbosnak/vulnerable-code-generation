//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: romantic
#include <stdio.h>
#include <string.h>

void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];
        
        // Encrypt lowercase letters
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        // Encrypt uppercase letters
        else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        
        message[i] = ch;
    }
}

void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];
        
        // Decrypt lowercase letters
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - shift + 26) % 26 + 'a';
        }
        // Decrypt uppercase letters
        else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        
        message[i] = ch;
    }
}

void display_instructions() {
    printf("Welcome to the Enchanted Love Message Encoder!\n");
    printf("Here, we shall share your heartfelt messages in secret.\n");
    printf("Let's wrap your words with a cloak of charm using a lovely shift!\n");
    printf("Please remember your secret shift to decode your affection later.\n");
    printf("Enter your romantic message and the shift value (1-25).\n");
}

int main() {
    char message[256];
    int shift;

    display_instructions();
    
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);
    
    // Remove the newline character from fgets
    message[strcspn(message, "\n")] = '\0';

    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);
    
    if (shift < 1 || shift > 25) {
        printf("Shift value must be between 1 and 25. Please try again next time!\n");
        return 1;
    }

    printf("\nYour original message: \"%s\"\n", message);
    
    encrypt(message, shift);
    printf("Your enchanted message: \"%s\"\n", message);
    
    decrypt(message, shift);
    printf("Decoding your message back: \"%s\"\n", message);
    
    printf("\nThank you for sharing your love. May your heart ever soar!\n");
    
    return 0;
}