//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char choice[100];
    char name[100];
    char inventory[100];
    int x, y, width, height;

    printf("Welcome to the Adventure Game!\n\n");

    gets(name);

    x = 1;
    y = 1;
    width = 60;
    height = 20;

    while (1) {
        printf("You are standing at (%d, %d).\n\n", x, y);
        printf("What would you like to do?\n\n");

        gets(choice);

        if (choice[0] == 'n') {
            printf("You move north.\n");
            y++;
        } else if (choice[0] =='s') {
            printf("You move south.\n");
            y--;
        } else if (choice[0] == 'e') {
            printf("You move east.\n");
            x++;
        } else if (choice[0] == 'w') {
            printf("You move west.\n");
            x--;
        } else if (choice[0] == 'q') {
            printf("You quit the game.\n");
            break;
        } else {
            printf("I don't understand that command.\n");
        }
    }

    printf("Thank you for playing!\n");

    return 0;
}