//FormAI DATASET v1.0 Category: Table Game ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int arr[10][10], sum=0, i, j, row, col, guess;
    
    srand(time(NULL)); // seed for random numbers
    
    // initialize array with random numbers between 1 and 10
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            arr[i][j] = rand() % 10 + 1;
        }
    }
    
    // display the array
    printf("Here is the array:\n\n");
    for(i=0; i<10; i++) {
        for(j=0; j<10; j++) {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
    
    // ask user to guess the sum of a specific row/colum
    printf("Can you guess the sum of a specific row/column? Enter 1 for rows or 2 for columns: ");
    fflush(stdout);
    scanf("%d", &guess);
    
    // if user selects row
    if(guess == 1) {
        printf("Enter row number (0 to 9): ");
        fflush(stdout);
        scanf("%d", &row);
        for(j=0; j<10; j++) {
            sum += arr[row][j];
        }
        printf("The sum of your selected row is %d", sum);
    }
    
    // if user selects column
    else if(guess == 2) {
        printf("Enter column number (0 to 9): ");
        fflush(stdout);
        scanf("%d", &col);
        for(i=0; i<10; i++) {
            sum += arr[i][col];
        }
        printf("The sum of your selected column is %d", sum);
    }
    
    // if user enters incorrect choice
    else {
        printf("Invalid choice!");
    }
    
    return 0;
}