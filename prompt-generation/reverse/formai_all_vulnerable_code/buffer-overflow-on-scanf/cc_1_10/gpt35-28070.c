//FormAI DATASET v1.0 Category: Benchmarking ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 1000
int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];

void puzzle()
{
    printf("Solve this puzzle to continue: \n");
    printf("I am a 3-digit number. My second digit is 4 times bigger than my third digit.\n");
    printf("My first digit is 3 less than my second digit and 2 less than my third digit.\n");
    printf("What number am I? Enter your answer: ");
    int ans;
    scanf("%d", &ans);
    if(ans != 248)
    {   
        printf("Sorry, that's incorrect. Try again later.\n");
        exit(0);
    }
}

void matrixMultiplication(){ 
    int i, j, k;
    clock_t start,end;
    double cpu_time_used;

    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;
        }
    }

    start = clock();

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            c[i][j] = 0;
            for (k =0; k < MAX; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    end = clock();
    printf("Matrix multiplication completed in %lf seconds\n", (double)(end-start)/CLOCKS_PER_SEC);

    printf("Result of multiplication is:\n");

    for(i = 0; i < MAX; i++){
        for(j = 0; j < MAX; j++){
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}

int main(){
    puzzle();
    printf("Benchmarking Matrix Multiplication for %d x %d matrix\n", MAX, MAX);
    matrixMultiplication();
    return 0;
}