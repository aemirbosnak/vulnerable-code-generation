//FormAI DATASET v1.0 Category: Memory Game ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to swap to integers
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//function to shuffle array
void shuffle(int arr[], int n){
    // Use a different seed value so that we don't get same
    // result each time we run this program
    srand(time(NULL));
 
    // Start from the last element and swap one by one. We don't
    // need to run for the first element that's why i > 0
    for (int i = n - 1; i > 0; i--) {
        // Pick a random index from 0 to i
        int j = rand() % (i + 1);
 
        // Swap arr[i] with the element at random index
        swap(&arr[i], &arr[j]);
    }
}

//function to display the game board
void display(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//function to check if game is over
int isOver(int arr[], int n){
    for(int i=0;i<n;i++){
        if(arr[i]!=i+1){
            return 0;
        }
    }
    return 1;
}

int main(){
    printf("Welcome to Memory Game!\n");
    printf("Instructions:\n");
    printf("1. You will be shown a board of numbers in random order\n");
    printf("2. Memorize the order\n");
    printf("3. The board will be shuffled and you have to enter the numbers in the correct order\n");
    printf("4. You have 3 lives. Game ends if you lose all the lives\n");
    printf("5. Good luck!\n\n");

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int n=10;
    int lives = 3;
    int score = 0;
    int guess[10];

    shuffle(arr,n);

    printf("Memorize the board:\n\n");
    display(arr,n);

    getchar(); //pause for user to memorize

    system("clear"); //clear screen

    printf("Enter the numbers in correct order:\n\n");

    while(lives>0){
        display(arr,n);
        for(int i=0;i<n;i++){
            scanf("%d",&guess[i]);
        }
        if(isOver(guess,n)){
            printf("\nCongratulations! You win!\n");
            printf("Your score is %d.\n",score);
            break;
        }
        else{
            printf("\nSorry, wrong answer.\n");
            score--;
            lives--;
            printf("%d lives left.\n",lives);
            if(lives==0){
                printf("Game Over!\n");
                printf("Your score is %d.\n",score);
                break;
            }
        }
    }

    return 0;
}