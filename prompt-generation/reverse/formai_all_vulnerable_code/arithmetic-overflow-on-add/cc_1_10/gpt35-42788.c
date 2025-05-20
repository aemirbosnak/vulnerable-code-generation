//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int seconds)
{
    int milli = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli);
}

int main()
{
    int choice;
    printf("You are standing in front of a haunted house. Do you want to enter?\n");
    printf("1. Yes\n2. No\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
        printf("You enter the house and the door slams shut behind you. You are in complete darkness. \n");
        delay(2);
        printf("You hear a creaking noise and you feel something brush past you.\n");
        delay(2);
        printf("You feel your way along the walls and find a switch. Do you want to turn it on?\n");
        printf("1. Yes\n2. No\n");
        scanf("%d", &choice);
        if(choice == 1)
        {
            printf("You turn on the light and see a shadow move across the wall. You hear a scream.\n");
            delay(2);
            printf("You can feel your heart pounding in your chest. You hear a voice whisper, 'Get out.'\n");
            delay(2);
            printf("Do you want to continue exploring the house?\n");
            printf("1. Yes\n2. No\n");
            scanf("%d", &choice);
            if(choice == 1)
            {
                printf("You cautiously move forward and see a ghostly figure appear in front of you.\n");
                delay(2);
                printf("The figure speaks, 'Leave before it's too late.'\n");
                delay(2);
                printf("You turn and run for the door, but it won't open. You are trapped!\n");
                delay(2);
                printf("Game over.\n");
            }
            else
            {
                printf("You decide it's best to leave the house and turn around. The door is open and you run out.\n");
                printf("Congratulations! You've made it out alive.\n");
            }
        }
        else
        {
            printf("You decide not to turn on the light and move forward in the darkness. You trip and fall down a flight of stairs.\n");
            delay(2);
            printf("You are unconscious, but wake up later feeling lucky to be alive. You leave the house quickly.\n");
            printf("Congratulations! You've made it out alive.\n");
        }
    }
    else
    {
        printf("You decide not to enter the house. You walk away and never look back. Congratulations! You've made it out alive.\n");
    }
    return 0;
}