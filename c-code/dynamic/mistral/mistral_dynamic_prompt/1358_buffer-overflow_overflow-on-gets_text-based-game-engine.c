#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 32

void greet_player(char name[MAX_NAME_LENGTH]) {
    printf("Welcome, %s, to the Ultimate Quest!\n", name);
}

int main() {
    char player_name[MAX_NAME_LENGTH];
    printf("What is your hero's name? (Up to %d characters)\n", MAX_NAME_LENGTH);
    gets(player_name);
    greet_player(player_name);

    // Add more functions, game logic, etc. here

    return 0;
}
