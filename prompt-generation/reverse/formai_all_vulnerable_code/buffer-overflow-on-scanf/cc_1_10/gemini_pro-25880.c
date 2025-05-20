//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char **argv) {
    // Declare variables.
    int n, i, j, k;
    float a, b, c;
    char str[100];

    // Get input from the user.
    printf("Enter an integer: ");
    scanf("%d", &n);
    printf("Enter a float: ");
    scanf("%f", &a);
    printf("Enter a character: ");
    scanf(" %c", &c);
    printf("Enter a string: ");
    scanf("%s", str);

    // Perform arithmetic operations.
    i = n + 5;
    j = n - 3;
    k = n * 7;
    b = a * 2.5;
    c = a / 3.2;

    // Print the results.
    printf("The sum of n and 5 is: %d\n", i);
    printf("The difference of n and 3 is: %d\n", j);
    printf("The product of n and 7 is: %d\n", k);
    printf("The product of a and 2.5 is: %f\n", b);
    printf("The quotient of a and 3.2 is: %f\n", c);

    // Check if the string is a palindrome.
    int len = strlen(str);
    int is_palindrome = 1;
    for (i = 0, j = len - 1; i < len / 2; i++, j--) {
        if (str[i] != str[j]) {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}