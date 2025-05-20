//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int choice;
    int val;
    char name[20];
    srand(time(NULL));

    printf("Welcome, adventurer! What is your name?\n");
    scanf("%s", name);
    printf("Nice to meet you, %s. Are you ready to embark on a journey?\n", name);
    printf("1. Yes\n2. No\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Great choice! Let's get started.\n");
        printf("You find yourself in a dark forest. It is so dark you can barely see your hand in front of your face.\n");
        printf("What would you like to do?\n");
        printf("1. Keep walking\n2. Stay put\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("As you keep walking, you suddenly hear a growl. You turn around and see a giant wolf glaring at you.\n");
            printf("What do you do?\n");
            printf("1. Try to fight it\n2. Run away\n");
            scanf("%d", &choice);

            if (choice == 1) {
                val = rand() % 2;
                if (val == 0) {
                    printf("You manage to defeat the wolf! You continue on your journey.\n");
                    printf("As you keep walking, you come across a beautiful waterfall.\n");
                    printf("What do you want to do?\n");
                    printf("1. Take a swim\n2. Rest by the waterfall\n");
                    scanf("%d", &choice);

                    if (choice == 1) {
                        printf("As you're swimming, you notice a glimmer in the water. You dive down and find a treasure chest!\n");
                        printf("You decide to open the treasure chest and find a magic sword inside! Congratulations!\n");
                    }
                    else {
                        printf("You take a much-needed rest by the waterfall and continue on your journey.\n");
                    }
                }
                else {
                    printf("The wolf is too strong for you. You manage to run away, but you're left injured.\n");
                    printf("You find a cave to hide in and wait to recover.\n");
                    printf("As you're hiding, you notice something shiny in the corner.\n");
                    printf("What do you want to do?\n");
                    printf("1. Investigate\n2. Ignore it\n");
                    scanf("%d", &choice);

                    if (choice == 1) {
                        printf("You walk over to the corner and find a magical potion. You drink it and feel instantly better!\n");
                        printf("You decide to continue on your journey.\n");
                    }
                    else {
                        printf("You ignore it and continue to wait.\n");
                    }
                }
            }
            else {
                printf("You run away from the wolf as fast as you can. As you're running, you trip and fall into a hole.\n");
                printf("You find yourself in a dungeon.\n");
                printf("What do you want to do?\n");
                printf("1. Look for a way out\n2. Stay put\n");
                scanf("%d", &choice);

                if (choice == 1) {
                    printf("You explore the dungeon and find a way out. You continue on your journey.\n");
                    printf("As you're walking, you find a map. The map shows a treasure hidden in a nearby town.\n");
                    printf("What do you want to do?\n");
                    printf("1. Go find the treasure\n2. Ignore the map\n");
                    scanf("%d", &choice);

                    if (choice == 1) {
                        printf("You follow the map and find the treasure! Congratulations!\n");
                    }
                    else {
                        printf("You ignore the map and continue on your journey.\n");
                    }
                }
                else {
                    printf("You stay put in the dungeon and wait for someone to find you.\n");
                }
            }
        }
        else {
            printf("You stay put and wait for dawn to come.\n");
        }
    }
    else {
        printf("Come back when you're ready!\n");
    }

    return 0;
}