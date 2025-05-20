//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Beginning the delay
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}

int room1()
{
    printf("\nYou find yourself in a room with walls made entirely of jelly beans.\n");
    printf("In the center of the room is a table with a yellow vase on it.\n");
    printf("You see there is a piece of paper sticking out of the vase.\n");
    printf("What do you want to do?\n");
    printf("1. Take the paper from the vase\n");
    printf("2. Eat the jelly beans\n");
    printf("3. Leave the room\n");

    int choice;
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nYou pull the paper out of the vase.\n");
            delay(2);
            printf("It reads, 'The key to freedom is under a rock by a tree'\n");
            return 1;
            break;

        case 2:
            printf("\nAs you start to eat the jelly beans, they start to scream.\n");
            delay(2);
            printf("You quickly realize that the jelly beans were actually tiny people.\n");
            delay(2);
            printf("You feel bad for what you've done and quickly leave the room.\n");
            return 0;
            break;

        case 3:
            printf("\nYou leave the room and enter a long, dark hallway.\n");
            delay(2);
            return 0;
            break;

        default:
            printf("\nInvalid choice, please select again.\n");
            delay(2);
            room1();
            break;

    }

}

int room2()
{
    printf("\nThe hallway leads to a room with a giant floating head in the center.\n");
    printf("It seems to be trying to communicate with you, but you can't understand it.\n");
    printf("What do you want to do?\n");
    printf("1. Approach the head\n");
    printf("2. Run away\n");

    int choice;
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nAs you get closer, the head starts to speak English.\n");
            delay(2);
            printf("'Hello there, I am the great and powerful Zoltar. I have been waiting for you.'\n");
            delay(2);
            printf("'I can help you find the key to freedom and escape this nightmare, but you must first answer my riddle.'\n");
            delay(3);
            printf("What is always in front of you but can't be seen?\n");
            char answer[50];
            scanf("%s", answer);
            if(strcmp(answer, "future") == 0)
            {
                printf("\n'Well done, you have answered my riddle correctly. As a reward, I will give you this map.'\n");
                delay(2);
                printf("Zoltar hands you a map with a path leading to a tree.\n");
                delay(2);
                printf("'The key to freedom can be found under a rock by that tree. Good luck.'\n");
                return 1;
            }
            else
            {
                printf("\n'Incorrect, you are not worthy of my help.'\n");
                delay(2);
                return 0;
            }
            break;

        case 2:
            printf("\nYou run back to the previous room in fear.\n");
            delay(2);
            return 0;
            break;

        default:
            printf("\nInvalid choice, please select again.\n");
            delay(2);
            room2();
            break;
    }

}

int room3()
{
    printf("\nYou follow the path on the map until you reach a tree with a tombstone next to it.\n");
    printf("The tombstone reads 'RIP Reality'.\n");
    printf("You see a rock next to the tree that looks out of place.\n");
    printf("What do you want to do?\n");
    printf("1. Move the rock\n");
    printf("2. Leave the area\n");

    int choice;
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nYou move the rock and find a key.\n");
            delay(2);
            printf("You feel relieved that your journey is almost over.\n");
            return 1;
            break;

        case 2:
            printf("\nYou decide to leave the area and explore more.\n");
            delay(2);
            return 0;
            break;

        default:
            printf("\nInvalid choice, please select again.\n");
            delay(2);
            room3();
            break;
    }

}

int main()
{
    printf("\nWelcome to the surreal adventure game!\n");
    printf("Your goal is to find the key to freedom and escape the nightmare.\n");
    delay(3);

    int result1 = room1();
    if(result1 == 1)
    {
        int result2 = room2();
        if(result2 == 1)
        {
            int result3 = room3();
            if(result3 == 1)
            {
                printf("\nCongratulations, you have found the key to freedom and escaped the nightmare!\n");
            }
        }

    }
    else
    {
        printf("\nGame over, better luck next time!\n");
    }

    return 0;
}