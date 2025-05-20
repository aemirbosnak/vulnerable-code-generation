//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    char input[100];
    bool isHex = false;
    int decimal = 0;
    char hex[100];
    
    // Prompt user for input
    printf("Enter a hexadecimal number: ");
    
    // Read input from user
    fgets(input, 100, stdin);
    
    // Check if input is hexadecimal
    for (int i = 0; i < strlen(input); i++) {
        if (!isxdigit(input[i])) {
            isHex = false;
            break;
        }
        else if (isxdigit(input[i])) {
            isHex = true;
        }
    }
    
    // Convert input to decimal if it is hexadecimal
    if (isHex) {
        for (int i = 0; i < strlen(input); i++) {
            if (isxdigit(input[i])) {
                if (input[i] >= '0' && input[i] <= '9') {
                    decimal = (decimal * 16) + (input[i] - '0');
                }
                else if (input[i] >= 'A' && input[i] <= 'F') {
                    decimal = (decimal * 16) + (input[i] - 'A' + 10);
                }
                else if (input[i] >= 'a' && input[i] <= 'f') {
                    decimal = (decimal * 16) + (input[i] - 'a' + 10);
                }
            }
        }
        
        // Convert decimal to hexadecimal
        sprintf(hex, "%X", decimal);
        
        // Print result
        printf("Hexadecimal: %s\n", hex);
    }
    else {
        printf("Invalid input. Please enter a valid hexadecimal number.\n");
    }
    
    return 0;
}