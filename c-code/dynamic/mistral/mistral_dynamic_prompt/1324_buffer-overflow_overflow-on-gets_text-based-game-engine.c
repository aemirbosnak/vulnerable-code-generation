#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void greet(char *name) {
    printf("Hello, %s! Welcome to the Hidden Realms.\n", name);
}

void level1(char *input) {
    char room[256];
    strcpy(room, "You are in the quiet and dark hall. To your left, you see a door. What do you do?");
    printf("%s\n", room);

    gets(input);

    if (strstr(input, "left") || strstr(input, "go left"))
        printf("You open the door and find yourself in a magical forest.\n");
    else
        printf("The room grows darker and darker... You're lost.\n");
}

int main() {
    char player[256];
    printf("Enter your hero's name: ");
    gets(player);

    greet(player);
    level1(player);

    return 0;
}
