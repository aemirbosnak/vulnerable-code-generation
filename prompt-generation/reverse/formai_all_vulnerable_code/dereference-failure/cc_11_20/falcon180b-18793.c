//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int main() {
    char input[MAX_SIZE];
    char *output = NULL;
    int length = 0;
    int i, j;
    int upper = 0, lower = 0;
    int digit = 0;
    int special = 0;
    int space = 0;

    // Get input from user
    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);
    length = strlen(input);

    // Count number of uppercase, lowercase, digits, special characters and spaces
    for (i = 0; i < length; i++) {
        if (isupper(input[i])) {
            upper++;
        } else if (islower(input[i])) {
            lower++;
        } else if (isdigit(input[i])) {
            digit++;
        } else if (isalnum(input[i])) {
            special++;
        } else if (isspace(input[i])) {
            space++;
        }
    }

    // Remove spaces from input
    output = (char*)malloc(length - space + 1);
    i = 0;
    j = 0;
    while (i < length) {
        if (!isspace(input[i])) {
            output[j++] = input[i++];
        } else {
            i++;
        }
    }
    output[j] = '\0';

    // Convert all characters to lowercase
    for (i = 0; i < strlen(output); i++) {
        output[i] = tolower(output[i]);
    }

    // Reverse the string
    for (i = strlen(output) - 1; i >= 0; i--) {
        printf("%c", output[i]);
    }

    return 0;
}