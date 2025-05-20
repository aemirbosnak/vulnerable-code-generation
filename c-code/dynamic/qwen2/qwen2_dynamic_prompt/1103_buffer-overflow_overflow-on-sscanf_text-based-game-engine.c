#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void vulnerable_function(char *input) {
    char buffer[16];
    printf("Input: %s\n", input);
    sscanf(input, "%15s", buffer); // Vulnerable line
    printf("Buffer: %s\n", buffer);
}

int main() {
    char input[32];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    vulnerable_function(input);
    return 0;
}
