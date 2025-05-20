//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: medieval
/*
 * This is a unique C Graph Coloring Problem example program in a medieval style.
 * It involves finding the minimum number of colors required to color the graph
 * such that no two adjacent nodes have the same color.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int vertex;
    int color;
} Node;

int minColor(Node* nodes, int n) {
    int colors[n];
    int used[n];
    int i, j, min_color = 0;

    for (i = 0; i < n; i++) {
        colors[i] = i + 1;
        used[i] = false;
    }

    while (true) {
        min_color++;
        for (i = 0; i < n; i++) {
            if (!used[i]) {
                for (j = 0; j < n; j++) {
                    if (nodes[i].vertex!= nodes[j].vertex &&!used[j] && (nodes[i].color!= colors[j] || min_color > colors[j])) {
                        colors[j] = min_color;
                        used[j] = true;
                    }
                }
            }
        }

        if (min_color == n) {
            break;
        }
    }

    return min_color;
}

int main() {
    int n;
    scanf("%d", &n);

    Node nodes[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &nodes[i].vertex, &nodes[i].color);
    }

    printf("%d\n", minColor(nodes, n));

    return 0;
}