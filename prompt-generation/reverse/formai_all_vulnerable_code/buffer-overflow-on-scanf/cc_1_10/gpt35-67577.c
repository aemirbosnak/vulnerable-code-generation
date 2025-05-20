//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: careful
#include <stdio.h>

// Function prototype for hexadecimal to decimal conversion
int hex_to_dec(char hex[]);

// Function prototype for decimal to hexadecimal conversion
void dec_to_hex(int dec_num);

int main() {
    int choice = 0;
    char hex_num[20];

    // Loop until user enters 3 to exit
    while(choice != 3) {
        printf("Please choose an option:\n");
        printf("1. Convert hexadecimal to decimal\n");
        printf("2. Convert decimal to hexadecimal\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        if(choice == 1) {
            printf("Please enter a hexadecimal number: ");
            scanf("%s", &hex_num);
            printf("Decimal conversion: %d\n", hex_to_dec(hex_num));
        } else if(choice == 2) {
            int dec_num;
            printf("Please enter a decimal number: ");
            scanf("%d", &dec_num);
            printf("Hexadecimal conversion: ");
            dec_to_hex(dec_num);
            printf("\n");
        } else if(choice == 3) {
            printf("Goodbye!\n");
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to convert hexadecimal to decimal
int hex_to_dec(char hex[]) {
    int dec_num = 0, hex_digit, i;

    // Iterate through each hexadecimal digit
    for(i = 0; hex[i] != '\0'; i++) {
        // Convert hexadecimal digit to decimal (0-9)
        if(hex[i] >= '0' && hex[i] <= '9') {
            hex_digit = hex[i] - '0';
        } else {
            // Convert hexadecimal letter to decimal (10-15)
            switch(hex[i]) {
                case 'A':
                case 'a':
                    hex_digit = 10;
                    break;
                case 'B':
                case 'b':
                    hex_digit = 11;
                    break;
                case 'C':
                case 'c':
                    hex_digit = 12;
                    break;
                case 'D':
                case 'd':
                    hex_digit = 13;
                    break;
                case 'E':
                case 'e':
                    hex_digit = 14;
                    break;
                case 'F':
                case 'f':
                    hex_digit = 15;
                    break;
                default:
                    printf("Invalid hexadecimal number!\n");
                    return 0;
            }
        }

        // Add current digit to decimal number
        dec_num = dec_num * 16 + hex_digit;
    }

    return dec_num;
}

// Function to convert decimal to hexadecimal
void dec_to_hex(int dec_num) {
    int rem, i = 0;
    char hex_num[20];

    // Iterate until decimal number is 0
    while(dec_num != 0) {
        // Get remainder of dividing by 16
        rem = dec_num % 16;
        // Convert remainder to hexadecimal digit
        if(rem < 10) {
            hex_num[i] = rem + '0';
        } else {
            hex_num[i] = rem - 10 + 'A';
        }
        // Divide decimal number by 16
        dec_num /= 16;
        // Move to next digit position in hexadecimal number
        i++;
    }
    // Print hexadecimal number in reverse order
    for(int j = i - 1; j >= 0; j--) {
        printf("%c", hex_num[j]);
    }
}