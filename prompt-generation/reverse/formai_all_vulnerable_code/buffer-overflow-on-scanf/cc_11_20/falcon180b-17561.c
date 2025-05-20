//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int length;
    int i;

    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    length = strlen(input);

    if (length > 2 && input[0] == '0' && input[1] == 'x') {
        for (i = 2; i < length; i++) {
            if (!isxdigit(input[i])) {
                printf("Invalid hexadecimal number.\n");
                return 1;
            }
        }
    } else if (length > 2 && input[0] == '0' && input[1] == 'b') {
        for (i = 2; i < length; i++) {
            if (!isdigit(input[i])) {
                printf("Invalid binary number.\n");
                return 1;
            }
        }
    } else if (length > 2 && input[0] == '0' && input[1] == 'd') {
        for (i = 2; i < length; i++) {
            if (!isdigit(input[i])) {
                printf("Invalid decimal number.\n");
                return 1;
            }
        }
    } else {
        printf("Invalid input.\n");
        return 1;
    }

    if (length == 1) {
        sprintf(output, "0%c", input[0]);
    } else {
        sprintf(output, "%s", input);
    }

    printf("Decimal: %d\n", atoi(output));
    printf("Hexadecimal: %s\n", output);
    printf("Binary: ");
    for (i = 0; i < strlen(output); i++) {
        if (output[i] == '0') {
            printf("0");
        } else if (output[i] == '1') {
            printf("1");
        } else {
            printf("Error: Invalid character.\n");
            return 1;
        }
    }

    printf("\n");

    return 0;
}