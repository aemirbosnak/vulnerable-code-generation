//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: irregular
#include <stdio.h>

int main()
{
    int n, m = 0;
    char a = 'A', b = 'B', c = 'C';

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    if(n<1){
        printf("There should be at least one disk");
        return 0;
    }

    printf("\n\nThe sequence of moves involved in the Tower of Hanoi problem with %d disks is:\n", n);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            printf(" %c -> %c ", a, b);
        }
        m += i;
        if(i % 2 == 0){
            printf(" Number of moves made is %d\n", m);
            for(int j = 1; j <= i; j++){
                printf(" %c -> %c ", b, c);
            }
        }
        else{
            printf(" Number of moves made is %d\n", m);
            for(int j = 1; j <= i; j++){
                printf(" %c -> %c ", b, a);
            }
        }
        m += i;
        if(i % 2 == 0){
            printf(" Number of moves made is %d\n", m);
            for(int j = 1; j <= i; j++){
                printf(" %c -> %c ", a, c);
            }
        }
        else{
            printf(" Number of moves made is %d\n", m);
            for(int j = 1; j <= i; j++){
                printf(" %c -> %c ", a, b);
            }
        }
    }

    printf("\n\nTotal number of moves made in the Tower of Hanoi problem with %d disks is: %d", n, m);

    return 0;
}