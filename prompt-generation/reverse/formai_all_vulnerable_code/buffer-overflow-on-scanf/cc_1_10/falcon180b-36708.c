//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[100][100];
int n,m;
void init();
void drawBoard();
void percolate();
int countAdj(int i, int j);

int main() {
    srand(time(NULL));
    init();
    drawBoard();
    percolate();
    return 0;
}

void init() {
    printf("Enter board dimensions: ");
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void drawBoard() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(board[i][j] == 0) {
                printf(".");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
}

void percolate() {
    int i,j;
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(board[i][j] == 0) {
                int count = countAdj(i,j);
                if(count == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
}

int countAdj(int i, int j) {
    int count = 0;
    if(i>0 && board[i-1][j] == 1) count++;
    if(i<n-1 && board[i+1][j] == 1) count++;
    if(j>0 && board[i][j-1] == 1) count++;
    if(j<m-1 && board[i][j+1] == 1) count++;
    return count;
}