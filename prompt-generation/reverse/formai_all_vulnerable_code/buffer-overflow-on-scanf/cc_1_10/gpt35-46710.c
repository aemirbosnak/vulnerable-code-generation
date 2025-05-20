//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: funny
#include<stdio.h>
#include<stdlib.h>

/*
 * This program is a unique implementation of Graph Coloring Problem
 * You will be asked to enter the number of vertices in the graph
 * Based on that, you will be prompted whether you want to color the graph
 * Let's see how well you can do that!
*/

struct color{
    int red;
    int green;
    int blue;
};

void setColor(int v, int n, int **graph, struct color *colors){
    /*
     * This function sets the color for the given vertex
    */
    int flag = 0;
    for(int i=0; i<n; i++){
        if(i==v){
            continue;
        }
        if(graph[i][v]==1 && colors[i].red==colors[v].red && colors[i].green==colors[v].green && colors[i].blue==colors[v].blue){
            flag = 1;
            break;
        }
    }
    if(flag){
        printf("Uh oh! There is a conflict. Please choose another color.\n");
        printf("Enter the RGB values for vertex %d (separated by space): ", v);
        scanf("%d %d %d", &colors[v].red, &colors[v].green, &colors[v].blue);
        setColor(v, n, graph, colors);
        return;
    }
    printf("Great! Vertex %d has been assigned the following color: ", v);
    printf("(%d, %d, %d)\n", colors[v].red, colors[v].green, colors[v].blue);
}

int main(){
    printf("Welcome to the Graph Coloring Problem Program!\n");
    printf("Please enter the number of vertices in the graph: ");
    int n;
    scanf("%d", &n);

    int **graph = (int**)calloc(n, sizeof(int*));
    for(int i=0; i<n; i++){
        graph[i] = (int*)calloc(n, sizeof(int));
    }

    printf("Do you want to color the graph? (Y/N) ");
    char ch;
    scanf(" %c", &ch);

    if(ch=='N' || ch=='n'){
        printf("Okay! Bye!\n");
        return 0;
    }

    printf("Great! Let's color the graph!\n");
    printf("Enter the RGB values for vertex %d (separated by space): ", 0);
    struct color *colors = (struct color*)malloc(n*sizeof(struct color));
    for(int i=0; i<n; i++){
        scanf("%d %d %d", &colors[i].red, &colors[i].green, &colors[i].blue);
    }

    /*
     * Prompting for adjacency matrix
    */
    printf("Okay! Now let's define the adjacency matrix.\n");
    printf("Enter 1 if there is an edge between the vertices, else 0.\n");
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            printf("Is there an edge between vertex %d and vertex %d? (1/0) ", i, j);
            scanf("%d", &graph[i][j]);
            graph[j][i] = graph[i][j];
        }
    }

    /*
     * Running the actual graph coloring algorithm
    */
    for(int i=0; i<n; i++){
        setColor(i, n, graph, colors);
    }

    printf("Yay! All vertices have been assigned colors. Good job!\n");

    for(int i=0; i<n; i++){
        free(graph[i]);
    }
    free(graph);
    free(colors);

    return 0;
}