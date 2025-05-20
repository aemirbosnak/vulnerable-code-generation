#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void vulnerable_function(char *input) {
    char buffer[16];
    printf("Buffer address: %p\n", (void *)buffer);
    printf("Input address: %p\n", (void *)input);
    scanf("%s", buffer); // Vulnerable to buffer overflow
}

int main() {
    char input[24];
    printf("Enter data: ");
    scanf("%s", input);
    vulnerable_function(input);
    return 0;
}
