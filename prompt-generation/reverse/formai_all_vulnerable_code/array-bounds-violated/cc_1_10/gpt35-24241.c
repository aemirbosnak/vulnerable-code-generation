//FormAI DATASET v1.0 Category: Pattern printing ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define ROW 10
#define COL 10

char matrix[ROW][COL];

void print_matrix()
{
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
            printf("%c ",matrix[i][j]);
        printf("\n");
    }
}

void *print_c(void *arg)
{
    int start_col = *(int*)arg;
    for(int i=0;i<ROW;i++)
    {   
        matrix[i][start_col+i] = 'C';
    }

    return NULL;
}

void *print_backwards_c(void *arg)
{
    int start_row = *(int*)arg;
    for(int i=0;i<ROW;i++)
    {   
        matrix[start_row+i][COL-1-i] = 'C';
    }

    return NULL;
}

int main(int argc,char *argv[])
{
    pthread_t thread1,thread2;
    int thread1_args = 0;
    int thread2_args = 9;

    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
            matrix[i][j] = '-';
    }

    if(pthread_create(&thread1,NULL,&print_c,&thread1_args) != 0) 
        printf("Error creating thread1\n");

    if(pthread_create(&thread2,NULL,&print_backwards_c,&thread2_args) != 0) 
        printf("Error creating thread2\n");

    if(pthread_join(thread1,NULL) != 0) 
        printf("Error joining thread1\n");

    if(pthread_join(thread2,NULL) != 0) 
        printf("Error joining thread2\n");

    print_matrix();

    return 0;
}