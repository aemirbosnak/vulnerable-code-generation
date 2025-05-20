//FormAI DATASET v1.0 Category: Memory Game ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMS 100 
#define MAX_TRIES 5 

void initGame(int nums[], int size) {
    srand(time(NULL)); 
    for(int i=0; i<size; i++) {
        nums[i] = (rand() % MAX_NUMS) + 1; 
    }
}

void playGame(int nums[], int size) {
    int guess; 
    int tries = 0; 
    int correct = 0; 

    while(tries < MAX_TRIES && correct < size) {
        printf("Enter a number between 1 and %d: ", MAX_NUMS); 
        scanf("%d", &guess); 

        for(int i=0; i<size; i++) {
            if(nums[i] == guess) {
                correct++; 
                printf("You guessed correctly! You have %d numbers left to guess.\n", size-correct); 
                break;
            }
        }
        tries++; 
    }

    if(correct == size) {
        printf("Congratulations! You guessed all the numbers in %d tries.\n", tries); 
    }
    else {
        printf("Sorry, you did not guess all the numbers in %d tries.\n", MAX_TRIES); 
    }
}

int main() {
    int nums[10]; 

    printf("Welcome to the Memory Game! You will have to remember 10 random numbers between 1 and %d. You have %d tries to guess all the numbers.\n", MAX_NUMS, MAX_TRIES); 

    initGame(nums, 10); 
    playGame(nums, 10); 

    return 0; 
}