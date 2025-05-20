//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Define the number of disks
#define NUM_DISKS 3

// Define the towers
#define TOWER_A 'A'
#define TOWER_B 'B'
#define TOWER_C 'C'

// Define the colors of the disks
#define COLOR_RED 'R'
#define COLOR_GREEN 'G'
#define COLOR_BLUE 'B'

// Define the player names
#define PLAYER_1 "Sir Knight"
#define PLAYER_2 "Lady Faire"

// Declare the global variables
int num_moves = 0;
char towers[3] = {TOWER_A, TOWER_B, TOWER_C};
char disks[NUM_DISKS] = {COLOR_RED, COLOR_GREEN, COLOR_BLUE};

// Declare the function prototypes
void move_disk(char from_tower, char to_tower);
void display_towers();
int get_player_move(char player);
int check_for_win();

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the towers
    for (int i = 0; i < NUM_DISKS; i++)
    {
        towers[i] = disks[i];
    }

    // Display the initial state of the towers
    display_towers();

    // Get the player's moves
    while (!check_for_win())
    {
        int player_move = get_player_move(PLAYER_1);
        move_disk(towers[player_move - 1], towers[player_move]);
        display_towers();
    }

    // Display the final state of the towers
    display_towers();

    // Print the number of moves
    printf("The number of moves is %d.\n", num_moves);

    return 0;
}

void move_disk(char from_tower, char to_tower)
{
    // Check if the move is valid
    if (towers[from_tower - 1] == ' ' || towers[to_tower - 1] != ' ')
    {
        printf("Invalid move.\n");
        return;
    }

    // Move the disk
    towers[to_tower - 1] = towers[from_tower - 1];
    towers[from_tower - 1] = ' ';

    // Increment the number of moves
    num_moves++;
}

void display_towers()
{
    // Clear the screen
    system("clear");

    // Display the towers
    printf("Tower A: %c\n", towers[0]);
    printf("Tower B: %c\n", towers[1]);
    printf("Tower C: %c\n", towers[2]);
}

int get_player_move(char player)
{
    // Get the player's move
    int move;
    printf("%s, enter your move (1-3): ", player);
    scanf("%d", &move);

    // Return the player's move
    return move;
}

int check_for_win()
{
    // Check if all of the disks are on the same tower
    char winning_tower = towers[0];
    for (int i = 1; i < NUM_DISKS; i++)
    {
        if (towers[i] != winning_tower)
        {
            return 0;
        }
    }

    // Return true if all of the disks are on the same tower
    return 1;
}