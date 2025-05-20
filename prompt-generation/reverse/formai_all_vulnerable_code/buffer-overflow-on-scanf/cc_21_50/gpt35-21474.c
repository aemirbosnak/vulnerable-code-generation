//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i, j, choice, health = 100, key = 0, potion = 0, ghost = 0;
    char name[20];
    srand(time(0));

    printf("************************************************************\n");
    printf("Welcome to the Haunted House Simulator in Romeo and Juliet Style!\n");
    printf("************************************************************\n");
    printf("\n\nWhat is your name, brave adventurer? ");
    scanf("%s", name);

    printf("\n\n%s, you are now standing in front of the spooky house. \n", name);

    do
    {
        printf("\n\nDo you want to:\n");
        printf("1. Enter the house.\n");
        printf("2. Run away\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("\nYou are now inside the haunted house.\n");
            printf("You see a door on your left and a door on your right.\n");
            printf("Which one do you choose?\n");
            printf("1. Left Door\n");
            printf("2. Right Door\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            if(choice == 1)
            {
                printf("\nYou have entered the room on the left.\n");
                printf("The door shuts behind you.\n");
                printf("You are now locked in this room.\n");
                printf("You see a key on the table in front of you.\n");
                printf("What do you want to do?\n");
                printf("1. Take the key.\n");
                printf("2. Leave the key and search for another way out.\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if(choice == 1)
                {
                    printf("\nYou have taken the key.\n");
                    key = 1;
                    printf("You now have the key with you.\n");
                }

                else if(choice == 2)
                {
                    printf("\nYou leave the key and start searching for another way out.\n");
                }

                printf("You now hear some weird noises.\n");
                printf("There is a ghost in the room with you!\n");
                printf("What do you want to do?\n");
                printf("1. Fight the ghost.\n");
                printf("2. Use a potion to heal.\n");
                printf("3. Run away.\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if(choice == 1)
                {
                    if(key == 1)
                    {
                        printf("\nYou use the key to open the door and escape.\n");
                        printf("Congratulations, %s you have won the game!\n", name);
                        exit(0);
                    }

                    else
                    {
                        printf("\nThe ghost is too strong for you to fight.\n");
                        health -= 25;
                        printf("Your health has decreased by 25. Your current health is %d.\n", health);
                    }
                }

                else if(choice == 2)
                {
                    if(potion == 0)
                    {
                        printf("\nYou do not have any potions with you!\n");
                    }
                    else
                    {
                        potion -= 1;
                        health += 50;
                        printf("\nYou use a potion to heal yourself.\n");
                        printf("Your health has been increased by 50. Your current health is %d.\n", health);
                    }
                }

                else if(choice == 3)
                {
                    printf("\nYou are afraid and you run away from the ghost.\n");
                }
            }

            else if(choice == 2)
            {
                printf("\nYou have entered the room on the right.\n");
                printf("You see a chest in the middle of the room.\n");
                printf("What do you want to do?\n");
                printf("1. Open the chest.\n");
                printf("2. Leave the room.\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if(choice == 1)
                {
                    printf("\nYou open the chest and see a potion.\n");
                    printf("Do you want to take the potion?\n");
                    printf("1. Yes\n");
                    printf("2. No\n");
                    printf("Enter your choice: ");
                    scanf("%d", &choice);

                    if(choice == 1)
                    {
                        printf("\nYou take the potion.\n");
                        potion += 1;
                        printf("You now have %d potions with you.\n", potion);
                    }

                    else if(choice == 2)
                    {
                        printf("\nYou leave the potion and start looking for other stuff.\n");
                    }
                }

                printf("You now hear some weird noises.\n");
                printf("There is a ghost in the room with you!\n");
                printf("What do you want to do?\n");
                printf("1. Fight the ghost.\n");
                printf("2. Use a potion to heal.\n");
                printf("3. Run away.\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if(choice == 1)
                {
                    if(key == 1)
                    {
                        printf("\nYou use the key to open the door and escape.\n");
                        printf("Congratulations, %s you have won the game!\n", name);
                        exit(0);
                    }

                    else
                    {
                        printf("\nThe ghost is too strong for you to fight.\n");
                        health -= 25;
                        printf("Your health has decreased by 25. Your current health is %d.\n", health);
                    }
                }

                else if(choice == 2)
                {
                    if(potion == 0)
                    {
                        printf("\nYou do not have any potions with you!\n");
                    }
                    else
                    {
                        potion -= 1;
                        health += 50;
                        printf("\nYou use a potion to heal yourself.\n");
                        printf("Your health has been increased by 50. Your current health is %d.\n", health);
                    }
                }

                else if(choice == 3)
                {
                    printf("\nYou are afraid and you run away from the ghost.\n");
                }
            }
        }

        else if(choice == 2)
        {
            printf("\nYou run away from the haunted house and are never seen again.\n");
            exit(0);
        }

    }while(health > 0);

    printf("\nYou have lost the game. Better luck next time.\n");
    exit(0);
}