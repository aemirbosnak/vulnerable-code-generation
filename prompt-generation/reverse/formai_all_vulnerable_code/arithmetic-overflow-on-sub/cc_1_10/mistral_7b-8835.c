//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: Alan Turing
#include <stdio.h>

#define BINARY_SIZE 1000

char celsius_binary[BINARY_SIZE];
char fahrenheit_binary[BINARY_SIZE];

void print_binary(char binary[]) {
    int i;
    for (i = BINARY_SIZE - 1; i >= 0; i--) {
        if ((i % 8) == 0 && i != 0)
            printf(" ");
        printf("%c", binary[i] + '0');
    }
    printf("\n");
}

void decimal_to_binary(int decimal, char binary[]) {
    int i = 0, bit;

    for (; decimal != 0; decimal /= 2, i++) {
        bit = decimal % 2;
        binary[i] = bit + '0';
    }
}

void celsius_to_fahrenheit(int celsius) {
    int fahrenheit = (celsius * 9 / 5) + 32;
    decimal_to_binary(fahrenheit, fahrenheit_binary);
}

void fahrenheit_to_celsius(int fahrenheit) {
    int celsius = (fahrenheit - 32) * 5 / 9;
    decimal_to_binary(celsius, celsius_binary);
}

int main() {
    int celsius, fahrenheit;
    char op;

    printf("Welcome to the Temperature Converter!\n");
    printf("Enter C for Celsius to Fahrenheit or F for Fahrenheit to Celsius: ");
    scanf("%c", &op);

    printf("Enter temperature in degree: ");
    scanf("%d", &celsius);

    if (op == 'C' || op == 'c') {
        celsius_to_fahrenheit(celsius);
        printf("Fahrenheit in binary:\n");
        print_binary(fahrenheit_binary);
        fahrenheit_to_celsius(atoi(fahrenheit_binary));
        printf("Celsius in binary:\n");
        print_binary(celsius_binary);
    } else if (op == 'F' || op == 'f') {
        fahrenheit_to_celsius(celsius);
        printf("Celsius in binary:\n");
        print_binary(celsius_binary);
        celsius_to_fahrenheit(atoi(celsius_binary));
        printf("Fahrenheit in binary:\n");
        print_binary(fahrenheit_binary);
    } else {
        printf("Invalid option. Exiting...\n");
        return 1;
    }

    return 0;
}