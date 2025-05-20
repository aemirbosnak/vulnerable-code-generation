//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* str, int shift) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= ' ' && str[i] <= '~') { // Check for printable characters
            str[i] = str[i] + shift;
            // Wrap around the printable ASCII characters
            if (str[i] > '~') {
                str[i] = ' ' + (str[i] - '~' - 1);
            }
        }
    }
}

void decrypt(char* str, int shift) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= ' ' && str[i] <= '~') { // Check for printable characters
            str[i] = str[i] - shift;
            // Wrap around the printable ASCII characters
            if (str[i] < ' ') {
                str[i] = '~' - (' ' - str[i] - 1);
            }
        }
    }
}

int main() {
    char str[256];
    int shift;
    
    printf("Welcome to the Enchanted Encryption Program!\n");
    printf("Enter a string to encrypt: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character from input
    str[strcspn(str, "\n")] = '\0';

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);
    
    // Ensuring the shift value is in range
    if (shift < 1 || shift > 25) {
        printf("Shift value must be between 1 and 25!\n");
        return 1;
    }
    
    printf("\nEncrypting your message...\n");
    encrypt(str, shift);
    printf("Encrypted message: %s\n", str);

    printf("\nDecrypting your message...\n");
    decrypt(str, shift);
    printf("Decrypted message: %s\n", str);

    printf("Thank you for using the Enchanted Encryption Program!\n");
    return 0;
}