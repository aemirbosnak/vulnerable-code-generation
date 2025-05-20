//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    char input[100];
    char output[100];
    int i = 0;
    int j = 0;

    printf("Enter the color code: ");
    scanf("%s", input);

    // Check if input is valid color code
    if (strlen(input)!= 6 || input[0]!= '#') {
        printf("Invalid color code\n");
        return 0;
    }

    // Convert input color code to RGB values
    for (i = 1; i < strlen(input); i++) {
        if (isxdigit(input[i])) {
            if (isupper(input[i])) {
                output[j] = input[i] - 55;
            } else {
                output[j] = input[i] - 48;
            }
            j++;
        } else {
            printf("Invalid color code\n");
            return 0;
        }
    }

    // Convert RGB values to hexadecimal color code
    output[j] = '\0';
    for (i = 0; i < j; i++) {
        if (output[i] > 9) {
            output[i] += 7;
        }
    }
    output[j] = '\0';

    // Print the converted hexadecimal color code
    printf("The hexadecimal color code is: %s\n", output);

    return 0;
}