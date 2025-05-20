//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_NODES 100
#define MAX_COMP 300
#define MAX_VAL 6

struct element
{
    char name[5];
    double value;
    int node[2];
}comp[MAX_COMP];

int number_of_nodes = 0, number_of_comp = 0;
double A[MAX_NODES+1][MAX_NODES+2];

void construct_matrix()   //Construction of matrix A
{
    int i, j, k, l, m, n;

    for(i=1;i<=number_of_nodes;i++)
    {
        for(j=1;j<=number_of_nodes+1;j++)
        {
            A[i][j] = 0;
        }
    }

    for(i=1;i<=number_of_comp;i++)
    {
        if(comp[i].name[0]=='V')    //For independent voltage source
        {
            if(comp[i].node[0]!=0)
            {
                A[comp[i].node[0]][number_of_nodes+1] -= comp[i].value;
            }
            if(comp[i].node[1]!=0)
            {
                A[comp[i].node[1]][number_of_nodes+1] += comp[i].value;
            }
        }

        else if(comp[i].name[0]=='I')   //For independent current source
        {
            if(comp[i].node[0]!=0)
            {
                A[comp[i].node[0]][comp[i].node[0]] += 1;
            }
            if(comp[i].node[1]!=0)
            {
                A[comp[i].node[1]][comp[i].node[1]] += 1;
            }
            if(comp[i].node[0]!=0 && comp[i].node[1]!=0)
            {
                A[comp[i].node[0]][comp[i].node[1]] -= 1;
                A[comp[i].node[1]][comp[i].node[0]] += 1;
            }
        }

        else        //For resistors, capacitors and inductors
        {
            if(comp[i].node[0]!=0)
            {
                A[comp[i].node[0]][comp[i].node[0]] += 1/comp[i].value;
            }
            if(comp[i].node[1]!=0)
            {
                A[comp[i].node[1]][comp[i].node[1]] += 1/comp[i].value;
            }
            if(comp[i].node[0]!=0 && comp[i].node[1]!=0)
            {
                A[comp[i].node[0]][comp[i].node[1]] -= 1/comp[i].value;
                A[comp[i].node[1]][comp[i].node[0]] += 1/comp[i].value;
            }
        }
    }
}

void solve_matrix()   //Solution of matrix A to get the node voltages
{
    int i, j, k;
    double factor;

    for(k=1;k<=number_of_nodes;k++)
    {
        for(i=1;i<=number_of_nodes;i++)
        {
            if(i!=k)
            {
                factor = A[i][k]/A[k][k];
                for(j=k+1;j<=number_of_nodes+1;j++)
                {
                    A[i][j] -= A[k][j]*factor;
                }
                A[i][k] = 0;
            }
        }
    }

    for(i=1;i<=number_of_nodes;i++)
    {
        printf("Voltage at node %d: %lf\n",i,A[i][number_of_nodes+1]/A[i][i]);
    }
}

int main()
{
    int i, temp;
    char type = 'R', name[5];

    printf("Enter the number of nodes in the circuit: ");
    scanf("%d",&number_of_nodes);

    while(1)    //Getting components
    {
        printf("Enter component type (R, L, C, V, I) or press Q to quit: ");
        scanf(" %c",&type);

        if(type=='Q')
        {
            break;
        }

        printf("Enter component name (up to 3 characters): ");
        scanf("%s",name);

        printf("Enter first node: ");
        scanf("%d",&comp[number_of_comp+1].node[0]);

        printf("Enter second node: ");
        scanf("%d",&comp[number_of_comp+1].node[1]);

        if(comp[number_of_comp+1].node[0]==0 && comp[number_of_comp+1].node[1]==0)   //Checking for ground
        {
            printf("At least one node must be connected to ground. Try again!\n\n");
            continue;
        }

        comp[number_of_comp+1].name[0] = type;
        comp[number_of_comp+1].name[1] = '\0';

        if(type=='V' || type=='I')
        {
            printf("Enter value: ");
            scanf("%lf",&comp[number_of_comp+1].value);
        }

        else
        {
            printf("Enter value (maximum 5 characters): ");
            scanf("%lf",&comp[number_of_comp+1].value);
        }

        number_of_comp++;
    }

    construct_matrix();
    solve_matrix();

    return 0;
}