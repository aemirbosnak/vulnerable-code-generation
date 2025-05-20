//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hexadecimal string to an integer
int64_t hex_to_int(const char *hex)
{
    int64_t result = 0;
    int64_t base = 1;
    size_t length = strlen(hex);

    for (size_t i = length - 1; i >= 0; i--) {
        int64_t digit = 0;
        switch (hex[i]) {
            case '0':
                digit = 0;
                break;
            case '1':
                digit = 1;
                break;
            case '2':
                digit = 2;
                break;
            case '3':
                digit = 3;
                break;
            case '4':
                digit = 4;
                break;
            case '5':
                digit = 5;
                break;
            case '6':
                digit = 6;
                break;
            case '7':
                digit = 7;
                break;
            case '8':
                digit = 8;
                break;
            case '9':
                digit = 9;
                break;
            case 'a':
            case 'A':
                digit = 10;
                break;
            case 'b':
            case 'B':
                digit = 11;
                break;
            case 'c':
            case 'C':
                digit = 12;
                break;
            case 'd':
            case 'D':
                digit = 13;
                break;
            case 'e':
            case 'E':
                digit = 14;
                break;
            case 'f':
            case 'F':
                digit = 15;
                break;
            default:
                return -1;
        }
        result += digit * base;
        base *= 16;
    }
    return result;
}

// Function to convert an integer to a hexadecimal string
char *int_to_hex(int64_t number)
{
    char *result = malloc(sizeof(char) * 65);
    int64_t quotient = number;
    int64_t remainder = 0;
    int64_t index = 0;

    while (quotient != 0) {
        remainder = quotient % 16;
        switch (remainder) {
            case 0:
                result[index++] = '0';
                break;
            case 1:
                result[index++] = '1';
                break;
            case 2:
                result[index++] = '2';
                break;
            case 3:
                result[index++] = '3';
                break;
            case 4:
                result[index++] = '4';
                break;
            case 5:
                result[index++] = '5';
                break;
            case 6:
                result[index++] = '6';
                break;
            case 7:
                result[index++] = '7';
                break;
            case 8:
                result[index++] = '8';
                break;
            case 9:
                result[index++] = '9';
                break;
            case 10:
                result[index++] = 'a';
                break;
            case 11:
                result[index++] = 'b';
                break;
            case 12:
                result[index++] = 'c';
                break;
            case 13:
                result[index++] = 'd';
                break;
            case 14:
                result[index++] = 'e';
                break;
            case 15:
                result[index++] = 'f';
                break;
        }
        quotient /= 16;
    }
    result[index] = '\0';
    
    // Reverse the string
    char *start = result;
    char *end = result + strlen(result) - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    return result;
}

int main()
{
    char *hex = "FF";
    int64_t number = hex_to_int(hex);
    printf("%s -> %lld\n", hex, number);

    int64_t number2 = 255;
    char *hex2 = int_to_hex(number2);
    printf("%lld -> %s\n", number2, hex2);

    free(hex2);

    return 0;
}