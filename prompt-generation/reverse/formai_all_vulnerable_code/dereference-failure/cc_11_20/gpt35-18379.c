//FormAI DATASET v1.0 Category: Chess AI ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEPTH 3

struct move {
    int from_pos;
    int to_pos;
};

struct chess_board {
    char board[8][8];
    char side_to_move;
    int en_passant_square;
    int white_king_pos;
    int black_king_pos;
};

struct node {
    struct chess_board* board;
    int score;
    int depth;
    struct move best_move;
};

void display_board(struct chess_board* board) {
    printf("\n  A B C D E F G H\n");
    printf(" +---------------+\n");
    for (int rank = 7; rank >= 0; rank--) {
        printf("%d", rank+1);
        for (int file = 0; file < 8; file++) {
            printf("|%c", board->board[rank][file]);
        }
        printf("|%d\n +---------------+\n", rank+1);
    }
    printf("  A B C D E F G H\n");
}

int get_board_score(struct chess_board* board) {
    int score = 0;
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            char piece = board->board[rank][file];
            if (piece == 'P') score += 1;
            else if (piece == 'N' || piece == 'B') score += 3;
            else if (piece == 'R') score += 5;
            else if (piece == 'Q') score += 9;
            else if (piece == 'p') score -= 1;
            else if (piece == 'n' || piece == 'b') score -= 3;
            else if (piece == 'r') score -= 5;
            else if (piece == 'q') score -= 9;
        }
    }
    return score;
}

int is_valid_move(struct chess_board* board, struct move* move) {
    char piece = board->board[move->from_pos / 8][move->from_pos % 8];
    char target_piece = board->board[move->to_pos / 8][move->to_pos % 8];
    if (piece == ' ') return 0;
    if (piece == 'P') {
        if (move->from_pos / 8 == 1 && move->to_pos / 8 == 3 && 
            move->from_pos % 8 == move->to_pos % 8 && target_piece == ' ') {
                board->en_passant_square = move->to_pos + 8;
                return 1;
        } else if (move->to_pos == board->en_passant_square && 
                   (move->from_pos / 8) == 4 && (move->to_pos / 8) == 5) {
                return 1;
        } else if (move->to_pos / 8 == move->from_pos / 8 + 1 && 
                   move->to_pos % 8 == move->from_pos % 8 && target_piece == ' ') {
                return 1;
        } else if (move->to_pos / 8 == move->from_pos / 8 + 1 && 
                   abs(move->to_pos % 8 - move->from_pos % 8) == 1 &&
                   target_piece != ' ' &&
                   target_piece < 'a') {
                return 1;
        } else {
            return 0;
        }
    } else if (piece == 'p') {
        if (move->from_pos / 8 == 6 && move->to_pos / 8 == 4 && 
            move->from_pos % 8 == move->to_pos % 8 && target_piece == ' ') {
                board->en_passant_square = move->to_pos - 8;
                return 1;
        } else if (move->to_pos == board->en_passant_square && 
                   (move->from_pos / 8) == 3 && (move->to_pos / 8) == 2) {
                return 1;
        } else if (move->to_pos / 8 == move->from_pos / 8 - 1 && 
                   move->to_pos % 8 == move->from_pos % 8 && target_piece == ' ') {
                return 1;
        } else if (move->to_pos / 8 == move->from_pos / 8 - 1 && 
                   abs(move->to_pos % 8 - move->from_pos % 8) == 1 &&
                   target_piece != ' ' &&
                   target_piece > 'a') {
                return 1;
        } else {
            return 0;
        }
    } else if (piece == 'N') {
        return abs(move->from_pos / 8 - move->to_pos / 8) * 
               abs(move->from_pos % 8 - move->to_pos % 8) == 2;
    } else if (piece == 'n') {
        return abs(move->from_pos / 8 - move->to_pos / 8) * 
               abs(move->from_pos % 8 - move->to_pos % 8) == 2;
    } else if (piece == 'B') {
        return abs(move->from_pos / 8 - move->to_pos / 8) == 
               abs(move->from_pos % 8 - move->to_pos % 8);
    } else if (piece == 'b') {
        return abs(move->from_pos / 8 - move->to_pos / 8) == 
               abs(move->from_pos % 8 - move->to_pos % 8);
    } else if (piece == 'R') {
        return move->from_pos / 8 == move->to_pos / 8 || 
               move->from_pos % 8 == move->to_pos % 8;
    } else if (piece == 'r') {
        return move->from_pos / 8 == move->to_pos / 8 || 
               move->from_pos % 8 == move->to_pos % 8;
    } else if (piece == 'Q') {
        return abs(move->from_pos / 8 - move->to_pos / 8) == 
               abs(move->from_pos % 8 - move->to_pos % 8) ||
               move->from_pos / 8 == move->to_pos / 8 || 
               move->from_pos % 8 == move->to_pos % 8;
    } else if (piece == 'q') {
        return abs(move->from_pos / 8 - move->to_pos / 8) == 
               abs(move->from_pos % 8 - move->to_pos % 8) ||
               move->from_pos / 8 == move->to_pos / 8 || 
               move->from_pos % 8 == move->to_pos % 8;
    } else if (piece == 'K') {
        return abs(move->from_pos / 8 - move->to_pos / 8) <= 1 && 
               abs(move->from_pos % 8 - move->to_pos % 8) <= 1;
    } else if (piece == 'k') {
        return abs(move->from_pos / 8 - move->to_pos / 8) <= 1 && 
               abs(move->from_pos % 8 - move->to_pos % 8) <= 1;
    }
    return 0;
}

