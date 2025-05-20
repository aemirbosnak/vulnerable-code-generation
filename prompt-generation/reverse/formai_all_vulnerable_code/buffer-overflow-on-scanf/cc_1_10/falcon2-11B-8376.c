//Falcon2-11B DATASET v1.0 Category: Bitwise operations ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int main(void) {
    srand(time(NULL)); // initialize random number generator
    char num1[10];
    char num2[10];
    char result[10];
    int i;

    // ask user for two numbers
    printf("Enter first number: ");
    scanf("%s", num1);
    printf("Enter second number: ");
    scanf("%s", num2);

    // convert input to integers and perform bitwise operations
    int n1 = atoi(num1);
    int n2 = atoi(num2);
    int result_int = n1 & n2;
    int result_bool = n1 && n2;
    int result_or = n1 | n2;
    int result_xor = n1 ^ n2;
    int result_not = ~n1;

    // print results
    printf("Bitwise AND: %d\n", result_int);
    printf("Logical AND: %d\n", result_bool);
    printf("OR: %d\n", result_or);
    printf("XOR: %d\n", result_xor);
    printf("NOT: %d\n", result_not);

    // convert integers to characters and print results
    sprintf(result, "%d", result_int);
    printf("Bitwise AND (%s): %s\n", num1, result);
    sprintf(result, "%d", result_bool);
    printf("Logical AND (%s, %s): %s\n", num1, num2, result);
    sprintf(result, "%d", result_or);
    printf("OR (%s, %s): %s\n", num1, num2, result);
    sprintf(result, "%d", result_xor);
    printf("XOR (%s, %s): %s\n", num1, num2, result);
    sprintf(result, "%d", result_not);
    printf("NOT (%s): %s\n", num1, result);

    return 0;
}