//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h> 

void heraldIntroduction() {
    printf("Hearken, noble traveler! Welcome to the great hall of the Binary Converter.\n");
    printf("In this place, thou shalt see thy numbers transformed from base ten to their binary representation!\n");
}

void displayBinary(int number) {
    int binary[32]; // Array to hold the binary digits
    int index = 0;
    
    if (number == 0) {
        printf("Thy number is zero, and its binary form is: 0\n");
        return;
    }
    
    // Convert the number to binary
    while (number > 0) {
        binary[index] = number % 2;
        number = number / 2;
        index++;
    }
    
    printf("Behold, the binary representation is: ");
    // Print the binary number in reverse
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

void invokeConversion() {
    int number;
    printf("Pray, enter an integer number from which thou wishest to derive the binary form: ");
    scanf("%d", &number);
    
    if (number < 0) {
        printf("Alas! Negative numbers shall not cross these gates. Please enter a positive integer!\n");
        return;
    }
    
    displayBinary(number);
}

void farewellMessage() {
    printf("May thy journey into the realms of binary speak well of your wisdom! Fare thee well!\n");
}

int main() {
    heraldIntroduction();
    
    char continueConversion;
    do {
        invokeConversion();
        printf("Dost thou wish to convert another number? (y/n): ");
        scanf(" %c", &continueConversion); // Note the space before %c to consume newline
    } while (continueConversion == 'y' || continueConversion == 'Y');
    
    farewellMessage();
    return 0;
}