//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    char name[20];
    printf("Welcome to the Land of Mystery, %s!\n", name);
    printf("You find yourself in a mysterious forest. There are three paths in front of you.\n");
    printf("Path 1: The Red Path - It appears to be worn by warriors.\n");
    printf("Path 2: The Blue Path - It appears to be worn by mages.\n");
    printf("Path 3: The Green Path - It appears to be worn by healers.\n");

    printf("Please choose a path number: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You choose the Red Path and follow it. You encounter a group of warriors who offer you a sword and ask you to fight. Do you accept their offer? (Y/N) ");
            scanf(" %c", &choice);

            if (choice == 'Y')
            {
                printf("You accept the offer and fight the warriors. You win! You have entered the mysterious temple.\n");
            }
            else
            {
                printf("You decline the offer and flee. You escape the warriors but fail to enter the temple.\n");
            }
            break;

        case 2:
            printf("You choose the Blue Path and follow it. You encounter a group of mages who offer you a magical spell. Do you accept their offer? (Y/N) ");
            scanf(" %c", &choice);

            if (choice == 'Y')
            {
                printf("You accept the offer and learn the spell. You use the spell to defeat a group of enemies and enter the temple.\n");
            }
            else
            {
                printf("You decline the offer and flee. You escape the mages but fail to enter the temple.\n");
            }
            break;

        case 3:
            printf("You choose the Green Path and follow it. You encounter a group of healers who offer you healing. Do you accept their offer? (Y/N) ");
            scanf(" %c", &choice);

            if (choice == 'Y')
            {
                printf("You accept the offer and receive healing. You are restored to health and enter the temple.\n");
            }
            else
            {
                printf("You decline the offer and flee. You escape the healers but fail to enter the temple.\n");
            }
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }

    return 0;
}