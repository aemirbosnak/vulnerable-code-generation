#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[16];
    strcpy(buffer, input);
}

int main() {
    char user_input[256];
    printf("Enter your name: ");
    gets(user_input); // Vulnerable to buffer overflow
    vulnerable_function(user_input);
    return 0;
}
