//FormAI DATASET v1.0 Category: Chess engine ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Piece Codes
#define EMPTY 0
#define WP 1
#define WN 2
#define WB 3
#define WR 4
#define WQ 5
#define WK 6
#define BP 7
#define BN 8
#define BB 9
#define BR 10
#define BQ 11
#define BK 12

// Board Codes
#define A1 21
#define B1 22
#define C1 23
#define D1 24
#define E1 25
#define F1 26
#define G1 27
#define H1 28
#define A8 91
#define B8 92
#define C8 93
#define D8 94
#define E8 95
#define F8 96
#define G8 97
#define H8 98
#define SIZE 130

int board[SIZE];

const int PawnTable[SIZE] ={
0,     0,     0,     0,     0,     0,     0,     0,
10,    10,    0,     -10,   -10,   0,     10,    10,
5,     0,     0,     5,     5,     0,     0,     5,
0,     0,     10,    20,    20,    10,    0,     0,
5,     5,     5,     10,    10,    5,     5,     5,
10,    10,    10,    20,    20,    10,    10,    10,
20,    20,    20,    30,    30,    20,    20,    20,
0,     0,     0,     0,     0,     0,     0,     0
};

// Reset Board function
void reset_board(){
    int i;
    for (i = 0; i < SIZE; ++i)
        board[i] = 99;
        
    for (i = A1; i <= H1; ++i)
        board[i] = WK;
    
    for (int i = A8; i <= H8; ++i)
        board[i] = BK;
        
    board[A1] = WR; board[H1] = WR;
    board[A8] = BR; board[H8] = BR;
    
    for (i = A1+1; i <= H1-1; ++i)
        board[i] = WP;
        
    for (i = A8+1; i <= H8-1; ++i)
        board[i] = BP;
}

void print_board(){
    char pce[] = ".PNBRQKpnbrqk";
    int file, rank, piece;
    
    for (rank = 8; rank >= 1; --rank){
        printf("%d ",rank);
        for (file = A1; file <= H1; ++file){
            piece = board[rank*10+file];
            printf("%c",pce[piece]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

int main(){
    reset_board();
    print_board();
    return 0;
}