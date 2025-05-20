//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clear_screen()
{
    system("clear||cls");
}

void wait_for_enter()
{
    printf("\nPress enter to continue ...");
    while (getchar() != '\n');
}

void show_intro()
{
    clear_screen();
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    printf("You are a brave adventurer on a quest to retrieve a precious\n");
    printf("artifact from a dangerous dungeon. Your journey will be fraught\n");
    printf("with peril, so brace yourself and be prepared for anything!\n\n");
    wait_for_enter();
}

void show_menu()
{
    clear_screen();
    printf("What would you like to do?\n\n");
    printf("1) Enter the dungeon\n");
    printf("2) Check your inventory\n");
    printf("3) Quit the game\n\n");
}

void show_inventory(char inventory[])
{
    clear_screen();
    printf("Your inventory contains: \n\n");
    printf("%s\n\n", inventory);
    wait_for_enter();
}

void gameOver()
{
    printf("You have failed in your quest and lost your life...\n");
    printf("GAME OVER!\n");
    exit(0);
}

void winGame()
{
    printf("Congratulations! You have successfully retrieved the artifact and completed your quest!\n");
    printf("THANK YOU FOR PLAYING!\n");
    exit(0);
}

void enter_dungeon(char inventory[])
{
    clear_screen();
    printf("You have entered the dungeon...\n\n");

    int room = 0;   // initial room

    while(room != 4)    // final room
    {
        // room descriptions
        switch(room)
        {
            case 0:
                printf("You are in the entrance hall of the dungeon.\n");
                printf("There is a door to the north and a passageway to the east.\n");
                break;
            case 1:
                printf("You are in a long corridor.\n");
                printf("There are doors to the north and south.\n");
                break;
            case 2:
                printf("You are in a large room with a high ceiling.\n");
                printf("There are no visible exits, but there is a treasure chest in the middle of the room.\n");
                break;
            case 3:
                printf("You are in a small room.\n");
                printf("There is an exit to the west and a monster blocking the passageway to the east.\n");
                break;
        }

        // player choices
        printf("\nWhat would you like to do?\n\n");

        if(room == 0)
        {
            printf("1) Go north\n");
        }

        if(room == 0 || room == 1)
        {
            printf("2) Go east\n");
        }

        if(room == 1)
        {
            printf("3) Go north\n");
            printf("4) Go south\n");
        }

        if(room == 2)
        {
            printf("5) Open the treasure chest\n");
        }

        if(room == 3)
        {
            printf("6) Fight the monster\n");
            printf("7) Flee to the west\n");
        }

        printf("\nYour choice: ");
        int choice;
        scanf("%d", &choice);

        // room transitions
        switch(room)
        {
            case 0:
                if(choice == 1)
                {
                    room = 1;
                    printf("You go north.\n");
                }
                else if(choice == 2)
                {
                    room = 2;
                    printf("You go east.\n");
                }
                else
                {
                    printf("Invalid choice.\n");
                }
                break;

            case 1:
                if(choice == 3)
                {
                    room = 2;
                    printf("You go north.\n");
                }
                else if(choice == 4)
                {
                    room = 0;
                    printf("You go south.\n");
                }
                else if(choice == 2)
                {
                    room = 3;
                    printf("You go east.\n");
                }
                else
                {
                    printf("Invalid choice.\n");
                }
                break;

            case 2:
                if(choice == 5)
                {
                    printf("You open the treasure chest and find a key!\n");
                    strcat(inventory, "key ");
                    wait_for_enter();

                    printf("You hear the distant sound of a door unlocking...\n");
                    wait_for_enter();

                    printf("You suddenly find yourself teleported to an unknown location!\n");
                    room = 4;
                }
                else
                {
                    printf("Invalid choice.\n");
                }
                break;

            case 3:
                if(choice == 6)
                {
                    printf("You bravely fight the monster...\n");
                    wait_for_enter();

                    if(rand() % 2 == 0)   // 50% chance of success
                    {
                        printf("You have defeated the monster!\n");
                        wait_for_enter();

                        printf("You notice a key on the ground near the monster's remains.\n");
                        strcat(inventory, "key ");
                        wait_for_enter();

                        printf("You hear the distant sound of a door unlocking...\n");
                        wait_for_enter();

                        printf("You suddenly find yourself teleported to an unknown location!\n");
                        room = 4;
                    }
                    else
                    {
                        printf("Unfortunately, the monster was too powerful and you lost your life...\n");
                        wait_for_enter();
                        gameOver();
                    }
                }
                else if(choice == 7)
                {
                    room = 0;
                    printf("You flee to the west.\n");
                }
                else
                {
                    printf("Invalid choice.\n");
                }
                break;
        }
    }

    winGame();
}

int main()
{
    // initialize inventory
    char inventory[50];
    inventory[0] = '\0';

    show_intro();

    while(1)
    {
        show_menu();

        printf("Your choice: ");
        int choice;
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enter_dungeon(inventory);
                break;
            case 2:
                show_inventory(inventory);
                break;
            case 3:
                printf("\nThank you for playing!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n\n");
                wait_for_enter();
        }
    }

    return 0;
}