//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int score = 0; // player's score
char name[20]; // player's name
char direction[6]; // player's chosen direction
int end_game = 0; // to end game loop

int main()
{
    printf("Welcome to the Adventure Game! Enter your name:\n");
    scanf("%s", name);

    printf("\n%s, you are lost in the wilderness. You have\n", name);
    printf("no idea where you are or how you got here. You\n");
    printf("must find your way to civilization. Good luck!\n\n");

    while (!end_game) {

        printf("You come to a fork in the road. Do you go left or right?\n");
        scanf("%s", direction);

        if(strcmp(direction, "left") == 0) {
            printf("\nYou encounter a river. Do you swim across or follow it?\n");
            scanf("%s", direction);

            if(strcmp(direction, "swim") == 0) {
                printf("\nYou start swimming, but soon find the current is too strong.\n");
                printf("You are swept away and drown. Game over.\n");
                end_game = 1; // end game loop
            }
            else if(strcmp(direction, "follow") == 0) {
                printf("\nYou follow the river and come across a bridge.\n");
                printf("You cross the bridge and find a road.\n");
                score += 10; // increase score by 10
            }
            else {
                printf("\nInvalid input. Try again.\n");
            }

        }
        else if(strcmp(direction, "right") == 0) {
            printf("\nYou walk for a while and come across a cave.\n");
            printf("Do you enter the cave or continue on?\n");
            scanf("%s", direction);

            if(strcmp(direction, "enter") == 0) {
                printf("\nYou enter the cave and find a treasure chest.\n");
                printf("You open the chest and find a map.\n");
                score += 20; // increase score by 20
            }
            else if(strcmp(direction, "continue") == 0) {
                printf("\nYou continue on and find a village.\n");
                score += 15; // increase score by 15
            }
            else {
                printf("\nInvalid input. Try again.\n");
            }
        }
        else {
            printf("\nInvalid input. Try again.\n");
        }

        // display current score
        printf("\nScore: %d\n", score);

        // check if player won
        if(score >= 50) {
            printf("\nCongratulations %s! You have found civilization and won the game!\n", name);
            end_game = 1; // end game loop
        }
    }

    return 0;
}