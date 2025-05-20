//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STR_LEN 100

void convertToHex(char* input_string);
void convertToInt(char* input_string);

int main(int argc, char** argv) {
    char input_string[MAX_STR_LEN];
    char input_type;

    printf("Enter the input string: ");
    fgets(input_string, MAX_STR_LEN, stdin);

    printf("Enter the input type (h or i): ");
    scanf("%c", &input_type);

    if (tolower(input_type) == 'h') {
        convertToInt(input_string);
    } else if (tolower(input_type) == 'i') {
        convertToHex(input_string);
    } else {
        printf("Invalid input type!\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void convertToHex(char* input_string) {
    int input_int = atoi(input_string);
    char hex_string[MAX_STR_LEN];

    sprintf(hex_string, "%X", input_int);
    printf("Hexadecimal equivalent: %s\n", hex_string);
}

void convertToInt(char* input_string) {
    long int input_hex = strtol(input_string, NULL, 16);

    if (input_hex == 0 && input_string[0] != '0') {
        printf("Invalid hexadecimal input!\n");
        exit(EXIT_FAILURE);
    }

    printf("Integer equivalent: %ld\n", input_hex);
}