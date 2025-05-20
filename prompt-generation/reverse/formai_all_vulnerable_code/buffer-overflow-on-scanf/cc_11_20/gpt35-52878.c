//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Global Variables
int room_number = 1, cards = 0, keys = 0, matches = 0;
int door_locked = 0, window_broken = 0, gas_stove_on = 0;
int ghost_appeared = 0, player_alive = 1;

//Function Declarations
void display_room();
void check_room();
int flip_coin();
int check_item_existence(char item_name[]);
void check_if_alive();

int main()
{
    printf("Welcome to the Haunted House Simulator!\n\n");

    while(player_alive && room_number <= 10)
    {
        display_room();
        check_room();
    }

    if(!player_alive)
    {
        printf("GAME OVER! You have been killed by the ghost.\n");
    }
    else
    {
        printf("Congratulations! You have successfully escaped the haunted house.\n");
    }

    return 0;
}

// Displays the information about the current room
void display_room()
{
    printf("ROOM %d\n", room_number);
    switch(room_number)
    {
        case 1:
            printf("You are standing in the living room. There is a door on your left and a window on your right.\n");
            if(!door_locked)
            {
                printf("The door is unlocked.\n");
            }
            if(!window_broken)
            {
                printf("The window is unbroken.\n");
            }
            break;
        case 2:
            printf("You are standing in the kitchen. There is a gas stove on the left and a drawer on the right.\n");
            if(!gas_stove_on)
            {
                printf("The gas stove is off.\n");
            }
            if(!check_item_existence("matchstick"))
            {
                printf("You don't have a matchstick to light the stove.\n");
            }
            break;
        case 3:
            printf("You are standing in the dining room. There are two doors - one on your left and one on your right.\n");
            if(!door_locked)
            {
                printf("The left door is unlocked.\n");
            }
            if(!keys)
            {
                printf("You don't have the key to the right door.\n");
            }
            break;
        case 4:
            printf("You are standing in the bathroom. There is a drawer on your left and a mirror in front of you.\n");
            if(!check_item_existence("card"))
            {
                printf("You don't have a card to slide into the drawer's lock.\n");
            }
            break;
        case 5:
            printf("You are standing in the bedroom. There is a bed, a cupboard, and a table with a lamp on it.\n");
            if(!check_item_existence("key"))
            {
                printf("You don't have the key to the cupboard.\n");
            }
            break;
        case 6:
            printf("You are standing in the guest room. There is a bed, a table, and a drawer next to the bed.\n");
            if(!check_item_existence("key"))
            {
                printf("You don't have the key to the drawer.\n");
            }
            break;
        case 7:
            printf("You are standing in the study room. There is a desk, a bookshelf, and a painting on the wall.\n");
            if(!check_item_existence("card"))
            {
                printf("You don't have a card to slide into the desk's lock.\n");
            }
            break;
        case 8:
            printf("You are standing in the gallery. There are paintings all around.\n");
            if(!check_item_existence("matchstick"))
            {
                printf("You don't have a matchstick to light the lamp in the gallery.\n");
            }
            break;
        case 9:
            printf("You are standing in the basement. There is a locked door on your right and a window on your left.\n");
            if(!keys)
            {
                printf("You don't have the key to the door.\n");
            }
            if(!window_broken)
            {
                printf("The window is unbroken.\n");
            }
            break;
        case 10:
            printf("You are standing in the attic. There is a chest on your left and a window on your right.\n");
            if(!check_item_existence("key"))
            {
                printf("You don't have the key to the chest.\n");
            }
            if(!window_broken)
            {
                printf("The window is unbroken.\n");
            }
            break;
    }
}

