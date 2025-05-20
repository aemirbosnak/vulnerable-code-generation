//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char input[100], hex[200], *p;
    int i, j, len, digit;

    // Check if the user entered a string
    if (argc < 2) {
        printf("Error: Please enter a string to convert!\n");
        exit(1);
    }

    // Copy the string to input
    strcpy(input, argv[1]);

    // Remove any leading or trailing white spaces
    len = strlen(input);
    if (len > 0 && isspace(input[0])) {
        for (i = 0; i < len; i++) {
            if (!isspace(input[i])) {
                strcpy(input, &input[i]);
                break;
            }
        }
    }
    if (len > 0 && isspace(input[len - 1])) {
        input[len - 1] = '\0';
    }

    // Convert the string to hexadecimal
    p = hex;
    for (i = 0; i < len; i++) {
        digit = tolower(input[i]) - 'a';
        if (digit < 0 || digit > 9) {
            printf("Error: Invalid character '%c'!\n", input[i]);
            exit(1);
        }
        *p++ = '0' + digit;
    }
    *p = '\0';

    // Print the hexadecimal string
    printf("The hexadecimal representation of '%s' is:\n", input);
    printf("0x%s\n", hex);

    return 0;
}