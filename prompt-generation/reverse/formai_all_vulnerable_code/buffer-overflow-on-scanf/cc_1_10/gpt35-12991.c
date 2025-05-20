//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

void printFibonacci(int);

int main()
{
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printFibonacci(n);
    return 0;
}

void printFibonacci(int n)
{
    int i, t1 = 0, t2 = 1, nextTerm;
    char visual[50][50] = {0};
    
    visual[0][0] = '0';
    visual[1][0] = '1';
    
    for (i = 2; i < n; i++) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        int j = 0;
        while(visual[i-1][j]!='\0')
        {
            visual[i][j] += visual[i-1][j] + visual[i-2][j];
            j++;
        }
        
        for(int k=0;k<50;k++){
            if(visual[i][k] == '\0') break;
            visual[i][k] += nextTerm;
        }
    }
    
    printf("The Fibonacci Sequence results are:\n\n");
    for (i = 0; i < n; i++) {
        for(int j=0;j<50;j++){
            if(visual[i][j] == '\0') break;
            printf("%c ", visual[i][j]);
        }    
        printf("\n");
    }

}