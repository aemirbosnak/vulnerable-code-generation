//Falcon2-11B DATASET v1.0 Category: Text-Based Adventure Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_ROOM 20
#define MAX_TURN 20
#define MAX_INPUT 80

int room[MAX_ROOM];
int room_number = 0;
int turn_number = 0;
int input[MAX_INPUT];

int main() {
    char input[MAX_INPUT];
    int choice;

    printf("Welcome to the Adventure Game!\n");
    printf("You are in a dark forest. There is a path to the left and right.\n");
    printf("Which path do you take? (left/right)\n");

    scanf("%s", input);

    if (strcmp(input, "left") == 0) {
        printf("You take the path to the left and come across a river.\n");
        printf("Do you cross the river? (yes/no)\n");
        scanf("%s", input);

        if (strcmp(input, "yes") == 0) {
            printf("You cross the river and find a hidden cave.\n");
            printf("Do you enter the cave? (yes/no)\n");
            scanf("%s", input);

            if (strcmp(input, "yes") == 0) {
                printf("You enter the cave and find a treasure chest!\n");
                printf("Do you open the chest? (yes/no)\n");
                scanf("%s", input);

                if (strcmp(input, "yes") == 0) {
                    printf("Congratulations, you found the treasure!\n");
                } else {
                    printf("You decide not to open the chest and leave the cave.\n");
                }
            } else {
                printf("You decide not to enter the cave and leave the forest.\n");
            }
        } else {
            printf("You decide not to cross the river and leave the forest.\n");
        }
    } else {
        printf("You take the path to the right and come across a cliff.\n");
        printf("Do you climb the cliff? (yes/no)\n");
        scanf("%s", input);

        if (strcmp(input, "yes") == 0) {
            printf("You climb the cliff and find a hidden cave.\n");
            printf("Do you enter the cave? (yes/no)\n");
            scanf("%s", input);

            if (strcmp(input, "yes") == 0) {
                printf("You enter the cave and find a treasure chest!\n");
                printf("Do you open the chest? (yes/no)\n");
                scanf("%s", input);

                if (strcmp(input, "yes") == 0) {
                    printf("Congratulations, you found the treasure!\n");
                } else {
                    printf("You decide not to open the chest and leave the cave.\n");
                }
            } else {
                printf("You decide not to enter the cave and leave the forest.\n");
            }
        } else {
            printf("You decide not to climb the cliff and leave the forest.\n");
        }
    }

    return 0;
}