//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: careful
#include <stdio.h>
#include <string.h>

void clearInputBuffer() {
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    printf("Welcome to The Dungeon!\n");
    printf("Enter your name: ");

    char playerName[20] = "";
    fgets(playerName, 20, stdin);
    playerName[strcspn(playerName, "\n")] = 0; // Remove trailing newline

    printf("Welcome, %s, to the dungeon!\n", playerName);
    printf("You find yourself in a dark and damp room. You can see two doors.\n");
    printf("One to your left and one to your right.\n");

    char choice[10] = "";
    while (strcmp(choice, "left") != 0 && strcmp(choice, "right") != 0) {
        printf("Which door do you choose? (left/right)\n");
        fgets(choice, 10, stdin);
        choice[strcspn(choice, "\n")] = 0; // Remove trailing newline
        if (strcmp(choice, "left") != 0 && strcmp(choice, "right") != 0) {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("You open the %s door and enter the next room.\n", choice);
    printf("This room is filled with treasure, but there is also a monster guarding it.\n");
    printf("You have a sword to defend yourself.\n");

    int hasSword = 1;

    while (1) {
        if (hasSword) {
            printf("Do you want to attack the monster? (y/n)\n");
        } else {
            printf("You have already defeated the monster.\n");
            printf("Do you want to search the treasure? (y/n)\n");
        }

        char answer[2] = "";
        fgets(answer, 2, stdin);
        clearInputBuffer();

        if (strcmp(answer, "y") == 0) {
            if (hasSword) {
                printf("You attack the monster and defeat it!\n");
                printf("You have earned the treasure. Congratulations!\n");
                hasSword = 0;
            } else {
                printf("You search the treasure and find a map to the exit!\n");
                printf("You use the map to escape the dungeon. Congratulation!\n");
                break;
            }
        } else if (strcmp(answer, "n") == 0) {
            printf("You decide to not take any risks and go back to the previous room.\n");
            strcpy(choice, ""); // Reset the choice variable to trigger the door selection loop again
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    if (strlen(choice) > 0) {
        printf("You open the %s door and enter the next room.\n", choice);
        printf("This room is filled with poison gas! You start to feel dizzy...\n");
        printf("You need to find a way out before it's too late.\n");

        while (1) {
            printf("What do you want to do?\n");
            printf("1. Look for an exit.\n");
            printf("2. Cover your mouth and wait for the gas to clear.\n");

            int option = 0;
            scanf("%d", &option);
            clearInputBuffer();

            if (option == 1) {
                printf("You search the room and find a hidden passage in the wall.\n");
                printf("You crawl through it and finally see daylight!\n");
                printf("You have escaped the dungeon. Congratulations!\n");
                break;
            } else if (option == 2) {
                printf("You cover your mouth with your shirt and wait for the gas to clear.\n");
                printf("A few minutes later, the gas dissipates and you can breathe normally again.\n");
                printf("You start to feel weak, but you manage to get out of the dungeon.\n");
                printf("You survived, but barely. Better luck next time!\n");
                break;
            } else {
                printf("Invalid option. Please try again.\n");
            }
        }
    }

    return 0;
}