//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 1000
#define MAX_COLORS 10

int color[MAX_NODES];
int colors[MAX_COLORS];

void initializeColors(void) {
    int i;
    for (i = 0; i < MAX_COLORS; i++) {
        colors[i] = 0;
    }
}

int colorGraph(int n, int m) {
    int i, j, k, cnt, max_colors = MAX_COLORS - 1;
    initializeColors();
    for (i = 0; i < n; i++) {
        color[i] = -1;
    }
    for (i = 0; i < m; i++) {
        j = 0;
        for (k = 0; k < MAX_COLORS; k++) {
            if (colors[k] > 0) {
                colors[k]--;
                cnt = 0;
                while (color[j]!= -1 && color[j]!= k) {
                    j++;
                    cnt++;
                }
                if (j == n && cnt == n) {
                    printf("Graph coloring is not possible\n");
                    return 0;
                }
                if (j == n) {
                    color[j] = k;
                    i--;
                    break;
                }
            }
        }
    }
    printf("Graph coloring is possible\n");
    return 1;
}

int main(void) {
    int n, m;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    colorGraph(n, m);
    return 0;
}