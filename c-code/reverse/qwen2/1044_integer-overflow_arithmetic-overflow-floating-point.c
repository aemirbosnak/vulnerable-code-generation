#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int n = 1000;
    float sum = 0.0f;

    for (int i = 0; i <= n; i++) { // Vulnerable to integer overflow if n is too large
        sum += i * 1.5f;
    }

    printf("Sum: %f\n", sum);

    return 0;
}
