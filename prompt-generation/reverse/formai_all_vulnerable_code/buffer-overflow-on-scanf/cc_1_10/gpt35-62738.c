//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: unmistakable
#include <stdio.h>

void decimalToHexadecimal(int decimal) {
    int remainder;
    int i = 1;
    char hexadecimal[20];
    
    while (decimal != 0) {
        remainder = decimal % 16;
        
        if (remainder < 10) {
            hexadecimal[i++] = remainder + 48;
        } else {
            hexadecimal[i++] = remainder + 55;
        }
        
        decimal /= 16;
    }
    
    printf("Hexadecimal Number: ");
    
    for (int j = i; j > 0; j--) {
        printf("%c", hexadecimal[j]);
    }
}

int hexadecimalToDecimal(char hexadecimal[]) {
    int decimal = 0;
    int i = 0;
    int power = 1;
    int length = 0;
    
    while (hexadecimal[length] != '\0') {
        length++;
    }
    
    for (int j = length - 1; j >= 0; j--) {
        if (hexadecimal[j] >= '0' && hexadecimal[j] <= '9') {
            decimal += (hexadecimal[j] - 48) * power;
            power *= 16;
        } else if (hexadecimal[j] >= 'A' && hexadecimal[j] <= 'F') {
            decimal += (hexadecimal[j] - 55) * power;
            power *= 16;
        } else if (hexadecimal[j] >= 'a' && hexadecimal[j] <= 'f') {
            decimal += (hexadecimal[j] - 87) * power;
            power *= 16;
        } else {
            printf("Invalid Hexadecimal Number.");
            return -1;
        }
    }
    
    printf("Decimal Number: %d", decimal);
    return decimal;
}

int main() {
    int choice;
    int decimal;
    char hexadecimal[20];
    
    while (1) {
        printf("1. Convert Decimal to Hexadecimal\n");
        printf("2. Convert Hexadecimal to Decimal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimal);
                decimalToHexadecimal(decimal);
                printf("\n");
                break;
            case 2:
                printf("Enter a hexadecimal number: ");
                scanf("%s", &hexadecimal);
                hexadecimalToDecimal(hexadecimal);
                printf("\n");
                break;
            case 3:
                printf("Exiting...");
                exit(0);
            default:
                printf("Invalid Choice!\n");
                break;
        }
    }
    
    return 0;
}