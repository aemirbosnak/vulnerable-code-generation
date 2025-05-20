//Falcon-180B DATASET v1.0 Category: Bingo Simulator ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 5

char bingo_card[SIZE][SIZE] = {
    {'B', 'I', 'N', 'G', 'O'},
    {'I', 'N', 'G', 'O', 'B'},
    {'G', 'O', 'B', 'I', 'N'},
    {'O', 'B', 'I', 'N', 'G'},
    {'N', 'G', 'O', 'I', 'B'}
};

int main() {
    int i, j;
    int player_score = 0;
    int computer_score = 0;
    int flag = 0;

    srand(time(NULL));
    int num = rand() % 75 + 1;

    //Printing the bingo card
    for(i=0;i<SIZE;i++) {
        for(j=0;j<SIZE;j++) {
            printf("%c ", bingo_card[i][j]);
        }
        printf("\n");
    }

    while(flag!= 1) {
        int choice;
        printf("\nEnter your choice of number (1-75): ");
        scanf("%d", &choice);

        if(choice == num) {
            player_score++;
            flag = 1;
        }
        else if(bingo_card[choice/15][choice%15]!= 'X') {
            bingo_card[choice/15][choice%15] = 'X';
        }
        else {
            printf("\nSorry, the number %d is already marked with X\n", choice);
        }
    }

    printf("\nCongratulations! You have won the game with a score of %d\n", player_score);

    return 0;
}