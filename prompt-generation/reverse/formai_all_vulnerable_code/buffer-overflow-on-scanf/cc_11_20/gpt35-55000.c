//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    char ans1, ans2, ans3;
    int score = 0;

    printf("Welcome to the Quest for the Holy Grail!\n");

    printf("\nYou are a brave adventurer on a quest to find the Holy Grail, a legendary artifact said to hold miraculous powers.\n");
    printf("You come across a fork in the road. Do you go left (l) or right (r)?\n");
    scanf(" %c", &ans1);

    if(ans1 == 'r') {
        printf("You chose to go right. You eventually come across a castle. Do you enter (e) or continue on (c)?\n");
        scanf(" %c", &ans2);

        if(ans2 == 'e') {
            printf("You entered the castle and are promptly faced with a group of knights guarding a door. Do you fight (f) or sneak past (s)?\n");
            scanf(" %c", &ans3);

            if(ans3 == 's') {
                printf("You sneak past the knights and find yourself face to face with the Holy Grail!\n");
                printf("Congratulations, you have completed your quest!\n");
                score = 100;
            }
            else if(ans3 == 'f') {
                printf("You fought valiantly, but were ultimately outnumbered and defeated.\n");
                printf("Game over.\n");
                score = -50;
            }
            else {
                printf("Invalid input.\n");
            }
        }
        else if(ans2 == 'c') {
            printf("You continue on, but after hours of wandering, you become lost. Game over.\n");
            score = -25;
        }
        else {
            printf("Invalid input.\n");
        }
    }
    else if(ans1 == 'l') {
        printf("You chose to go left. You eventually come across a cave. Do you enter (e) or continue on (c)?\n");
        scanf(" %c", &ans2);

        if(ans2 == 'e') {
            printf("You entered the cave and come across a dark abyss. Do you jump across (j) or find another way around (a)?\n");
            scanf(" %c", &ans3);

            if(ans3 == 'a') {
                printf("You find another way around and eventually stumble upon the Holy Grail!\n");
                printf("Congratulations, you have completed your quest!\n");
                score = 100;
            }
            else if(ans3 == 'j') {
                printf("You jump across the abyss, but fall short and plummet to your death. Game over.\n");
                score = -50;
            }
            else {
                printf("Invalid input.\n");
            }
        }
        else if(ans2 == 'c') {
            printf("You continue on, but after hours of wandering, you become lost. Game over.\n");
            score = -25;
        }
        else {
            printf("Invalid input.\n");
        }
    }
    else {
        printf("Invalid input.\n");
    }

    printf("Your final score is: %d\n", score);

    return 0;
}