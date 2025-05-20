//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000

int main(int argc, char *argv[]) {
    char input_string[MAX_CHARS];
    char output_string[MAX_CHARS];
    int i = 0;
    int j = 0;
    int string_length = 0;
    int hex_value = 0;
    int is_hex = 0;
    int is_valid_input = 1;
    int is_valid_hex = 1;
    int is_valid_string = 1;
    int is_valid_output = 1;

    printf("Enter a string to convert to hexadecimal: ");
    fgets(input_string, MAX_CHARS, stdin);
    string_length = strlen(input_string);

    // Remove newline character from input
    input_string[string_length - 1] = '\0';

    for (i = 0; i < string_length; i++) {
        if (isalpha(input_string[i])) {
            is_hex = 0;
            break;
        } else if (isdigit(input_string[i])) {
            is_hex = 1;
        }
    }

    if (is_hex) {
        printf("Enter a hexadecimal string to convert to ASCII: ");
        fgets(input_string, MAX_CHARS, stdin);
        string_length = strlen(input_string);

        // Remove newline character from input
        input_string[string_length - 1] = '\0';

        for (i = 0; i < string_length; i++) {
            if (!isxdigit(input_string[i])) {
                is_valid_hex = 0;
                break;
            }
        }

        if (is_valid_hex) {
            for (i = 0; i < string_length; i += 2) {
                sscanf(input_string + i, "%2x", &hex_value);
                output_string[j++] = hex_value;
            }

            printf("The ASCII string is: %s\n", output_string);
        } else {
            printf("Invalid hexadecimal string.\n");
        }
    } else {
        for (i = 0; i < string_length; i++) {
            if (!isprint(input_string[i])) {
                is_valid_input = 0;
                break;
            }
        }

        if (is_valid_input) {
            for (i = 0; i < string_length; i++) {
                sprintf(&output_string[j], "%c", input_string[i]);
                j++;
            }

            printf("The hexadecimal string is: %s\n", output_string);
        } else {
            printf("Invalid input string.\n");
        }
    }

    return 0;
}