//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_PLAYERS 4

// Declare necessary data structures
typedef struct {
    int room_number;
    int is_occupied[MAX_PLAYERS];
    int has_ghost;
} Room;

typedef struct {
    int player_number;
    int current_room;
    int lives;
} Player;

// Declare necessary global variables
Room rooms[MAX_ROOMS];
Player players[MAX_PLAYERS];
int num_players = 0;

// Function prototypes
void create_rooms();
void add_player();
void run_game();
int roll_dice();
int check_ghost(int player_room);
int move_player(int player_num);

// The main function
int main() {
    puts("Welcome to the Haunted House Simulator!");
    create_rooms();
    add_player();
    run_game();
    puts("Game over!");
    return 0;
}

// Function to create the rooms
void create_rooms() {
    // Set up the random number generator
    srand(time(NULL));
    
    // Set up the rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].room_number = i + 1;
        for (int j = 0; j < MAX_PLAYERS; j++) {
            rooms[i].is_occupied[j] = 0;
        }
        rooms[i].has_ghost = (rand() % 10 == 0);
    }
}

// Function to add a player to the game
void add_player() {
    if (num_players >= MAX_PLAYERS) {
        printf("Sorry, the game is already full.\n");
        return;
    }
    
    printf("Enter the name of the player: ");
    char name[100];
    scanf("%s", name);
    printf("Welcome, %s!\n", name);
    
    players[num_players].player_number = num_players + 1;
    players[num_players].current_room = 1;
    players[num_players].lives = 3;
    rooms[0].is_occupied[num_players] = 1;
    
    num_players++;
}

// Function to run the game
void run_game() {
    int winner = -1;
    
    while (winner == -1) {
        for (int i = 0; i < num_players; i++) {
            printf("============================\n");
            printf("Player %d's turn\n", players[i].player_number);
            printf("You are in room %d\n", players[i].current_room);
            
            int ghost_here = check_ghost(players[i].current_room);
            if (ghost_here) {
                printf("A ghost is here! You have to roll a six to escape!\n");
                int roll = roll_dice();
                printf("You rolled a %d!\n", roll);
                if (roll == 6) {
                    printf("You escaped from the ghost!\n");
                } else {
                    printf("The ghost got you! You lost a life!\n");
                    players[i].lives--;
                    if (players[i].lives <= 0) {
                        printf("Sorry, you are out of lives. You are a ghost now.\n");
                        rooms[players[i].current_room - 1].is_occupied[i] = 0;
                        rooms[players[i].current_room - 1].has_ghost = 1;
                    }
                }
            }
            
            if (players[i].lives > 0) {
                int move_success = move_player(i);
                if (!move_success) {
                    printf("Sorry, you cannot move in that direction.\n");
                }
            }
            
            // Check for a winner
            if (players[i].current_room == MAX_ROOMS) {
                winner = i;
                break;
            }
        }
    }
    
    printf("Congratulations, player %d! You won!\n", players[winner].player_number);
}

// Function to roll a six-sided die
int roll_dice() {
    return rand() % 6 + 1;
}

// Function to check if a ghost is in the current room
int check_ghost(int player_room) {
    if (rooms[player_room - 1].has_ghost) {
        return 1;
    }
    return 0;
}

// Function to move the player
int move_player(int player_num) {
    printf("Which direction do you want to move (N, S, E, W)? ");
    char direction;
    scanf(" %c", &direction);
    
    if (direction == 'N' && player_num > 0) {
        if (rooms[players[player_num].current_room - 1].is_occupied[player_num - 1]) {
            printf("Sorry, another player is already in that room.\n");
            return 0;
        }
        rooms[players[player_num].current_room - 1].is_occupied[player_num] = 0;
        rooms[players[player_num - 1].current_room - 1].is_occupied[player_num] = 1;
        players[player_num].current_room = players[player_num - 1].current_room;
        printf("You are now in room %d.\n", players[player_num].current_room);
        return 1;
    } else if (direction == 'S' && player_num < num_players - 1) {
        if (rooms[players[player_num].current_room - 1].is_occupied[player_num + 1]) {
            printf("Sorry, another player is already in that room.\n");
            return 0;
        }
        rooms[players[player_num].current_room - 1].is_occupied[player_num] = 0;
        rooms[players[player_num + 1].current_room - 1].is_occupied[player_num] = 1;
        players[player_num].current_room = players[player_num + 1].current_room;
        printf("You are now in room %d.\n", players[player_num].current_room);
        return 1;
    } else if (direction == 'E' && players[player_num].current_room < MAX_ROOMS) {
        if (rooms[players[player_num].current_room].is_occupied[player_num]) {
            printf("Sorry, another player is already in that room.\n");
            return 0;
        }
        rooms[players[player_num].current_room - 1].is_occupied[player_num] = 0;
        rooms[players[player_num].current_room].is_occupied[player_num] = 1;
        players[player_num].current_room++;
        printf("You are now in room %d.\n", players[player_num].current_room);
        return 1;
    } else if (direction == 'W' && players[player_num].current_room > 1) {
        if (rooms[players[player_num].current_room - 2].is_occupied[player_num]) {
            printf("Sorry, another player is already in that room.\n");
            return 0;
        }
        rooms[players[player_num].current_room - 1].is_occupied[player_num] = 0;
        rooms[players[player_num].current_room - 2].is_occupied[player_num] = 1;
        players[player_num].current_room--;
        printf("You are now in room %d.\n", players[player_num].current_room);
        return 1;
    } else {
        return 0;
    }
}