//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>

#define NUM_THREADS 10

double A[100][100],B[100][100],C[100][100];
int m,n,k,i,j,l;
pthread_mutex_t mutex;

void *runner(void *param)
{
    int start = *(int*)param;
    int end = start + 10;

    for(int i=start; i<end; i++)
    {
        for(int j=0; j<k; j++)
        {
            pthread_mutex_lock(&mutex);
            C[i][j] = 0;
            for(int l=0; l<m; l++)
            {
                C[i][j] += A[i][l] * B[l][j];
            }
            pthread_mutex_unlock(&mutex);
        }
    }

    return NULL;
}

int main()
{
    printf("Enter the number of rows and columns for first matrix: ");
    scanf("%d%d",&m,&k);
    printf("Enter the number of columns for second matrix: ");
    scanf("%d",&n);

    printf("Enter elements of first matrix:\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<k; j++)
        {
            scanf("%lf",&A[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for(i=0; i<k; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%lf",&B[i][j]);
        }
    }

    pthread_t workers[NUM_THREADS];
    int ids[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);

    for(l=0; l<NUM_THREADS; l++)
    {
        pthread_create(&workers[l], NULL, runner, (void*)l);
        ids[l] = l;
    }

    for(l=0; l<NUM_THREADS; l++)
    {
        pthread_join(workers[l], NULL);
    }

    printf("Resultant Matrix:\n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%lf\t",C[i][j]);
        }
        printf("\n");
    }

    return 0;
}