//FormAI DATASET v1.0 Category: Memory Game ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 16

int randomize(int arr[]){
    srand(time(NULL));
    for(int i=0;i<MAX;i++){
        arr[i] = rand()%8 + 1;
    }
}

void display(int arr[],int guess[]){
    printf("\nCurrent state: ");
    for(int i=0;i<MAX;i++){
        if(guess[i]==1){
            printf("%d ",arr[i]);
        }
        else{
            printf("- ");
        }
    }
    printf("\n");
}

int main(){
    int arr[MAX],guess[MAX],count=0,last_pos=-1;

    randomize(arr);

    for(int i=0;i<MAX;i++){
        guess[i]=0;
    }

    while(count<MAX/2){
        display(arr,guess);
        int num1,num2;
        printf("Enter two positions (from 0 to %d) to reveal their values: ",MAX-1);
        scanf("%d %d",&num1,&num2);

        if(num1<0 || num1>=MAX || num2<0 || num2>=MAX){
            printf("Invalid position.\n");
            continue;
        }

        if(num1==last_pos || num2==last_pos){
            printf("These positions are already revealed.\n");
            continue;
        }

        if(guess[num1]==1 || guess[num2]==1){
            printf("These positions are already revealed.\n");
            continue;
        }

        if(arr[num1]==arr[num2]){
            printf("Match found!\n");
            guess[num1]=1;
            guess[num2]=1;
            count++;
        }
        else{
            printf("No match.\n");
        }

        last_pos=num2;
    }

    printf("\nCongratulations! You have won the game!\n");

    return 0;
}