//FormAI DATASET v1.0 Category: Game ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char answer[10];
    int choice;

    printf("Welcome to the Mind Bender Game!\n");
    printf("Do you want to play? (yes or no): ");
    scanf("%s", answer);

    if(strcmp(answer, "yes") == 0) {

        printf("\nGreat! Let's begin:\n");
        printf("\nThere are three doors in front of you.");
        printf("\nBehind one of them is the prize you seek!");
        printf("\nChoose a door (1, 2, or 3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYou chose Door Number One.");
                printf("\nBut wait! Before I show you what's behind it, let me tell you...");
                printf("\n\nThis door is cursed. If you choose this door, your fate will be sealed.");
                printf("\n\nDo you want to change your choice? (yes or no): ");
                scanf("%s", answer);

                if (strcmp(answer, "yes") == 0) {
                    printf("\nWhich door do you want to choose now? (2 or 3): ");
                    scanf("%d", &choice);
                }

                if (choice == 1) {
                    printf("\nYou have chosen the cursed door.");
                    printf("\nSorry, but your journey ends here.\n");
                } else if (choice == 2) {
                    printf("\nYou have chosen Door Number Two.");
                    printf("\nLet's see what's behind it...");
                    printf("\n...\n...\n...\n");
                    printf("\nCongratulations! You have won a brand new car!\n");
                } else if (choice == 3) {
                    printf("\nYou have chosen Door Number Three.");
                    printf("\nYou open it eagerly, and...");
                    printf("\n...\n...\n...\n");
                    printf("\nA swarm of bees fly out and attack you!\n");
                    printf("\nSorry, but you have lost. Please try again.\n");
                } else {
                    printf("\nInvalid choice. Please try again.\n");
                }
                break;

            case 2:
                printf("\nYou have chosen Door Number Two.");
                printf("\nLet's see what's behind it...");
                printf("\n...\n...\n...\n");
                printf("\nCongratulations! You have won a brand new car!\n");
                break;

            case 3:
                printf("\nYou have chosen Door Number Three.");
                printf("\nYou open it eagerly, and...");
                printf("\n...\n...\n...\n");
                printf("\nA swarm of bees fly out and attack you!\n");
                printf("\nSorry, but you have lost. Please try again.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } else {
        printf("\nVery well. Maybe next time. Goodbye!\n");
    }

    return 0;
}