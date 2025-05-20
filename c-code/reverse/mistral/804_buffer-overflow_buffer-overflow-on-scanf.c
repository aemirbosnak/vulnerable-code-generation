#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void game() {
    char player[10];
    printf("Welcome to the Simple Adventure Game!\n");
    printf("Enter your name (up to 9 characters): ");
    scanf("%s", player);

    // Vulnerable code with buffer overflow
    strcat(player, " is a brave adventurer!");
    printf("Hello, %s\n", player);
}

int main() {
    game();
    return 0;
}
