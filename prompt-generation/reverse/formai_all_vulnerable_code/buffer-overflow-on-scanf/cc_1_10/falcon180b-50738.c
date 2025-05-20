//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

// Cryptic function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Cryptic function to reverse a string
void reverse_string(char* str, int length) {
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    // Cryptic input from user
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // Cryptic calculation of factorial using a loop
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    // Cryptic output of result
    printf("Factorial of %d is %d\n", n, result);

    // Cryptic input of a string from user
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    // Cryptic reversal of the string
    int length = strlen(str);
    reverse_string(str, length);

    // Cryptic output of the reversed string
    printf("Reversed string is: %s\n", str);

    return 0;
}