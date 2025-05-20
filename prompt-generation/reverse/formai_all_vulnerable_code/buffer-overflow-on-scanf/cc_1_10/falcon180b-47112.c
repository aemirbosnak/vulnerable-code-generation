//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000 // Maximum size of input buffer

char input_buffer[MAX_SIZE]; // Input buffer
int input_size; // Input size
int output_size; // Output size

void read_input() {
    printf("Enter binary number: ");
    fgets(input_buffer, MAX_SIZE, stdin);
    input_size = strlen(input_buffer);
}

void convert_binary_to_decimal() {
    char *ptr = input_buffer;
    int decimal = 0;
    int sign = 1;
    if (*ptr == '-') {
        sign = -1;
        ptr++;
    }
    while (*ptr!= '\0') {
        if (*ptr == '1') {
            decimal += sign;
        } else if (*ptr!= '0') {
            printf("Invalid binary number.\n");
            exit(1);
        }
        ptr++;
    }
    output_size = 1;
    while (decimal > 9) {
        output_size++;
        decimal /= 10;
    }
    output_size += 2; // Add sign and null terminator
    printf("Decimal number: %d\n", decimal);
}

void convert_decimal_to_binary() {
    int decimal = 0;
    int sign = 1;
    if (input_buffer[0] == '-') {
        sign = -1;
        input_buffer[0] = '1';
    }
    int i = strlen(input_buffer) - 1;
    while (i >= 0) {
        decimal += (input_buffer[i] - '0') * sign;
        sign *= 2;
        i--;
    }
    printf("Binary number: ");
    for (i = 0; i < strlen(input_buffer); i++) {
        printf("%d", decimal % 2);
        decimal /= 2;
    }
    printf("\n");
}

int main() {
    read_input();
    if (input_buffer[0] == '0') {
        printf("Decimal number: 0\n");
    } else {
        convert_binary_to_decimal();
    }
    printf("Do you want to convert the decimal number to binary? (y/n): ");
    char choice;
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y') {
        convert_decimal_to_binary();
    }
    return 0;
}