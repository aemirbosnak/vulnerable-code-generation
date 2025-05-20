#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_input(char *buf) {
    char player[10];
    int level;

    printf("Enter your character's name: ");
    scanf("%s", player);
    printf("Enter your character's level: ");
    sscanf(buf, " %*s %n %*c %d", (int *) &level);

    printf("Welcome, %s, to the Game of Danger!\n", player);
    printf("You are level %d. Good luck!\n", level);

    // game loop
    int i;
    for (i = 0; i < level * 10; ++i) {
        printf("You fought a monster and... \n");
        if (i % 3 == 0) {
            printf("Gained an experience point.\n");
        } else {
            printf("Died... Game Over.\n");
            return;
        }
    }
    printf("Congratulations! You've beaten the game.\n");
}

int main(int argc, char *argv[]) {
    char input[1024];

    printf("Text-based Game Engine\n");
    fgets(input, 1024, stdin);
    process_input(input);

    return 0;
}
