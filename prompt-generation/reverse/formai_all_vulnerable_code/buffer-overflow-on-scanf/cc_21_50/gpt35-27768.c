//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int lives = 3;
    int ghosts = 0;
    int has_key = 0;
    int room_number = 1;
    int is_light_on = 0;
    int is_game_over = 0;

    srand(time(0));

    printf("Welcome to the Haunted House Simulator!!\n\n");
    printf("You have just entered a haunted house, your goal is to find the key and escape before the ghosts get you!\n");   
    printf("You have 3 lives, use them wisely...\n\n");

    while (!is_game_over)
    {
        printf("You are in room %d\n", room_number);

        if (room_number == 1)
        {
            printf("You see a dimly lit room with cobwebs hanging from the ceiling.\n");
            if (!is_light_on)
                printf("It's too dark to see anything.\n");
            else
                printf("You notice the key on a table in the middle of the room!\n");
        }
        else if (room_number == 2)
        {
            printf("You have entered a gloomy dining room, a long table stretches in front of you with chairs around it.\n");
            printf("There's a ghost at the end of the table!\n");
            ghosts++;
        }
        else if (room_number == 3)
        {
            printf("You enter a room with creepy dolls that are moving on their own.\n");
            printf("You feel uneasy... \n");
        }
        else if (room_number == 4)
        {
            printf("You have found the library, it's filled with old books and dusty shelves.\n");
            printf("You hear a strange noise coming from the corner of the room.\n");
            ghosts++;
        }
        else if (room_number == 5)
        {
            printf("You stumble upon an eerie laboratory with weird chemicals and potions labeled with strange symbols.\n");
            printf("You see a ghostly figure tinkering with the equipment over in the corner!\n");
            ghosts++;
        }
        else if (room_number == 6)
        {
            printf("You have entered a room with mirrors lining the walls, reflecting back at you.\n"); 
            printf("One of the mirrors shatters into pieces, and suddenly you see multiple images of yourself staring at you with cold eyes.\n");
            printf("You try to run away, but something pulls you back...\n");
            ghosts++;
        }
        else if (room_number == 7)
        {
            printf("You made it to the attic! This is where you'll find the door that leads outside.\n");
            if (!has_key)
                printf("The door is locked and requires a key to open.\n");
            else 
            {
                printf("You use the key to unlock the door.  Congratulations, you're free!!!\n");
                printf("You've made it out alive!\n");
                is_game_over = 1;
            }
        }
        else 
        {
            printf("You're not sure where you are...\n");
            printf("You feel lost and scared...\n");
            ghosts++;
        }

        if (ghosts > 0)
        {
            if (lives > 1)
                printf("Oh no!  You've been caught by a ghost!  You lose one life.\n");
            else if(lives == 1)
            {
                printf("You've been caught by a ghost!  You're out of lives.  GAME OVER.\n");
                is_game_over = 1;
            }
            else
            {
                printf("?????????????????????????????????????????\n");
                printf("?????????????????????????????????????????\n");
                printf("?????????????????????????????????????????\n");
                printf("?????????????????????????????????????????\n");
                printf("?????????????????????????????????????????\n");
                printf("?????????????????????????????????????????\n");
                printf("?????????????????????????????????????????\n");
                printf("?????????????????????????????????????????\n");
                printf("?????????????????????????????????????????\n");
                printf("?????????????????????????????????????????\n");
                ghosts = 0;
            }
            lives--;
        }

        if (room_number == 1 && is_light_on)
            has_key = 1;

        printf("\n");
        printf("You have %d lives left.\n", lives);
        printf("There are %d ghosts in the house.\n", ghosts);
        if (!is_game_over)
        {
            printf("What do you want to do next?\n");
            printf("1. Go left\n");
            printf("2. Go right\n");
            printf("3. Turn light switch on/off\n");
            printf("4. Check inventory\n");
            printf("5. Quit\n");

            int choice = 0;
            scanf("%d", &choice);

            while (choice < 1 || choice > 5)
            {
                printf("Invalid input, please choose again.\n");
                scanf("%d", &choice);
            }

            switch (choice)
            {
            case 1:
                if (room_number == 2 || room_number == 4 || room_number == 6)
                    printf("You can't go left from here.\n");
                else
                    room_number--;
                break;
            case 2:
                if (room_number == 1 || room_number == 3 || room_number == 7)
                    printf("You can't go right from here.\n");
                else
                    room_number++;
                break;
            case 3:
                if (is_light_on)
                {
                    printf("You turn the light switch off.\n");
                    is_light_on = 0;
                }
                else
                {
                    printf("You turn the light switch on.\n");
                    is_light_on = 1;
                }
                break;
            case 4:
                printf("You currently have %s the key in your inventory.\n", has_key ? "" : "not");
                break;
            case 5:
                printf("Game over.  Sorry to see you leave.  Goodbye!\n");
                is_game_over = 1;
                break;
            }
        }
    }

    return 0;
}