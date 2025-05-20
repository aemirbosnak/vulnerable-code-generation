//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    srand(time(NULL));

    printf("Welcome to the Haunted House Simulator\n");

    char name[20];
    printf("What's your name? ");
    scanf("%s", name);

    printf("\nHello, %s! You find yourself standing in front of an old, abandoned house.\n", name);
    printf("The wind is howling and the branches are scraping across the windows.\n");
    printf("Do you dare enter? (y/n)\n");

    char choice;
    scanf(" %c", &choice);

    if (choice == 'n') {
        printf("You turn around and run as fast as you can. GAME OVER.\n");
        return 0;
    }

    printf("You push open the creaky front door and step into the dusty foyer.\n");
    printf("The door slams shut behind you and you hear it lock.\n");
    printf("You're trapped inside the haunted house! What will you do?\n");

    int steps = 0;
    int room = 1;
    while (room != 0) {
        printf("\nYou're in room %d.\n", room);

        // Random chance of encountering a ghost
        int ghost = rand() % 10;
        if (ghost == 0) {
            printf("A ghost appears and scares you! You run back to the foyer.\n");
            room = 1;
            continue;
        }

        printf("What will you do? (1: go forward, 2: go right, 3: go left) ");
        int move;
        scanf("%d", &move);

        switch (room) {
            case 1:
                if (move == 1) {
                    printf("You enter the living room.\n");
                    room = 2;
                    steps++;
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 2:
                if (move == 1) {
                    printf("You enter the kitchen.\n");
                    room = 3;
                    steps++;
                } else if (move == 2) {
                    printf("You enter the dining room.\n");
                    room = 4;
                    steps++;
                } else if (move == 3) {
                    printf("You go back to the foyer.\n");
                    room = 1;
                    steps++;
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 3:
                if (move == 1) {
                    printf("You find a hidden passage!\n");
                    room = 5;
                    steps++;
                } else if (move == 2) {
                    printf("You can't go that way.\n");
                } else if (move == 3) {
                    printf("You go back to the living room.\n");
                    room = 2;
                    steps++;
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 4:
                if (move == 1) {
                    printf("You find a secret door!\n");
                    room = 6;
                    steps++;
                } else if (move == 2) {
                    printf("You go back to the living room.\n");
                    room = 2;
                    steps++;
                } else if (move == 3) {
                    printf("You can't go that way.\n");
                } else {
                    printf("You can't go that way.\n");
                }
                break;
            case 5:
                printf("You find a ghost! GAME OVER.\n");
                room = 0;
                break;
            case 6:
                printf("You find a chest of treasure! Congratulations, you win!\n");
                printf("It took you %d steps.\n", steps);
                room = 0;
                break;
        }
    }

    return 0;
}