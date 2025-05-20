//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: secure
#include <stdio.h>

int fibonacci(int n) {
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

void printLine(int length) {
    printf("+");
    for(int i=0; i<length; i++) {
        printf("-");
    }
    printf("+\n");
}

void printFibonacci(int n) {
    int a = 1, b = 1, c = 1, i;

    printf("%d %d ", a, b);
    for(i=3; i<=n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
}

void printTable(int n) {
    int i, j, num, maxLength;

    for(i=0; i<n; i++) {
        printf("| ");
        for(j=0; j<n; j++) {
            num = fibonacci(i+j+1);

            maxLength = 0;
            while(num>0) {
                num = num/10;
                maxLength++;
            }

            printf("%d", fibonacci(i+j+1));
            for(int k=0; k<4-maxLength; k++) {
                printf(" ");
            }
            printf("| ");
        }
        printf("\n");
    }
}

void main() {
    int n;

    printf("Enter the number of rows/columns: ");
    scanf("%d", &n);
    printf("\n");

    printLine(5*n);
    printTable(n);
    printLine(5*n);
}