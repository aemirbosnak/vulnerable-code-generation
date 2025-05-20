#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void vulnerable_function() {
    char buffer[16];
    printf("Enter your name: ");
    gets(buffer); // Vulnerable to buffer overflow
}

int main() {
    printf("Welcome to the Game Engine Debugger!\n");
    vulnerable_function();
    printf("Debugging session complete.\n");
    return 0;
}
