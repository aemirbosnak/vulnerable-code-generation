#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char choice[3];
    int path = 0;

    printf("Welcome to the Adventure Game!\n");
    printf("You find yourself in a dark forest. Do you go left or right?\n");
    scanf("%s", choice);

    if (strcmp(choice, "left") == 0) {
        path = 1;
    } else if (strcmp(choice, "right") == 0) {
        path = 2;
    } else {
        printf("Invalid choice! You stumble around aimlessly.\n");
        return 0;
    }

    if (path == 1) {
        printf("You enter a cave. Inside, you see a treasure chest. Do you open it?\n");
        scanf("%s", choice);
        if (strcmp(choice, "yes") == 0) {
            printf("Congratulations! You found a secret room filled with gold!\n");
        } else {
            printf("You decide not to risk it and leave the cave empty-handed.\n");
        }
    } else if (path == 2) {
        printf("You encounter a wild beast! Do you fight or run?\n");
        scanf("%s", choice);
        if (strcmp(choice, "fight") == 0) {
            printf("You bravely fight the beast and defeat it!\n");
        } else if (strcmp(choice, "run") == 0) {
            printf("You wisely choose to run away and escape unharmed.\n");
        } else {
            printf("Invalid choice! The beast attacks you and you perish.\n");
        }
    }

    return 0;
}
