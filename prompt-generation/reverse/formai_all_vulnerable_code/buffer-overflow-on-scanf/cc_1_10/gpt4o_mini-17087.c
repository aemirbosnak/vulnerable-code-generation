//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: Romeo and Juliet
#include <stdio.h>

void toHex(int num, char *hex) {
    char *hexDigits = "0123456789ABCDEF";
    int i = 0;

    if (num == 0) {
        hex[i++] = '0';
    } else {
        while (num != 0) {
            hex[i++] = hexDigits[num % 16];
            num /= 16;
        }
        hex[i] = '\0';
        
        // Reverse the string to get the correct order
        for (int j = 0; j < i / 2; ++j) {
            char temp = hex[j];
            hex[j] = hex[i - j - 1];
            hex[i - j - 1] = temp;
        }
    }
}

void presentConversion(int decimal) {
    char hex[20];
    toHex(decimal, hex);
    printf("\nIn fair Verona, thou dost seek to know,\n"
           "The hex of thy number, let us bestow.\n"
           "Oh, %d is no mere integer plain,\n"
           "But transformed to hex, shall not be in vain.\n"
           "Behold! The dichotomy of life's great dance,\n"
           "Hexadecimal brilliance in code's sweet romance:\n"
           "%s\n\n", decimal, hex);
}


int main() {
    int decimal;
    printf("Welcome, dear user, to the grand conversion stage!\n"
           "Enter thy decimal number, turn the page:\n");
    scanf("%d", &decimal);

    if (decimal < 0) {
        printf("Alas! This number dost bear no joy,\n"
               "For under zero, no hex can employ.\n");
    } else {
        presentConversion(decimal);
    }
    
    printf("Go forth, dear friend, to code’s tender embrace,\n"
           "In hexadecimal glory, your thoughts interlace.\n");

    return 0;
}