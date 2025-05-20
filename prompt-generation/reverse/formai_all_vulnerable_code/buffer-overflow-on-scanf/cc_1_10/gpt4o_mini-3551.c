//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decimalToHexadecimal(int num, char *hexStr) {
    int index = 0;
    while (num != 0) {
        int remainder = num % 16;
        
        // Handle the conversion of remainder to hex char
        if (remainder < 10) {
            hexStr[index++] = remainder + '0'; // '0' to '9'
        } else {
            hexStr[index++] = (remainder - 10) + 'A'; // 'A' to 'F'
        }
        num /= 16;
    }
    hexStr[index] = '\0';

    // Reverse the string to get the correct order
    int start = 0;
    int end = index - 1;
    while (start < end) {
        char temp = hexStr[start];
        hexStr[start] = hexStr[end];
        hexStr[end] = temp;
        start++;
        end--;
    }
}

void printHexadecimal(int num) {
    char hexStr[100];
    decimalToHexadecimal(num, hexStr);
    printf("The hexadecimal representation of %d is: %s\n", num, hexStr);
}

int main() {
    int decimalNum;

    printf("Surprise! Let's convert decimal to hexadecimal!\n");
    printf("Please enter a decimal number: ");
    
    // Check if the input is valid
    if (scanf("%d", &decimalNum) != 1) {
        printf("Oh no! That was not a valid number. Please try again!\n");
        return 1;
    }

    // Call the function to print hexadecimal
    printHexadecimal(decimalNum);

    // Add a little fun
    printf("Isn't this cool? Imagine the numbers in hex!\n");
    printf("Would you like to convert another number? (1 for Yes, 0 for No): ");
    
    int continueConversion;
    if (scanf("%d", &continueConversion) != 1 || (continueConversion != 0 && continueConversion != 1)) {
        printf("Hmm... Invalid input. Exiting the program!\n");
        return 1;
    }

    while (continueConversion) {
        printf("Please enter a decimal number: ");
        
        if (scanf("%d", &decimalNum) != 1) {
            printf("Oh no! That was not a valid number. Please try again!\n");
            continue;
        }

        printHexadecimal(decimalNum);

        printf("Would you like to convert another number? (1 for Yes, 0 for No): ");
        if (scanf("%d", &continueConversion) != 1 || (continueConversion != 0 && continueConversion != 1)) {
            printf("Hmm... Invalid input. Exiting the program!\n");
            return 1;
        }
    }

    printf("Thanks for playing with hexadecimal numbers! Have a great day!\n");
    return 0;
}