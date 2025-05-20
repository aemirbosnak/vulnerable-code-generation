//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_SIZE 100

// function to reverse a string
void reverse_string(char* str, int size) {
    char temp;
    for (int i = 0; i < size / 2; i++) {
        temp = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = temp;
    }
}

// function to convert decimal to binary
void decimal_to_binary(int decimal, char* binary) {
    int remainder;
    int index = 0;
    while (decimal > 0) {
        remainder = decimal % 2;
        binary[index] = remainder + '0';
        decimal /= 2;
        index++;
    }
    reverse_string(binary, index);
}

// function to convert binary to decimal
int binary_to_decimal(char* binary) {
    int decimal = 0;
    int power = 0;
    int size = strlen(binary);
    for (int i = 0; i < size; i++) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

int main() {
    char decimal[MAX_NUM_SIZE];
    char binary[MAX_NUM_SIZE];
    int choice;
    printf("Enter a decimal number: ");
    scanf("%s", decimal);
    printf("Enter 1 to convert decimal to binary\nEnter 2 to convert binary to decimal: ");
    scanf("%d", &choice);
    if (choice == 1) {
        decimal_to_binary(atoi(decimal), binary);
        printf("Binary equivalent: %s\n", binary);
    } else if (choice == 2) {
        int decimal_num = binary_to_decimal(decimal);
        printf("Decimal equivalent: %d\n", decimal_num);
    } else {
        printf("Invalid choice!\n");
    }
    return 0;
}