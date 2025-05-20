//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    // Define variables
    char input[100];
    int length = 0;
    int i = 0;

    // Prompt user for input
    printf("Enter a hexadecimal number: ");

    // Get user input
    while(1) {
        char c = getchar();
        if(c == '\n') {
            break;
        }
        input[i++] = c;
    }

    // Convert input to uppercase
    for(i = 0; input[i]!= '\0'; i++) {
        input[i] = toupper(input[i]);
    }

    // Check if input is a valid hexadecimal number
    for(i = 0; input[i]!= '\0'; i++) {
        if(!isxdigit(input[i])) {
            printf("Invalid input. Please enter a valid hexadecimal number.\n");
            return 0;
        }
    }

    // Convert hexadecimal to decimal
    int decimal = 0;
    for(i = strlen(input) - 1; i >= 0; i--) {
        if(input[i] >= '0' && input[i] <= '9') {
            decimal += input[i] - '0';
        }
        else if(input[i] >= 'A' && input[i] <= 'F') {
            decimal += input[i] - 'A' + 10;
        }
        else {
            printf("Invalid input. Please enter a valid hexadecimal number.\n");
            return 0;
        }
        decimal *= 16;
    }

    // Print result
    printf("The decimal equivalent of %s is %d.\n", input, decimal);

    return 0;
}