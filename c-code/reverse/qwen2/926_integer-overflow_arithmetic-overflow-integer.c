#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    int result = a + b;
    if (result < a) {
        printf("Integer overflow occurred!\n");
    } else {
        printf("Result: %d\n", result);
    }
    return 0;
}
