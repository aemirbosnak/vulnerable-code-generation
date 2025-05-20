//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main()
{
    char name[20], choice1, choice2, weapon[20], password[20];
    int health = 100, shield = 50, ammo = 100, enemies_killed = 0, key_card = 0, hacking_attempts = 3;

    printf("Welcome to Cyber City, Agent! What is your name?\n");
    scanf("%s", name);

    printf("Greetings, %s! You have been assigned a mission to infiltrate a secret facility owned by the notorious cyber gang 'The Black Hand'.\n", name);
    printf("You have two options to enter the facility. Do you want to 1) sneak in or 2) blast your way in?\n");
    scanf(" %c", &choice1);

    if(choice1 == '1')
    {
        printf("Smart choice, Agent. You quietly make your way to the facility and find a way to enter.\n");
    }
    else if(choice1 == '2')
    {
        printf("Bold move, Agent. You equip your weapon of choice. What will it be?\n");
        scanf("%s", weapon);
        printf("You blast your way into the facility with your %s.\n", weapon);
        health -= 20;
        shield -= 10;
        ammo -= 50;
    }
    else
    {
        printf("Invalid selection. Exiting game.\n");
        return 0;
    }

    printf("You find yourself in a dimly lit corridor. There are two doors ahead of you. Which one do you want to go through? (L)eft or (R)ight?\n");
    scanf(" %c", &choice2);

    if(choice2 == 'L')
    {
        printf("You enter the door on your left and find yourself in a room with a computer console. You approach the console and see a message.\n");
        printf("The message reads:\n");
        printf("To access the mainframe, enter the correct password. You have %d attempts remaining.\n", hacking_attempts);
        printf("Enter password: ");
        scanf("%s", password);

        while(strcmp(password, "blackhand") != 0 && hacking_attempts > 0)
        {
            printf("Incorrect password. You have %d attempts remaining. Enter password: ", hacking_attempts-1);
            scanf("%s", password);
            hacking_attempts--;
        }

        if(hacking_attempts == 0)
        {
            printf("You failed to hack the console. You hear footsteps approaching. You hide behind the door.\n");
            printf("The door opens and two guards enter the room. You take them down quickly and quietly.\n");
            health -= 30;
            shield -= 20;
            enemies_killed += 2;
        }
        else
        {
            printf("Access granted. You access the mainframe and download vital information.\n");
            key_card = 1;
        }
    }
    else if(choice2 == 'R')
    {
        printf("You enter the door on your right and find yourself in an armory. You stock up on ammo and equipment.\n");
        ammo += 50;
        health += 10;
        shield += 20;
    }
    else
    {
        printf("Invalid selection. Exiting game.\n");
        return 0;
    }

    if(key_card == 1)
    {
        printf("With the vital information downloaded, you make your way to the mainframe room. You swipe the key card and enter the room.\n");
        printf("The Black Hand boss is waiting for you. A fierce battle ensues!\n");
        health -= 50;
        shield -= 30;
        ammo -= 50;
        enemies_killed++;

        if(enemies_killed > 0)
        {
            printf("You emerge victorious and exit the facility. Congratulations, Agent %s! Your mission is complete.\n", name);
        }
    }
    else
    {
        printf("You hear a loud alarm. Your cover has been compromised. You must fight your way out of the facility!\n");
        printf("You encounter numerous guards and drones in your path. Your survival skills are put to the test.\n");

        while(enemies_killed < 5 && health > 0)
        {
            printf("You have encountered an enemy. Do you want to (F)ight or (R)un?\n");
            scanf(" %c", &choice2);

            if(choice2 == 'F')
            {
                printf("You engage in a fierce battle with the enemy.\n");
                health -= 20;
                shield -= 10;
                ammo -= 10;
                enemies_killed++;
            }
            else if(choice2 == 'R')
            {
                printf("You attempt to run from the enemy.\n");
                ammo -= 10;
            }
            else
            {
                printf("Invalid selection.\n");
            }

            if(enemies_killed == 5)
            {
                printf("You have successfully fought your way out of the facility. Congratulations, Agent %s! Your mission is complete.\n", name);
            }
            else if(health <= 0)
            {
                printf("You have been defeated. Mission failed.\n");
            }
        }
    }

    return 0;
}