#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 16

void vulnerable_function(char *input) {
    char buffer[BUFFER_SIZE];
    printf("Input: %s\n", input);
    strcpy(buffer, input); // Vulnerable to buffer overflow
}

int main() {
    char user_input[256];
    printf("Enter data: ");
    scanf("%255s", user_input); // Safe read up to 255 characters
    vulnerable_function(user_input);
    return 0;
}
