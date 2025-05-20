//FormAI DATASET v1.0 Category: Chess engine ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DEPTH 6
#define INFINITY 1000000
#define NEG_INFINITY -1000000

/* The board is represented as a 12x10 array.
   The extra rows and columns are used as a border to avoid 
   boundary checks and to help check for valid moves.*/
   
char board[12][10] = {
    { '+', '+', '+', '+', '+', '+', '+', '+', '+', '+' },
    { '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+' },
    { '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+' },
    { '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+' },
    { '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+' },
    { '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+' },
    { '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+' },
    { '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+' },
    { '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+' },
    { '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+' },
    { '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+' },
    { '+', '+', '+', '+', '+', '+', '+', '+', '+', '+' }
};

/* Structure to represent a move */
typedef struct {
    int start_row, start_col;
    int end_row, end_col;
} Move;

/* Structure to represent a game state */
typedef struct {
    char game_board[12][10];
    int score;
} GameState;

/* Function for scoring a game state */
int score_game_state(GameState state){
    int score = 0;
    int row, col;
    
    for(row=1; row<=10; row++){
        for(col=1; col<=8; col++){
            if(state.game_board[row][col] == 'W')
                score += 1;
            if(state.game_board[row][col] == 'B')
                score -= 1;
            if(state.game_board[row][col] == 'w')
                score += 3;
            if(state.game_board[row][col] == 'b')
                score -= 3;
            if(state.game_board[row][col] == 'm')
                score += 5;
            if(state.game_board[row][col] == 'M')
                score -= 5;
        }
    }
    
    return score;
}

/* Function to make a move on a game board */
GameState make_move(GameState state, Move move){
    GameState new_state = state;
    char piece = state.game_board[move.start_row][move.start_col];
    char opp_piece;
    
    if(piece == 'W' || piece == 'w')
        opp_piece = 'B';
    else
        opp_piece = 'W';
    
    /* Move the piece */
    new_state.game_board[move.end_row][move.end_col] = piece;
    new_state.game_board[move.start_row][move.start_col] = ' ';
    
    /* Check if the move results in capture */
    if(move.end_col == move.start_col - 2 || move.end_col == move.start_col + 2 ||
       move.end_row == move.start_row - 2 || move.end_row == move.start_row + 2){
           int cap_row = (move.start_row + move.end_row) / 2;
           int cap_col = (move.start_col + move.end_col) / 2;
           if(new_state.game_board[cap_row][cap_col] == opp_piece){
               new_state.game_board[cap_row][cap_col] = ' ';
               if(opp_piece == 'B')
                   new_state.score += 1;
               else
                   new_state.score -= 1;
           }
    }
    
    return new_state;
}

/* Function to check if a move is valid */
int is_valid_move(GameState state, Move move){
    char piece = state.game_board[move.start_row][move.start_col];
    int row_diff = move.end_row - move.start_row;
    int col_diff = move.end_col - move.start_col;
    
    if(piece == ' ')
        return 0;
        
    if(piece == 'W' && row_diff != -1)
        return 0;
    
    if(piece == 'B' && row_diff != 1)
        return 0;
        
    if(state.game_board[move.end_row][move.end_col] != ' ')
        return 0;
    
    if(abs(row_diff) == 2 && abs(col_diff) == 2){
        int cap_row = (move.start_row + move.end_row) / 2;
        int cap_col = (move.start_col + move.end_col) / 2;
        char cap_piece = state.game_board[cap_row][cap_col];
        if(cap_piece == ' ' || cap_piece == piece || cap_piece == toupper(piece))
            return 0;
    }
    else{
        if(abs(row_diff) != 1 || abs(col_diff) != 1)
            return 0;
    }
    
    return 1;
}

