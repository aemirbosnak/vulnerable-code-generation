//FormAI DATASET v1.0 Category: Table Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the game board size
#define BOARD_SIZE 3

// define player signs
#define PLAYER1_SIGN 'X'
#define PLAYER2_SIGN 'O'

// define game states
#define GAME_STATE_RUNNING 0
#define GAME_STATE_PLAYER1_WON 1
#define GAME_STATE_PLAYER2_WON 2
#define GAME_STATE_DRAW 3

// define the game board structure
typedef struct {
    char cells[BOARD_SIZE][BOARD_SIZE];
} GameBoard;

// define the game structure
typedef struct {
    GameBoard board;
    int gameState;
} Game;

// function prototypes
Game createGame();
void displayGameBoard(GameBoard board);
void playerTurn(Game* game, char playerSign);
void getComputerTurn(Game* game, char playerSign);
int checkGameState(GameBoard board);

// main function
int main() {
    Game game = createGame();
    displayGameBoard(game.board);
    do {
        playerTurn(&game, PLAYER1_SIGN);
        if(game.gameState != GAME_STATE_RUNNING) break;
        getComputerTurn(&game, PLAYER2_SIGN);
        displayGameBoard(game.board);
    } while(game.gameState == GAME_STATE_RUNNING);
    switch(game.gameState) {
        case GAME_STATE_PLAYER1_WON:
            printf("Congratulations! You win!");
            break;
        case GAME_STATE_PLAYER2_WON:
            printf("Sorry, you lost.");
            break;
        case GAME_STATE_DRAW:
            printf("It's a draw.");
            break;
    }
    return 0;
}

// function to create a new game
Game createGame() {
    // initialize random seed
    srand(time(NULL));
    // create a blank game board
    GameBoard board;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board.cells[i][j] = ' ';
        }
    }
    // create the game structure and set initial game state
    Game game;
    game.board = board;
    game.gameState = GAME_STATE_RUNNING;
    return game;
}

// function to display the game board
void displayGameBoard(GameBoard board) {
    printf("\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf(" %c | %c | %c ", board.cells[i][0], board.cells[i][1], board.cells[i][2]);
        if(i < BOARD_SIZE - 1) printf("\n---|---|---\n");
    }
    printf("\n");
}

// function for player turn
void playerTurn(Game* game, char playerSign) {
    int row, col;
    do {
        printf("Enter row and column for %c: ", playerSign);
        scanf("%d %d", &row, &col);
    } while(row < 1 || row > 3 || col < 1 || col > 3 || game->board.cells[row-1][col-1] != ' ');
    game->board.cells[row-1][col-1] = playerSign;
    game->gameState = checkGameState(game->board);
    displayGameBoard(game->board);
}

// function for computer turn
void getComputerTurn(Game* game, char playerSign) {
    int row, col;
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while(game->board.cells[row][col] != ' ');
    game->board.cells[row][col] = playerSign;
    game->gameState = checkGameState(game->board);
    printf("The computer played at row %d, column %d.\n", row+1, col+1);
}

// function to check the game state
int checkGameState(GameBoard board) {
    // check rows
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board.cells[i][0] == board.cells[i][1] && board.cells[i][1] == board.cells[i][2]) {
            if(board.cells[i][0] == PLAYER1_SIGN) {
                return GAME_STATE_PLAYER1_WON;
            } else if(board.cells[i][0] == PLAYER2_SIGN) {
                return GAME_STATE_PLAYER2_WON;
            }
        }
    }
    // check columns
    for(int i = 0; i < BOARD_SIZE; i++) {
        if(board.cells[0][i] == board.cells[1][i] && board.cells[1][i] == board.cells[2][i]) {
            if(board.cells[0][i] == PLAYER1_SIGN) {
                return GAME_STATE_PLAYER1_WON;
            } else if(board.cells[0][i] == PLAYER2_SIGN) {
                return GAME_STATE_PLAYER2_WON;
            }
        }
    }
    // check diagonals
    if(board.cells[0][0] == board.cells[1][1] && board.cells[1][1] == board.cells[2][2]) {
        if(board.cells[0][0] == PLAYER1_SIGN) {
            return GAME_STATE_PLAYER1_WON;
        } else if(board.cells[0][0] == PLAYER2_SIGN) {
            return GAME_STATE_PLAYER2_WON;
        }
    }
    if(board.cells[0][2] == board.cells[1][1] && board.cells[1][1] == board.cells[2][0]) {
        if(board.cells[0][2] == PLAYER1_SIGN) {
            return GAME_STATE_PLAYER1_WON;
        } else if(board.cells[0][2] == PLAYER2_SIGN) {
            return GAME_STATE_PLAYER2_WON;
        }
    }
    // check for draw
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board.cells[i][j] == ' ') {
                return GAME_STATE_RUNNING;
            }
        }
    }
    return GAME_STATE_DRAW;
}