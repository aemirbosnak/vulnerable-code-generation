//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

// Function to clear the screen
void clearScreen() {
    printf("\033[2J\033[1;1H");
}

// Function to print the game board
void printBoard(char board[]) {
    printf("\n\n");
    printf("\t     %c | %c | %c \n", board[0], board[1], board[2]);
    printf("\t    ---|---|---\n");
    printf("\t     %c | %c | %c \n", board[3], board[4], board[5]);
    printf("\t    ---|---|---\n");
    printf("\t     %c | %c | %c \n", board[6], board[7], board[8]);
    printf("\n\n");
}

// Function to check if anyone has won the game
int checkForWin(char board[]) {
    if(board[0] == board[1] && board[1] == board[2]) {
        return 1;
    }
    else if(board[3] == board[4] && board[4] == board[5]) {
        return 1;
    }
    else if(board[6] == board[7] && board[7] == board[8]) {
        return 1;
    }
    else if(board[0] == board[3] && board[3] == board[6]) {
        return 1;
    }
    else if(board[1] == board[4] && board[4] == board[7]) {
        return 1;
    }
    else if(board[2] == board[5] && board[5] == board[8]) {
        return 1;
    }
    else if(board[0] == board[4] && board[4] == board[8]) {
        return 1;
    }
    else if(board[2] == board[4] && board[4] == board[6]) {
        return 1;
    }
    else {
        return 0;
    }
}

// Function to check if the game is a draw
int checkForDraw(char board[]) {
    int i;
    for(i = 0; i < 9; i++) {
        if(isdigit(board[i])) {
            return 0;
        }
    }
    return 1;
}

// Main function
int main() {
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int player = 1, choice, win = 0, draw = 0;
    char mark;
    
    clearScreen();
    printf("\t\tWelcome to Tic Tac Toe Game!\n");
    printf("\t\tPlayer 1 (X) vs Player 2 (O)\n\n");

    do {
        printBoard(board);

        player = (player % 2) ? 1 : 2;
        printf("Player %d, enter the number where you want to place your mark: ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';
        
        if(choice == 1 && board[0] == '1') {
            board[0] = mark;
        }
        else if(choice == 2 && board[1] == '2') {
            board[1] = mark;
        }
        else if(choice == 3 && board[2] == '3') {
            board[2] = mark;
        }
        else if(choice == 4 && board[3] == '4') {
            board[3] = mark;
        }
        else if(choice == 5 && board[4] == '5') {
            board[4] = mark;
        }
        else if(choice == 6 && board[5] == '6') {
            board[5] = mark;
        }
        else if(choice == 7 && board[6] == '7') {
            board[6] = mark;
        }
        else if(choice == 8 && board[7] == '8') {
            board[7] = mark;
        }
        else if(choice == 9 && board[8] == '9') {
            board[8] = mark;
        }
        else {
            printf("Invalid move! Please try again.\n");
            player--;
            getchar();
        }

        win = checkForWin(board);
        draw = checkForDraw(board);
        
        player++;
    } while(win == 0 && draw == 0);

    printBoard(board);

    if(win) {
        printf("Player %d wins. Congratulations!\n", (player % 2) ? 1 : 2);
    }
    else {
        printf("The game is a draw.\n");
    }

    return 0;
}