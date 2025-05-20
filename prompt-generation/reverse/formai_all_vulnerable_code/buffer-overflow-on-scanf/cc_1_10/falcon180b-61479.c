//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAX_HEX_LENGTH 1000
#define MAX_DEC_LENGTH 1000

int main() {
    char hex[MAX_HEX_LENGTH];
    char dec[MAX_DEC_LENGTH];
    int choice;
    int len;
    int i;

    printf("Welcome to the C Hexadecimal Converter!\n");
    printf("Please enter your choice:\n");
    printf("1. Convert decimal to hexadecimal\n");
    printf("2. Convert hexadecimal to decimal\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter a decimal number: ");
            fgets(dec, MAX_DEC_LENGTH, stdin);
            len = strlen(dec);
            for(i = 0; i < len; i++) {
                if(!isdigit(dec[i])) {
                    printf("Invalid input. Please enter a valid decimal number.\n");
                    return 0;
                }
            }
            printf("Hexadecimal number: ");
            sprintf(hex, "%X", atoi(dec));
            printf("%s\n", hex);
            break;
        case 2:
            printf("Enter a hexadecimal number: ");
            fgets(hex, MAX_HEX_LENGTH, stdin);
            len = strlen(hex);
            for(i = 0; i < len; i++) {
                if(!isxdigit(hex[i])) {
                    printf("Invalid input. Please enter a valid hexadecimal number.\n");
                    return 0;
                }
            }
            printf("Decimal number: %d\n", atoi(hex));
            break;
        default:
            printf("Invalid choice. Please enter a valid choice.\n");
            return 0;
    }

    return 0;
}