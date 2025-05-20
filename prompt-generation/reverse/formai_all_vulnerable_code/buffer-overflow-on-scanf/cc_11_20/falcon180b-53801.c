//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEX_LENGTH 9

int main(int argc, char **argv) {
    char input[MAX_HEX_LENGTH + 1];
    char output[MAX_HEX_LENGTH + 1];
    int i, j;
    int is_hex = 0;
    int is_upper_case = 0;
    int is_lower_case = 0;

    printf("Cyberpunk C Hexadecimal Converter\n");
    printf("-----------------------------------\n");

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    for (i = 0; i < strlen(input); i++) {
        if (!isxdigit(input[i])) {
            printf("Error: Invalid hexadecimal number\n");
            return 1;
        }
    }

    if (strlen(input) == 0) {
        printf("Error: Empty input\n");
        return 1;
    }

    if (strlen(input) > MAX_HEX_LENGTH) {
        printf("Error: Input too long\n");
        return 1;
    }

    for (i = 0; i < strlen(input); i++) {
        if (isupper(input[i])) {
            is_upper_case = 1;
        } else if (islower(input[i])) {
            is_lower_case = 1;
        } else if (isdigit(input[i])) {
            is_hex = 1;
        }
    }

    if (!is_hex) {
        printf("Error: Invalid hexadecimal number\n");
        return 1;
    }

    for (i = 0, j = 0; i < strlen(input); i++) {
        if (isupper(input[i])) {
            output[j] = input[i];
            j++;
        } else if (islower(input[i])) {
            output[j] = toupper(input[i]);
            j++;
        } else if (isdigit(input[i])) {
            output[j] = input[i];
            j++;
        }
    }

    printf("Hexadecimal number: %s\n", output);

    return 0;
}