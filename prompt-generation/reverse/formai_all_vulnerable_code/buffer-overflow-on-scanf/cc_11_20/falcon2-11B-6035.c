//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct graph{
    int v;
    int **adj;
    int *color;
};

int main(){
    srand(time(0));
    int n,m,i,j,k;
    int **adj, *color;
    struct graph g;
    
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    printf("Enter the number of edges: ");
    scanf("%d",&m);
    printf("Enter the edges: ");
    for(i=0;i<m;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[i] = malloc(n*sizeof(int));
        for(j=0;j<n;j++){
            adj[i][j] = 0;
        }
        adj[i][u-1] = 1;
        adj[i][v-1] = 1;
    }
    printf("Enter the starting vertex: ");
    scanf("%d",&g.v);
    g.adj = adj;
    g.color = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        g.color[i] = rand()%2;
    }
    printf("Graph coloring: ");
    for(i=0;i<n;i++){
        printf("%d ",g.color[i]);
    }
    printf("\n");
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(g.adj[i][k] && g.adj[j][k] && g.color[i] == g.color[j]){
                    g.color[j] = (g.color[j] == 0)?1:0;
                }
            }
        }
    }
    printf("Graph coloring: ");
    for(i=0;i<n;i++){
        printf("%d ",g.color[i]);
    }
    printf("\n");
    return 0;
}