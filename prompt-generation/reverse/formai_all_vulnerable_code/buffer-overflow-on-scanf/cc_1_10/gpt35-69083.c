//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multivariable
#include<stdio.h>

int graph[10][10], colors[10], N, M;

void welcomemsg(){
    printf("Welcome to Graph Coloring Program!\n");
    printf("Enter number of vertices: ");
    scanf("%d",&N);

    printf("Enter number of edges: ");
    scanf("%d",&M);

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            graph[i][j] = 0;

    printf("Enter the edges:\n");

    int x,y;
    for(int i=0;i<M;i++){
        scanf("%d %d",&x,&y);
        graph[x-1][y-1] = 1;
        graph[y-1][x-1] = 1;
    }
}

int isSafe(int vertex, int color){
    for(int i=0;i<N;i++)
        if(graph[vertex][i] && color == colors[i])
            return 0;
    return 1;
}

void printSolution(){
    printf("The assigned colors of the graph are:\n");
    for(int i=0;i<N;i++){
        printf("Vertex %d: Color %d\n",i+1,colors[i]);
    }
}

int graphColoring(int vertex){
    if(vertex == N)
        return 1;

    for(int color=1;color<=N;color++){
        if(isSafe(vertex,color)){
            colors[vertex] = color;

            if(graphColoring(vertex+1) == 1)
                return 1;
        }

        colors[vertex] = 0;
    }

    return 0;
}

int main(){
    welcomemsg();

    if(graphColoring(0) == 0){
        printf("Solution does not exist");
        return 0;
    }

    printSolution();
    return 0;
}