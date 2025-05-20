#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void vulnerableFunction(char* input) {
    char buffer[16];
    printf("Enter your name: ");
    scanf("%s", buffer);
}

int main() {
    printf("Welcome to the Game Engine Debugger!\n");
    vulnerableFunction("This is a very long string that will cause a buffer overflow!");
    return 0;
}
