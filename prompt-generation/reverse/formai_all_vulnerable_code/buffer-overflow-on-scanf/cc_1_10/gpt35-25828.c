//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

int main() {
    char name[20], answer;
    int choice = 0;

    printf("Welcome to the Adventure Game!\n");
    printf("What is your name: ");
    scanf("%s", name);

    printf("%s, you find yourself in a dark room.\n", name);
    printf("There are two doors, one on your left and one on your right.\n");

    while (choice != 1 && choice != 2) {
        printf("Which door do you choose? (1 or 2): ");
        scanf("%d", &choice);
    }
    if (choice == 1) {
        printf("You have entered the left door.\n");
        printf("In front of you is a long tunnel containing many traps.\n");
        printf("Do you wish to proceed? (y/n): ");
        scanf(" %c", &answer);

        if (answer == 'y') {
            printf("You have successfully navigated the trap-filled tunnel.\n");
            printf("Ahead of you is a treasure chest!\n");
            printf("Do you wish to open it? (y/n): ");
            scanf(" %c", &answer);

            if (answer == 'y') {
                printf("Congratulations! You have found the treasure and won the game!\n");
            }
            else {
                printf("You leave the chest behind and continue on your journey.\n");
            }
        }
        else {
            printf("You wisely choose to avoid the dangerous tunnel.\n");
            printf("You continue through the left door and find yourself in a peaceful garden.\n");
            printf("You have completed the game!\n");
        }
    }
    else {
        printf("You have entered the right door.\n");
        printf("You see a group of people gathered around a table playing cards.\n");
        printf("Do you wish to join them? (y/n): ");
        scanf(" %c", &answer);

        if (answer == 'y') {
            printf("The game is Texas Hold'em, and you are quickly eliminated.\n");
            printf("You leave the room discouraged and continue on your journey.\n");
        }
        else {
            printf("You choose not to join the game and explore a nearby hallway.\n");
            printf("After walking for a while, you discover a room filled with gold!\n");
            printf("However, there is a sleeping dragon guarding it.\n");
            printf("Do you wish to attempt to take the gold? (y/n): ");
            scanf(" %c", &answer);

            if (answer == 'y') {
                printf("You are brave and try to take the gold, but the dragon wakes up!\n");
                printf("You are quickly defeated and the dragon takes the gold back.\n");
                printf("Game over, %s. Better luck next time!\n", name);
            }
            else {
                printf("You wisely choose not to take the gold and continue on your journey.\n");
                printf("You have completed the game!\n");
            }
        }
    }
    return 0;
}