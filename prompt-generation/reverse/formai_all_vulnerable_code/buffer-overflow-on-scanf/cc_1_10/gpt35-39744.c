//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: creative
#include <stdio.h>

// function to convert hexadecimal to decimal
int hexToDec(char hex[]) {
    int len = 0;
    while (hex[len] != '\0') { // calculate length of string
        len++;
    }

    int base = 1; // initialize base value to 1 (16^0)
    int dec = 0;

    for (int i = len - 1; i >= 0; i--) { // iterate through string from right to left
        if (hex[i] >= '0' && hex[i] <= '9') { // if character is a number
            dec += (hex[i] - 48) * base; // convert to decimal and add to total
            base *= 16; // increase power of 16
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') { // if character is a letter
            dec += (hex[i] - 55) * base; // convert to decimal and add to total
            base *= 16; // increase power of 16
        }
    }

    return dec;
}

// function to convert decimal to hexadecimal
void decToHex(int dec) {
    char hex[100]; // create an array to store hexadecimal digits
    int i = 0;

    while (dec != 0) { // convert decimal to hexadecimal until all digits are converted
        int temp = 0;
        temp = dec % 16; // get remainder when dividing by 16
        if (temp < 10) { // if remainder is less than 10
            hex[i] = temp + 48; // add 48 to get ASCII value of digit
            i++;
        }
        else { // if remainder is 10 or greater
            hex[i] = temp + 55; // add 55 to get ASCII value of letter
            i++;
        }
        dec /= 16; // divide decimal by 16 to get next digit
    }

    printf("Hexadecimal equivalent: ");
    for (int j = i - 1; j >= 0; j--) { // print array in reverse order to get correct hex value
        printf("%c", hex[j]);
    }
    printf("\n");
}

int main() {
    int choice = 0;

    while (choice != 3) { // continue displaying menu until user chooses to exit
        printf("1. Convert hexadecimal to decimal\n");
        printf("2. Convert decimal to hexadecimal\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) { // convert hexadecimal to decimal
            char hex[100];
            printf("Enter hexadecimal number: ");
            scanf("%s", hex);

            int dec = hexToDec(hex);
            printf("Decimal equivalent: %d\n", dec);
        }
        else if (choice == 2) { // convert decimal to hexadecimal
            int dec;
            printf("Enter decimal number: ");
            scanf("%d", &dec);

            decToHex(dec);
        }
        else if (choice == 3) { // exit program
            printf("Goodbye!\n");
            break;
        }
        else { // invalid choice
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}