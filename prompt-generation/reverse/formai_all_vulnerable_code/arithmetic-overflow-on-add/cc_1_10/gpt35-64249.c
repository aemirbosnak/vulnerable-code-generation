//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int number_of_seconds) {
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds) {}
}

int main() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are in a dark cave, you can see two paths.\n");

    int choice;
    printf("Enter 1 to go left or 2 to go right: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("You choose to go left.\n");
        printf("You see a small light in the distance.\n");
        delay(2);
        printf("You walk towards the light and find a chest.\n");
        printf("Do you want to open the chest? Enter 1 for yes or 2 for no: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("You open the chest and find a map and a key.\n");
            printf("The map shows a path to some treasure and the key may be useful.\n");
        }
        else {
            printf("You decide not to open the chest and continue on your journey.\n");
        }

        printf("You see a fork in the path.\n");
        printf("Enter 1 to go left or 2 to go right: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("You choose to go left.\n");
            printf("You hear strange noises in the distance.\n");
            delay(2);
            printf("You see a dragon guarding a pile of treasure.\n");
            printf("Do you want to fight the dragon? Enter 1 for yes or 2 for no: ");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("You try to fight the dragon but it is too powerful.\n");
                printf("You lose the game.\n");
            }
            else {
                printf("You decide not to fight the dragon and continue on your journey.\n");
            }

        }
        else {
            printf("You choose to go right.\n");
            printf("You see an old man sitting on a rock.\n");
            printf("Do you want to talk to him? Enter 1 for yes or 2 for no: ");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("You talk to the old man and he tells you a riddle.\n");
                printf("If you solve the riddle, he will give you a prize.\n");
                printf("Here is the riddle: What is always in front of you but can't be seen?\n");
                char answer[20];
                printf("Enter your answer: ");
                scanf("%s", answer);

                if(strcmp(answer, "the future") == 0) {
                    printf("You solve the riddle and the old man gives you a magical sword.\n");
                }
                else {
                    printf("You fail to solve the riddle and the old man disappears.\n");
                }
            }
            else {
                printf("You decide not to talk to the old man and continue on your journey.\n");
            }
        }

    }
    else {
        printf("You choose to go right.\n");
        printf("You see a river blocking your path.\n");
        printf("Do you want to swim across? Enter 1 for yes or 2 for no: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("You try to swim across but the current is too strong.\n");
            printf("You lose the game.\n");
        }
        else {
            printf("You decide not to swim across and continue on your journey.\n");
        }

        printf("You see a fork in the path.\n");
        printf("Enter 1 to go left or 2 to go right: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("You choose to go left.\n");
            printf("You see a mysterious door.\n");
            printf("Do you want to open the door? Enter 1 for yes or 2 for no: ");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("You open the door and find a room filled with treasure.\n");
                printf("You win the game!\n");
            }
            else {
                printf("You decide not to open the door and continue on your journey.\n");
            }
        }
        else {
            printf("You choose to go right.\n");
            printf("You stumble upon a group of thieves.\n");
            printf("Do you want to fight them? Enter 1 for yes or 2 for no: ");
            scanf("%d", &choice);

            if(choice == 1) {
                printf("You fight the thieves and defeat them.\n");
                delay(2);
                printf("You find a hidden entrance to a cave filled with treasure.\n");
                printf("You win the game!\n");
            }
            else {
                printf("You decide not to fight the thieves and continue on your journey.\n");
            }
        }

    }

    return 0;
}