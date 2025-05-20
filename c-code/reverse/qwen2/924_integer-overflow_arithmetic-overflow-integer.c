#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <limits.h>

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    if (a > INT_MAX - b) {
        printf("Integer overflow detected!\n");
    } else {
        int result = a + b;
        printf("Result: %d\n", result);
    }

    return 0;
}
