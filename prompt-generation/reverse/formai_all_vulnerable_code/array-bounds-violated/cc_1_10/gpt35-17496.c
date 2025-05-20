//FormAI DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

// Function to shuffle array
void shuffleArray(int arr[], int n) 
{ 
    // Use a different seed value so that 
    // we don't get same result each time 
    srand(time(NULL)); 
  
    // Start from the last element and swap one by one 
    for (int i = n-1; i > 0; i--) 
    { 
        // Pick a random index from 0 to i 
        int j = rand() % (i+1); 
  
        // Swap arr[i] with the element at random index 
        int temp = arr[i]; 
        arr[i] = arr[j]; 
        arr[j] = temp; 
    } 
}

int main() 
{
    int board[BOARD_SIZE*BOARD_SIZE];
    int flipped[BOARD_SIZE*BOARD_SIZE] = { 0 };
    int x, y, i;

    // Initialize the board
    for(i=0; i<(BOARD_SIZE*BOARD_SIZE); i+=2) {
        board[i] = i/2;
        board[i+1] = i/2;
    }

    // Shuffle the board
    shuffleArray(board, BOARD_SIZE*BOARD_SIZE);

    while (1) {
        // Print the board
        printf("\n\n");
        for(y=0; y<BOARD_SIZE; y++) {
            for(x=0; x<BOARD_SIZE; x++) {
                if(flipped[y*BOARD_SIZE+x]) {
                    printf("%2d ", board[y*BOARD_SIZE+x]);
                } else {
                    printf("## ");
                }
            }
            printf("\n");
        }

        // Get user input
        printf("\nEnter x y coordinates of the card to flip: ");
        scanf("%d%d", &x, &y);

        // Flip the card
        if(x<1 || x>BOARD_SIZE || y<1 || y>BOARD_SIZE) {
            printf("Invalid input. Try again.");
        } else {
            x--;
            y--;
            flipped[y*BOARD_SIZE+x] = 1;

            // Check for a match
            if(flipped[y*BOARD_SIZE+x] == flipped[y*BOARD_SIZE+(x+1)%BOARD_SIZE] &&
               flipped[y*BOARD_SIZE+x] == flipped[y*BOARD_SIZE+(x+BOARD_SIZE-1)%BOARD_SIZE] &&
               flipped[y*BOARD_SIZE+x] == flipped[(y+1)*BOARD_SIZE+x] &&
               flipped[y*BOARD_SIZE+x] == flipped[(y+BOARD_SIZE-1)*BOARD_SIZE+x]) {
                printf("Match found!\n");
            }   
        }
    }

    return 0;
}