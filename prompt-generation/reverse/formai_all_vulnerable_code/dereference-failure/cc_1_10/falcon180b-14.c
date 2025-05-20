//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LENGTH 64

typedef struct {
    char* decimal;
    char* binary;
} Number;

Number* number_create(char* decimal) {
    Number* num = malloc(sizeof(Number));
    num->decimal = strdup(decimal);
    num->binary = NULL;
    return num;
}

void number_destroy(Number* num) {
    free(num->decimal);
    free(num->binary);
    free(num);
}

char* number_to_binary(Number* num) {
    char* binary = malloc(MAX_NUM_LENGTH * sizeof(char));
    sprintf(binary, "%d", atoi(num->decimal));
    return binary;
}

char* number_to_decimal(Number* num) {
    char* decimal = malloc(MAX_NUM_LENGTH * sizeof(char));
    sprintf(decimal, "%s", num->binary);
    return decimal;
}

int main() {
    char input[MAX_LINE_LENGTH];
    char* decimal = NULL;
    char* binary = NULL;
    Number* num = NULL;
    int state = 0;
    int i = 0;

    printf("Enter a decimal number: ");
    fgets(input, MAX_LINE_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    decimal = strdup(input);

    while (state!= 3) {
        switch (state) {
            case 0:
                num = number_create(decimal);
                binary = number_to_binary(num);
                printf("Binary: %s\n", binary);
                state++;
                break;
            case 1:
                num = number_create(binary);
                decimal = number_to_decimal(num);
                printf("Decimal: %s\n", decimal);
                state++;
                break;
            case 2:
                printf("Enter a number to convert (0 for decimal, 1 for binary): ");
                scanf("%d", &i);
                if (i == 0) {
                    num = number_create(decimal);
                    binary = number_to_binary(num);
                    printf("Binary: %s\n", binary);
                } else if (i == 1) {
                    num = number_create(binary);
                    decimal = number_to_decimal(num);
                    printf("Decimal: %s\n", decimal);
                }
                state++;
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid state\n");
        }
    }

    return 0;
}