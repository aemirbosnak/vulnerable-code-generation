//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to enchant the text using a magical shift
void enchantText(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char currentChar = text[i];

        // Check if the character is a lowercase letter
        if (currentChar >= 'a' && currentChar <= 'z') {
            text[i] = (currentChar - 'a' + shift) % 26 + 'a';
        }
        // Check if the character is an uppercase letter
        else if (currentChar >= 'A' && currentChar <= 'Z') {
            text[i] = (currentChar - 'A' + shift) % 26 + 'A';
        }
        // Spaces and non-alphabet characters remain unchanged
    }
}

// Function to summon the magic number from the user
int summonMagicNumber() {
    int magicNumber;
    printf("Enter a magical shift number (1-25): ");
    scanf("%d", &magicNumber);
    // We want the magic number to wrap around
    return (magicNumber % 26);
}

// Function to transform and display the enchanted message
void displayEnchantedMessage(char *text) {
    printf("Your enchanted message is: %s\n", text);
}

int main() {
    char *spookyInput;
    int magicalShift;

    // Allocate space for the user's message
    spookyInput = (char *)malloc(256 * sizeof(char));
    if (spookyInput == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    // Prompt the user for a message
    printf("Enter the text you wish to enchant: ");
    getchar();  // Clear input buffer
    fgets(spookyInput, 256, stdin);
    
    // Remove newline character if present
    spookyInput[strcspn(spookyInput, "\n")] = '\0';

    // Summon the magic number for encryption
    magicalShift = summonMagicNumber();

    // Enchant the text with the magical shift
    enchantText(spookyInput, magicalShift);

    // Display the enchanted text
    displayEnchantedMessage(spookyInput);

    // Release the captured memory back to the ether
    free(spookyInput);
    
    return 0;
}