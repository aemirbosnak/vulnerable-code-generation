//FormAI DATASET v1.0 Category: Memory Game ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random numbers
int generateRandomNumber(int lower, int upper){
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void main(){
    int size, *p, *q, i, j, temp_pos, temp_val, attempts=0, matched=0;
    printf("Enter the size of the Memory Game: ");
    scanf("%d", &size);

    if(size%2!=0){
        printf("Size should be even!");
        exit(0);
    }

    // Initialize two arrays with same random numbers shuffled in them
    p = (int*)malloc(size*sizeof(int));
    q = (int*)malloc(size*sizeof(int));

    srand(time(NULL));

    for(i=0;i<size;i++){
        p[i] = i/2+1;
        q[i] = p[i];
    }

    for(i=0;i<size;i++){
        temp_pos = generateRandomNumber(0,size-1);
        temp_val = p[i];
        p[i] = p[temp_pos];
        p[temp_pos] = temp_val;

        temp_pos = generateRandomNumber(0,size-1);
        temp_val = q[i];
        q[i] = q[temp_pos];
        q[temp_pos] = temp_val;
    }

    // Print the shuffled arrays
    printf("\nMemory Game Starts!\n");
    for(i=0;i<size;i++){
        printf("%d ",p[i]);
    }
    printf("\n\n");

    for(i=0;i<size;i++){
        printf("? ");
    }
    printf("\n");

    // Start the Memory Game
    while(matched<size/2){

        printf("\nEnter two indexes to check (Separated by space): ");
        int index1, index2;
        scanf("%d %d", &index1, &index2);

        // If both the indexes are same or invalid, skip to next loop
        if(index1==index2 || index1<0 || index1>=size || index2<0 || index2>=size){
            printf("Invalid move! Choose two different indexes.\n");
            continue;
        }

        // If both the numbers at the indexes of p array matched, update q array and counter for matched pairs
        if(p[index1]==p[index2]){
            q[index1] = p[index1];
            q[index2] = p[index2];
            matched++;
        }
        else{
            printf("\nNot a match! Try again.\n");
        }

        // Print the current state of board
        for(i=0;i<size;i++){
            if(q[i]==0){
                printf("? ");
            }
            else{
                printf("%d ",q[i]);
            }
        }
        printf("\n");

        attempts++;     // Increment attempts counter on each move
    }

    printf("\n\nCongratulations! You completed the Memory Game in %d attempts.", attempts);

}