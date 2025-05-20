#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char input[10];
    printf("Enter a unit: ");
    scanf("%9s", input); // Vulnerable to buffer overflow
    printf("You entered: %s\n", input);
    return 0;
}
