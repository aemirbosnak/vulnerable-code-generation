//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define ROWS 5
#define COLS 5

int bingoBoard[ROWS][COLS] = {{0}};
int numbersCalled[ROWS*COLS] = {0};

int checkBingo(int board[][COLS])
{
    int i, j;
    int row, col, diagonal1 = 0, diagonal2 = 0;
    int bingoCount = 0;
  
    // Check each row for a bingo
    for (i = 0; i < ROWS; i++) {
        row = 1;
        for (j = 0; j < COLS; j++) {
            row &= board[i][j];
        }
        if (row) {
            bingoCount += 1;
        }
    }
  
    // Check each column for a bingo
    for (j = 0; j < COLS; j++) {
        col = 1;
        for (i = 0; i < ROWS; i++) {
            col &= board[i][j];
        }
        if (col) {
            bingoCount += 1;
        }
    }
  
    // Check diagonal from top-left to bottom-right for a bingo
    for (i = 0; i < ROWS; i++) {
        diagonal1 &= board[i][j];
        j++;
    }
    if (diagonal1) {
        bingoCount += 1;
    }
  
    // Check diagonal from bottom-left to top-right for a bingo
    j = 0;
    for (i = ROWS-1; i >= 0; i--) {
        diagonal2 &= board[i][j];
        j++;
    }
    if (diagonal2) {
        bingoCount += 1;
    }
  
    return bingoCount;
}

void *caller(void *threadid)
{
    int i, num, row, col, count = 0;
    long tid = (long)threadid;
    srand(time(NULL) + tid); // Use thread id to seed random number generator
  
    while (count < ROWS*COLS) {
        // Generate a random number
        num = rand() % (ROWS*COLS) + 1;
    
        // Check if the number has already been called
        for (i = 0; i < ROWS*COLS; i++) {
            if (num == numbersCalled[i]) {
                break;
            }
        }
      
        // If the number hasn't been called, add it to the numbers called array, and mark it on the board
        if (i == ROWS*COLS) {
            printf("Caller %ld: %d\n", tid, num);
            numbersCalled[count] = num;
        
            row = (num-1)/ROWS;
            col = (num-1)%COLS;
            bingoBoard[row][col] = 1;
        
            count++;
        }
    }
  
    pthread_exit(NULL);
}

int main()
{
    int i, j, numCallers;
    pthread_t *threads;
    void *status;
  
    printf("How many callers would you like? (1 to 10): ");
    scanf("%d", &numCallers);
  
    threads = (pthread_t *)malloc(sizeof(pthread_t) * numCallers);
    if (!threads) {
        perror("Error allocating memory for threads\n");
        exit(1);
    }
  
    for (i = 0; i < numCallers; i++) {
        printf("Creating caller thread %d\n", i+1);
        if (pthread_create(&threads[i], NULL, caller, (void *)i)) {
            perror("Error creating thread\n");
            exit(1);
        }
    }
  
    for (i = 0; i < numCallers; i++) {
        if (pthread_join(threads[i], &status)) {
            perror("Error joining thread\n");
            exit(1);
        }
    }
  
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%2d ", bingoBoard[i][j]);
        }
        printf("\n");
    }
  
    printf("Number of bingos: %d\n", checkBingo(bingoBoard));
  
    free(threads);
  
    return 0;
}