//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 5
#define COLS 5

int main() 
{
    char name[20];
    srand(time(NULL));

    //Displaying Rules of Bingo
    printf("Welcome to the Bingo Simulator Game!\n");
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Hello %s, let's start the game!\n", name);
    printf("Here are the rules of the game:\n");
    printf("1. You will be given a 5x5 grid with random numbers from 1 to 25.\n");
    printf("2. The numbers in each column will be in the range of 1-15, 16-30, 31-45, 46-60, and 61-75 respectively.\n");
    printf("3. A random number will be chosen from 1 to 75.\n");
    printf("4. If the number chosen matches any number in the grid, that number will be replaced by an 'X'.\n");
    printf("5. The game ends when a player has marked all the numbers in a row, column, or diagonal.\n");

    //Creating and Displaying the Grid
    int grid[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(j == 0) {
                grid[i][j] = rand() % 15 + 1; //1-15
            } else if(j == 1) {
                grid[i][j] = rand() % 15 + 16; //16-30
            } else if(j == 2) {
                grid[i][j] = rand() % 15 + 31; //31-45
            } else if(j == 3) {
                grid[i][j] = rand() % 15 + 46; //46-60
            } else {
                grid[i][j] = rand() % 15 + 61; //61-75
            }
            printf("%d\t", grid[i][j]);
        }
        printf("\n");
    }

    //Playing the Game
    int row, col, diagonal1 = 0, diagonal2 = 0, win = 0, count = 0, num;
    printf("Press any key to start playing the game!\n");
    getchar(); //Clearing the Input Buffer
    getchar();
    while(win == 0) {
        num = rand() % 75 + 1;
        printf("The number called is: %d\n", num);
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                if(grid[i][j] == num) {
                    grid[i][j] = -1; //Marking the Number with an 'X'
                    count++;
                }
                if(i == j && grid[i][j] == -1) {
                    diagonal1++;
                }
                if(i + j == ROWS - 1 && grid[i][j] == -1) {
                    diagonal2++;
                }
                printf("%d\t", grid[i][j]);
            }
            printf("\n");
            if(count == 5) {
                printf("Congratulations! You have completed a row!\n");
                win = 1;
                break;
            }
            if(diagonal1 == 5 || diagonal2 == 5) {
                printf("Congratulations! You have completed a diagonal!\n");
                win = 1;
                break;
            }
        }
        for(int i = 0; i < COLS; i++) {
            count = 0;
            for(int j = 0; j < ROWS; j++) {
                if(grid[j][i] == -1) {
                    count++;
                }
                if(count == 5) {
                    printf("Congratulations! You have completed a column!\n");
                    win = 1;
                    break;
                }
            }
            if(win == 1) {
                break;
            }
        }
    }
    printf("Thanks for playing the game, %s!\n", name);
    return 0;
}