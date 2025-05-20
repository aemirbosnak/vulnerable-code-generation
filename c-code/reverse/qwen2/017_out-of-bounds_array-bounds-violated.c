#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[64];
    strcpy(buffer, input);
}

int main() {
    char input[256];
    printf("Enter a command: ");
    fgets(input, sizeof(input), stdin);
    vulnerable_function(input);
    return 0;
}