// Checks the current room for any actions that can be performed
void check_room()
{
    switch(room_number)
    {
        case 1:
            if(!door_locked)
            {
                printf("Do you want to go through the door on the left? (yes/no)\n");
                char choice[10];
                scanf("%s", choice);
                if(strcmp(choice, "yes") == 0)
                {
                    room_number = 3;
                }
            }

            if(!window_broken)
            {
                printf("Do you want to break the window on your right? (yes/no)\n");
                char choice[10];
                scanf("%s", choice);
                if(strcmp(choice, "yes") == 0)
                {
                    window_broken = 1;
                    printf("You broke the window!\n");
                    check_if_alive();
                }
            }
            break;
        case 2:
            if(!gas_stove_on && check_item_existence("matchstick"))
            {
                printf("Do you want to light the gas stove? (yes/no)\n");
                char choice[10];
                scanf("%s", choice);
                if(strcmp(choice, "yes") == 0)
                {
                    gas_stove_on = 1;
                    matches--;
                    printf("You lit the gas stove!\n");
                    check_if_alive();
                }
            }
            break;
        case 3:
            printf("Do you want to go through the left door? (yes/no)\n");
            char choice[10];
            scanf("%s", choice);
            if(strcmp(choice, "yes") == 0)
            {
                room_number = 4;
            }
            if(keys && !door_locked)
            {
                printf("Do you want to use the key to unlock the right door? (yes/no)\n");
                scanf("%s", choice);
                if(strcmp(choice, "yes") == 0)
                {
                    door_locked = 1;
                    printf("You unlocked the door!\n");
                }
            }
            break;
        case 4:
            if(check_item_existence("card"))
            {
                printf("Do you want to slide the card into the drawer's lock? (yes/no)\n");
                char choice[10];
                scanf("%s", choice);
                if(strcmp(choice, "yes") == 0)
                {
                    cards--;
                    printf("You opened the drawer! There is a key inside.\n");
                    keys++;
                }
            }
            break;
        case 5:
            if(check_item_existence("key"))
            {
                printf("Do you want to use the key to unlock the cupboard? (yes/no)\n");
                char choice[10];
                scanf("%s", choice);
                if(strcmp(choice, "yes") == 0)
                {
                    printf("You opened the cupboard! There is a card inside.\n");
                    cards++;
                }
            }
            break;
        case 6:
            if(check_item_existence("key"))
            {
                printf("Do you want to use the key to unlock the drawer? (yes/no)\n");
                char choice[10];
                scanf("%s", choice);
                if(strcmp(choice, "yes") == 0)
                {
                    printf("You opened the drawer! There is a matchstick inside.\n");
                    matches++;
                }
            }
            break;
        case 7:
            if(check_item_existence("card"))
            {
                printf("Do you want to slide the card into the desk's lock? (yes/no)\n");
                char choice[10];
                scanf("%s", choice);
                if(strcmp(choice, "yes") == 0)
                {
                    cards--;
                    printf("You opened the desk! There is a matchstick inside.\n");
                    matches++;
                }
            }
            break;
        case 8:
            if(check_item_existence("matchstick"))
            {
                printf("Do you want to light the lamp in the gallery using the matchstick? (yes/no)\n");
                char choice[10];
                scanf("%s", choice);
                if(strcmp(choice, "yes") == 0)
                {
                    matches--;
                    printf("You lit the lamp! There is a door on the opposite wall that you didn't notice before.\n");
                }
            }
            break;
        case 9:
            if(keys && !door_locked)
            {
                printf("Do you want to use the key to unlock the door on your right? (yes/no)\n");
                char choice[10];
                scanf("%s", choice);
                if(strcmp(choice, "yes") == 0)
                {
                    door_locked = 1;
                    printf("You unlocked the door!\n");
                }
            }
            if(!window_broken)
            {
                printf("Do you want to break the window on your left? (yes/no)\n");
                char choice[10];
                scanf("%s", choice);
                if(strcmp(choice, "yes") == 0)
                {
                    window_broken = 1;
                    printf("You broke the window!\n");
                    check_if_alive();
                }
            }
            break;
        case 10:
            if(check_item_existence("key"))
            {
                printf("Do you want to use the key to unlock the chest? (yes/no)\n");
                char choice[10];
                scanf("%s", choice);
                if(strcmp(choice, "yes") == 0)
                {
                    printf("You unlocked the chest! There is a card inside.\n");
                    cards++;
                }
            }
            if(!window_broken)
            {
                printf("Do you want to break the window on your right? (yes/no)\n");
                char choice[10];
                scanf("%s", choice);
                if(strcmp(choice, "yes") == 0)
                {
                    window_broken = 1;
                    printf("You broke the window!\n");
                    check_if_alive();
                }
            }
    }
}

// Flips a coin - returns 0 or 1
int flip_coin()
{
    srand(time(NULL));
    return rand() % 2;
}

// Checks whether an item exists in the player's inventory
int check_item_existence(char item_name[])
{
    if(strcmp(item_name, "card") == 0)
    {
        return cards;
    }
    else if(strcmp(item_name, "key") == 0)
    {
        return keys;
    }
    else if(strcmp(item_name, "matchstick") == 0)
    {
        return matches;
    }
    return 0;
}

// Checks if the player is alive
void check_if_alive()
{
    if(!flip_coin())
    {
        printf("A ghost appeared! Oh no! You have been killed.\n");
        player_alive = 0;
    }
}