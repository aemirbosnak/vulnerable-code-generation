#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int ull;

void calculate(char **tokens, int count) {
    ull num1 = 0, num2 = 0, result = 0;
    char operation;

    for (int i = 0; i < count; ++i) {
        if (i % 2) {
            num2 = strtoull(tokens[i], NULL, 10);
            operation = tokens[++i][0];
        } else {
            num1 = strtoull(tokens[i], NULL, 10);
            switch (operation) {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/': result = num1 / num2; break;
                case '%': result = num1 % num2; break;
            }
        }
    }

    printf("%llu\n", result);
}

int main() {
    char *input[] = {"12345678901234567890", "1", "+", "98765432109876543210", "*", "2", "/", "3", "4", "%"};
    calculate(input, sizeof(input) / sizeof(input[0]));

    return 0;
}
