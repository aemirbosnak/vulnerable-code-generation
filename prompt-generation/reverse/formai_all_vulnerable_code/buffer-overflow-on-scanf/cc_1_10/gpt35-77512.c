//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Linus Torvalds
#include <stdio.h>

int hex_digit_value(char hex) {
    if (hex >= '0' && hex <= '9') {
        return hex - '0'; // convert char to its corresponding int value
    } else if (hex >= 'A' && hex <= 'F') {
        return hex - 'A' + 10; // convert char to its corresponding int value (A is 10, B is 11, etc.)
    } else if (hex >= 'a' && hex <= 'f') {
        return hex - 'a' + 10; // convert char to its corresponding int value (a is 10, b is 11, etc.)
    } else {
        return -1; // invalid hex character
    }
}

void hex_to_int(char hex[]) {
    int result = 0;
    int i = 0;
    while (hex[i] != '\0') {
        int digit_value = hex_digit_value(hex[i]);
        if (digit_value == -1) {
            printf("Error: %c is not a valid hex character\n", hex[i]);
            return;
        }
        result = result * 16 + digit_value;
        i++;
    }
    printf("%s in hexadecimal is %d in decimal\n", hex, result);
}

void int_to_hex(int decimal) {
    char hex[10];
    int i = 0;
    while (decimal != 0) {
        int remainder = decimal % 16;
        if (remainder < 10) {
            hex[i] = remainder + '0'; // convert int to its corresponding hex digit (0 is 48, 1 is 49, etc.)
        } else {
            hex[i] = remainder + 'A' - 10; // convert int to its corresponding hex digit (A is 65, B is 66, etc.)
        }
        decimal /= 16;
        i++;
    }
    hex[i] = '\0';
    printf("%d in decimal is %s in hexadecimal\n", decimal, hex);
}

int main() {
    char hex[10];
    printf("Enter a hexadecimal value: ");
    scanf("%s", hex);
    hex_to_int(hex);
    
    int decimal;
    printf("Enter a decimal value: ");
    scanf("%d", &decimal);
    int_to_hex(decimal);
    
    return 0;
}