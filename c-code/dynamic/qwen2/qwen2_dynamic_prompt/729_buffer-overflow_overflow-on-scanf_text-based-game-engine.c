#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[16];
    printf("Input: ");
    scanf("%s", buffer);
    printf("Buffer: %s\n", buffer);
}

int main() {
    char input[32];
    printf("Enter your name: ");
    fgets(input, sizeof(input), stdin);
    vulnerable_function(input);
    return 0;
}
