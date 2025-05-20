//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toHex(int num, char* hexStr) {
    if (num < 0) {
        num = -num;
        strcat(hexStr, "-");
    }

    char hexDigits[] = "0123456789ABCDEF";
    int temp = num;
    char result[20]; 
    int index = 0;

    if (num == 0) {
        strcpy(result, "0");
    } else {
        while (temp > 0) {
            int remainder = temp % 16;
            result[index++] = hexDigits[remainder];
            temp /= 16;
        }
    }

    // Reverse the string
    for (int i = 0; i < index; i++) {
        hexStr[i] = result[index - i - 1];
    }
    hexStr[index] = '\0'; // Null terminate the string
}

void displayMenu() {
    printf("\n--- Hexadecimal Converter ---\n");
    printf("1. Convert Decimal to Hexadecimal\n");
    printf("2. Exit\n");
    printf("-----------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    int num;  
    char hexStr[20];  

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &num);
                memset(hexStr, 0, sizeof(hexStr)); // Clearing the hexStr

                toHex(num, hexStr);
                printf("Hexadecimal representation: %s\n", hexStr);
                break;

            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid option, please try again.\n");
                break;
        }

    } while (choice != 2);

    return 0;
}