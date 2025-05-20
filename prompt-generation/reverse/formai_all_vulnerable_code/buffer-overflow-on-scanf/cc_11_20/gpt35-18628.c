//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Claude Shannon
#include<stdio.h>

char board[9] = {'1','2','3','4','5','6','7','8','9'}; // Tic Tac Toe board

void display_board(){ // Function to display Tic Tac Toe board
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0], board[1], board[2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c  \n", board[3], board[4], board[5]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c  \n", board[6], board[7], board[8]);

    printf("     |     |     \n\n");
}

int check_winning_condition(){ // Function to check if any player has won
    if (board[0] == board[1] && board[1] == board[2])

        return 1;
    else if (board[3] == board[4] && board[4] == board[5])

        return 1;
    else if (board[6] == board[7] && board[7] == board[8])

       return 1;
    else if (board[0] == board[3] && board[3] == board[6])

        return 1;
    else if (board[1] == board[4] && board[4] == board[7])

        return 1;
    else if (board[2] == board[5]  && board[5] == board[8])

        return 1;
    else if (board[0] == board[4] && board[4] == board[8])

        return 1;
    else if (board[6] == board[4] && board[4] == board[2])

        return 1;
    else if (board[0] != '1' && board[1] != '2' && board[2] != '3' 
                     && board[3] != '4' && board[4] != '5' && board[5] != '6' 
                   && board[6] != '7' && board[7] != '8' && board[8] != '9')

        return 0;
    else
        return -1;
}

void tic_tac_toe(){
    int player = 1,i,choice;

    char mark;
    do {
        display_board();

        player = (player%2) ? 1 : 2;

        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && board[0] == '1'){

            board[0] = mark;}

        else if (choice == 2 && board[1] == '2'){

            board[1] = mark;}

        else if (choice == 3 && board[2] == '3'){

            board[2] = mark;}

        else if (choice == 4 && board[3] == '4'){

            board[3] = mark;}

        else if (choice == 5 && board[4] == '5'){

            board[4] = mark;}

        else if (choice == 6 && board[5] == '6'){

            board[5] = mark;}

        else if (choice == 7 && board[6] == '7'){

            board[6] = mark;}

        else if (choice == 8 && board[7] == '8'){

            board[7] = mark;}

        else if (choice == 9 && board[8] == '9'){

            board[8] = mark;}

        else {
            printf("Invalid move ");

            player--;
            scanf("%d", &choice);
        }

        i = check_winning_condition();

        player++;

    }while(i == -1);

    display_board();

    if(i==1){

        printf("==>\aPlayer %d win ",--player);}
    else{

        printf("==>\aGame draw");}

    printf("\n\nPress any key to continue...");

    getchar();
}

int main(){

    tic_tac_toe();
    return 0;
}