//Falcon-180B DATASET v1.0 Category: Table Game ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 5
#define MAX_VALUE 100

void generateTable(int table[SIZE][SIZE], int value) {
    int i, j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            table[i][j] = rand() % value;
        }
    }
}

void printTable(int table[SIZE][SIZE]) {
    int i, j;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int table[SIZE][SIZE];
    int value;
    int i, j, sum;

    printf("Enter the value for the table: ");
    scanf("%d", &value);

    srand(time(NULL));

    generateTable(table, value);

    printf("The table is:\n");
    printTable(table);

    sum = 0;
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            sum += table[i][j];
        }
    }

    printf("The sum of the table is: %d\n", sum);

    return 0;
}