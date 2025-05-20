//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main(int argc, char *argv[]) {
    char input[MAX_SIZE];
    char *output;
    int i, j, len;
    int hex;

    printf("Enter the decimal number: ");
    scanf("%s", input);

    len = strlen(input);

    if (len == 0) {
        printf("Invalid input\n");
        return 1;
    }

    for (i = 0; i < len; i++) {
        if (!isdigit(input[i])) {
            printf("Invalid input\n");
            return 1;
        }
    }

    output = malloc(MAX_SIZE);

    hex = 0;
    for (i = 0; i < len; i++) {
        hex = hex * 16 + input[i] - '0';
    }

    for (i = 0, j = 0; i < len + 1; i++) {
        if (i == 0) {
            output[j] = '0';
            output[j + 1] = 'x';
            j += 2;
        }
        else if (hex == 0) {
            output[j] = '0';
            j++;
        }
        else {
            output[j] = hex % 16 + '0';
            if (output[j] > '9') {
                output[j] += 7;
            }
            j++;
            hex /= 16;
        }
    }

    printf("Hexadecimal number: %s\n", output);

    return 0;
}