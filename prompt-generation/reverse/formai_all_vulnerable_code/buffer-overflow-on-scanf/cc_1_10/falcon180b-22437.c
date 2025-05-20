//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000000

char* binary_to_decimal(char* binary) {
    int decimal = 0;
    int power = 0;
    char* temp = binary;

    while(*temp!= '\0') {
        if(*temp == '1') {
            decimal += pow(2, power);
        }
        power++;
        temp++;
    }

    char* result = malloc(MAX_LENGTH);
    sprintf(result, "%d", decimal);
    return result;
}

char* decimal_to_binary(int decimal) {
    char* binary = malloc(MAX_LENGTH);
    int power = 0;
    int remainder;

    while(decimal > 0) {
        remainder = decimal % 2;
        binary[power] = remainder + '0';
        power++;
        decimal /= 2;
    }

    binary[power] = '\0';
    return binary;
}

int main() {
    char* binary;
    char* decimal;
    int choice;

    do {
        printf("Enter 1 to convert binary to decimal\n");
        printf("Enter 2 to convert decimal to binary\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter binary number: ");
                scanf("%s", binary);
                decimal = binary_to_decimal(binary);
                printf("Decimal number: %s\n", decimal);
                break;

            case 2:
                printf("Enter decimal number: ");
                scanf("%d", &decimal);
                binary = decimal_to_binary(decimal);
                printf("Binary number: %s\n", binary);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 0);

    return 0;
}