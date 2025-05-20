//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: Dennis Ritchie
#include <stdio.h>

// Function prototypes
void toHexadecimal(int num);
void reverseString(char str[], int length);
void intToHex(int num, char hexStr[]);

int main() {
    int number;
    char choice;

    printf("Hexadecimal Converter by Dennis Ritchie\n");
    printf("Enter an integer number to convert to hexadecimal: ");

    while (scanf("%d", &number) == 1) {
        printf("The hexadecimal representation of %d is: ", number);
        toHexadecimal(number);

        printf("\nWould you like to convert another number? (y/n): ");
        while ((choice = getchar()) == '\n');  // Clear the buffer

        if (choice == 'y' || choice == 'Y') {
            printf("Enter an integer number to convert to hexadecimal: ");
        } else {
            break;
        }
    }

    printf("Exiting the Hexadecimal Converter. Goodbye!\n");
    return 0;
}

// Function to convert an integer to hexadecimal and print it
void toHexadecimal(int num) {
    char hexStr[20]; // Array to hold the hexadecimal representation
    intToHex(num, hexStr);
    printf("%s\n", hexStr);
}

// Function to convert an integer to a hexadecimal string
void intToHex(int num, char hexStr[]) {
    int i = 0, rem;
    const char *hexDigits = "0123456789ABCDEF";

    if(num == 0) {
        hexStr[i++] = '0';
        hexStr[i] = '\0';
        return;
    }

    // Generate hexadecimal representation
    while (num != 0) {
        rem = num % 16;
        hexStr[i++] = hexDigits[rem];
        num /= 16;
    }
  
    hexStr[i] = '\0'; // Null-terminate string

    // Reverse the string to get the correct hexadecimal representation
    reverseString(hexStr, i);
}

// Function to reverse a string
void reverseString(char str[], int length) {
    int start = 0;
    int end = length - 1;
    char temp;

    while (start < end) {
        // Swap characters
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}