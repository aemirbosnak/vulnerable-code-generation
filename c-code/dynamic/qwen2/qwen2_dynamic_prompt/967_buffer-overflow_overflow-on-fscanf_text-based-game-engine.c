#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void vulnerable_function() {
    char buffer[16];
    printf("Enter your name: ");
    fscanf(stdin, "%s", buffer); // Vulnerable to buffer overflow
}

int main() {
    printf("Welcome to the Game Engine!\n");
    vulnerable_function();
    printf("Game Over.\n");
    return 0;
}
