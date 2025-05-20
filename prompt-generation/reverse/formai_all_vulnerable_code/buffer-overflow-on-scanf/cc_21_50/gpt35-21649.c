//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int room = 1;
    int choice;
    srand(time(0));
    printf("\nWelcome to the haunted house simulator!\n");
    while (room != 10)
    {
        switch(room)
        {
            case 1:
                printf("\nYou are in the entrance hall. There are three doors - one to the left, one to the right, and one straight ahead. Which one do you choose?\n");
                printf("1. Left Door\n2. Right Door\n3. Straight Ahead\nChoice: ");
                scanf("%d", &choice);
                if(choice == 1)
                {
                    printf("\nYou open the left door and find yourself in a long, dark hallway. You hear creaking floorboards and a strange voice whispering your name. Do you want to continue, or go back?\n");
                    printf("1. Continue down the hallway\n2. Go back to entrance hall\nChoice: ");
                    scanf("%d", &choice);
                    if(choice == 1)
                    {
                        printf("\nAs you walk down the hallway, the whispers get louder and the floorboards creak louder. Suddenly, you hear a loud thud behind you. Do you want to turn around or run?\n");
                        printf("1. Turn around\n2. Run\nChoice: ");
                        scanf("%d", &choice);
                        if(choice == 1)
                        {
                            printf("\nYou turn around to see the ghostly figure of a woman in a white dress. She floats towards you, her eyes fixed on you. You run as fast as you can, and eventually find yourself back at the entrance hall.\n");
                            room = 1;
                        }
                        else if(choice == 2)
                        {
                            printf("\nYou run as fast as you can down the hallway. You hear the whispers grow louder and louder, but you don't turn around. You eventually find yourself in a room filled with old furniture.\n");
                            room = 2;
                        }
                    }
                    else if(choice == 2)
                    {
                        room = 1;
                    }
                }
                else if(choice == 2)
                {
                    printf("\nYou open the right door and find yourself in a large room. In the center of the room is a table with a Ouija board on it. Do you want to use it, or leave it alone?\n");
                    printf("1. Use the Ouija board\n2. Leave it alone\nChoice: ");
                    scanf("%d", &choice);
                    if(choice == 1)
                    {
                        printf("\nYou place your fingers on the planchette and ask a question. Suddenly, the planchette moves by itself, spelling out a message. Do you want to continue, or leave?\n");
                        printf("1. Continue using the board\n2. Leave the room\nChoice: ");
                        scanf("%d", &choice);
                        if(choice == 1)
                        {
                            printf("\nThe planchette moves more quickly now, spelling out answers to your questions. Suddenly, the board bursts into flames and you hear screams. You run out of the room and find yourself back in the entrance hall.\n");
                            room = 1;
                        }
                        else if(choice == 2)
                        {
                            room = 1;
                        }
                    }
                    else if(choice == 2)
                    {
                        room = 1;
                    }
                }
                else if(choice == 3)
                {
                    room = 2;
                }
                break;
            case 2:
                printf("\nYou are in a room filled with old furniture. There is a window on one wall and two doors - one to the left and one to the right. Which way do you go?\n");
                printf("1. Left Door\n2. Right Door\n3. Exit through the window\nChoice: ");
                scanf("%d", &choice);
                if(choice == 1)
                {
                    printf("\nYou go through the left door and find yourself in a room with a fireplace. The fire is out, but you can see something moving in the shadows. Do you want to investigate, or leave?\n");
                    printf("1. Investigate the shadows\n2. Leave the room\nChoice: ");
                    scanf("%d", &choice);
                    if(choice == 1)
                    {
                        printf("\nAs you get closer to the shadows, you realize they are the ghostly figures of a man and a woman. They appear to be arguing, but you can't make out what they're saying. Suddenly, they disappear and the room goes dark. You hear a faint whisper telling you to leave, so you do.\n");
                        room = 2;
                    }
                    else if(choice == 2)
                    {
                        room = 2;
                    }
                }
                else if(choice == 2)
                {
                    printf("\nYou go through the right door and find yourself in a room with a strange, glowing orb in the center. Do you want to touch it, or leave it alone?\n");
                    printf("1. Touch the orb\n2. Leave it alone\nChoice: ");
                    scanf("%d", &choice);
                    if(choice == 1)
                    {
                        printf("\nAs you touch the orb, it begins to glow brighter and brighter. Suddenly, you hear a loud noise and the room starts to shake. You run out of the room and find yourself back in the entrance hall.\n");
                        room = 1;
                    }
                    else if(choice == 2)
                    {
                        room = 2;
                    }
                }
                else if(choice == 3)
                {
                    printf("\nYou try to climb out of the window, but the glass shatters and you fall to the ground. You are badly injured and can't move. Suddenly, the ghostly figure of a woman appears, saying that she knew you would try to leave. She disappears and you die.\n");
                    return 0;
                }
                break;
        }
    }
    printf("\nCongratulations! You've made it through the haunted house alive!\n");
    return 0;
}