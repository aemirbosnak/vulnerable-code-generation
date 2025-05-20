//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[20];
    int age;
    char decision[20];
    int player_num;
    int score = 0;
    printf("Welcome to the Adventure Game!\n");
    printf("What's your name? ");
    scanf("%s", name);
    printf("Hello, %s! Please enter your age: ", name);
    scanf("%d", &age);
    if (age < 18) {
        printf("Oops! You're not old enough to play this game!\n");
        return 0;
    }
    printf("Great! You're old enough to play.\n");
    printf("Please choose a player number (1-4): ");
    scanf("%d", &player_num);
    printf("You are player %d.\n", player_num);
    printf("%s, you find yourself in a dark forest. You must make your way out before it's too late!\n", name);
    printf("You have two choices: Go left or go right?\n");
    scanf("%s", decision);
    if (strcmp("left", decision) == 0) {
        printf("You've chosen to go left and you stumble upon a cave!\n");
        printf("Would you like to enter the cave? ");
        scanf("%s", decision);
        if (strcmp("yes", decision) == 0) {
            printf("You enter the cave and find a treasure chest!\n");
            printf("Do you open the chest? ");
            scanf("%s", decision);
            if (strcmp("yes", decision) == 0) {
                printf("You open the chest and find a map!\n");
                score += 10;
            } else {
                printf("You leave the chest alone and leave the cave empty handed.\n");
            }
        } else {
            printf("You decide not to enter the cave and continue down the path.\n");
        }
    } else if (strcmp("right", decision) == 0) {
        printf("You've chosen to go right and you come across a river.\n");
        printf("What do you do? Swim across or try to find a bridge? ");
        scanf("%s", decision);
        if (strcmp("swim", decision) == 0) {
            printf("You attempt to swim across the river, but the current is too strong and you are swept away.\n");
            printf("Game over!\n");
            return 0;
        } else {
            printf("You search for a bridge and eventually find one.\n");
            printf("You cross the bridge and continue on your journey.\n");
        }
    } else {
        printf("Sorry, I didn't understand your decision. Goodbye!\n");
        return 0;
    }
    printf("Congratulations, %s! You've made it out of the forest and your score is %d.\n", name, score);
    return 0;
}