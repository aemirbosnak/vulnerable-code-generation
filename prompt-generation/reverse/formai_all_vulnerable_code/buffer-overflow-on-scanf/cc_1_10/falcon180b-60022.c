//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    int value;
    char *hex;
    char *bin;
} Hexadecimal;

Hexadecimal hexadecimal_table[] = {
    {0, "0", "00000000"},
    {1, "1", "00000001"},
    {2, "2", "00000010"},
    {3, "3", "00000011"},
    {4, "4", "00000100"},
    {5, "5", "00000101"},
    {6, "6", "00000110"},
    {7, "7", "00000111"},
    {8, "8", "00001000"},
    {9, "9", "00001001"},
    {10, "A", "00001010"},
    {11, "B", "00001011"},
    {12, "C", "00001100"},
    {13, "D", "00001101"},
    {14, "E", "00001110"},
    {15, "F", "00001111"}
};

int main(int argc, char *argv[]) {
    int decimal, i, j, k;
    char input[100];
    char hexadecimal[100];
    char binary[100];

    printf("Please enter a decimal number: ");
    scanf("%s", input);

    decimal = atoi(input);

    if (decimal < 0 || decimal > 15) {
        printf("Invalid input. Please enter a decimal number between 0 and 15.\n");
        return 1;
    }

    for (i = 0; i < 16; i++) {
        if (hexadecimal_table[i].value == decimal) {
            strcpy(hexadecimal, hexadecimal_table[i].hex);
            break;
        }
    }

    printf("Hexadecimal representation: %s\n", hexadecimal);

    for (i = 0, j = strlen(hexadecimal) - 1; i < strlen(hexadecimal); i++, j--) {
        binary[i] = hexadecimal[j];
    }

    binary[i] = '\0';

    printf("Binary representation: %s\n", binary);

    return 0;
}