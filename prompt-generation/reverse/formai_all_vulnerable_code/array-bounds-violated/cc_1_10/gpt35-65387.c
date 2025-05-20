//FormAI DATASET v1.0 Category: Memory Game ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 4

//function to randomly shuffle the array
void shuffle(int arr[], int n){
    srand(time(NULL));
    for(int i = n-1; i > 0; i--){
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

//function to display the current state of the game board
void display(int arr[][SIZE], int n){
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("\n");
        for(int j = 0; j < n; j++)
            printf("%d\t", arr[i][j]);
    }
}

//function to check if the game is over, i.e. all the numbers have been matched
int game_over(int arr[][SIZE], int n){
    int count = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(arr[i][j] == -1)
                count++;
    if(count == n*n)
        return 1;
    return 0;
}

int main(){
    int arr[SIZE][SIZE], n = SIZE*SIZE/2;
    int num[n];
    int player1_score = 0, player2_score = 0;
    for(int i = 0; i < n; i++){
        num[i] = i+1;
        num[i+n] = i+1;
    }
    shuffle(num, n*2);
    int current_player = 1;
    //initialize game board
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            arr[i][j] = num[SIZE*i + j];
        }
    }
    //initialize all elements as not guessed (-1)
    int guessed[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            guessed[i][j] = -1;
    display(arr, SIZE);
    while(!game_over(guessed, SIZE)){
        int x1, y1, x2, y2;
        printf("\nPlayer %d's turn.\nEnter the row and column of your first choice:\n", current_player);
        scanf("%d%d", &x1, &y1);
        while(guessed[x1-1][y1-1] != -1){
            printf("\nThis cell has already been guessed. Please try again.\nEnter the row and column of your first choice:\n");
            scanf("%d%d", &x1, &y1);
        }
        guessed[x1-1][y1-1] = arr[x1-1][y1-1];
        display(guessed, SIZE);
        printf("\nEnter the row and column of your second choice:\n");
        scanf("%d%d", &x2, &y2);
        while(guessed[x2-1][y2-1] != -1){
            printf("\nThis cell has already been guessed. Please try again.\nEnter the row and column of your second choice:\n");
            scanf("%d%d", &x2, &y2);
        }
        guessed[x2-1][y2-1] = arr[x2-1][y2-1];
        display(guessed, SIZE);
        if(arr[x1-1][y1-1] == arr[x2-1][y2-1]){
            printf("\nCongratulations! You have guessed the pair.\n");
            if(current_player == 1)
                player1_score++;
            else
                player2_score++;
        }else{
            printf("\nSorry! You have guessed incorrectly.\n");
            guessed[x1-1][y1-1] = -1;
            guessed[x2-1][y2-1] = -1;
            if(current_player == 1)
                current_player = 2;
            else
                current_player = 1;
        }
        printf("\nPlayer 1 Score: %d\tPlayer 2 Score: %d\n", player1_score, player2_score);
    }
    printf("\nGAME OVER!\n");
    if(player1_score > player2_score)
        printf("\nPlayer 1 wins!\n");
    else if(player2_score > player1_score)
        printf("\nPlayer 2 wins!\n");
    else
        printf("\nIt's a tie!\n");
    return 0;
}