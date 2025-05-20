//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: calm
#include <stdio.h>

char board[3][3]; // our tic tac toe board

// Function to print the board
void print_board() {
    printf("\n");
    for(int i=0; i<3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if(i != 2) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n\n");
}

// Function to check if the move is valid or not
int is_valid_move(int row, int col) {
    if(row < 0 || row > 2 || col < 0 || col > 2) {
        return 0; // Invalid move
    }
    if(board[row][col] != '-') {
        return 0; // Cell is already occupied
    }
    return 1; // Valid Move
}

// Function to check if the game is over or not
int check_game_over() {
    // Check Rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return 1; // Game Over
        }
    }
    
    // Check Columns
    for(int j=0; j<3; j++) {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '-') {
            return 1; // Game Over
        }
    }
    
    // Check Diagonals
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-')) {
        return 1; // Game Over
    }
    
    // Check if the board is full
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == '-') {
                return 0; // Game is still on
            }
        }
    }
    
    return 2; // Game Over - Draw
}

// Function to check if the CPU can win in the next move
int cpu_winning_move(char cpu_symbol) {
    // Check Rows
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][0] == cpu_symbol && board[i][2] == '-') {
            board[i][2] = cpu_symbol;
            return 1;
        }
        if(board[i][0] == board[i][2] && board[i][0] == cpu_symbol && board[i][1] == '-') {
            board[i][1] = cpu_symbol;
            return 1;
        }
        if(board[i][1] == board[i][2] && board[i][1] == cpu_symbol && board[i][0] == '-') {
            board[i][0] = cpu_symbol;
            return 1;
        }
    }
    
    // Check Columns
    for(int j=0; j<3; j++) {
        if(board[0][j] == board[1][j] && board[0][j] == cpu_symbol && board[2][j] == '-') {
            board[2][j] = cpu_symbol;
            return 1;
        }
        if(board[0][j] == board[2][j] && board[0][j] == cpu_symbol && board[1][j] == '-') {
            board[1][j] = cpu_symbol;
            return 1;
        }
        if(board[1][j] == board[2][j] && board[1][j] == cpu_symbol && board[0][j] == '-') {
            board[0][j] = cpu_symbol;
            return 1;
        }
    }
    
    // Check Diagonal
    if(board[0][0] == board[1][1] && board[0][0] == cpu_symbol && board[2][2] == '-') {
        board[2][2] = cpu_symbol;
        return 1;
    }
    if(board[0][0] == board[2][2] && board[0][0] == cpu_symbol && board[1][1] == '-') {
        board[1][1] = cpu_symbol;
        return 1;
    }
    if(board[1][1] == board[2][2] && board[1][1] == cpu_symbol && board[0][0] == '-') {
        board[0][0] = cpu_symbol;
        return 1;
    }
    if(board[0][2] == board[1][1] && board[0][2] == cpu_symbol && board[2][0] == '-') {
        board[2][0] = cpu_symbol;
        return 1;
    }
    if(board[0][2] == board[2][0] && board[0][2] == cpu_symbol && board[1][1] == '-') {
        board[1][1] = cpu_symbol;
        return 1;
    }
    if(board[1][1] == board[2][0] && board[1][1] == cpu_symbol && board[0][2] == '-') {
        board[0][2] = cpu_symbol;
        return 1;
    }
    
    return 0;
}

// Function to check if the CPU needs to prevent user from winning 
int cpu_blocking_move(char user_symbol) {
    int cpu_winning = cpu_winning_move(user_symbol == 'X' ? 'O' : 'X');
    if(cpu_winning) {
        return 1;
    }
    return 0;
}

// Function to get CPU's move
void get_cpu_move(char cpu_symbol) {
    // Check if CPU can win in the next move
    int cpu_winning = cpu_winning_move(cpu_symbol);
    if(cpu_winning) {
        return;
    }
    
    // Check if CPU needs to prevent user from winning
    int cpu_blocking = cpu_blocking_move(cpu_symbol);
    if(cpu_blocking) {
        return;
    }
    
    // Otherwise, make a random move
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while(!is_valid_move(row, col));
    board[row][col] = cpu_symbol;
}

int main() {
    // Initialize the board with empty cells
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = '-';
        }
    }
    
    // Prompt user to choose symbol
    char user_symbol;
    printf("Choose your symbol (X or O): ");
    scanf("%c", &user_symbol);
    
    // Initialize CPU's symbol
    char cpu_symbol = user_symbol == 'X' ? 'O' : 'X';
    
    // Print the empty board
    print_board();
    
    // Start the game
    int game_over = 0;
    while(!game_over) {
        // User's turn
        int row, col;
        printf("Make your move (row,col): ");
        scanf("%d,%d", &row, &col);
        if(!is_valid_move(row, col)) {
            printf("Invalid Move. Try again.\n");
            continue;
        }
        board[row][col] = user_symbol;
        print_board();
        game_over = check_game_over();
        if(game_over) {
            break;
        }
        
        // CPU's turn
        printf("CPU's Turn:\n");
        get_cpu_move(cpu_symbol);
        print_board();
        game_over = check_game_over();
    }
    
    // Output the result
    if(game_over == 1) {
        printf("Congratulations! You won.\n");
    } else if(game_over == 2) {
        printf("Game Over - Tie.\n");
    } else {
        printf("Sorry! You lost.\n");
    }
    
    return 0;
}