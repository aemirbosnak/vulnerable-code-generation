//FormAI DATASET v1.0 Category: Memory Game ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int memory[5][5] = {0}; // 5x5 array for memory game
    int row1, col1, row2, col2; // variables for user input
    int count = 0; // variable to keep track of the number of pairs found
    int attempts = 0; // variable to keep track of the number of attempts made by user
    int i, j; // loop variables
    srand(time(NULL)); // random seed for generating numbers
    printf("Welcome to Memory Game. Let's begin!\n"); 
    // loop to randomly assign values to memory game array
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            int random_num = rand() % 10 + 1; // generate random number between 1-10
            memory[i][j] = random_num; // assign random number to array
        }
    }
    // loop to display memory game array
    for(i=0; i<5; i++){
        for(j=0; j<5; j++){
            printf("%d ", memory[i][j]); // print number in array
        }
        printf("\n"); // new line after each row
    }
    // loop to allow user to play game
    while(count < 12){
        // ask user for first card
        printf("Enter row and column of first card: ");
        scanf("%d %d", &row1, &col1);
        // print value of selected card
        printf("Value selected: %d\n\n", memory[row1][col1]);
        // ask user for second card
        printf("Enter row and column of second card: ");
        scanf("%d %d", &row2, &col2);
        // print value of selected card
        printf("Value selected: %d\n\n", memory[row2][col2]);
        if(memory[row1][col1] == memory[row2][col2]){
            printf("You found a pair!\n\n");
            memory[row1][col1] = 0; // set values to 0 to indicate pair found
            memory[row2][col2] = 0;
            count++; // increment number of pairs found
        }
        else{
            printf("Sorry, not a pair.\n\n");
        }
        attempts++; // increment number of attempts made by user
    }
    printf("Congratulations! You found all pairs in %d attempts.\n", attempts);
    return 0;
}