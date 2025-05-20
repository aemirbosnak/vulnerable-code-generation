#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void vulnerable_function() {
    char input[10];
    printf("Enter a string: ");
    fscanf(stdin, "%s", input); // Vulnerable to buffer overflow
}

int main() {
    vulnerable_function();
    return 0;
}
