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
    printf("Welcome to the Text-Based Game Engine!\n");
    printf("Enter your command: ");
    char command[256];
    scanf("%s", command); // Vulnerable to buffer overflow
    vulnerable_function(command);
    printf("Command executed successfully.\n");
    return 0;
}
