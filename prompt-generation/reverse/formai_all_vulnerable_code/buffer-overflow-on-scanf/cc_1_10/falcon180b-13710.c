//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
void game();
void instructions();
void play_again();

int main() {
    srand(time(NULL));
    intro();
    game();
    play_again();
    return 0;
}

void intro() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("You are a brave adventurer on a quest to find the legendary treasure.\n");
    printf("Along the way, you will encounter various challenges and obstacles.\n");
    printf("Do you have what it takes to complete the quest and claim the treasure?\n");
    printf("Press any key to begin.\n");
    getchar();
}

void game() {
    int choice;
    char input[100];
    int treasure_found = 0;

    printf("You find yourself in a dark, damp cave.\n");
    printf("There are three paths before you. Which one will you take?\n");
    printf("1. Path to the left\n");
    printf("2. Path in the middle\n");
    printf("3. Path to the right\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("You take the path to the left.\n");
            printf("You come across a deep chasm.\n");
            printf("Do you want to try to jump over it? (y/n): ");
            scanf(" %c", &input[0]);
            if(input[0] == 'y') {
                printf("You make the jump and land safely on the other side!\n");
            } else {
                printf("You decide not to risk it and turn back.\n");
            }
            break;
        case 2:
            printf("You take the path in the middle.\n");
            printf("You encounter a fierce dragon!\n");
            printf("Do you want to fight it? (y/n): ");
            scanf(" %c", &input[0]);
            if(input[0] == 'y') {
                printf("You engage in a fierce battle with the dragon.\n");
                printf("After a long and grueling fight, you emerge victorious!\n");
            } else {
                printf("You decide to run away.\n");
            }
            break;
        case 3:
            printf("You take the path to the right.\n");
            printf("You find yourself in a large chamber.\n");
            printf("In the center of the chamber, you see a glittering treasure chest!\n");
            printf("You open the chest and find the legendary treasure!\n");
            treasure_found = 1;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }

    if(treasure_found == 0) {
        printf("You have not found the treasure yet.\n");
        printf("Do you want to continue the quest? (y/n): ");
        scanf(" %c", &input[0]);
        if(input[0] == 'n') {
            printf("You give up and return home.\n");
        } else {
            game();
        }
    }
}

void instructions() {
    printf("Instructions:\n");
    printf("1. Choose a path by entering the corresponding number.\n");
    printf("2. Answer the prompts by entering 'y' or 'n'.\n");
    printf("3. Press any key to continue.\n");
}

void play_again() {
    char input[100];
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &input[0]);
    if(input[0] == 'y') {
        main();
    } else {
        printf("Thank you for playing!\n");
        exit(0);
    }
}