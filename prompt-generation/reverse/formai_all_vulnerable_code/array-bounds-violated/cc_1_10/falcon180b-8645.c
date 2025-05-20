//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_OUTPUT_LENGTH 200

int main() {
    char input[MAX_INPUT_LENGTH] = {0};
    char output[MAX_OUTPUT_LENGTH] = {0};
    int length = 0;
    int i = 0;
    int j = 0;
    int num = 0;
    int base = 0;

    printf("Enter a hexadecimal number: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    length = strlen(input);

    // Remove any leading or trailing white spaces from the input
    while ((i < length) && isspace(input[i])) {
        i++;
    }
    while ((j < length) && isspace(input[j])) {
        j--;
        input[j] = '\0';
    }

    base = 16;
    for (i = 0; i < length; i++) {
        if (isdigit(input[i])) {
            num = input[i] - '0';
        } else if (isalpha(input[i])) {
            if (isupper(input[i])) {
                num = input[i] - 'A' + 10;
            } else {
                num = input[i] - 'a' + 10;
            }
        } else {
            printf("Invalid character found in input.\n");
            exit(1);
        }
        sprintf(&output[j], "%02X", num);
        j += 2;
    }

    printf("Decimal equivalent: %s\n", output);
    printf("Binary equivalent: ");
    for (i = 0; i < j; i += 2) {
        printf("%c", output[i]);
    }
    printf("\n");

    return 0;
}