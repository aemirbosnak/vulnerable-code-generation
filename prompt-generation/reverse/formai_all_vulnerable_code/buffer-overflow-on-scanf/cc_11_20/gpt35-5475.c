//FormAI DATASET v1.0 Category: Bitwise operations ; Style: artistic
//The following program performs bitwise operations on two hexadecimal numbers.

#include <stdio.h>

//Function to convert hexadecimal to binary
long int hex_to_bin(char hex[])
{
    long int bin = 0;
    int i = 0;

    while (hex[i])
    {
        switch (hex[i])
        {
            case '0':
                bin = bin * 16 + 0;
                break;
            case '1':
                bin = bin * 16 + 1;
                break;
            case '2':
                bin = bin * 16 + 2;
                break;
            case '3':
                bin = bin * 16 + 3;
                break;
            case '4':
                bin = bin * 16 + 4;
                break;
            case '5':
                bin = bin * 16 + 5;
                break;
            case '6':
                bin = bin * 16 + 6;
                break;
            case '7':
                bin = bin * 16 + 7;
                break;
            case '8':
                bin = bin * 16 + 8;
                break;
            case '9':
                bin = bin * 16 + 9;
                break;
            case 'A':
            case 'a':
                bin = bin * 16 + 10;
                break;
            case 'B':
            case 'b':
                bin = bin * 16 + 11;
                break;
            case 'C':
            case 'c':
                bin = bin * 16 + 12;
                break;
            case 'D':
            case 'd':
                bin = bin * 16 + 13;
                break;
            case 'E':
            case 'e':
                bin = bin * 16 + 14;
                break;
            case 'F':
            case 'f':
                bin = bin * 16 + 15;
                break;
            default:
                printf("Invalid hexadecimal digit %c", hex[i]);
        }
        i++;
    }
    return bin;
}

int main()
{
    char hex1[20];
    char hex2[20];

    printf("Enter the first hexadecimal number: ");
    scanf("%s", hex1);

    printf("Enter the second hexadecimal number: ");
    scanf("%s", hex2);

    //Convert hexadecimal to binary
    long int num1 = hex_to_bin(hex1);
    long int num2 = hex_to_bin(hex2);

    printf("\nThe bitwise AND operation: %lX & %lX = %lX", num1, num2, num1 & num2);
    printf("\nThe bitwise OR operation: %lX | %lX = %lX", num1, num2, num1 | num2);
    printf("\nThe bitwise XOR operation: %lX ^ %lX = %lX", num1, num2, num1 ^ num2);
    printf("\nThe bitwise NOT operation: ~%lX = %lX", num1, ~num1);
    printf("\nThe left shift operation: %lX << 3 = %lX", num1, num1 << 3);
    printf("\nThe right shift operation: %lX >> 3 = %lX", num2, num2 >> 3);

    return 0;
}