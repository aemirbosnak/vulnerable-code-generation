//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

int winning_moves[8][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}}; //All possible winning moves

void print_board(char* board) {
    printf("\n");
    for(int i=0;i<9;i++) {
        printf("%c",*(board+i));
        if(i%3==2) printf("\n");
    }
}

int check_winner(char* board, char mark) {
    for(int i=0;i<8;i++) {
        if(board[winning_moves[i][0]]==mark && board[winning_moves[i][1]]==mark && board[winning_moves[i][2]]==mark) {
            return 1;
        }
    }
    return 0;
}

char get_computer_mark(char player_mark) {
    if(player_mark=='X') return 'O';
    else return 'X';
}

int get_opponent_move(char* board, char opponent_mark) {
    int move=-1;
    for(int i=0;i<8;i++) {
        int j = winning_moves[i][0]; int k=winning_moves[i][1]; int l=winning_moves[i][2];
        if(board[j]==opponent_mark && board[k]==opponent_mark && board[l]!='X' && board[l]!='O') {
            move = l;
            break;
        }
        if(board[j]==opponent_mark && board[l]==opponent_mark && board[k]!='X' && board[k]!='O') {
            move = k;
            break;
        }
        if(board[k]==opponent_mark && board[l]==opponent_mark && board[j]!='X' && board[j]!='O') {
            move = j;
            break;
        }
    }
    if(move==-1) return -1;
    return move;  
}

int get_computer_move(char* board, char computer_mark, char player_mark) {
    int move = get_opponent_move(board, player_mark); //Check if opponent can win in next move
    if(move!=-1) return move;

    for(int i=0;i<8;i++) {  //Check if computer can win in next move
        int j = winning_moves[i][0]; int k=winning_moves[i][1]; int l=winning_moves[i][2];
        if(board[j]==computer_mark && board[k]==computer_mark && board[l]!='X' && board[l]!='O') {
            move = l;
            break;
        }
        if(board[j]==computer_mark && board[l]==computer_mark && board[k]!='X' && board[k]!='O') {
            move = k;
            break;
        }
        if(board[k]==computer_mark && board[l]==computer_mark && board[j]!='X' && board[j]!='O') {
            move = j;
            break;
        }
    }
    if(move!=-1) return move;

    for(int i=0;i<8;i++) {  //Choose a corner if available
        int j = winning_moves[i][0]; int k=winning_moves[i][1]; int l=winning_moves[i][2];
        if((j==0 || j==2 || j==6 || j==8) && board[j]!='X' && board[j]!='O') {
            move = j;
            break;
        }
        if((k==0 || k==2 || k==6 || k==8) && board[k]!='X' && board[k]!='O') {
            move = k;
            break;
        }
        if((l==0 || l==2 || l==6 || l==8) && board[l]!='X' && board[l]!='O') {
            move = l;
            break;
        }
    }
    if(move!=-1) return move;

    for(int i=0;i<8;i++) { //Choose center if available
        int j = winning_moves[i][0]; int k=winning_moves[i][1]; int l=winning_moves[i][2];
        if(j==4 && board[j]!='X' && board[j]!='O') {
            move = j;
            break;
        }
        if(k==4 && board[k]!='X' && board[k]!='O') {
            move = k;
            break;
        }
        if(l==4 && board[l]!='X' && board[l]!='O') {
            move = l;
            break;
        }
    }
    if(move!=-1) return move;

    for(int i=0;i<8;i++) { //Choose a side
        int j = winning_moves[i][0]; int k=winning_moves[i][1]; int l=winning_moves[i][2];
        if((j==1 || j==3 || j==5 || j==7) && board[j]!='X' && board[j]!='O') {
            move = j;
            break;
        }
        if((k==1 || k==3 || k==5 || k==7) && board[k]!='X' && board[k]!='O') {
            move = k;
            break;
        }
        if((l==1 || l==3 || l==5 || l==7) && board[l]!='X' && board[l]!='O') {
            move = l;
            break;
        }
    }
    return move;
}

int main() {
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    char player_mark, computer_mark;
    int player_move;
    int game_over = 0;
    printf("Welcome to Tic Tac Toe!\n");
    printf("Do you want to play first? (Y/N)\n");
    char choice;
    scanf("%c",&choice);
    if(choice=='Y' || choice=='y') player_mark = 'X';
    else player_mark = 'O';
    computer_mark = get_computer_mark(player_mark);

    while(!game_over) {
        print_board(board);
        if(player_mark=='X') printf("Your turn (X): ");
        else printf("Your turn (O): ");
        scanf("%d",&player_move);
        if(board[player_move-1]!='X' && board[player_move-1]!='O') {
            board[player_move-1] = player_mark;
        } else {
            printf("Invalid move. Try again\n");
            continue;
        }
        if(check_winner(board,player_mark)) {
            printf("You win!\n");
            print_board(board);
            game_over = 1;
            break;
        }
        int computer_move = get_computer_move(board, computer_mark,player_mark);
        if(computer_move==-1) {
            printf("It's a draw!\n");
            print_board(board);
            game_over = 1;
            break;
        } else {
            printf("Computer plays: %d\n",computer_move+1);
            board[computer_move] = computer_mark;
        }
        if(check_winner(board,computer_mark)) {
            printf("You lose!\n");
            print_board(board);
            game_over = 1;
            break;
        }
    }
    return 0;
}