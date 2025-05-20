//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>
#include <string.h>

void convertToBinary(int num, char *binaryStr) {
    int index = 0;
    while (num > 0) {
        binaryStr[index] = (num % 2) + '0'; // Store the binary digit
        num = num / 2; // Divide by 2
        index++;
    }
    // Reverse the string to get correct binary representation
    for (int i = 0; i < index / 2; i++) {
        char temp = binaryStr[i];
        binaryStr[i] = binaryStr[index - 1 - i];
        binaryStr[index - 1 - i] = temp;
    }
    binaryStr[index] = '\0'; // Null-terminate the string
}

void displayTitle() {
    printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n");
    printf("*  The Medieval Binary Converter  *\n");
    printf("~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n");
    printf("\n");
}

void greetUser() {
    printf("Hark! Good traveler! Enter an integer such that thou mayest witness its binary form!\n");
}

void farewell() {
    printf("\nMay fortune favor thee, and may thy knowledge of binary art grow ever stronger!\n");
}

int main() {
    displayTitle();
    greetUser();

    int number;
    char binaryRepresentation[32]; // Assuming 32 bits for simplicity

    // Prompt the user for an integer
    printf("Pray, enter the integer: ");
    scanf("%d", &number);

    // Validate if the number is non-negative
    if (number < 0) {
        printf("Alas! Only non-negative integers may be converted unto binary!\n");
        return 1; // Exit if not valid
    }

    // Perform the conversion
    convertToBinary(number, binaryRepresentation);
    
    // Display the result
    printf("The binary representation of %d is: %s\n", number, binaryRepresentation);
    
    // Depart with a farewell
    farewell();
    
    return 0;
}