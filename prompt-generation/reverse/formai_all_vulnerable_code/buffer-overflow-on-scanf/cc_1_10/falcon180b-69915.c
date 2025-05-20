//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void print_table(int table[ROWS][COLS]) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j, num1, num2, correct=0;
    int table[ROWS][COLS];
    srand(time(NULL));

    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            num1 = rand()%100;
            num2 = rand()%100;
            table[i][j] = num1 + num2;
        }
    }

    printf("Periodic Table Quiz\n");
    printf("------------------\n");
    printf("Answer the following questions:\n");
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("What is the sum of %d and %d? ", num1, num2);
            if(scanf("%d", &num1)!= 1) {
                printf("Invalid input.\n");
                exit(1);
            }
            if(num1 == table[i][j]) {
                correct++;
            }
        }
    }

    printf("\nYou got %d out of %d correct.\n", correct, ROWS*COLS);

    return 0;
}