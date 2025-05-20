//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* path = malloc(10);
    srand(time(NULL));
    int choice;
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are in a dark forest. There are three paths to choose from.\n");
    printf("1. Go left\n");
    printf("2. Go right\n");
    printf("3. Go straight ahead\n");
    printf("What do you choose? ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            sprintf(path, "left");
            break;
        case 2:
            sprintf(path, "right");
            break;
        case 3:
            sprintf(path, "straight");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    printf("You choose to %s.\n", path);
    printf("You see a path in front of you. Do you choose to follow it? (y/n): ");
    char input[10];
    scanf("%s", input);
    if (input[0] == 'y') {
        printf("You follow the path and come across a river. Do you choose to cross it? (y/n): ");
        scanf("%s", input);
        if (input[0] == 'y') {
            printf("You successfully cross the river. You come across a cave. Do you enter it? (y/n): ");
            scanf("%s", input);
            if (input[0] == 'y') {
                printf("You enter the cave and find a treasure chest. Do you open it? (y/n): ");
                scanf("%s", input);
                if (input[0] == 'y') {
                    printf("You open the treasure chest and find a magical sword. You win the game!\n");
                    exit(0);
                } else {
                    printf("You decide not to open the treasure chest and leave the cave.\n");
                    exit(0);
                }
            } else {
                printf("You decide not to enter the cave and leave the river.\n");
                exit(0);
            }
        } else {
            printf("You decide not to cross the river and leave the path.\n");
            exit(0);
        }
    } else {
        printf("You decide not to follow the path and leave the forest.\n");
        exit(0);
    }
}