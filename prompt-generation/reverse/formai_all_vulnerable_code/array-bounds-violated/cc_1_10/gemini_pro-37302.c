//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//define the size of the table
#define TABLE_SIZE 5

//define the number of players
#define NUM_PLAYERS 2

//define the number of turns
#define NUM_TURNS 10

//define the different states of the game
#define STATE_PLAYING 0
#define STATE_PLAYER1_WIN 1
#define STATE_PLAYER2_WIN 2
#define STATE_DRAW 3

//define the different types of moves
#define MOVE_ADD 0
#define MOVE_REMOVE 1

//define the structure of a move
typedef struct {
    int type;
    int row;
    int col;
} Move;

//define the structure of a player
typedef struct {
    int id;
    int score;
} Player;

//create the table
int table[TABLE_SIZE][TABLE_SIZE];

//create the players
Player players[NUM_PLAYERS];

//create the current move
Move current_move;

//create the current state of the game
int game_state;

//initialize the game
void init_game() {
    //initialize the table
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            table[i][j] = 0;
        }
    }

    //initialize the players
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i].id = i + 1;
        players[i].score = 0;
    }

    //initialize the current move
    current_move.type = MOVE_ADD;
    current_move.row = 0;
    current_move.col = 0;

    //initialize the current state of the game
    game_state = STATE_PLAYING;
}

//print the table
void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

//make a move
void make_move(Move move) {
    //add a piece to the table
    if (move.type == MOVE_ADD) {
        table[move.row][move.col] = 1;
    }
    //remove a piece from the table
    else if (move.type == MOVE_REMOVE) {
        table[move.row][move.col] = 0;
    }
}

//check if the game is over
int check_game_over() {
    //check if there are no more moves left
    int num_moves = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            if (table[i][j] == 0) {
                num_moves++;
            }
        }
    }
    if (num_moves == 0) {
        return STATE_DRAW;
    }

    //check if there is a winner
    int player1_score = 0;
    int player2_score = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            if (table[i][j] == 1) {
                if ((i == 0) || (i == TABLE_SIZE - 1) || (j == 0) || (j == TABLE_SIZE - 1)) {
                    player1_score++;
                }
                else {
                    player2_score++;
                }
            }
        }
    }
    if (player1_score > player2_score) {
        return STATE_PLAYER1_WIN;
    }
    else if (player2_score > player1_score) {
        return STATE_PLAYER2_WIN;
    }
    else {
        return STATE_PLAYING;
    }
}

//get the next move from a player
Move get_move(Player player) {
    Move move;

    //get the type of move from the player
    printf("Player %d, enter the type of move (0 for add, 1 for remove): ", player.id);
    scanf("%d", &move.type);

    //get the row and column of the move from the player
    printf("Player %d, enter the row and column of the move (0-indexed): ", player.id);
    scanf("%d %d", &move.row, &move.col);

    return move;
}

//play the game
void play_game() {
    //initialize the game
    init_game();

    //loop until the game is over
    while (game_state == STATE_PLAYING) {
        //get the next move from each player
        Move move1 = get_move(players[0]);
        Move move2 = get_move(players[1]);

        //make the moves
        make_move(move1);
        make_move(move2);

        //print the table
        print_table();

        //check if the game is over
        game_state = check_game_over();
    }

    //print the winner
    if (game_state == STATE_PLAYER1_WIN) {
        printf("Player 1 wins!\n");
    }
    else if (game_state == STATE_PLAYER2_WIN) {
        printf("Player 2 wins!\n");
    }
    else if (game_state == STATE_DRAW) {
        printf("Draw!\n");
    }
}

//main function
int main() {
    //seed the random number generator
    srand(time(NULL));

    //play the game
    play_game();

    return 0;
}