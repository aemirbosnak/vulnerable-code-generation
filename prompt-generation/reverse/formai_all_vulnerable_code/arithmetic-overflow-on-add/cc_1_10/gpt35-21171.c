//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void delay(int delay_time);
void intro();
void print_room(char room[][70], int rows);
bool is_door(char direction, int row, int col);
bool is_key(int row, int col);
bool is_monster(int row, int col);
bool is_exit(int row, int col);
int move_player(char direction, int row, int col);
bool check_game_over(int row, int col);
int generate_random(int max);
void spawn_key(int row, int col);
void spawn_monster(int row, int col);

// game variables
char current_room[10][70];
int player_row = 1;
int player_col = 1;
bool has_key = false;
bool game_over = false;

int main() {
    // seed the random number generator
    srand(time(NULL));

    // print introduction message
    intro();

    // initialize current room
    strcpy(current_room[0], "#####################################################");
    strcpy(current_room[1], "#P                                                K#");
    strcpy(current_room[2], "#                                                 ##");
    strcpy(current_room[3], "#      #######################################    #");
    strcpy(current_room[4], "#      #                             M       #    #");
    strcpy(current_room[5], "#      #                                       #    #");
    strcpy(current_room[6], "#      ###########           #############    #    #");
    strcpy(current_room[7], "#                 #                         #    #");
    strcpy(current_room[8], "#                E#                        M     #");
    strcpy(current_room[9], "#####################################################");

    // game loop
    while (!game_over) {
        print_room(current_room, 10);  // display the current room

        char input = getchar();  // prompt the user for input
        getchar();  // consume extra newline character

        switch (input) {
        case 'w':  // move up
            player_row = move_player('w', player_row, player_col);
            break;
        case 'a':  // move left
            player_col = move_player('a', player_row, player_col);
            break;
        case 's':  // move down
            player_row = move_player('s', player_row, player_col);
            break;
        case 'd':  // move right
            player_col = move_player('d', player_row, player_col);
            break;
        default:
            break;
        }

        if (check_game_over(player_row, player_col)) {  // check if the game is over
            game_over = true;
            continue;
        }
    }

    // display game over message
    printf("GAME OVER\n");
    if (has_key) {
        printf("You escaped with the key!\n");
    } else {
        printf("You failed to escape!\n");
    }

    return 0;
}

// delay function
void delay(int delay_time) {
    clock_t start_time = clock();
    while (clock() < start_time + delay_time);
}

// introduction message
void intro() {
    printf("Welcome to the Haunted House Simulator!\n");
    delay(1000);
    printf("You have been trapped inside a haunted house.\n");
    delay(1000);
    printf("Your goal is to find the key and escape through the exit.\n");
    delay(1000);
    printf("Beware of the monsters that roam the halls!\n");
    delay(1000);
    printf("Good luck...\n\n");
    delay(1000);
}

// print current room
void print_room(char room[][70], int rows) {
    system("clear");  // clear the terminal

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < 70; c++) {
            printf("%c", room[r][c]);
        }
        printf("\n");
    }
}

// check if a given direction is a door
bool is_door(char direction, int row, int col) {
    switch (direction) {
    case 'w':
        return current_room[row - 1][col] == '#';
    case 'a':
        return current_room[row][col - 1] == '#';
    case 's':
        return current_room[row + 1][col] == '#';
    case 'd':
        return current_room[row][col + 1] == '#';
    default:
        return false;
    }
}

// check if there is a key at the given position
bool is_key(int row, int col) {
    return current_room[row][col] == 'K';
}

// check if there is a monster at the given position
bool is_monster(int row, int col) {
    return current_room[row][col] == 'M';
}

// check if there is an exit at the given position
bool is_exit(int row, int col) {
    return current_room[row][col] == 'E';
}

// move the player in the given direction
int move_player(char direction, int row, int col) {
    int new_row = row;
    int new_col = col;

    switch (direction) {
    case 'w':  // move up
        if (!is_door('w', row, col)) {
            new_row--;
        }
        break;
    case 'a':  // move left
        if (!is_door('a', row, col)) {
            new_col--;
        }
        break;
    case 's':  // move down
        if (!is_door('s', row, col)) {
            new_row++;
        }
        break;
    case 'd':  // move right
        if (!is_door('d', row, col)) {
            new_col++;
        }
        break;
    default:
        break;
    }

    // check if there is a key at the new position
    if (is_key(new_row, new_col)) {
        has_key = true;
        spawn_key(row, col);  // spawn a new key somewhere else
    }

    // check if there is a monster at the new position
    if (is_monster(new_row, new_col)) {
        if (has_key) {  // player has the key
            has_key = false;
            spawn_key(row, col);  // spawn a new key somewhere else
        } else {  // player does not have the key
            game_over = true;
            return new_row;
        }
    }

    // check if there is an exit at the new position
    if (is_exit(new_row, new_col)) {
        if (has_key) {  // player has the key and can escape
            game_over = true;
            return new_row;
        }
    }

    // update the current room
    current_room[row][col] = ' ';  // remove player from old position
    current_room[new_row][new_col] = 'P';  // add player to new position

    return new_row;
}

// check if the game is over
bool check_game_over(int row, int col) {
    return is_monster(row, col) && !has_key;
}

// generate a random number between 0 and max-1
int generate_random(int max) {
    return rand() % max;
}

// spawn a new key somewhere else
void spawn_key(int row, int col) {
    int new_row, new_col;
    do {
        new_row = generate_random(10);
        new_col = generate_random(70);
    } while (current_room[new_row][new_col] != ' ');  // loop until empty cell is found
    current_room[new_row][new_col] = 'K';  // place new key
}

// spawn a new monster somewhere else
void spawn_monster(int row, int col) {
    int new_row, new_col;
    do {
        new_row = generate_random(10);
        new_col = generate_random(70);
    } while (current_room[new_row][new_col] != ' ');  // loop until empty cell is found
    current_room[new_row][new_col] = 'M';  // place new monster
}