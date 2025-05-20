//FormAI DATASET v1.0 Category: Memory Game ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shuffle(int *arr, int n){
    for(int i=n-1; i>=0; i--){
        int j=rand()/(RAND_MAX/(i+1)+1);
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}

void printBoard(int *arr, int n){
    for(int i=0; i<n; i++){
        if(arr[i] != -1){
            printf("%d, ", arr[i]);
        }
        else{
            printf("*, ");
        }
    }
    printf("\n");
}

void checkMatch(int *arr, int n, int i, int j){
    if(arr[i] == arr[j]){
        arr[i] = -1;
        arr[j] = -1;
    }
}

int main(){
    srand(time(NULL));
    int n = 10;
    int board[n];
    int foundPair = 0;
    for(int i=0; i<n/2; i++){
        board[i] = i+1;
        board[i+n/2] = i+1;
    }
    shuffle(board, n);
    printf("Welcome to the Memory Game!\n\n");

    while(!foundPair){
        int i, j;
        printBoard(board, n);
        printf("Enter the index of two numbers (0-%d) you want to flip over and check for matching (separate with space): ", n-1);
        scanf("%d %d", &i, &j);
        checkMatch(board, n, i, j);
        foundPair = 1;
        for(int k=0; k<n; k++){
            if(board[k] != -1){
                foundPair = 0;
                break;
            }
        }
    }

    printf("\nCongratulations! You found all pairs!");

    return 0;
}