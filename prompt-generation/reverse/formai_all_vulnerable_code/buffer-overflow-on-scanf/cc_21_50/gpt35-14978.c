//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 50            /* maximum number of nodes */
#define MAX_VAL 100            /* maximum value of a component */

int main()
{
    float V[MAX_NODES], I[MAX_NODES], A[MAX_NODES][MAX_NODES];
    int N, M, i, j, k;
    char choice;

    do{
        printf("Enter number of nodes (maximum %d) and elements (maximum %d): ", MAX_NODES-1, MAX_NODES*(MAX_NODES-1)/2);
        scanf("%d%d", &N, &M);
        if(N < 2 || N > MAX_NODES-1 || M < N-1 || M > MAX_NODES*(MAX_NODES-1)/2)
            printf("Invalid Input\n");
        else
            break;
    }while(1);

    /* Initializing matric A and vector V with zeros */
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            A[i][j] = 0;
    for (i = 0; i < N; i++)
        V[i] = 0;

    /* Taking input for nodes and elements */
    printf("Enter the elements one by one: \n");
    for (k = 0; k < M; k++)
    {
        int n1, n2, val;
        float g;
        char type;

        do{
            printf("Node 1: ");
            scanf("%d", &n1);
            if(n1 < 0 || n1 > N-1)
                printf("Invalid Node Number\n");
            else
                break;
        }while(1);

        do{
            printf("Node 2: ");
            scanf("%d", &n2);
            if(n2 < 0 || n2 > N-1)
                printf("Invalid Node Number\n");
            else if(n1==n2)
                printf("Node 1 and Node 2 cannot be the same\n");
            else
                break;
        }while(1);

        printf("Component Type (R/L/C): ");
        scanf(" %c", &type);

        switch(type){
            case 'R':
                printf("Resistance value (maximum %d): ", MAX_VAL);
                scanf("%d", &val);
                g = 1.0/val;
                break;
            case 'L':
                printf("Inductance value (maximum %d): ", MAX_VAL);
                scanf("%d", &val);
                g = 1.0/(2*M_PI*val);
                break;
            case 'C':
                printf("Capacitance value (maximum %d): ", MAX_VAL);
                scanf("%d", &val);
                g = 2*M_PI*val;
                break;
            default:
                printf("Invalid Component\n");
                k--;
                continue;
        }

        A[n1][n1] += g;
        A[n2][n2] += g;
        A[n1][n2] -= g;
        A[n2][n1] -= g;
    }

    /* Printing the matrix A */
    printf("\nMatrix A:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%f ", A[i][j]);
        printf("\n");
    }

    /* Taking input for voltage source values */
    printf("Enter the values of voltage sources: (-1 for ground)\n");
    for (i = 0; i < N; i++)
    {
        printf("Voltage at node %d: ", i);
        scanf("%f", &V[i]);
    }

    /* Printing the vector V */
    printf("\nVector V:\n");
    for (i = 0; i < N; i++)
        printf("%f ", V[i]);
    printf("\n\n");

    /* Solving the matrix equation */
    for (k = 0; k < N-1; k++)
    {
        for (i = k+1; i < N; i++)
        {
            float factor = A[i][k]/A[k][k];
            V[i] -= factor*V[k];
            for (j = k; j < N; j++)
                A[i][j] -= factor*A[k][j];
        }
    }

    /* Computing the values of I */
    I[N-1] = V[N-1]/A[N-1][N-1];
    for (i = N-2; i >= 0; i--)
    {
        float sum = 0;
        for (j = i+1; j < N; j++)
            sum += A[i][j]*I[j];
        I[i] = (V[i]-sum)/A[i][i];
    }

    /* Printing the solution */
    printf("Solution:\n");
    for (i = 0; i < N; i++)
        printf("V%d = %f, I%d = %f\n",i,I[i],i,I[i]*1000);

    /* Asking for rerun */
    printf("\nRun again? (y/n) ");
    scanf(" %c", &choice);
    if(choice == 'y' || choice == 'Y')
        main();
    else
        printf("Goodbye!\n");

    return 0;
}