#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[]) {
    char buffer[10];
    int num1, num2, result;

    printf("Enter a string (up to 10 characters): ");
    gets(buffer);

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    result = num1 + num2 * strlen(buffer);

    printf("Result: %d\n", result);
}