/* Function to get all possible moves from a game state */
Move* get_moves(GameState state, int* num_moves){
    int max_moves = 1000;
    Move* moves = (Move*) malloc(max_moves * sizeof(Move));
    int row, col;
    int move_num = 0;
    
    for(row=1; row<=10; row++){
        for(col=1; col<=8; col++){
            if(state.game_board[row][col] == 'W' || state.game_board[row][col] == 'w'){
                if(is_valid_move(state, (Move) {row, col, row-1, col-1})){
                    moves[move_num++] = (Move) {row, col, row-1, col-1};
                    if(move_num == max_moves) {
                      max_moves += 1000;
                      moves = (Move*)realloc(moves, max_moves * sizeof(Move));
                    }
                }
                if(is_valid_move(state, (Move) {row, col, row-1, col+1})){
                    moves[move_num++] = (Move) {row, col, row-1, col+1};
                    if(move_num == max_moves) {
                      max_moves += 1000;
                      moves = (Move*)realloc(moves, max_moves * sizeof(Move));
                    }
                }
                if(is_valid_move(state, (Move) {row, col, row+1, col-1})){
                    moves[move_num++] = (Move) {row, col, row+1, col-1};
                    if(move_num == max_moves) {
                      max_moves += 1000;
                      moves = (Move*)realloc(moves, max_moves * sizeof(Move));
                    }
                }
                if(is_valid_move(state, (Move) {row, col, row+1, col+1})){
                    moves[move_num++] = (Move) {row, col, row+1, col+1};
                    if(move_num == max_moves) {
                      max_moves += 1000;
                      moves = (Move*)realloc(moves, max_moves * sizeof(Move));
                    }
                }
                if(is_valid_move(state, (Move) {row, col, row-2, col-2})){
                    moves[move_num++] = (Move) {row, col, row-2, col-2};
                    if(move_num == max_moves) {
                      max_moves += 1000;
                      moves = (Move*)realloc(moves, max_moves * sizeof(Move));
                    }
                }
                if(is_valid_move(state, (Move) {row, col, row-2, col+2})){
                    moves[move_num++] = (Move) {row, col, row-2, col+2};
                    if(move_num == max_moves) {
                      max_moves += 1000;
                      moves = (Move*)realloc(moves, max_moves * sizeof(Move));
                    }
                }
                if(is_valid_move(state, (Move) {row, col, row+2, col-2})){
                    moves[move_num++] = (Move) {row, col, row+2, col-2};
                    if(move_num == max_moves) {
                      max_moves += 1000;
                      moves = (Move*)realloc(moves, max_moves * sizeof(Move));
                    }
                }
                if(is_valid_move(state, (Move) {row, col, row+2, col+2})){
                    moves[move_num++] = (Move) {row, col, row+2, col+2};
                    if(move_num == max_moves) {
                      max_moves += 1000;
                      moves = (Move*)realloc(moves, max_moves * sizeof(Move));
                    }
                }
            }
            else if(state.game_board[row][col] == 'B' || state.game_board[row][col] == 'b'){
                if(is_valid_move(state, (Move) {row, col, row+1, col-1})){
                    moves[move_num++] = (Move) {row, col, row+1, col-1};
                    if(move_num == max_moves) {
                      max_moves += 1000;
                      moves = (Move*)realloc(moves, max_moves * sizeof(Move));
                    }
                }
                if(is_valid_move(state, (Move) {row, col, row+1, col+1})){
                    moves[move_num++] = (Move) {row, col, row+1, col+1};
                    if(move_num == max_moves) {
                      max_moves += 1000;
                      moves = (Move*)realloc(moves, max_moves * sizeof(Move));
                    }
                }
                if(is_valid_move(state, (Move) {row, col, row-1, col-1})){
                    moves[move_num++] = (Move) {row, col, row-1, col-1};
                    if(move_num == max_moves) {
                      max_moves += 1000;
                      moves = (Move*)realloc(moves, max_moves * sizeof(Move));
                    }
                }
                if(is_valid_move(state, (Move) {row, col, row-1, col+1})){
                    moves[move_num++] = (Move) {row, col, row-1, col+1};
                    if(move_num == max_moves) {
                      max_moves += 1000;
                      moves = (Move*)realloc(moves, max_moves * sizeof(Move));
                    }
                }
                if(is_valid_move(state, (Move) {row, col, row-2, col-2})){
                    moves[move_num++] = (Move) {row, col, row-2, col-2};
                    if(move_num == max_moves) {
                      max_moves += 1000;
                      moves = (Move*)realloc(moves, max_moves * sizeof(Move));
                    }
                }
                if(is_valid_move(state, (Move) {row, col, row-2, col+2})){
                    moves[move_num++] = (Move) {row, col, row-2, col+2};
                    if(move_num == max_moves) {
                      max_moves += 1000;
                      moves = (Move*)realloc(moves, max_moves * sizeof(Move));
                    }
                }
                if(is_valid_move(state, (Move) {row, col, row+2, col-2})){
                    moves[move_num++] = (Move) {row, col, row+2, col-2};
                    if(move_num == max_moves) {
                      max_moves += 1000;
                      moves = (Move*)realloc(moves, max_moves * sizeof(Move));
                    }
                }
                if(is_valid_move(state, (Move) {row, col, row+2, col+2})){
                    moves[move_num++] = (Move) {row, col, row+2, col+2};
                    if(move_num == max_moves) {
                      max_moves += 1000;
                      moves = (Move*)realloc(moves, max_moves * sizeof(Move));
                    }
                }
            }
        }
    }
    
    *num_moves = move_num;
    return moves;
}

