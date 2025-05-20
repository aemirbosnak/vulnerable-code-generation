//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define MAX 1000

int graph[MAX][MAX];
int color[MAX];
int n;

void readGraph(){
    int i,j;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
}

int checkColor(int c){
    int i;
    for(i=0;i<n;i++){
        if(color[i]==c){
            return 0;
        }
    }
    return 1;
}

void colorGraph(){
    int i,j,k;
    for(i=0;i<n;i++){
        color[i]=1;
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(graph[i][j]==1){
                for(k=1;k<=n;k++){
                    if(checkColor(k)){
                        color[i] = k;
                        color[j] = k;
                        break;
                    }
                }
            }
        }
    }
    printf("\nThe colored graph is:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<n;i++){
        printf("%d ",color[i]);
    }
}

int main(){
    srand(time(0));
    readGraph();
    colorGraph();
    return 0;
}