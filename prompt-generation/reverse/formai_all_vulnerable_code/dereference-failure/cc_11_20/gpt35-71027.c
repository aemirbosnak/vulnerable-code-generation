//FormAI DATASET v1.0 Category: Graph representation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

//This is a program to draw a unique graph representation 
//It is gonna be AMAZING!

int main(){

    printf("Are you ready to see my amazing graph?! \n\n");

    int n = 7;
    int i,j;

    int** graph = (int**) malloc(n * sizeof(int*));

    for(i=0; i<n; i++){
        graph[i] = (int*) malloc(n * sizeof(int));
    }

    printf("Here is your graph: \n\n");

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i==0 || i==n-1) {
                printf("* ");
                graph[i][j] = 1;
            }
            else if(j==0 || j==n-1) {
                printf("* ");
                graph[i][j] = 1;
            }
            else if(i==j){
                printf("* ");
                graph[i][j] = 1;
            }
            else if(i==n-j-1){
                printf("* ");
                graph[i][j] = 1;
            }
            else{
                printf("  ");
                graph[i][j] = 0;
            }
        }
        printf("\n");
    }

    printf("\n\nOMG! My graph is AMAZING! \n\n");

    for(i=0; i<n; i++){
        free(graph[i]);
    }

    free(graph);

    return 0;
}