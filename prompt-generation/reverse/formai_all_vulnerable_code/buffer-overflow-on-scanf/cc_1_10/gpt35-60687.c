//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define NUM_OF_ROOMS 5

void sig_handler(int signo);

int main()
{
    int rooms[NUM_OF_ROOMS] = {0};
    int current_room = 0;
    int ghost_in_room = 0;
    int player_won = 0;
    int player_lost = 0;
    signal(SIGINT, sig_handler);

    srand(time(NULL));

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are currently in room %d.\n", current_room + 1);
    printf("Look around and find the ghost!\n");

    while(!player_won && !player_lost) {
        int go_to_room = 0;
        ghost_in_room = (rand() % NUM_OF_ROOMS) == current_room;
        printf("\nYou are in room %d.\n", current_room + 1);
        if(ghost_in_room) {
            printf("Oops, you found the ghost! You lost.\n");
            player_lost = 1;
            break;
        }
        printf("Where would you like to go? (1-%d): ", NUM_OF_ROOMS);
        scanf("%d", &go_to_room);
        if(go_to_room < 1 || go_to_room > NUM_OF_ROOMS) {
            printf("Invalid room number.\n");
            continue;
        }
        current_room = go_to_room - 1;
        rooms[current_room] = 1;
        printf("You moved to room %d.\n", current_room + 1);
        int all_rooms_visited = 1;
        for(int i = 0; i < NUM_OF_ROOMS; i++) {
            if(!rooms[i]) {
                all_rooms_visited = 0;
                break;
            }
        }
        if(all_rooms_visited) {
            printf("Congratulations, you visited all the rooms and won!\n");
            player_won = 1;
        }
    }
}

void sig_handler(int signo)
{
    if (signo == SIGINT) {
        printf("\nReceived SIGINT, shutting down Haunted House Simulator.\n");
        exit(0);
    }
}