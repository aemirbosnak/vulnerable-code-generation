//Falcon2-11B DATASET v1.0 Category: Procedural Space Adventure ; Style: Ada Lovelace
// Ada Lovelace's Procedural Space Adventure
#include <stdio.h>
#include <stdlib.h>

int main() {
    char command[100];
    int x, y, z;

    printf("Welcome to Ada's Space Adventure!\n");
    printf("Please enter a command:\n");
    fgets(command, sizeof(command), stdin);

    sscanf(command, "%d %d %d", &x, &y, &z);

    if (command[0] == 'w') {
        if (x > 0) {
            printf("You moved west!\n");
            x--;
        } else {
            printf("You can't move west!\n");
        }
    } else if (command[0] == 'a') {
        if (y > 0) {
            printf("You moved north!\n");
            y--;
        } else {
            printf("You can't move north!\n");
        }
    } else if (command[0] =='s') {
        if (x < 100) {
            printf("You moved east!\n");
            x++;
        } else {
            printf("You can't move east!\n");
        }
    } else if (command[0] == 'd') {
        if (y < 100) {
            printf("You moved south!\n");
            y++;
        } else {
            printf("You can't move south!\n");
        }
    } else {
        printf("Unknown command!\n");
    }

    printf("Here's your current location:\n");
    printf("X: %d\n", x);
    printf("Y: %d\n", y);
    printf("Z: %d\n", z);

    return 0;
}