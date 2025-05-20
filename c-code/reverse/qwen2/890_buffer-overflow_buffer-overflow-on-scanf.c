#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char name[10];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Welcome, %s! You find yourself in a dark, eerie house.\n", name);

    int choice;
    printf("Do you want to go through the front door (1) or the back door (2)? ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You enter the front room and see a ghostly figure.\n");
        printf("Do you try to scare it away (1) or run away (2)? ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("The ghost disappears, but you feel a chill down your spine.\n");
        } else if (choice == 2) {
            printf("You run out of the house, heart pounding.\n");
        }
    } else if (choice == 2) {
        printf("You open the back door and find a secret passage.\n");
        printf("Do you follow it (1) or leave it alone (2)? ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You step into the passage and find a treasure chest!\n");
        } else if (choice == 2) {
            printf("You decide to stay outside and enjoy the night.\n");
        }
    }

    return 0;
}
