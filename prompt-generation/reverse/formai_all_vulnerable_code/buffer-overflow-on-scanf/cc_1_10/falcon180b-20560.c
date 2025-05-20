//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int rows, cols, i, j, num, sum = 0;

    srand(time(NULL));

    //Get user input for number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    //Create a 2D array with random numbers
    int arr[rows][cols];

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            arr[i][j] = rand() % 100;
        }
    }

    //Display the 2D array
    printf("\nThe 2D array is:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter a number to search for: ");
    scanf("%d", &num);

    //Search for the given number in the array
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (arr[i][j] == num) {
                sum += num;
            }
        }
    }

    //Display the sum of all occurrences of the given number
    printf("\nThe sum of all occurrences of %d is %d\n", num, sum);

    return 0;
}