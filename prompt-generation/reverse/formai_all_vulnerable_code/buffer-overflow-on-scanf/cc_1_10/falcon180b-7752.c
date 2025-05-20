//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 10

int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX], m, n, p, q, i, j, k;
int sum = 0;
int count = 0;

void *runner(void *param); // the thread

int main() {

    printf("Enter rows and columns for first matrix: ");
    scanf("%d%d", &m, &n);

    printf("Enter elements of first matrix:\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d%d", &p, &q);

    if(n!=p)
        printf("The matrices can't be multiplied with each other.\n");
    else {
        printf("Enter elements of second matrix:\n");
        for(i=0; i<p; i++)
            for(j=0; j<q; j++)
                scanf("%d", &B[i][j]);

        pthread_t workers[m];
        int rows[m];

        for(i=0; i<m; i++) {
            rows[i] = i;
            pthread_create(&workers[i], NULL, runner, &rows[i]);
        }

        for(i=0; i<m; i++)
            pthread_join(workers[i], NULL);

        printf("Product of entered matrices:\n");
        for(i=0; i<m; i++) {
            for(j=0; j<q; j++) {
                C[i][j] = 0;
                for(k=0; k<n; k++)
                    C[i][j] += A[i][k]*B[k][j];
            }
        }

        for(i=0; i<m; i++) {
            for(j=0; j<q; j++)
                printf("%d\t", C[i][j]);
            printf("\n");
        }
    }

    return 0;
}

void *runner(void *param) {
    int id = *((int *) param);

    for(int c=0; c<q; c++) {
        sum = 0;
        for(int k=0; k<n; k++) {
            sum += A[id][k]*B[k][c];
        }
        C[id][c] = sum;
    }

    pthread_exit(0);
}