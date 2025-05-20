#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 10
#define MAX_LEVEL 10

typedef struct Player {
    char name[MAX_NAME_LENGTH];
    int level;
} Player;

int main() {
    Player player;
    char input[100];

    printf("Welcome to Level Overflow! Enter your name (up to 10 characters):\n");
    fgets(player.name, MAX_NAME_LENGTH, stdin);
    sscanf(player.name, "%99s", &input); // overflow occurs here

    printf("Hello, %s! You are now on level %d.\n", player.name, 1);

    while (player.level < MAX_LEVEL) {
        printf("Enter level: ");
        scanf("%d", &player.level);
        printf("Congratulations, you leveled up to level %d!\n", player.level);
    }

    printf("Game Over! You have reached the max level %d. Thank you for playing.\n", MAX_LEVEL);

    return 0;
}
