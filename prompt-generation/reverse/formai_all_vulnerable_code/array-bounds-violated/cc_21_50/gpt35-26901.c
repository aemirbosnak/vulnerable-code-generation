//FormAI DATASET v1.0 Category: Table Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i,j,cnt=1,x;
    char ans;
    printf("Welcome to the C Table Game !\n");

    do{
        srand(time(NULL));
        // Generating a 3x3 matrix with random values
        int arr[3][3];
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                x = rand()%10;
                arr[i][j]=x;
            }
        }

        // Displaying initial matrix
        printf("\nInitial Table: \n");
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }

        // Settings rules for the C Table Game
        printf("\nThe goal is to change the table to the following:\n\n");
        printf("X X X \nX X X \nX X X \n");

        printf("\nEach player can select a position on the table and replace the value at that position with an X or O.\n");
        printf("Players take turns using X and O to make moves.\n");
        printf("A player wins by having three X's or O's lined up either horizontally, vertically, or diagonally on the table.\n");

        printf("\nLet's Start the Game !\n");
        printf("Player 1 will use X and Player 2 will use O.\n");

        int p = 1;
        int row, col;

        do {
            printf("\nPlayer %d, Enter row: ", p);
            scanf("%d", &row);
            printf("Player %d, Enter column: ", p);
            scanf("%d", &col);

            if (p == 1) {
                arr[row-1][col-1] = 'X';
            } else {
                arr[row-1][col-1] = 'O';
            }

            printf("\nBoard:\n");
            // Displaying updated matrix
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    printf("%c ",arr[i][j]);
                }
                printf("\n");
            }

            // Checking winning condition
            if(cnt>=5) {
                if ((arr[0][0] == arr[0][1] && arr[0][1] == arr[0][2]) ||
                    (arr[1][0] == arr[1][1] && arr[1][1] == arr[1][2]) ||
                    (arr[2][0] == arr[2][1] && arr[2][1] == arr[2][2]) ||
                    (arr[0][0] == arr[1][0] && arr[1][0] == arr[2][0]) ||
                    (arr[0][1] == arr[1][1] && arr[1][1] == arr[2][1]) ||
                    (arr[0][2] == arr[1][2] && arr[1][2] == arr[2][2]) ||
                    (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) ||
                    (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])) {
                    printf("\nPlayer %d has WON!\n",p);
                    break;
                }
            }

            if (p == 1)
                p = 2;
            else
                p = 1;

            cnt++;

        } while (cnt <= 9);

        if(cnt==10){
            printf("\nThe game is a DRAW!\n");
        }

        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c",&ans);

    } while (ans == 'Y' || ans == 'y');

    return 0;
}