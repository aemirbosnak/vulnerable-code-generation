//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function to check if a string is a valid integer
int isInteger(char* str) {
    int i = 0;
    while (str[i]!= '\0') {
        if (!isdigit(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to convert a string to an integer
int strToInt(char* str) {
    int num = 0;
    int i = 0;
    while (str[i]!= '\0') {
        num = num * 10 + str[i] - '0';
        i++;
    }
    return num;
}

// Function to perform bitwise operations
void bitwise(int num1, int num2, char op) {
    int result;
    switch (op) {
        case '&':
            result = num1 & num2;
            break;
        case '|':
            result = num1 | num2;
            break;
        case '^':
            result = num1 ^ num2;
            break;
        case '~':
            result = ~num1;
            break;
        case '<<':
            result = num1 << num2;
            break;
        case '>>':
            result = num1 >> num2;
            break;
        default:
            printf("Invalid operation\n");
            return;
    }
    printf("Result: %d\n", result);
}

int main() {
    char str1[MAX_SIZE];
    char str2[MAX_SIZE];
    char op;

    printf("Enter first integer: ");
    scanf("%s", str1);
    if (!isInteger(str1)) {
        printf("Invalid input\n");
        return 1;
    }
    int num1 = strToInt(str1);

    printf("Enter second integer: ");
    scanf("%s", str2);
    if (!isInteger(str2)) {
        printf("Invalid input\n");
        return 1;
    }
    int num2 = strToInt(str2);

    printf("Enter operation (+, -, *, /, b (bitwise)): ");
    scanf(" %c", &op);
    if (op == 'b') {
        printf("Enter bitwise operation (&, |, ^, ~, <<, >>): ");
        scanf(" %c", &op);
        bitwise(num1, num2, op);
    } else {
        printf("Invalid operation\n");
    }

    return 0;
}