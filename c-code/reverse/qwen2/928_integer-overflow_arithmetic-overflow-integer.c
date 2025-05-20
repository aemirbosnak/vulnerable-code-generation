#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int a, b, c, d, e;
    printf("Enter five integers: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    
    int result = a + b * c - d / e;
    printf("Result: %d\n", result);
    
    return 0;
}
