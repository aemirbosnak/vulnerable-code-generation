//FormAI DATASET v1.0 Category: Memory Game ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    
    printf("-----------Welcome to C Memory Game-----------\n\n");
    
    int tiles[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}; //We will use these tiles to hide numbers
    
    int matched[16] = {0}; //This array will keep track of matched numbers
    
    srand(time(0)); //To generate random numbers
    
    //shuffle algorithm
    for(int i=0;i<16;i++){
        int temp = tiles[i];
        int randomIndex = rand()%16;
        tiles[i]=tiles[randomIndex];
        tiles[randomIndex]=temp;
    }
    
    //Printing initial board
    printf("\tMemory Game Board\n\n");
    for(int i=0;i<16;i++){
        if(i%4==0){
            printf("\n");
        }
        printf("\t%d\t",tiles[i]);
    }
    
    printf("\n\n");
    
    int guess1,guess2; 
    int count = 0;
    
    //loop repeats until all tiles are matched
    while(count<16){
        
        printf("Enter two tile numbers (separated by space) to reveal its value: ");
        scanf("%d %d",&guess1,&guess2);
        
        if(matched[guess1-1]==1 || matched[guess2-1]==1){
            printf("Tile is already matched! Try Again.\n\n");
            continue;
        }
        
        if(tiles[guess1-1]==tiles[guess2-1]){
            printf("\nMatch found: %d and %d\n\n",tiles[guess1-1],tiles[guess2-1]);
            matched[guess1-1]=1;
            matched[guess2-1]=1;
            count+=2;
        }
        else{
            printf("\nNo match found! Please try again.\n\n");
        }
        
        //Printing current board status
        printf("\tMemory Game Board\n\n");
        for(int i=0;i<16;i++){
            if(matched[i]==1){
                printf("\tX\t");
            }
            else{
                printf("\t%d\t",tiles[i]);
            }
            if(i%4==3){
                printf("\n");
            }
        }
        
        printf("\n\n");
        
    }
    printf("Congratulations! You have won the game.");
    return 0;
}