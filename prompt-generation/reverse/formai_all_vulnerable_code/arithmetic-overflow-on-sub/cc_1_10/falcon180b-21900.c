//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: invasive
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>

#define MAX_V 1000
#define MAX_E 5000
#define INF INT_MAX

typedef struct{
    int v;
    int w;
    int next;
}Edge;

Edge graph[MAX_E];
int dist[MAX_V];
int parent[MAX_V];
int n,m;

void dijkstra(int s);
void print_path(int v);

int main(){

    int i,j,u,v,w;
    FILE *fp;
    char filename[20];

    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    printf("Enter the number of edges: ");
    scanf("%d",&m);

    printf("Enter the name of the input file: ");
    scanf("%s",filename);

    fp = fopen(filename,"r");

    if(fp == NULL){
        printf("Error opening file\n");
        exit(0);
    }

    for(i=0;i<m;i++){
        fscanf(fp,"%d %d %d",&u,&v,&w);
        graph[i].v = v;
        graph[i].w = w;
        graph[i].next = -1;
    }

    fclose(fp);

    dijkstra(0);

    return 0;
}

void dijkstra(int s){

    int i,u,v;
    int min_dist = INF;
    int min_index;

    dist[s] = 0;

    for(i=0;i<n-1;i++){
        min_dist = INF;
        min_index = -1;

        for(u=0;u<n;u++){
            if(dist[u] < min_dist && dist[u]!= INF){
                min_dist = dist[u];
                min_index = u;
            }
        }

        if(min_index == -1)
            break;

        for(v=0;v<n;v++){
            if(graph[min_index].next!= -1 && graph[min_index].v == v){
                if(dist[min_index] + graph[min_index].w < dist[v]){
                    dist[v] = dist[min_index] + graph[min_index].w;
                    parent[v] = min_index;
                }
            }
        }
    }

    print_path(n-1);
}

void print_path(int v){

    if(parent[v] == -1)
        return;

    print_path(parent[v]);

    printf("%d ",v);
}