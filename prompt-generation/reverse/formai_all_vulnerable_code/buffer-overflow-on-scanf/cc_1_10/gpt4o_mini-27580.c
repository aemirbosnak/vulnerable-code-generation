//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include <stdio.h>

void convertToHex(int number);
void printHexCharacter(int number);

int main() {
    int decimalNumber;
    
    // A grand introduction
    printf("=== A Medieval Hexadecimal Converter ===\n");
    printf("Hark! Enter a number, and let it be transformed into the mystic realm of Hexadecimal!\n");
    
    // The noble user prompts for a number
    printf("Pray, enter a decimal number (greater than 0): ");
    scanf("%d", &decimalNumber);
    
    // Validating the input
    if (decimalNumber < 0) {
        printf("Alas! The number must be non-negative for such a conversion.\n");
        return 1;
    }

    // The conversion process
    printf("Thou hast entered: %d\n", decimalNumber);
    printf("Lo! The hexadecimal representation is: ");
    convertToHex(decimalNumber);
    printf("\nMay thou find wisdom in numbers!\n");

    return 0;
}

void convertToHex(int number) {
    // If the number be 0, return the hex for 0
    if (number == 0) {
        printf("0");
        return;
    }

    // Preparing the grand tapestry of hexadecimal numbers
    char hexRepresentation[20];
    int index = 0;

    // Converting to hex
    while (number != 0) {
        int remainder = number % 16;
        hexRepresentation[index++] = remainder;
        number /= 16;
    }

    // The hex representation string must be reversed
    printf("0x");
    for (int j = index - 1; j >= 0; j--) {
        printHexCharacter(hexRepresentation[j]);
    }
}

void printHexCharacter(int number) {
    // This noble method prints the hexadecimal equivalent characters
    if (number < 10) {
        printf("%d", number);  // For numbers 0-9
    } else {
        printf("%c", 'A' + (number - 10)); // For numbers 10-15
    }
}

// End of the program