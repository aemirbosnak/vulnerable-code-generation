//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: Dennis Ritchie
#include <stdio.h>

void toHexadecimal(int num) {
    char hexDigits[] = "0123456789ABCDEF";
    char hex[9];  // 8 digits for max value + Null character
    int index = 0;
    
    if(num < 0) {
        num = -num; // Convert to positive to process
    }
    
    if(num == 0) {
        hex[index++] = '0';
    } else {
        while(num > 0) {
            hex[index++] = hexDigits[num % 16];
            num /= 16;
        }
    }

    // Reverse the hex array
    for(int i = 0; i < index / 2; i++) {
        char temp = hex[i];
        hex[i] = hex[index - 1 - i];
        hex[index - 1 - i] = temp;
    }
    
    hex[index] = '\0'; // Null terminate the string
    printf("Hexadecimal: %s\n", hex);
}

void displayMenu() {
    printf("\nHexadecimal Converter\n");
    printf("=========================\n");
    printf("1. Convert decimal to hexadecimal\n");
    printf("2. Exit\n");
}

int main() {
    int choice;
    int number;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &number);
                toHexadecimal(number);
                break;

            case 2:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice, please select again.\n");
                break;
        }
    } while(choice != 2);

    return 0;
}