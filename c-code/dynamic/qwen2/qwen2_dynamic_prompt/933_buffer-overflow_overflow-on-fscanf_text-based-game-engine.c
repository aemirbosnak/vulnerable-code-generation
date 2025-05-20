#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void vulnerable_function() {
    char buffer[10];
    printf("Enter your name: ");
    fscanf(stdin, "%s", buffer);
}

int main() {
    printf("Welcome to the Game Engine!\n");
    vulnerable_function();
    printf("Hello, %s! Enjoy your game.\n", "Player");
    return 0;
}
