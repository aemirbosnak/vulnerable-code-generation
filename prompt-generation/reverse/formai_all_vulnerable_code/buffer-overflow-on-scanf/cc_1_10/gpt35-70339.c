//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROOMS 10
#define GHOSTS 5

int player_room = 0;
bool found_key = false;
bool found_treasure = false;

void print_room(int);
void player_move(int);
void check_events(int);
void encounter_ghost();

int main(void)
{
    srand(time(NULL));
    puts("Welcome to the Haunted House Simulator!");
    puts("You have been dared to spend the night in this spooky house.");
    puts("Try to find the treasure hidden somewhere in the house, but beware of the ghosts!");
    puts("");
    puts("You are standing in front of the entrance to the house.");
    puts("");
    while(!found_treasure)
    {
        print_room(player_room);
        player_move(player_room);
        check_events(player_room);
    }
    puts("Congratulations, you have found the treasure and escaped the haunted house!");
    return 0;
}

void print_room(int room_number)
{
    printf("You are in room %d.\n", room_number+1);
    if(room_number == 0)
    {
        puts("You are standing in front of the entrance to the haunted house.");
        puts("The front door is slightly open, swaying in the wind.");
    }
    else if(room_number == ROOMS-1)
    {
        puts("You have found the treasure!");
        found_treasure = true;
    }
    else if(room_number % (rand() % 3 + 1) == 0)
    {
        puts("You feel a creepy presence in this room.");
        encounter_ghost();
    }
    else
    {
        puts("This room is empty.");
    }
    puts("");
}

void player_move(int current_room)
{
    int target_room;
    printf("Where do you want to go? (0-%d)\n", ROOMS-1);
    scanf("%d", &target_room);
    if(target_room < 0 || target_room >= ROOMS)
    {
        puts("That room does not exist!");
    }
    else if(abs(target_room - current_room) > 1)
    {
        puts("You can only move one room at a time!");
    }
    else
    {
        player_room = target_room;
    }
}

void check_events(int current_room)
{
    if(current_room == 2 && !found_key)
    {
        puts("You have found a rusty key!");
        found_key = true;
    }
    else if(current_room == 8 && found_key)
    {
        puts("You have used the rusty key to open a hidden door!");
    }
}

void encounter_ghost()
{
    int roll = rand() % 6 + 1;
    if(roll <= GHOSTS)
    {
        puts("You have encountered a ghost!");
        if(roll == 1)
        {
            puts("The ghost has possessed you!");
            puts("You are now trapped in the haunted house... forever.");
            exit(0);
        }
        else
        {
            puts("You managed to escape the ghost!");
        }
    }
}