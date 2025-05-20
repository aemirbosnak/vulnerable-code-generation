//Falcon-180B DATASET v1.0 Category: Table Game ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 5
#define START_VALUE 1
#define END_VALUE 100

int main(){
    int table[SIZE][SIZE];
    int i,j,k,l;
    int sum = 0;
    int count = 0;
    int start_value, end_value;
    int random_value;
    int player_value;
    int player_choice;
    int computer_value;
    int computer_choice;
    int win_lose = 0;

    srand(time(NULL));
    start_value = rand() % (START_VALUE-1) + START_VALUE;
    end_value = rand() % (END_VALUE-1) + START_VALUE;

    //initialize table with random values
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            random_value = rand() % (end_value-start_value+1) + start_value;
            table[i][j] = random_value;
        }
    }

    //print table
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter your value: ");
    scanf("%d",&player_value);

    while(win_lose == 0){
        printf("\nEnter your choice: ");
        scanf("%d",&player_choice);

        //check for invalid choice
        if(player_choice < 1 || player_choice > SIZE){
            printf("\nInvalid choice. Try again.\n");
            continue;
        }

        //check for win
        if(table[player_choice-1][0] == player_value){
            printf("\nYou win!\n");
            win_lose = 1;
            break;
        }

        //check for lose
        if(table[player_choice-1][SIZE-1] == player_value){
            printf("\nYou lose!\n");
            win_lose = -1;
            break;
        }

        //check for draw
        if(table[player_choice-1][SIZE-1] == player_value + table[player_choice-1][0] - 1){
            printf("\nIt's a draw.\n");
            win_lose = 0;
            break;
        }

        //computer's turn
        computer_value = table[player_choice-1][0] + table[player_choice-1][SIZE-1] - player_value;
        computer_choice = rand() % SIZE;
        while(table[computer_choice][0]!= computer_value){
            computer_choice = rand() % SIZE;
        }
        table[computer_choice][SIZE-1] = computer_value;
    }

    return 0;
}