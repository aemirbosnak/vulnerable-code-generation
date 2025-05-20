//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: genious
#include <stdio.h>

/* Function to convert decimal to hexadecimal */
void dectohex(unsigned int n) {
    int rem; 
    char hex[32];
    int i = 0;
    while (n > 0) {
        rem = n % 16;
        if (rem < 10) {
            hex[i] = rem + 48; 
            i++;
        } else {
            hex[i] = rem + 55; 
            i++;
        }
        n = n / 16;
    }
    printf("\nHexadecimal output: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}

/* Function to convert hexadecimal to decimal */
void hextodec(char *hex) {
    unsigned int n = 0; 
    int i = 0;
    while (hex[i] != '\0') {
        if (hex[i] >= '0' && hex[i] <= '9') {
            n = n * 16 + hex[i] - '0';
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            n = n * 16 + hex[i] - 'a' + 10; 
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            n = n * 16 + hex[i] - 'A' + 10; 
        } else {
            printf("\nInvalid input! Please enter a valid hexadecimal number.\n");
            return; 
        }
        i++;
    }
    printf("\nDecimal output: %u", n);
}

/* Main function */
int main() {

    int choice;
    unsigned int decimal;
    char hexadecimal[32];
    
    printf("Welcome to the Hexadecimal Converter!\n");
    printf("1. Decimal to Hexadecimal\n");
    printf("2. Hexadecimal to Decimal\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: 
            printf("\nEnter the decimal number: ");
            scanf("%u", &decimal);
            dectohex(decimal);
            break; 
        case 2: 
            printf("\nEnter the hexadecimal number: ");
            scanf("%s", hexadecimal);
            hextodec(hexadecimal);
            break; 
        default: 
            printf("\nInvalid choice! Please enter a valid choice.");
            break; 
    }
    
    return 0;
}