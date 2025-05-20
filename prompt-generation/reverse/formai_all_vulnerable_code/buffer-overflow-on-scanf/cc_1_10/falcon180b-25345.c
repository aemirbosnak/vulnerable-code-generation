//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int choice;
    char name[20];

    printf("Welcome to the Brave Adventure!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\n%s, you find yourself in a dark forest with only a dimly lit torch to guide you. The air is thick with fog and the ground is covered in fallen leaves. You can hear the distant sound of a river.\n", name);

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Explore the forest\n");
        printf("2. Follow the river\n");
        printf("3. Rest for a while\n");
        printf("4. Quit\n");
        printf("\n> ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nYou begin to explore the forest, walking carefully through the thick fog. Suddenly, you hear a rustling in the bushes nearby.\n");
                printf("A wild boar charges towards you! What do you do?\n");
                printf("1. Fight the boar\n");
                printf("2. Run away\n");
                printf("\n> ");
                scanf("%d", &choice);

                if(choice == 1) {
                    printf("\nYou draw your sword and prepare to fight the boar.\n");
                    int attack = rand() % 10 + 1;
                    int defense = rand() % 10 + 1;
                    if(attack > defense) {
                        printf("\nYou strike the boar with your sword, killing it instantly.\n");
                    } else {
                        printf("\nThe boar charges towards you, knocking you to the ground.\n");
                        printf("\nGame Over\n");
                        exit(0);
                    }
                } else {
                    printf("\nYou turn and run as fast as you can, narrowly avoiding the boar's charge.\n");
                }
                break;

            case 2:
                printf("\nYou follow the sound of the river, eventually coming across a small wooden bridge.\n");
                printf("Do you cross the bridge?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                printf("\n> ");
                scanf("%d", &choice);

                if(choice == 1) {
                    printf("\nYou carefully cross the bridge, feeling the wood creak beneath your feet.\n");
                } else {
                    printf("\nYou decide to turn back and explore the forest further.\n");
                }
                break;

            case 3:
                printf("\nYou find a quiet spot beneath a large tree and sit down to rest.\n");
                printf("After a while, you feel refreshed and ready to continue your adventure.\n");
                break;

            case 4:
                printf("\nYou decide to end your adventure and return home.\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}