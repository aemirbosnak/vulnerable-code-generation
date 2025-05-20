//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char square[10] = {'0','1','2','3','4','5','6','7','8','9'};

void board();
int checkwin();
void draw_ComputerMove(int);
void draw_PlayerMove(int);

int main(){
    int player_choice, computer_choice, flag = 0;
    char player_mark, computer_mark;
    srand(time(NULL));
    printf("Enter the mark you want Player (X/O): ");
    scanf("%c", &player_mark);
    if(player_mark == 'X' || player_mark == 'x'){
        computer_mark = 'O';
        printf("\nComputer gets the mark %c\n", computer_mark);
    }
    else{
        computer_mark = 'X';
        printf("\nComputer gets the mark %c\n", computer_mark);
    }
    printf("Press any key to start..");
    getchar(); // I added this line to read the new line character from the input buffer
    board();
    while(!flag){
        printf("\n\nPlayer's turn\n");
        printf("Enter the position where do you want to place your mark: ");
        scanf("%d", &player_choice);
        if (player_choice > 9 || player_choice < 1){
            printf("Invalid input!");
            continue;
        }
        if(square[player_choice] == player_mark || square[player_choice] == computer_mark){
            printf("\nPosition already occupied! Try again");
            continue;
        }
        square[player_choice] = player_mark;
        draw_PlayerMove(player_choice);
        flag = checkwin();
        if(flag)
            break;
        printf("\n\nComputer's turn\n");
        while(1){
            computer_choice = rand() % 9 + 1;
            if(square[computer_choice] != player_mark && square[computer_choice] != computer_mark){
                break;
            }
        }
        square[computer_choice] = computer_mark;
        draw_ComputerMove(computer_choice);
        flag = checkwin();
    }
    if(flag == 1){
        printf("\n\nCongratulation!!! You won");
    }
    else if(flag == 2){
        printf("\n\nSorry!!! You lost...");
    }
    else{
        printf("\n\nGame ended in a draw");
    }
    return 0;
}

void board(){
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X) - Computer (%c)\n\n", square[5]);
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);
    printf("     |     |     \n");
}

void draw_PlayerMove(int choice){
    switch (choice){
    case 1:
        square[1] = 'X';
        break;
    case 2:
        square[2] = 'X';
        break;
    case 3:
        square[3] = 'X';
        break;
    case 4:
        square[4] = 'X';
        break;
    case 5:
        square[5] = 'X';
        break;
    case 6:
        square[6] = 'X';
        break;
    case 7:
        square[7] = 'X';
        break;
    case 8:
        square[8] = 'X';
        break;
    case 9:
        square[9] = 'X';
        break;
    default:
        break;
    }
    board();
}

void draw_ComputerMove(int choice){
    switch (choice){
    case 1:
        square[1] = 'O';
        break;
    case 2:
        square[2] = 'O';
        break;
    case 3:
        square[3] = 'O';
        break;
    case 4:
        square[4] = 'O';
        break;
    case 5:
        square[5] = 'O';
        break;
    case 6:
        square[6] = 'O';
        break;
    case 7:
        square[7] = 'O';
        break;
    case 8:
        square[8] = 'O';
        break;
    case 9:
        square[9] = 'O';
        break;
    default:
        break;
    }
    board();
}

int checkwin(){
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if(square[1] != '1' && square[2] != '2' && square[3] != '3'
                && square[4] != '4' && square[5] != '5' && square[6] != '6'
              && square[7] != '7' && square[8] != '8' && square[9] != '9')
                    return 0;
    else
        return 2;
}