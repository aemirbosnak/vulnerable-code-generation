//FormAI DATASET v1.0 Category: Graph representation ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int graph[MAX][MAX],n,e;

void createGraph();
void display();
void searchGraph();
void deleteEdge();

int main(){
    int choice;
    while(1){
        printf("1. Create Graph\n");
        printf("2. Display Graph\n");
        printf("3. Search Graph\n");
        printf("4. Delete Edge\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: createGraph();
                    break;
            case 2: display();
                    break;
            case 3: searchGraph();
                    break;
            case 4: deleteEdge();
                    break;
            case 5: exit(0);
        }
    }
}

void createGraph(){
    int i,origin,dest;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter the edge %d (-1 -1 to quit): ",i);
        scanf("%d %d",&origin,&dest);
        if(origin==-1 && dest==-1)
            break;
        if(origin<0 || dest<0 || origin>=n || dest>=n){
            printf("Invalid vertex!\n");
            i--;
        }
        else{
            graph[origin][dest] = 1;
            graph[dest][origin] = 1;
        }
    }
    e = i-1;
}

void display(){
    int i,j;
    printf("\nThe graph is:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void searchGraph(){
    int i,j,flag=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(graph[i][j] == 1 && i<j){
                printf("%d-%d, ",i,j);
                flag=1;
            }
        }
    }
    if(flag==0)
        printf("No edges found!");
    printf("\n");
}

void deleteEdge(){
    int origin,dest,i,j;
    printf("Enter edge to be deleted: ");
    scanf("%d %d",&origin,&dest);
    if(origin<0 || dest<0 || origin>=n || dest>=n || graph[origin][dest]==0){
        printf("Invalid edge!\n");
    }
    else{
        graph[origin][dest] = 0;
        graph[dest][origin] = 0;
        printf("Edge deleted!\n");
    }
}