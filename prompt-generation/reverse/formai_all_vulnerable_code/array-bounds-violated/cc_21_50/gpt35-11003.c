//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));                          //initialize random seed
    
    char card[5][5] = { {'B', 'I', 'N', 'G', 'O'},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}
    };
    
    //fill out the card with random numbers
    for(int col = 1; col <= 5; col++) {
        for(int row = 1; row <= 5; row++) {
            if(col == 1 && row == 1) card[row][col] = 'F';
            else if(col == 3 && row == 3) card[row][col] = 'R';
            else {
                int num = rand() % 15 + 1;
                while(num == 0) num = rand() % 15 + 1;
                card[row][col] = num;
            }
        }
    }
    
    printf("B\tI\tN\tG\tO\n");                 //print out the card
    for(int row = 1; row <= 5; row++) {
        for(int col = 1; col <= 5; col++) {
            if(card[row][col] == 'F') printf("FREE\t");
            else if(card[row][col] == 'R') printf("REP\t");
            else printf("%d\t", card[row][col]);
        }
        printf("\n");
    }
    
    printf("\n\n");

    int calls[75] = { 0 };                      //initialize the array of called numbers
    
    int num_calls = 0;
    
    printf("Starting the game!\n\n");
    
    while(num_calls < 75) {                     //play the game
        int num = rand() % 75 + 1;
        while(calls[num - 1] == 1) {
            num = rand() % 75 + 1;
        }
        calls[num - 1] = 1;
        num_calls++;
        printf("The call is: %d\n", num);
        
        //check for matches
        for(int row = 1; row <= 5; row++) {
            for(int col = 1; col <= 5; col++) {
                if(card[row][col] == num) {
                    card[row][col] = 'X';
                }
            }
        }
        
        //check for winning conditions
        int bingo = 0;
        
        //rows
        for(int row = 1; row <= 5; row++) {
            bingo = 1;
            for(int col = 1; col <= 5; col++) {
                if(card[row][col] != 'X') {
                    bingo = 0;
                }
            }
            if(bingo) {
                printf("BINGO! ROW %d!\n", row);
                exit(0);
            }
        }
        
        //columns
        for(int col = 1; col <=5; col++) {
            bingo = 1;
            for(int row = 1; row <= 5; row++) {
                if(card[row][col] != 'X') {
                    bingo = 0;
                }
            }
            if(bingo) {
                printf("BINGO! COLUMN %d!\n", col);
                exit(0);
            }
        }
        
        //diagonals
        if(card[1][1] == 'X' && card[2][2] == 'X' && card[3][3] == 'X' && card[4][4] == 'X' && card[5][5] == 'X') {
            printf("BINGO! DIAGONAL FROM TOP LEFT TO BOTTOM RIGHT!\n");
            exit(0);
        }
        if(card[1][5] == 'X' && card[2][4] == 'X' && card[3][3] == 'X' && card[4][2] == 'X' && card[5][1] == 'X') {
            printf("BINGO! DIAGONAL FROM TOP RIGHT TO BOTTOM LEFT!\n");
            exit(0);
        }
        
        printf("\n");
    }
    
    printf("Game over! No bingo was achieved.\n");
    
    return 0;
}