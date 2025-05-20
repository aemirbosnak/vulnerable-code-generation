//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int option, key, ghost, spider, bat, door;
    srand(time(NULL));
    ghost = rand() % 4 + 1;
    spider = rand() % 4 + 1;
    bat = rand() % 4 + 1;
    door = rand() % 4 + 1;

    printf("\n\n\t\t WELCOME TO THE HAUNTED HOUSE SIMULATOR\n\n");

    printf("You find yourself in a dark, creepy hallway. There are four doors ahead of you.\n");
    printf("Which door do you choose? (1, 2, 3, or 4):\n");
    scanf("%d", &option);

    if (option == door) {
        printf("\n\nCongratulations! You have unlocked the door and made it to the next room!\n");
        printf("You see a treasure chest in the middle of the room. To unlock it, you must find the key!\n");
        printf("There are three items in the room: a table, a broom, and a chair. Which do you investigate first? (1, 2, or 3):\n");

        int item;
        scanf("%d", &item);

        switch (item) {
            case 1:
                printf("\n\nYou find nothing on the table of interest.\n");
                break;

            case 2:
                printf("\n\nYou find a key wedged in the bristles of the old broom!\n");
                key = 1;
                break;

            case 3:
                printf("\n\nYou investigate the chair and find nothing of value.\n");
                break;

            default:
                printf("\n\nInvalid option. You are frozen in fear and unable to make a decision.\n");
                break;
        }

        if (key == 1) {
            printf("\n\nYou take the key and open the treasure chest. Inside, you find a rare gemstone!\n");
            printf("Your excitement is short-lived as you hear a strange noise coming from behind you.\n");
            printf("You turn around to see a ghost, a spider, and a bat blocking your escape!\n");
            printf("You must defeat them to make it out alive! Choose your weapon wisely!\n");

            int weapon;
            printf("\n\n1. Sword\n");
            printf("2. Bow and arrow\n");
            printf("3. Magic wand\n");
            printf("Enter your weapon of choice: ");
            scanf("%d", &weapon);

            if (weapon == 1) {
                printf("\n\nYou draw your sword and charge at the enemies!\n");

                if (ghost == 1 || spider == 1 || bat == 1) {
                    printf("\n\nYou attack the enemy and defeat it!\n");
                } else {
                    printf("\n\nYou flail your sword around like a madman and miss every enemy!\n");
                }

            } else if (weapon == 2) {
                printf("\n\nYou select your bow and arrow and take aim!\n");

                if (ghost == 2 || spider == 2 || bat == 2) {
                    printf("\n\nYou fire your arrow and hit the enemy directly!\n");
                } else {
                    printf("\n\nYou miss the enemy completely and the arrow hits the wall behind them!\n");
                }

            } else if (weapon == 3) {
                printf("\n\nYou wave your magic wand and cast a spell!\n");

                if (ghost == 3 || spider == 3 || bat == 3) {
                    printf("\n\nYour spell hits the enemy and they fall to the ground defeated!\n");
                } else {
                    printf("\n\nYou summon a small gust of wind that does nothing to the enemies.\n");
                }

            } else {
                printf("\n\nInvalid weapon selection. You are devoured by the ghost, spider, and bat.\n");
                printf("GAME OVER.");
                return 0;
            }

            printf("You have defeated the enemies and can now leave the haunted house with your treasure!\n");
            printf("CONGRATULATIONS, YOU WIN!\n");

        } else {
            printf("\n\nYou did not find the key and cannot open the treasure chest. You're trapped forever!");
        }

    } else {
        printf("\n\nOh no, you picked the wrong door!\n");
        printf("You are immediately attacked by a ghost, spider, and bat!\n");
        printf("You try to run but it's too late, they've caught you!\n");
        printf("GAME OVER.");
    }

    return 0;
}