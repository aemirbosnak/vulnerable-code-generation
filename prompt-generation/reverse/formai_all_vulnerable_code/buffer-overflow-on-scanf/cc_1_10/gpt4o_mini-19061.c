//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to convert integer to binary and store as string
void intToBinary(int n, char *binaryStr) {
    int index = 0;
    // Generate binary representation
    while (n > 0) {
        binaryStr[index++] = (n % 2) ? '1' : '0';
        n /= 2;
    }
    binaryStr[index] = '\0';
    
    // Reverse the string to get the correct order
    for (int i = 0; i < index / 2; i++) {
        char temp = binaryStr[i];
        binaryStr[i] = binaryStr[index - i - 1];
        binaryStr[index - i - 1] = temp;
    }
}

// Function to enchant the user with a romantic display
void romanticMessage(char *message) {
    printf("\n💖✨ Just for you, my dear! ✨💖\n");
    printf("Here is a secret message transformed into binary beauty:\n");
    printf("> %s <\n", message);
}

int main() {
    // The heart of the program
    int number;
    char binaryStr[33]; // Enough for a 32-bit integer binary representation
    
    // A warm invitation
    printf("🌹 Welcome to the Love and Binary Conversion Program 🌹\n");
    printf("Enter a non-negative integer, my lovely: ");
    
    if (scanf("%d", &number) != 1 || number < 0) {
        printf("Oh dear! That wasn't quite right. Please enter a non-negative integer next time.\n");
        return 1;
    }

    // Convert the number to binary
    intToBinary(number, binaryStr);
    
    // Show the binary representation in a heartfelt way
    romanticMessage(binaryStr);

    // Additional charming interactions
    printf("\nAs night falls, let's together dive into the depths of binary forever.\n");
    printf("Enter a string of your heart's desires (limited to 64 characters): ");
    char inputStr[65];
    getchar(); // clear the newline character after previous input
    fgets(inputStr, sizeof(inputStr), stdin);
    
    // Remove newline character from fgets
    inputStr[strcspn(inputStr, "\n")] = 0;

    // Transform each character to binary and display
    printf("\n💞 Your sweet message in binary:\n");
    for (int i = 0; i < strlen(inputStr); i++) {
        // Convert each character to binary
        char charBinary[9]; // 8 bits + null-terminator
        intToBinary(inputStr[i], charBinary);
        printf("%c: %s\n", inputStr[i], charBinary);
    }

    // A gentle conclusion
    printf("\n🌙 Thank you for joining me on this romantic binary journey. 🌙\n");
    return 0;
}