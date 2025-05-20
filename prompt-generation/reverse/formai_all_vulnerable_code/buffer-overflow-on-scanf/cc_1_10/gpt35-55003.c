//FormAI DATASET v1.0 Category: Graph representation ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>

#define MAX 100
void create_graph();

int A[MAX][MAX], n;
void paranoia_check(int arr[MAX][MAX], int n, int sum)//checks if the sum of each row and column is same
{
    int i,j,Rsum,Csum;
    for(i=0;i<n;i++)
    {
        Rsum = Csum = 0;
        for(j=0;j<n;j++)
        {
            Rsum += arr[i][j];
            Csum += arr[j][i];
        }
        if(Rsum!=sum || Csum!=sum)
        {
            printf("PARANOIA ALERT!! Hacked graph detected.\n");
            exit(0);
        }
    }
    printf("Graph is secured. No sign of hacking detected.\n");
}

int main()
{
    int i,j, sum=0;
    printf("Enter number of vertices: ");
    scanf("%d",&n);

    create_graph();

    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);
            sum += A[i][j];
        }
    }
    sum = sum/n;

    paranoia_check(A, n, sum);

    printf("\nAdjacency Matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }

    return 0;
}

void create_graph()
{   
    char *paranoia_message = "BEWARE! Creating graph!";
    printf("%s\n", paranoia_message); //paranoia alert
    int MAX_EDGES;
    int count,u,v;

    MAX_EDGES = n*(n-1)/2;

    for(count=1; count<=MAX_EDGES; count++)
    {
        printf("Enter edge %d(-1 -1 to quit): ",count);
        scanf("%d %d",&u,&v);

        if(u==-1 && v==-1)
            break;

        if(u<0 || v<0 || u>n || v>n)
        {
            printf("Invalid edge!\n");
            count--;
        }
        else
        {
            A[u][v] = A[v][u] = 1;
        }
    }
}