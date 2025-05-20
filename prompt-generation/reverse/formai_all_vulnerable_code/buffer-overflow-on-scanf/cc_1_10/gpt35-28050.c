//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

int main()
{
    char name[20];
    int age;
    char choice[10];

    printf("Welcome to the Adventure Game! Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! How old are you? ", name);
    scanf("%d", &age);

    printf("\nYou find yourself standing in a dark forest. In front of you, there is a path leading to a castle. What do you do?\n");

    while(strcmp(choice, "castle") != 0 && strcmp(choice, "leave") != 0)
    {
        printf("Do you go to the 'castle' or 'leave' the forest? ");
        scanf("%s", choice);
        if(strcmp(choice, "castle") == 0)
        {
            printf("\nYou make your way towards the castle. As you approach, you see a guard standing at the entrance. What do you do?\n");
            printf("Do you 'fight' the guard or 'sneak' past him? ");
            scanf("%s", choice);
            if(strcmp(choice, "fight") == 0)
            {
                printf("\nYou engage in battle with the guard. Unfortunately, he is too strong for you and you are defeated. Game over.\n");
                return 0;
            }
            else if(strcmp(choice, "sneak") == 0)
            {
                printf("\nYou manage to sneak past the guard and enter the castle. Inside, you find a treasure chest. Do you 'open' it or 'leave' it? ");
                scanf("%s", choice);
                if(strcmp(choice, "open") == 0)
                {
                    printf("\nYou open the treasure chest and find a magical amulet. As you put it on, you feel a surge of power course through your body! Congratulations, you have won the game!\n");
                    return 0;
                }
                else if(strcmp(choice, "leave") == 0)
                {
                    printf("\nYou leave the treasure chest and continue through the castle. As you walk down a hallway, you are ambushed by a group of guards. They capture you and throw you in the dungeon. Game over.\n");
                    return 0;
                }
                else
                {
                    printf("\nInvalid choice. Please try again.\n");
                }
            }
            else
            {
                printf("\nInvalid choice. Please try again.\n");
            }
        }
        else if(strcmp(choice, "leave") == 0)
        {
            printf("\nYou leave the forest and make your way back home. The end.\n");
            return 0;
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}