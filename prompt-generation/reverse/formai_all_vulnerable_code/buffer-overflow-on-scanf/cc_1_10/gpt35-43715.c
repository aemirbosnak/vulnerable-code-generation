//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100 // Maximum size of input array

void to_hexadecimal(int decimal_num, char* hexadecimal); // Function to convert decimal number to hexadecimal string
void reverse_string(char* str); // Function to reverse string

int main() {
    int decimal_num;
    char hexadecimal[MAX_SIZE];

    printf("Enter the decimal number: ");
    scanf("%d", &decimal_num);

    to_hexadecimal(decimal_num, hexadecimal);

    printf("The equivalent hexadecimal value is: %s\n", hexadecimal);

    return 0;
}

void to_hexadecimal(int decimal_num, char* hexadecimal) {
    int remainder, index = 0;

    while (decimal_num != 0) {
        remainder = decimal_num % 16;

        if (remainder < 10)
            *(hexadecimal + index) = 48 + remainder; // Add value of the remainder to ASCII value of '0'
        else
            *(hexadecimal + index) = 55 + remainder; // Add value of the remainder to ASCII value of 'A'

        decimal_num /= 16;
        index++;
    }

    *(hexadecimal + index) = '\0'; // Add NULL character at the end of the string

    // Reverse the string to get the correct hexadecimal value
    reverse_string(hexadecimal);
}

void reverse_string(char* str) {
    int length = strlen(str);
    char temp;

    for (int i = 0; i < length / 2; i++) {
        temp = *(str + i);
        *(str + i) = *(str + length - i - 1);
        *(str + length - i - 1) = temp;
    }
}