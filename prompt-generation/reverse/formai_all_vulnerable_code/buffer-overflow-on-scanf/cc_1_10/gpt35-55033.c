//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice;
    printf("Welcome to the Haunted House Simulator.\n");
    printf("You find yourself standing in front of a spooky old mansion.\n");
    printf("Do you dare enter?\n");
    printf("1. Yes\n");
    printf("2. No\n");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("You enter the mansion and the door slams shut behind you.\n");
        printf("You hear strange noises coming from the basement.\n");
        printf("Do you want to go down and investigate?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%d", &choice);
        if(choice == 1)
        {
            printf("You descend the stairs and find yourself in a dark, damp basement.\n");
            printf("You hear whispers coming from behind a locked door.\n");
            printf("Do you want to try and open the door?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &choice);
            if(choice == 1)
            {
                printf("You unlock the door and find a room filled with ancient artifacts.\n");
                printf("As you approach one of the artifacts, you feel a cold hand on your shoulder.\n");
                printf("You turn around, but there's no one there.\n");
                printf("You hear a voice whispering, 'Get out...before it's too late.'\n");
                printf("Do you want to leave?\n");
                printf("1. Yes\n");
                printf("2. No\n");
                scanf("%d", &choice);
                if(choice == 1)
                {
                    printf("You turn and run for the stairs.\n");
                    printf("As you reach the stairs, you hear a low growling noise behind you.\n");
                    printf("You turn to see a dark figure descending the stairs.\n");
                    printf("You run up the stairs and through the front door, never looking back.\n");
                    printf("You made it out of the Haunted House Simulator alive!\n");
                }
                else
                {
                    printf("You decide to stay and investigate further.\n");
                    printf("The whispers grow louder, and soon you can hear more than one voice.\n");
                    printf("You turn to leave, but the door is gone.\n");
                    printf("You hear laughter as the artifacts start to glow and the room begins to spin.\n");
                    printf("As you black out, you realize too late that you should've left.\n");
                    printf("You died inside the Haunted House Simulator.\n");
                }
            }
            else
            {
                printf("You turn and run up the stairs.\n");
                printf("As you reach the top, you hear the door behind you unlock.\n");
                printf("You turn to see a dark figure emerging from the basement.\n");
                printf("You run through the front door and into the night, heart racing.\n");
                printf("You made it out of the Haunted House Simulator alive!\n");
            }
        }
        else
        {
            printf("You turn and run away from the basement.\n");
            printf("As you reach the stairs, you hear a low growling noise behind you.\n");
            printf("You turn to see a dark figure descending the stairs.\n");
            printf("You run up the stairs and through the front door, never looking back.\n");
            printf("You made it out of the Haunted House Simulator alive!\n");
        }
    }
    else
    {
        printf("You turn and walk away from the mansion, feeling nervous about what could have been inside.\n");
        printf("As you walk down the path, you hear footsteps behind you.\n");
        printf("You turn to see a ghostly figure hovering above the ground.\n");
        printf("You try to run, but your feet won't move.\n");
        printf("The ghostly figure moves closer and closer, until it envelops you.\n");
        printf("You feel a coldness inside you, and then nothing.\n");
        printf("You died outside the Haunted House Simulator.\n");
    }
    return 0;
}