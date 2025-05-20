#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char name[10];
    printf("Welcome to the Treasure Hunt Game!\n");
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! You are on a quest to find the treasure.\n", name);
    printf("Move north (N), south (S), east (E), or west (W): ");
    char direction;
    scanf(" %c", &direction);
    if (direction == 'N') {
        printf("You found a treasure chest!\n");
    } else {
        printf("You encountered a monster and lost the game!\n");
    }
    return 0;
}
