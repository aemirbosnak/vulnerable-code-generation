//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 7
#define INF 1000000

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int n;

void init(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = rand() % (MAX_COLORS - 1) + 1;
        }
    }
}

void print_solution(int n, int color[]) {
    printf("Vertex   Color\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", i, color[i]);
    }
}

int is_valid(int v, int c, int color[], int parent) {
    if (color[v]!= 0 && color[v]!= c && color[v]!= parent)
        return 0;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == c || graph[v][i] == parent)
            return 0;
    }
    return 1;
}

void color_graph(int n) {
    int i, j, k, u, v, c, parent;
    for (i = 0; i < n; i++) {
        color[i] = 0;
        for (j = 1; j <= MAX_COLORS; j++) {
            if (is_valid(i, j, color, 0)) {
                color[i] = j;
                break;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == color[i])
                continue;
            for (k = 1; k <= MAX_COLORS; k++) {
                if (is_valid(j, k, color, i)) {
                    color[j] = k;
                    parent = i;
                    break;
                }
            }
        }
    }
}

int main(void) {
    srand(time(NULL));
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_VERTICES) {
        printf("Invalid number of vertices.\n");
        return 0;
    }

    init(n);

    color_graph(n);

    print_solution(n, color);

    return 0;
}