//FormAI DATASET v1.0 Category: Data mining ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

/* Data Mining Algorithm - Paint by Numbers */

int main() {

    int rows, columns;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &columns);

    int picture[rows][columns];

    // Randomly generate numbers between 0 and 1 for the picture grid
    for(int i = 0; i < rows; i++) {
        
        for(int j = 0; j < columns; j++) {
            picture[i][j] = rand() % 2;
        }
        
    }

    // Print the generated picture grid
    printf("\nGenerated picture grid:\n");

    for(int i = 0; i < rows; i++) {
        
        for(int j = 0; j < columns; j++) {
            printf("%d ", picture[i][j]);
        }

        printf("\n");
        
    }

    int numbered_rows[rows][columns];
    int numbered_columns[rows][columns];

    // Initialize numbered rows and columns arrays with 0s
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            numbered_rows[i][j] = 0;
            numbered_columns[i][j] = 0;
        }
    }

    // Paint by numbers algorithm for rows
    for(int i = 0; i < rows; i++) {
        
        int number_count = 0;

        for(int j = 0; j < columns; j++) {
            
            if(picture[i][j] == 1) {
                number_count++;
            } else {
                if(number_count > 0) {
                    for(int k = j - number_count; k < j; k++) {
                        numbered_rows[i][k] = number_count;
                    }
                }
                number_count = 0;
            }

        }

        if(number_count > 0) {
            for(int k = columns - number_count; k < columns; k++) {
                numbered_rows[i][k] = number_count;
            }
        }

    }

    // Paint by numbers algorithm for columns
    for(int j = 0; j < columns; j++) {

        int number_count = 0;

        for(int i = 0; i < rows; i++) {

            if(picture[i][j] == 1) {
                number_count++;
            } else {
                if(number_count > 0) {
                    for(int k = i - number_count; k < i; k++) {
                        numbered_columns[k][j] = number_count;
                    }
                }
                number_count = 0;
            }

        }

        if(number_count > 0) {
            for(int k = rows - number_count; k < rows; k++) {
                numbered_columns[k][j] = number_count;
            }
        }

    }

    // Print the numbered rows and columns arrays
    printf("\nNumbered rows:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("%d ", numbered_rows[i][j]);
        }
        printf("\n");
    }

    printf("\nNumbered columns:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            printf("%d ", numbered_columns[i][j]);
        }
        printf("\n");
    }

    return 0;

}