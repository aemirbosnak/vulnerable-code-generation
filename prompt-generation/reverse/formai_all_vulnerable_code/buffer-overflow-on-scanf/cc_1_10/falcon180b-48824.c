//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MAX_COLOR 7

int graph[MAX][MAX];
int color[MAX][MAX];
int count[MAX_COLOR] = {0};
int n;

void init_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = rand() % MAX_COLOR + 1;
        }
    }
}

void print_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void print_color() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", color[i][j]);
        }
        printf("\n");
    }
}

int check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == color[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

void color_graph() {
    int start_time = clock();
    int k = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (color[i][j] == 0) {
                color[i][j] = k;
                if (check() == 0) {
                    for (int l = 0; l < n; l++) {
                        for (int m = 0; m < n; m++) {
                            color[l][m] = 0;
                        }
                    }
                    k = 1;
                } else {
                    k++;
                }
            }
        }
    }
    int end_time = clock();
    printf("Time taken: %d\n", end_time - start_time);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    init_graph();
    print_graph();
    color_graph();
    printf("\nColor Matrix:\n");
    print_color();
    return 0;
}