//Falcon2-11B DATASET v1.0 Category: Chess AI ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* board = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

int main() {
    char* boardCopy = malloc(sizeof(char) * strlen(board));
    strcpy(boardCopy, board);
    
    int size = strlen(boardCopy);
    int move = 0;
    
    while (size > 0) {
        size--;
        if (boardCopy[size] == 'R') {
            move++;
        }
        if (boardCopy[size] == 'N') {
            move++;
        }
        if (boardCopy[size] == 'B') {
            move++;
        }
        if (boardCopy[size] == 'Q') {
            move++;
        }
        if (boardCopy[size] == 'K') {
            move++;
        }
        if (boardCopy[size] == 'r') {
            move++;
        }
        if (boardCopy[size] == 'n') {
            move++;
        }
        if (boardCopy[size] == 'b') {
            move++;
        }
        if (boardCopy[size] == 'q') {
            move++;
        }
        if (boardCopy[size] == 'k') {
            move++;
        }
    }
    
    printf("Move %d\n", move);
    
    free(boardCopy);
    return 0;
}