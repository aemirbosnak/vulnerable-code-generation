//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Welcome to the Fibonacci Sequence Visualizer in Medieval Style!\n");
    printf("Please enter the number of terms you want to see:\n");
    int n;
    scanf("%d", &n);

    long long first = 0, second = 1, next;
    printf("Here is the Fibonacci Sequence up to %d terms:\n", n);

    printf("******O******\n");
    printf("*          *\n");
    printf("*    0     *\n");
    printf("*          *\n");
    printf("******O******\n");

    for(int i = 0; i < n; i++){
        if(i == 0){
            next = first;
        }else if(i == 1){
            next = second;
        }else{
            next = first + second;
            first = second;
            second = next;
        }
        printf("\n\n");
        printf("***************O***************\n");
        printf("*                             *\n");
        printf("*          %lld               *\n", next);
        printf("*                             *\n");
        printf("***************O***************\n");

        if((i+1) % 3 == 0){
            printf("\n");
            printf("**************O**************\n");
            printf("*                            *\n");
            printf("*         The End            *\n");
            printf("*                            *\n");
            printf("**************O**************\n");
        }else{
            printf("************O************\n");
            printf("*                      *\n");
            printf("*     Continue...      *\n");
            printf("*                      *\n");
            printf("************O************\n");
        }

        printf("\n");
        printf("******O******\n");
        printf("*          *\n");
        printf("*    %lld     *\n", second);
        printf("*          *\n");
        printf("******O******\n");
    }

    return 0;
}