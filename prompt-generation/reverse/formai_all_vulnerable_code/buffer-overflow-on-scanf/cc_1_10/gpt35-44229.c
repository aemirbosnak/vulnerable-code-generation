//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the rooms in the game
#define ROOM_START 0
#define ROOM_HALLWAY 1
#define ROOM_LIBRARY 2
#define ROOM_DUNGEON 3
#define ROOM_TREASURE 4

// Define the actions available to the player
#define ACTION_LOOK 0
#define ACTION_MOVE 1
#define ACTION_OPEN 2
#define ACTION_TAKE 3
#define ACTION_USE 4
#define ACTION_QUIT 5

// Define the items in the game
#define ITEM_KEY 0
#define ITEM_SCROLL 1
#define ITEM_SWORD 2

// Define the maximum number of items that the player can carry
#define MAX_ITEMS 3

int player_location = ROOM_START;
bool has_item[MAX_ITEMS] = { false };
bool game_running = true;

void display_room(int room_id){
    switch(room_id){
        case ROOM_START:
            printf("You are standing in a dark room.\n");
            printf("There is a door to the north, and a hallway to the east.\n");
            break;
        case ROOM_HALLWAY:
            printf("You are standing in a long hallway.\n");
            printf("There are doors to the north and south, and a staircase to the east.\n");
            break;
        case ROOM_LIBRARY:
            printf("You are standing in a dusty library.\n");
            printf("There are shelves of books on all sides, and a door to the west.\n");
            break;
        case ROOM_DUNGEON:
            printf("You are standing in a cold, damp dungeon.\n");
            printf("There is a rusty cage in the center of the room, and a door to the east.\n");
            break;
        case ROOM_TREASURE:
            printf("You are standing in a room filled with treasure.\n");
            printf("Gold coins and jewels glimmer in the light, alongside the legendary sword Excalibur.\n");
            printf("There is a door to the south, leading back to the hallway.\n");
            break;
        default:
            break;
    }
}

void display_inventory(){
    printf("You are carrying:\n");
    if(has_item[ITEM_KEY]){
        printf("  - A key\n");
    }
    if(has_item[ITEM_SCROLL]){
        printf("  - A mysterious scroll\n");
    }
    if(has_item[ITEM_SWORD]){
        printf("  - The legendary sword Excalibur\n");
    }
}

void show_actions(){
    printf("What do you want to do?\n");
    printf("  1. Look around\n");
    printf("  2. Move to another room\n");
    printf("  3. Open or unlock something\n");
    printf("  4. Take an item\n");
    printf("  5. Use an item\n");
    printf("  6. Quit the game\n");
}

void handle_look(){
    display_room(player_location);
    if(player_location == ROOM_LIBRARY){
        printf("You notice a strange book on the shelf, with a glowing aura around it.\n");
    }
    if(player_location == ROOM_TREASURE && has_item[ITEM_SWORD]){
        printf("You feel like you've completed your quest, and reached the end of the game.\n");
        printf("Congratulations, you've won!\n");
        game_running = false;
    }
}

void handle_move(){
    int direction;
    printf("Which way should we go? (1)north, (2)east, (3)south, (4)west\n");
    scanf("%d", &direction);
    if(player_location == ROOM_START && direction == 1){
        printf("The door is locked. You need a key to open it.\n");
    }
    else if(player_location == ROOM_HALLWAY && direction == 1){
        player_location = ROOM_LIBRARY;
    }
    else if(player_location == ROOM_HALLWAY && direction == 3){
        player_location = ROOM_DUNGEON;
    }
    else if(player_location == ROOM_HALLWAY && direction == 2){
        printf("The staircase is blocked by a large boulder. You need to find another way.\n");
    }
    else if(player_location == ROOM_DUNGEON && direction == 1){
        printf("The cage is locked, and you can't open it.\n");
    }
    else if(player_location == ROOM_DUNGEON && direction == 2){
        player_location = ROOM_HALLWAY;
    }
    else if(player_location == ROOM_LIBRARY && direction == 4){
        player_location = ROOM_HALLWAY;
    }
    else if(player_location == ROOM_TREASURE && direction == 3){
        player_location = ROOM_HALLWAY;
    }
    else{
        printf("You can't go that way from here.\n");
    }
}

void handle_open(){
    if(player_location == ROOM_START){
        printf("The door is locked. You need a key to open it.\n");
    }
    else if(player_location == ROOM_TREASURE){
        printf("The treasure chest is already open, and empty.\n");
    }
    else{
        printf("There is nothing to open here.\n");
    }
}

void handle_take(){
    if(player_location == ROOM_TREASURE){
        if(has_item[ITEM_SWORD]){
            printf("You already have the sword, there is no more treasure to take.\n");
        }
        else{
            printf("You take the legendary sword Excalibur from the treasure pile, and feel its power coursing through your veins.\n");
            has_item[ITEM_SWORD] = true;
        }
    }
    else if(player_location == ROOM_LIBRARY){
        printf("You reach for the strange book on the shelf, but as you touch it, you suddenly vanish into thin air.\n");
        printf("GAME OVER\n");
        game_running = false;
    }
    else{
        printf("There is nothing to take here.\n");
    }
}

void handle_use(){
    if(has_item[ITEM_KEY]){
        if(player_location == ROOM_START){
            printf("You insert the key into the lock, and the door creaks open.\n");
            player_location = ROOM_HALLWAY;
        }
        else{
            printf("There is no reason to use the key here.\n");
        }
    }
    else{
        printf("You don't have any items to use.\n");
    }
}

void handle_quit(){
    game_running = false;
}

int main(){
    printf("Welcome to the adventure game!\n\n");
    while(game_running){
        display_room(player_location);
        show_actions();
        int action;
        scanf("%d", &action);
        printf("\n");
        switch(action){
            case ACTION_LOOK:
                handle_look();
                break;
            case ACTION_MOVE:
                handle_move();
                break;
            case ACTION_OPEN:
                handle_open();
                break;
            case ACTION_TAKE:
                handle_take();
                break;
            case ACTION_USE:
                handle_use();
                break;
            case ACTION_QUIT:
                handle_quit();
                break;
            default:
                printf("I didn't understand what you meant. Please try again.\n");
                break;
        }
        printf("\n");
    }
    printf("Thanks for playing!\n");
    return 0;
}