/* Minimax algorithm with alpha-beta pruning */
int minimax_alpha_beta(GameState state, int depth, int alpha, int beta){
    if(depth == 0)
        return score_game_state(state);
    
    int num_moves, move_score;
    Move* moves = get_moves(state, &num_moves);
    
    if(num_moves == 0)
        return NEG_INFINITY + 1;
    
    /* Maximizing player */
    if(depth % 2 == 0){
        int max_score = NEG_INFINITY;
        int i;
        for(i=0; i<num_moves; i++){
            GameState new_state = make_move(state, moves[i]);
            move_score = minimax_alpha_beta(new_state, depth-1, alpha, beta);
            if(move_score > max_score)
                max_score = move_score;
            if(max_score > alpha)
                alpha = max_score;
            if(alpha >= beta)
                break;
        }
        free(moves);
        return max_score;
    }
    /* Minimizing player */
    else{
        int min_score = INFINITY;
        int i;
        for(i=0; i<num_moves; i++){
            GameState new_state = make_move(state, moves[i]);
            move_score = minimax_alpha_beta(new_state, depth-1, alpha, beta);
            if(move_score < min_score)
                min_score = move_score;
            if(min_score < beta)
                beta = min_score;
            if(beta <= alpha)
                break;
        }
        free(moves);
        return min_score;
    }
}

/* Function to get the best move using minimax with alpha-beta pruning */
Move get_best_move(GameState state){
    int num_moves, move_score;
    int max_score = NEG_INFINITY;
    Move best_move = {0,0,0,0};
    Move* moves = get_moves(state, &num_moves);
    int i;
    
    for(i=0; i<num_moves; i++){
        GameState new_state = make_move(state, moves[i]);
        move_score = minimax_alpha_beta(new_state, MAX_DEPTH, NEG_INFINITY, INFINITY);
        if(move_score > max_score){
            max_score = move_score;
            best_move = moves[i];
        }
    }
    
    free(moves);
    return best_move;
}

/* Function to print the game board */
void print_board(GameState state){
    int row, col;
    for(row=1; row<=10; row++){
        for(col=1; col<=8; col++){
            printf("%c ", state.game_board[row][col]);
        }
        printf("\n");
    }
    printf("Score: %d\n", state.score);
}

/* Entry point of the program */
int main(){
    int game_over = 0;
    GameState state = { board, 0 };
    Move move;
    while(!game_over){
        print_board(state);
        printf("Enter move (start row, start col, end row, end col): ");
        scanf("%d %d %d %d", &move.start_row, &move.start_col, &move.end_row, &move.end_col);
        if(is_valid_move(state, move)){
            state = make_move(state, move);
            if(state.score >= 100 || state.score <= -100)
                game_over = 1;
        }
        else{
            printf("Invalid move. Try again.\n");
        }
    }
    print_board(state);
    if(state.score >= 100)
        printf("You win!\n");
    else
        printf("You lose!\n");
    return 0;
}