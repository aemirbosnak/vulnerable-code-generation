//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PLAYERS 4

int main() {
    int num_players, i, j;
    int player_choice[MAX_PLAYERS];
    int room_chosen[MAX_PLAYERS];
    int haunted_rooms[] = {1, 3, 5, 7, 9};
    int num_haunted_rooms = sizeof(haunted_rooms) / sizeof(int);
    int haunted_player;
    srand(time(NULL));

    printf("*** Welcome to the Haunted House Simulator ***\n\n");
    printf("Enter number of players (1 to %d): ", MAX_PLAYERS);
    scanf("%d", &num_players);

    while (num_players < 1 || num_players > MAX_PLAYERS) {
        printf("Invalid number of players. Please enter a number between 1 and %d: ", MAX_PLAYERS);
        scanf("%d", &num_players);
    }

    printf("\nInstructions: You are all exploring a haunted house with %d rooms.\n", num_haunted_rooms);
    printf("Each round, players will choose a room to enter. Some rooms are haunted and will cause you to lose the game.\n");
    printf("The last player standing wins!\n\n");

    for (i = 0; i < num_players; i++) {
        printf("Player %d, choose a room number from 1 to %d: ", i+1, num_haunted_rooms);
        scanf("%d", &player_choice[i]);

        while (player_choice[i] < 1 || player_choice[i] > num_haunted_rooms) {
            printf("Invalid room number. Please choose a number between 1 and %d: ", num_haunted_rooms);
            scanf("%d", &player_choice[i]);
        }
    }

    printf("\n");

    while (num_players > 1) {
        for (i = 0; i < num_players; i++) {
            room_chosen[i] = player_choice[i];

            for (j = i+1; j < num_players; j++) {
                if (room_chosen[i] == room_chosen[j]) {
                    printf("Player %d and Player %d have chosen the same room. Roll a die to see who goes first.\n", i+1, j+1);
                    if (rand() % 2 == 0) {
                        printf("Player %d goes first.\n", i+1);
                        room_chosen[j] = (room_chosen[j] % num_haunted_rooms) + 1;
                        printf("Player %d, your new room choice is %d.\n", j+1, room_chosen[j]);
                    } else {
                        printf("Player %d goes first.\n", j+1);
                        room_chosen[i] = (room_chosen[i] % num_haunted_rooms) + 1;
                        printf("Player %d, your new room choice is %d.\n", i+1, room_chosen[i]);
                    }
                }
            }

            if (room_chosen[i] == haunted_rooms[rand() % num_haunted_rooms]) {
                haunted_player = i;
                break;
            }
        }

        if (room_chosen[haunted_player] == haunted_rooms[rand() % num_haunted_rooms]) {
            printf("Player %d has entered a haunted room and has been eliminated from the game.\n", haunted_player+1);
            
            for (i = haunted_player; i < num_players-1; i++) {
                player_choice[i] = player_choice[i+1];
            }
            
            num_players--;
        } else {
            printf("No one entered a haunted room this round. Choose your rooms again.\n");
            for (i = 0; i < num_players; i++) {
                printf("Player %d, choose a room number from 1 to %d: ", i+1, num_haunted_rooms);
                scanf("%d", &player_choice[i]);

                while (player_choice[i] < 1 || player_choice[i] > num_haunted_rooms) {
                    printf("Invalid room number. Please choose a number between 1 and %d: ", num_haunted_rooms);
                    scanf("%d", &player_choice[i]);
                }
            }
        }

        printf("\n");
    }

    printf("Player %d wins the game!\n", player_choice[0]);

    return 0;
}