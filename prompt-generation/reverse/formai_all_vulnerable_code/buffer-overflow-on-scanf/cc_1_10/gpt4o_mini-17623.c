//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

void printHex(int num);
void fetchInput(char *prompt, int *number);
void welcomeMessage();
void farewellMessage();

int main() {
    welcomeMessage();
    
    int decimalNumber;
    
    fetchInput("Enter a decimal number to convert to hexadecimal: ", &decimalNumber);
    
    printf("\nConverting the decimal number %d into its hexadecimal equivalent...\n", decimalNumber);
    
    printHex(decimalNumber);
    
    farewellMessage();
    return 0;
}

void welcomeMessage() {
    printf("🎉 Welcome to the Mystical Hexadecimal Converter! 🎉\n");
    printf("-------------------------------------------------\n");
    printf("In this enchanting realm, you shall witness the digital\n");
    printf("magic of turning mundane decimal numbers into their\n");
    printf("ethereal hexadecimal forms. Let the conversion begin!\n\n");
}

void farewellMessage() {
    printf("\nThank you for embarking on this mystical journey with us!\n");
    printf("May your hexadecimal quests be endless and your numbers ever vibrant! 🌌\n");
}

void fetchInput(char *prompt, int *number) {
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", number) == 1) {
            if (*number >= 0) break;
            else printf("Please enter a non-negative integer.\n");
        } else {
            printf("That's not a valid number! Try again...\n");
            while (getchar() != '\n'); // Clear invalid input
        }
    }
}

void printHex(int num) {
    char hexRepresentation[20]; // Array to hold the hexadecimal digits
    int index = 0;

    if (num == 0) {
        printf("Hexadecimal: 0x0\n");
        return;
    }

    while (num != 0) {
        int remainder = num % 16; // Get the remainder
        if (remainder < 10) {
            hexRepresentation[index++] = remainder + '0'; // Convert to character
        } else {
            hexRepresentation[index++] = remainder - 10 + 'A'; // Convert A-F
        }
        num /= 16; // Move to the next digit
    }
    
    printf("Hexadecimal: 0x");
    for (int i = index - 1; i >= 0; i--) { // Reverse the array
        putchar(hexRepresentation[i]);
    }
    printf("\n");
}