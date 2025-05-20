//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTEX 100
#define MAX_COLOR 7

int graph[MAX_VERTEX][MAX_VERTEX];
int color[MAX_VERTEX];
int n;

void init_graph() {
    srand(time(NULL));
    for (int i = 0; i < MAX_VERTEX; i++) {
        for (int j = 0; j < MAX_VERTEX; j++) {
            graph[i][j] = rand() % 2;
        }
    }
}

void print_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                printf(" %d ", j + 1);
            }
        }
        printf("\n");
    }
}

int is_valid(int v, int c) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

void color_graph(int v, int c) {
    color[v] = c;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1) {
            color[i] = (c + 1) % MAX_COLOR;
        }
    }
}

int main() {
    int sum = 0;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    init_graph();
    print_graph();
    sum += n;
    int max_color = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < MAX_COLOR; j++) {
            if (is_valid(i, j)) {
                color_graph(i, j);
                sum += j;
                if (j > max_color) {
                    max_color = j;
                }
                break;
            }
        }
    }
    printf("The minimum number of colors needed is: %d\n", max_color);
    return 0;
}