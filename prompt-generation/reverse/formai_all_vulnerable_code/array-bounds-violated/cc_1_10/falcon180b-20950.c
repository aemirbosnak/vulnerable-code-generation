//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

int graph[MAX][MAX];
int n;

void init_graph(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            graph[i][j] = rand()%2; // 0 or 1
        }
    }
}

void print_graph(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int n, int c, int a, int b) {
    for(int i=0; i<n; i++) {
        if(graph[a][i] == c || graph[b][i] == c || graph[i][a] == c || graph[i][b] == c) {
            return 0;
        }
    }
    return 1;
}

void color_graph(int n, int a, int b, int c) {
    graph[a][b] = c;
    graph[b][a] = c;
}

int main() {
    srand(time(NULL));
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    init_graph(n);
    print_graph(n);

    int a, b, c;
    printf("Enter two vertices to color: ");
    scanf("%d %d", &a, &b);

    c = rand()%3; // 0 or 1 or 2
    if(is_valid(n, c, a, b)) {
        color_graph(n, a, b, c);
        printf("Colored (%d, %d) with %d\n", a, b, c);
    } else {
        printf("Cannot color (%d, %d) with %d\n", a, b, c);
    }

    return 0;
}