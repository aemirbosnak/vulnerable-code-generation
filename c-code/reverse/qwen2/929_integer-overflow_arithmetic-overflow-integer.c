#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int ops[10][3], result = 0;
    char op;

    printf("Enter up to 10 arithmetic operations (e.g., 5 + 3): ");
    for(int i = 0; i < 10; i++) {
        if(scanf("%d %c %d", &ops[i][0], &op, &ops[i][2]) != 3) break;
        switch(op) {
            case '+': result += ops[i][0] + ops[i][2]; break;
            case '-': result -= ops[i][0] - ops[i][2]; break;
            case '*': result *= ops[i][0] * ops[i][2]; break;
            case '/': result /= ops[i][0] / ops[i][2]; break;
            default: continue;
        }
    }

    printf("Result: %d\n", result);
    return 0;
}
