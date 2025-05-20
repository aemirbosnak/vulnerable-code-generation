#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void vulnerable_function(char *input) {
    char buffer[16];
    printf("Input: %s\n", input);
    strcpy(buffer, input); // Vulnerable to buffer overflow
}

int main() {
    char user_input[256];
    printf("Welcome to the Text-Based Game Engine!\n");
    printf("Enter your command: ");
    scanf("%255s", user_input); // Safe read up to 255 characters
    vulnerable_function(user_input);
    return 0;
}
