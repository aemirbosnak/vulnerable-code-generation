//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: expert-level
#include <stdio.h>
#include <string.h>

int main()
{
    char name[20];
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s!\n", name);
    printf("You find yourself in a dark forest.\n");
    printf("It is pitch black outside except for a faint light in the distance.\n");
    printf("What do you want to do?\n");
    
    char choice[20];
    printf("\n> ");
    scanf("%s", choice);
    
    if(strcmp(choice, "walk") == 0)
    {
        printf("As you walk closer to the light, you discover that it is a campfire.\n");
        printf("There are two paths leading from the campfire, one to the south and one to the east.\n");
        printf("Which way do you want to go?\n");
        
        printf("\n> ");
        scanf("%s", choice);
        
        if(strcmp(choice, "south") == 0)
        {
            printf("You walk for a while and find a river.\n");
            printf("There is a boat docked by the river, but it looks very old and rickety.\n");
            printf("What do you want to do?\n");
            
            printf("\n> ");
            scanf("%s", choice);
            
            if(strcmp(choice, "take boat") == 0)
            {
                printf("As you start rowing down the river, the boat begins to break apart.\n");
                printf("You manage to make it to shore, but you are soaking wet.\n");
                printf("You come across a small village and are able to dry off and rest.\n");
                printf("Congratulations, you have completed the game %s!\n", name);
            }
            else
            {
                printf("You decide not to risk it with the old boat.\n");
                printf("You turn around and head back toward the campfire.\n");
                printf("What do you want to do?\n");
                
                printf("\n> ");
                scanf("%s", choice);
                
                if(strcmp(choice, "east") == 0)
                {
                    printf("As you walk through the forest, you hear footsteps behind you.\n");
                    printf("You turn around and see a bear charging at you!\n");
                    printf("What do you want to do?\n");
                    
                    printf("\n> ");
                    scanf("%s", choice);
                    
                    if(strcmp(choice, "run") == 0)
                    {
                        printf("You run as fast as you can and manage to outrun the bear.\n");
                        printf("You come across a small village and are able to rest and recover.\n");
                        printf("Congratulations, you have completed the game %s!\n", name);
                    }
                    else
                    {
                        printf("You freeze up and the bear mauls you to death.\n");
                        printf("Game over.\n");
                    }
                }
                else
                {
                    printf("You walk for a while and collapse from exhaustion.\n");
                    printf("Game over.\n");
                }
            }
        }
        else if(strcmp(choice, "east") == 0)
        {
            printf("As you walk through the forest, you hear footsteps behind you.\n");
            printf("You turn around and see a bear charging at you!\n");
            printf("What do you want to do?\n");
                    
            printf("\n> ");
            scanf("%s", choice);
                    
            if(strcmp(choice, "run") == 0)
            {
                printf("You run as fast as you can and manage to outrun the bear.\n");
                printf("You come across a small village and are able to rest and recover.\n");
                printf("Congratulations, you have completed the game %s!\n", name);
            }
            else
            {
                printf("You freeze up and the bear mauls you to death.\n");
                printf("Game over.\n");
            }
        }
        else
        {
            printf("You walk for a while and collapse from exhaustion.\n");
            printf("Game over.\n");
        }
    }
    else
    {
        printf("You stand there and do nothing.\n");
        printf("Game over.\n");
    }
    
    return 0;
}