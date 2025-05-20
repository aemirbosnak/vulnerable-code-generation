//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define SIZE 3 // size of the board 

char board[SIZE][SIZE]; // 2D array for the board

// displays the board
void display_board() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%c ", board[i][j]); // prints the value at that position
        }
        printf("\n");
    }
}

// initializes the board to contain only spaces
void init_board() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// checks if a player has won
int check_win(char symbol) {
    int row, col;
    
    // checks rows
    for(row=0; row<SIZE; row++) {
        for(col=0; col<SIZE; col++) {
            if(board[row][col] != symbol) {
                break;
            }
        }
        if(col == SIZE) {
            return 1;
        }
    }
    
    // checks columns
    for(col=0; col<SIZE; col++) {
        for(row=0; row<SIZE; row++) {
            if(board[row][col] != symbol) {
                break;
            }
        }
        if(row == SIZE) {
            return 1;
        }
    }
    
    // checks diagonal 1
    for(row=0, col=0; row<SIZE; row++, col++) {
        if(board[row][col] != symbol) {
            break;
        }
    }
    if(row == SIZE) {
        return 1;
    }
    
    // checks diagonal 2
    for(row=0, col=SIZE-1; row<SIZE; row++, col--) {
        if(board[row][col] != symbol) {
            break;
        }
    }
    if(row == SIZE) {
        return 1;
    }
    
    return 0;
}

// checks if the game is a tie
int check_tie() {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

// AI function to make the computer's move
void computer_move(char symbol) {
    int row, col;
    
    // checks if computer can win in the next move
    for(row=0; row<SIZE; row++) {
        for(col=0; col<SIZE; col++) {
            if(board[row][col] == ' ') {
                board[row][col] = symbol;
                if(check_win(symbol)) {
                    return;
                }
                board[row][col] = ' ';
            }
        }
    }
    
    // checks if player can win in the next move and blocks
    for(row=0; row<SIZE; row++) {
        for(col=0; col<SIZE; col++) {
            if(board[row][col] == ' ') {
                board[row][col] = (symbol == 'X') ? 'O' : 'X';
                if(check_win((symbol == 'X') ? 'O' : 'X')) {
                    board[row][col] = symbol;
                    return;
                }
                board[row][col] = ' ';
            }
        }
    }
    
    // if none of the above cases, choose a random empty space
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while(board[row][col] != ' ');
    
    board[row][col] = symbol;
}

// main function that runs the game
int main() {
    char player, computer;
    int turn = 0; // counts the number of turns
    
    printf("Welcome to Tic Tac Toe AI!\n");
    printf("Would you like to play X or O? ");
    scanf("%c", &player);
    getchar(); // clears the input buffer
    
    if(player == 'X' || player == 'x') {
        computer = 'O';
    }
    else {
        computer = 'X';
    }
    
    init_board(); // initializes the board
    display_board(); // displays the board
    
    // main game loop
    while(1) {
        // player's turn
        if(turn % 2 == 0) {
            int row, col;
            
            // get player's move
            printf("Enter your move (row column): ");
            scanf("%d %d", &row, &col);
            row--; // adjust for 0-indexing
            col--;
            
            if(row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != ' ') {
                printf("Invalid move. Try again.\n");
                continue;
            }
            
            board[row][col] = player; // updates the board
            turn++;
        }
        // computer's turn
        else {
            printf("Computer's move:\n");
            computer_move(computer); // makes the computer's move
            turn++;
        }
        
        display_board(); // displays the board
        
        if(check_win(player)) {
            printf("Congratulations! You win!\n");
            break;
        }
        else if(check_win(computer)) {
            printf("Sorry, you lose. Better luck next time!\n");
            break;
        }
        else if(check_tie()) {
            printf("It's a tie!\n");
            break;
        }
    }
    
    return 0;
}