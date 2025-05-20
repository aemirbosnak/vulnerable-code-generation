//FormAI DATASET v1.0 Category: Bitwise operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define SIZE 10

int a[SIZE], b[SIZE], c[SIZE];
int x, y;

void *and_op(void *args){
    int i;
    for(i = 0; i < SIZE; i++){
        c[i] = a[i] & b[i];
        printf("AND operation of a[%d] and b[%d] is %d\n", i, i, c[i]);
    }
    pthread_exit(NULL);
}

void *or_op(void *args){
    int i;
    for(i = 0; i < SIZE; i++){
        c[i] = a[i] | b[i];
        printf("OR operation of a[%d] and b[%d] is %d\n", i, i, c[i]);
    }
    pthread_exit(NULL);
}

void *not_op(void *args){
    int i;
    for(i = 0; i < SIZE; i++){
        c[i] = ~a[i];
        printf("NOT operation of a[%d] is %d\n", i, c[i]);
    }
    pthread_exit(NULL);
}

int main(){
    int i;
    printf("Enter values of array a:\n");
    for(i = 0; i < SIZE; i++)
        scanf("%d", &a[i]);
    
    printf("Enter values of array b:\n");
    for(i = 0; i < SIZE; i++)
        scanf("%d", &b[i]);
        
    pthread_t tid[3];
    
    if(pthread_create(&tid[0], NULL, and_op, NULL)){
        printf("Error creating thread 1\n");
        exit(EXIT_FAILURE);
    }
    
    if(pthread_create(&tid[1], NULL, or_op, NULL)){
        printf("Error creating thread 2\n");
        exit(EXIT_FAILURE);
    }
    
    if(pthread_create(&tid[2], NULL, not_op, NULL)){
        printf("Error creating thread 3\n");
        exit(EXIT_FAILURE);
    }
    
    for(i = 0; i < 3; i++){
        if(pthread_join(tid[i], NULL)){
            printf("Error joining thread %d\n", i+1);
            exit(EXIT_FAILURE);
        }
    }
    
    return 0;
}