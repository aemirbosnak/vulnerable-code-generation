//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int maze[20][20];

void generateMaze(int row, int col) {
    int i, j;
    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            maze[i][j] = rand()%2;
        }
    }
    // Make entrance and exit points
    maze[0][0] = 1;
    maze[row-1][col-1] = 1;
}

int findPath(int row, int col) {
    int i = 0, j = 0;
    while(i < row && j < col) {
        if(maze[i+1][j] == 1) {
            i++;
        } else if(maze[i][j+1] == 1) {
            j++;
        } else if(maze[i+1][j+1] == 1) {
            i++;
            j++;
        } else {
            return -1;
        }
    }
    return 1;
}

void printMaze(int row, int col) {
    int i, j;
    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            if(maze[i][j] == 1) {
                printf("0 ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int main() {
    int row, col;
    srand(time(NULL));
    printf("The Maze Creator\n");
    printf("Enter number of rows (max 20): ");
    scanf("%d", &row);
    printf("Enter number of cols (max 20): ");
    scanf("%d", &col);
    if(row > 20 || col > 20) {
        printf("Invalid input.\n");
        return 0;
    }
    generateMaze(row, col);
    printf("\nThe maze:-\n");
    printMaze(row, col);
    if(findPath(row, col) == 1) {
        printf("\n\nCongratulations! You have found the exit.\n");
    } else {
        printf("\n\nOops! You seem to be trapped in the maze!\n");
    }
    printf("\n\n\nCredits:-\nThis surreal maze was created by the surreal me!\n");
    return 0;
}