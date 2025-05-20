//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate graph edges randomly
void randomGraph(int graph[][10], int n)
{
    int i,j;
    srand(time(0));
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            graph[j][i]=graph[i][j]=rand()%2;
        }
    }
}

//Function to print the generated graph
void printGraph(int graph[][10], int n)
{
    printf("\nThe Adjacency Matrix is:\n");
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

//Function to color the graph using backtracking algorithm
int graphColoring(int graph[][10], int n, int m, int colors[])
{
    //If all vertices are colored
    if(n==0)
        return 1;

    int i,j;
    for(i=1;i<=m;i++)
    {
        //Check if the color i can be assigned to vertex n
        int flag=1;
        for(j=0;j<n;j++)
        {
            if(graph[n][j] && colors[j]==i)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            colors[n]=i;
            if(graphColoring(graph,n-1,m,colors))
                return 1;
            colors[n]=0;
        }
    }
    return 0;
}

//Main Function
int main()
{
    int graph[10][10],colors[10];
    int n,m,i,j;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the number of colors: ");
    scanf("%d",&m);

    //Initialize all colors as 0
    for(i=0;i<n;i++)
        colors[i]=0;

    //Generate a random graph
    randomGraph(graph,n);

    //Print the generated graph
    printGraph(graph,n);

    //Color the graph
    if(graphColoring(graph,n,m,colors))
    {
        printf("\nGraph can be colored using %d colors\n",m);
        printf("The color assigned to each vertex is:\n");
        for(i=0;i<n;i++)
        {
            printf("Vertex %d: Color %d\n",i+1,colors[i]);
        }
    }
    else
        printf("\nGraph can not be colored using %d colors\n",m);

    return 0;
}