struct chess_board* make_move(struct chess_board* board, struct move* move) {
    struct chess_board* new_board = malloc(sizeof(struct chess_board));
    memcpy(new_board, board, sizeof(struct chess_board));
    char piece = new_board->board[move->from_pos / 8][move->from_pos % 8];
    new_board->board[move->to_pos / 8][move->to_pos % 8] = piece;
    new_board->board[move->from_pos / 8][move->from_pos % 8] = ' ';
    if (piece == 'K') {
        new_board->white_king_pos = move->to_pos;
    } else if (piece == 'k') {
        new_board->black_king_pos = move->to_pos;
    } else if (piece == 'P') {
        if (move->to_pos / 8 == 7) new_board->board[move->to_pos / 8][move->to_pos % 8] = 'Q';
        new_board->en_passant_square = -1;
    } else if (piece == 'p') {
        if (move->to_pos / 8 == 0) new_board->board[move->to_pos / 8][move->to_pos % 8] = 'q';
        new_board->en_passant_square = -1;
    } else if (piece == 'R') {
        if (move->from_pos == 0) new_board->en_passant_square = -1;
        if (move->from_pos == 7) new_board->en_passant_square = -1;
    } else if (piece == 'r') {
        if (move->from_pos == 56) new_board->en_passant_square = -1;
        if (move->from_pos == 63) new_board->en_passant_square = -1;
    } else {
        new_board->en_passant_square = -1;
    }
    new_board->side_to_move = (new_board->side_to_move == 'w') ? 'b' : 'w';
    return new_board;
}

struct node min_max(struct node* node, int maximizing_player) {
    if (node->depth == 0) {
        node->score = get_board_score(node->board);
        return *node;
    }
    struct node best_node;
    best_node.depth = node->depth - 1;
    best_node.best_move.from_pos = -1;
    best_node.best_move.to_pos = -1;
    if (maximizing_player) {
        best_node.score = -1000000;
        for (int pos = 0; pos < 64; pos++) {
            if (node->board->board[pos / 8][pos % 8] != node->board->side_to_move) continue;
            for (int target_pos = 0; target_pos < 64; target_pos++) {
                struct move move = {pos, target_pos};
                if (!is_valid_move(node->board, &move)) continue;
                struct node child_node;
                child_node.board = make_move(node->board, &move);
                child_node.depth = node->depth - 1;
                struct node result = min_max(&child_node, 0);
                if (result.score > best_node.score) {
                    best_node.score = result.score;
                    best_node.best_move.from_pos = pos;
                    best_node.best_move.to_pos = target_pos;
                }
            }
        }
    } else {
        best_node.score = 1000000;
        for (int pos = 0; pos < 64; pos++) {
            if (node->board->board[pos / 8][pos % 8] != node->board->side_to_move) continue;
            for (int target_pos = 0; target_pos < 64; target_pos++) {
                struct move move = {pos, target_pos};
                if (!is_valid_move(node->board, &move)) continue;
                struct node child_node;
                child_node.board = make_move(node->board, &move);
                child_node.depth = node->depth - 1;
                struct node result = min_max(&child_node, 1);
                if (result.score < best_node.score) {
                    best_node.score = result.score;
                    best_node.best_move.from_pos = pos;
                    best_node.best_move.to_pos = target_pos;
                }
            }
        }
    }
    return best_node;
}

int main() {
    // Initialize chess board
    struct chess_board* board = malloc(sizeof(struct chess_board));
    board->side_to_move = 'w';
    board->en_passant_square = -1;
    board->white_king_pos = 4;
    board->black_king_pos = 60;
    char initial_board[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    memcpy(board->board, initial_board, sizeof(char) * 8 * 8);

    // Play game against AI
    struct node root_node = {board, 0, MAX_DEPTH, {0, 0}};
    while (1) {
        // User move
        display_board(board);
        printf("Enter move (e.g. e2e4): ");
        char user_input[5];
        fgets(user_input, 5, stdin);
        int from_file = user_input[0] - 'a';
        int from_rank = user_input[1] - '1';
        int to_file = user_input[2] - 'a';
        int to_rank = user_input[3] - '1';
        struct move user_move = {from_rank * 8 + from_file, to_rank * 8 + to_file};
        if (is_valid_move(board, &user_move)) {
            board = make_move(board, &user_move);
        } else {
            printf("Invalid move, try again.\n");
            continue;
        }

        // AI move
        display_board(board);
        printf("AI thinking...\n");
        srand(time(0));
        sleep(2);
        struct node result = min_max(&root_node, 1);
        printf("AI moves %c%d%c%d\n", 
               result.best_move.from_pos % 8 + 'a',
               result.best_move.from_pos / 8 + 1,
               result.best_move.to_pos % 8 + 'a',
               result.best_move.to_pos / 8 + 1);
        board = make_move(board, &result.best_move);
    }
    return 0;
}