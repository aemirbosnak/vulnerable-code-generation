//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: systematic
#include<stdio.h>

#include<math.h>

#define MAX 10

int n;

float R[MAX], G[MAX][MAX], E[MAX];

void GaussElimination()
{
    int i, j, k;
    float c, p, x[MAX];

    for(i=1;i<=n;i++)
    {
        c=R[i];

        for(j=i+1;j<=n;j++)
        {
            p=G[j][i]/G[i][i];

            for(k=i;k<=n;k++)
                G[j][k]=G[j][k]-p*G[i][k];

            R[j]=R[j]-p*c;
        }
    }

    x[n]=R[n]/G[n][n];

    for(i=n-1;i>=1;i--)
    {
        x[i]=R[i];

        for(j=i+1;j<=n;j++)
        {
            x[i]=x[i]-G[i][j]*x[j];
        }

        x[i]=x[i]/G[i][i];
    }

    printf("\n\nThe Solution is ::\n");

    for(i=1;i<=n;i++)
    {
        printf("\n\n Node %d : Voltage = %f ",i,x[i]);
    }
}

int main()
{
    int i,j,k;

    printf("\nCircuit Simulator\n");

    printf("\nEnter the No. of Nodes :: ");

    scanf("%d",&n);

    printf("\nEnter the Resistance of each Resistor ::\n");

    for(i=1;i<=n;i++)
    {
        printf("\nR[%d] = ",i);

        scanf("%f",&R[i]);
    }

    printf("\nEnter the Resistance between each Branch ::\n");

    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            if(i==j)
            {
                G[i][j]=0;
            }
            else
            {
                printf("\n R[%d][%d] = ",i,j);

                scanf("%f",&G[i][j]);

                G[j][i]=G[i][j];
            }
        }
    }

    printf("\nEnter the Voltage Sources ::\n");

    for(i=1;i<=n;i++)
    {
        printf("\n E[%d] = ",i);

        scanf("%f",&E[i]);
    }

    printf("\n\nThe Matrix System is ::\n");

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
            {
                for(k=1;k<=n;k++)
                    if(k!=j)
                        G[i][j]=G[i][j]+G[i][k];

                printf(" %f ",G[i][j]);
            }
            else
            {
                printf(" %f ",-G[i][j]);
            }
        }

        printf(" %f ",E[i]);

        printf("\n");
    }

    GaussElimination();

    return 0;
}