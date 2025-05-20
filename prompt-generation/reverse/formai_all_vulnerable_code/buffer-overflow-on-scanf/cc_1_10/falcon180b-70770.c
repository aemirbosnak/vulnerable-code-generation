//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1024

void shift_shape(char *str, int shift) {
    int i = 0;
    while (str[i]!= '\0') {
        if (isdigit(str[i])) {
            str[i] = str[i] + shift;
            if (str[i] > '9') {
                str[i] = str[i] - 7;
            }
        } else if (isupper(str[i])) {
            str[i] = str[i] + shift;
            if (str[i] > 'Z') {
                str[i] = str[i] - 6;
            }
        } else {
            str[i] = str[i] + shift;
            if (str[i] > 'z') {
                str[i] = str[i] - 7;
            }
        }
        i++;
    }
}

int main() {
    char input[MAX_SIZE];
    char output[MAX_SIZE];
    int choice, shift;

    printf("Welcome to the Shape Shifting Hexadecimal Converter!\n");
    printf("Please enter a hexadecimal number to convert: ");
    fgets(input, MAX_SIZE, stdin);

    printf("Please choose a shift:\n");
    printf("1. Shift left\n");
    printf("2. Shift right\n");
    scanf("%d", &choice);

    if (choice == 1) {
        shift = -1;
    } else {
        shift = 1;
    }

    shift_shape(input, shift);

    printf("The shifted hexadecimal number is: %s\n", input);

    return 0;
}