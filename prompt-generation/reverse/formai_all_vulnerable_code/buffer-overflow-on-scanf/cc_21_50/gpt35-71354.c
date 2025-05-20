//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand(time(NULL)); // Initializing the random seed with time
    int num[75];
    int chk = 0;
    int val = 0;
    int count = 0;
    int user_choice = 0;
    char ch;
    int i,j,k,temp;
    int flag = 0;
    int bingo_board[5][5] = {
                            {2, 17, 22, 41, 55},
                            {7, 20, 37, 49, 74},
                            {1, 16, 0, 44, 60},
                            {9, 26, 33, 52, 64},
                            {12, 29, 39, 46, 72}
                            };
    printf("\n\n Welcome to Bingo Simulator Game!\n");
    printf(" Here's your Bingo Board: \n\n");
    for(i = 0; i < 5; i++){
        printf("\t   ");
        for(j = 0; j < 5; j++){
            if(i == 2 && j == 2){ // Center of the board
                printf("  XX ");
            }
            else{
                printf("  %02d ",bingo_board[i][j]); // Printing numbers with proper spacing.
            }
        }
        printf("\n\n");
    }
    printf(" Type 1 to start the game!\n\n");
    scanf("%d",&user_choice);
    if(user_choice != 1){
        printf("\n Sorry, Can't Start the Game. Goodbye!");
        return 0;
    }
    else{
        printf("\n\n Let's begin the Game! Get ready to win!\n");
        printf(" Here are the rules for this game:\n ");
        printf(" 1. We will randomly select a number between 1 to 75.\n");
        printf(" 2. If that number is present in your board, we will replace it with XX.\n");
        printf(" 3. If you get five XX in any row, column, or diagonal, you win the game!\n\n");
        printf(" Are you ready? Press y to start!\n");
        scanf("%s",&ch);
        if(ch == 'y' || ch == 'Y'){
            printf("\n Okay, let's go!");
            while(1){
                val = rand() % 75 + 1; // Generating random number
                chk = 0;
                for(i = 0; i < count; i++){ // Checking if the number is already generated
                    if(num[i] == val){
                        chk = 1; // flag variable
                        break;
                    }
                }
                if(chk == 0){ // Proceed only if number is not generated previously
                    num[count++] = val; // Adding the generated number to array
                    printf("\n\n");
                    printf(" Number generated: %d\n\n",val);
                    for(i = 0; i < 5; i++){ // Search if number is present in the board;
                        for(j = 0; j < 5; j++){
                            if(bingo_board[i][j] == val){
                                bingo_board[i][j] = 0; // Replace the number with 0
                                flag = 1; // Turn the flag on
                                break;
                            }
                        }
                        if(flag == 1){
                            break; // break from the loop if the number is found
                        }
                    }
                    flag = 0; // reset the flag to 0
                    printf(" Your Bingo board:\n\n");
                    for(i = 0; i < 5; i++){ // Display updated board
                        printf("\t   ");
                        for(j = 0; j < 5; j++){
                            if(i == 2 && j == 2){ // Center of the board
                                printf("  XX ");
                            }
                            else{
                                printf("  %02d ",bingo_board[i][j]); // Display numbers with proper spacing
                            }
                        }
                        printf("\n\n");
                    }
                    // Check for winning conditions here
                    // Rows Check
                    for(i = 0; i < 5; i++){
                        flag = 1;
                        for(j = 0; j < 5; j++){
                            if(bingo_board[i][j] != 0){
                                flag = 0;
                                break;
                            }
                        }
                        if(flag == 1){
                            printf(" Yay! First Row Bingo! You Won! Congratulations!\n\n");
                            return 0;
                        }
                    }
                    flag = 0;
                    // Columns Check
                    for(i = 0; i < 5; i++){
                        flag = 1;
                        for(j = 0; j < 5; j++){
                            if(bingo_board[j][i] != 0){
                                flag = 0;
                                break;
                            }
                        }
                        if(flag == 1){
                            printf(" Yay! First Column Bingo! You Won! Congratulations!\n\n");
                            return 0;
                        }
                    }
                    flag = 0;
                    // Left Diagonal Check
                    for(i = 0; i < 5; i++){
                        if(bingo_board[i][i] != 0){
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0){
                        printf(" Yay! Left Diagonal Bingo! You Won! Congratulations!\n\n");
                        return 0;
                    }
                    flag = 0;
                    // Right Diagonal Check
                    for(i = 0; i < 5; i++){
                        if(bingo_board[i][4 - i] != 0){
                            flag = 1;
                            break;
                        }
                    }
                    if(flag == 0){
                        printf(" Yay! Right Diagonal Bingo! You Won! Congratulations!\n\n");
                        return 0;
                    }
                }
                else{
                    printf("\n This number has already been generated. Skipping...");
                }
            }
        }
        else{
            printf("\n Sorry, I can't simulate the game until you are ready. Goodbye!");
            return 0;
        }
    }
    return 0;
}