//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {

    char binary[100];
    char hex[100];
    char octal[100];
    char input[100];
    int decimal, i, j, k;
    int choice;

    printf("Enter the binary number: ");
    scanf("%s", input);

    for(i=0; i<strlen(input); i++) {
        if(!isdigit(input[i])) {
            printf("Invalid input. Please enter a binary number.\n");
            return 0;
        }
    }

    decimal = atoi(input);

    printf("Enter the conversion type:\n1. Binary to decimal\n2. Decimal to binary\n3. Binary to hexadecimal\n4. Hexadecimal to binary\n5. Binary to octal\n6. Octal to binary\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("The decimal equivalent of %s is %d.\n", input, decimal);
            break;
        case 2:
            sprintf(binary, "%b", decimal);
            printf("The binary equivalent of %d is %s.\n", decimal, binary);
            break;
        case 3:
            sprintf(hex, "%X", decimal);
            printf("The hexadecimal equivalent of %d is %s.\n", decimal, hex);
            break;
        case 4:
            sprintf(binary, "%b", decimal);
            printf("The binary equivalent of %s is %d.\n", binary, decimal);
            break;
        case 5:
            sprintf(octal, "%o", decimal);
            printf("The octal equivalent of %d is %s.\n", decimal, octal);
            break;
        case 6:
            sprintf(decimal, "%d", atoi(input));
            printf("The decimal equivalent of %s is %s.\n", input, decimal);
            break;
        default:
            printf("Invalid choice. Please enter a valid choice.\n");
    }

    return 0;
}