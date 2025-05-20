//FormAI DATASET v1.0 Category: Chess engine ; Style: retro
#include <stdio.h>

int main(){
    printf("\nWelcome to Retro Chess!");
    char board[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    printf("\n\nThe starting position is:\n");
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    int turn = 1;
    char move[4];
    while(1){
        printf("\n\nEnter your move (e.g. e2e4):\n");
        scanf("%s", move);
        int x1 = 8 - (move[1] - '0');
        int y1 = move[0] - 'a';
        int x2 = 8 - (move[3] - '0');
        int y2 = move[2] - 'a';
        char piece = board[x1][y1];
        if((turn == 1 && piece >= 'A' && piece <= 'Z') || (turn == -1 && piece >= 'a' && piece <= 'z')){
            printf("\nInvalid move! Try again.\n");
            continue;
        }
        if(piece == 'p'){
            if(x2 == x1 - 1 && y2 == y1){
                board[x2][y2] = 'p';
                board[x1][y1] = ' ';
            }
            else{
                printf("\nInvalid move! Try again.\n");
                continue;
            }
        }
        else if(piece == 'P'){
            if(x2 == x1 + 1 && y2 == y1){
                board[x2][y2] = 'P';
                board[x1][y1] = ' ';
            }
            else{
                printf("\nInvalid move! Try again.\n");
                continue;
            }
        }
        else{
            printf("\nInvalid move! Try again.\n");
            continue;
        }
        printf("\nThe updated position is:\n");
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        turn *= -1;
    }
    return 0;
}