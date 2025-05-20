//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 8
#define INF 100000

int n, m;
int graph[MAX_N][MAX_N];
int colors[MAX_N];

void read_graph() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
}

void print_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

void read_colors() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &colors[i]);
}

void print_colors() {
    for (int i = 0; i < n; i++)
        printf("%d ", colors[i]);
    printf("\n");
}

void minimum_coloring() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                colors[count] = i + 1;
                count++;
            }
        }
    }
}

void print_solution() {
    printf("Minimum coloring:\n");
    print_colors();
}

int main() {
    read_graph();
    print_graph();
    read_colors();
    minimum_coloring();
    print_solution();
    return 0;
}