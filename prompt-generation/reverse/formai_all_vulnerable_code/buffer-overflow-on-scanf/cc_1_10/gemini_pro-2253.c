//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_CODE_LENGTH 100

int main() {
    // Define the color code table
    char *color_code_table[] = {
        "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white"
    };

    // Get the color code from the user
    char color_code[MAX_COLOR_CODE_LENGTH];
    printf("Enter the color code: ");
    scanf("%s", color_code);

    // Convert the color code to uppercase
    for (int i = 0; i < strlen(color_code); i++) {
        color_code[i] = toupper(color_code[i]);
    }

    // Validate the color code
    int valid = 1;
    for (int i = 0; i < strlen(color_code); i++) {
        int found = 0;
        for (int j = 0; j < 10; j++) {
            if (color_code[i] == *color_code_table[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            valid = 0;
            break;
        }
    }

    // Convert the color code to a numerical value
    int numerical_value = 0;
    for (int i = 0; i < strlen(color_code); i++) {
        for (int j = 0; j < 10; j++) {
            if (color_code[i] == *color_code_table[j]) {
                numerical_value += j * pow(10, strlen(color_code) - i - 1);
                break;
            }
        }
    }

    // Print the numerical value
    if (valid) {
        printf("The numerical value of the color code is: %d\n", numerical_value);
    } else {
        printf("Invalid color code\n");
    }

    return 0;
}