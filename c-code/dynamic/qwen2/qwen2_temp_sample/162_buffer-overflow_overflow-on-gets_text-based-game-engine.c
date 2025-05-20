#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void win() {
    printf("Congratulations! You have won the game!\n");
}

int main() {
    char buffer[16];
    printf("Welcome to the Game Engine Test Tool\n");
    printf("Enter your name: ");
    gets(buffer);
    printf("Hello, %s!\n", buffer);
    if (strcmp(buffer, "admin") == 0) {
        win();
    }
    return 0;
}
