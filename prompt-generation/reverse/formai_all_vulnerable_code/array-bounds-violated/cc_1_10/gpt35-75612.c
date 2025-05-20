//FormAI DATASET v1.0 Category: Data validation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a valid integer
int isInteger(char *str) {
    int len = strlen(str);
    if (len == 0 || (len == 1 && !isdigit(str[0]))) {
        return 0;
    }

    int i = 0;
    if (str[i] == '+' || str[i] == '-') {
        i++;
    }

    for (; i < len; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }

    return 1;
}

// Function to check if a string is a valid float
int isFloat(char *str) {
    int len = strlen(str);
    if (len == 0 || (len == 1 && !isdigit(str[0]))) {
        return 0;
    }

    int i = 0;
    if (str[i] == '+' || str[i] == '-') {
        i++;
    }

    int dotCount = 0;
    for (; i < len; i++) {
        if (str[i] == '.') {
            dotCount++;
            if (dotCount > 1) {
                return 0;
            }
        } else if (!isdigit(str[i])) {
            return 0;
        }
    }

    return 1;
}

// Function to check if a string is a valid hex number
int isHex(char *str) {
    int len = strlen(str);
    if (len == 0 || (len == 1 && str[0] != '0')) {
        return 0;
    }

    int i = 0;
    if (str[i] == '-') {
        i++;
    }

    if (len > i + 2) {
        if (str[i] == '0' && (str[i+1] == 'x' || str[i+1] == 'X')) {
            i += 2;
        } else {
            return 0;
        }
    }

    for (; i < len; i++) {
        if (!isxdigit(str[i])) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char input[100];
    printf("Enter an integer: ");
    fgets(input, 100, stdin);
    input[strlen(input) - 1] = '\0';

    while (!isInteger(input)) {
        printf("Invalid input, please enter an integer: ");
        fgets(input, 100, stdin);
        input[strlen(input) - 1] = '\0';
    }

    int num = atoi(input);
    printf("You entered %d\n", num);

    printf("Enter a float: ");
    fgets(input, 100, stdin);
    input[strlen(input) - 1] = '\0';

    while (!isFloat(input)) {
        printf("Invalid input, please enter a float: ");
        fgets(input, 100, stdin);
        input[strlen(input) - 1] = '\0';
    }

    float f = atof(input);
    printf("You entered %f\n", f);

    printf("Enter a hex number: ");
    fgets(input, 100, stdin);
    input[strlen(input) - 1] = '\0';

    while (!isHex(input)) {
        printf("Invalid input, please enter a hex number: ");
        fgets(input, 100, stdin);
        input[strlen(input) - 1] = '\0';
    }

    int hex = strtol(input, NULL, 16);
    printf("You entered %#x\n", hex);

    return 0;
}