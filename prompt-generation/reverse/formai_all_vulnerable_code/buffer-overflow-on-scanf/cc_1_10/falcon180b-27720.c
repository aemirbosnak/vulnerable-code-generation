//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Alan Turing
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000000

char binary[MAX_SIZE];
int decimal = 0;
int binary_index = 0;

void convert_decimal_to_binary(int num) {
    if (num == 0) {
        binary[binary_index] = '0';
        binary_index++;
        return;
    }

    int remainder;
    while (num > 0) {
        remainder = num % 2;
        binary[binary_index] = remainder + '0';
        binary_index++;
        num /= 2;
    }
}

int main() {
    char input[MAX_SIZE];
    printf("Enter a decimal number: ");
    scanf("%s", input);

    int input_size = strlen(input);
    if (input_size == 0) {
        printf("Invalid input\n");
        return 1;
    }

    for (int i = 0; i < input_size; i++) {
        if (input[i] < '0' || input[i] > '9') {
            printf("Invalid input\n");
            return 1;
        }
    }

    int num = atoi(input);
    if (num == 0) {
        binary[binary_index] = '0';
        binary_index++;
    } else {
        convert_decimal_to_binary(num);
    }

    printf("Binary representation: ");
    for (int i = binary_index - 1; i >= 0; i--) {
        printf("%c", binary[i]);
    }
    printf("\n");

    return 0;
}