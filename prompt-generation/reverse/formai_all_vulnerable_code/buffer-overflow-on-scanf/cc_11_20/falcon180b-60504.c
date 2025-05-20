//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LEN 7

struct color_code {
    char code[MAX_CODE_LEN];
    int value;
};

int main() {
    int choice, num_codes;
    char input_code[MAX_CODE_LEN];
    struct color_code codes[10];
    int i;

    printf("Welcome to the Color Code Converter!\n");
    printf("Please enter the number of color codes you would like to convert: ");
    scanf("%d", &num_codes);

    // Initialize the color codes
    for (i = 0; i < num_codes; i++) {
        codes[i].value = -1;
    }

    // Get the color codes from the user
    for (i = 0; i < num_codes; i++) {
        printf("Enter color code %d: ", i+1);
        scanf("%s", input_code);

        // Convert the input code to uppercase
        for (int j = 0; j < strlen(input_code); j++) {
            input_code[j] = toupper(input_code[j]);
        }

        // Check if the input code is valid
        if (strlen(input_code)!= MAX_CODE_LEN) {
            printf("Invalid code length. Code must be exactly %d characters.\n", MAX_CODE_LEN);
            exit(1);
        }

        for (int j = 0; j < strlen(input_code); j++) {
            if (!isdigit(input_code[j]) && input_code[j]!= 'X') {
                printf("Invalid character in code: %c\n", input_code[j]);
                exit(1);
            }
        }

        // Convert the input code to decimal
        codes[i].value = 0;
        for (int j = 0; j < strlen(input_code); j++) {
            if (input_code[j] == 'X') {
                codes[i].value += 16;
            } else {
                codes[i].value += input_code[j] - '0';
            }
        }

        // Copy the input code to the struct
        strcpy(codes[i].code, input_code);
    }

    // Print the results
    printf("\nColor Code Conversions:\n");
    for (i = 0; i < num_codes; i++) {
        if (codes[i].value == -1) {
            continue;
        }

        printf("Code %d: %s = %d\n", i+1, codes[i].code, codes[i].value);
    }

    return 0;
}