//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice, player_choice, chance;
    char name[20];
    srand(time(NULL));
    
    printf("Welcome to the Cyberpunk Haunted House Simulator!\n");
    printf("What is your name, player?\n");
    scanf("%s", name);
    printf("\nWelcome, %s. You have been chosen to enter this haunted house and survive its horrors.\n", name);
    printf("You have 5 chances to escape. Choose wisely.\n\n");
    
    while (chance < 5)
    {
        printf("You are in a dark room. Do you want to...\n");
        printf("1. Turn on your flashlight\n");
        printf("2. Keep walking blindly\n");
        scanf("%d", &player_choice);
        
        switch (player_choice)
        {
            case 1:
                printf("You turn on your flashlight and see a creepy figure standing in front of you.\n");
                printf("Do you want to...\n");
                printf("1. Run away\n");
                printf("2. Fight\n");
                scanf("%d", &choice);
                
                if (choice == 2)
                {
                    printf("You try to fight the figure but it disappears. You feel a chill down your spine.\n");
                    chance++;
                }
                else
                {
                    printf("You run away but hear something chasing you. You reach a door and close it behind you.\n");
                    printf("You hear a voice saying, 'You can't escape me that easily, %s.'\n", name);
                    chance++;
                }
                break;
                
            case 2:
                printf("You keep walking blindly and trip on a wire. Suddenly, the room is filled with gas.\n");
                printf("Do you...\n");
                printf("1. Hold your breath and try to find a way out\n");
                printf("2. Breathe in the gas\n");
                scanf("%d", &choice);
                
                if (choice == 1)
                {
                    printf("You hold your breath and manage to find the door. You open it and escape the gas.\n");
                    chance++;
                }
                else
                {
                    printf("You breathe in the gas and pass out. You wake up in a locked room.\n");
                    printf("You hear a voice saying, 'There is no escape, %s.'\n", name);
                    chance++;
                }
                break;
                
            default:
                printf("Invalid input. Try again.\n");
                break;
        }
        
        if (chance == 5)
        {
            printf("You have run out of chances. You are trapped in this haunted house forever.\n");
        }
        else
        {
            printf("You have %d chances left to escape.\n", 5 - chance);
        }
    }
    
    return 0;
}