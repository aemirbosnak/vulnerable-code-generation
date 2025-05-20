//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node_s {
    int color;
    struct Node_s *next;
    struct Node_s *prev;
} Node;

Node *graph[100];

int main() {
    int n, m, i, j, c, k;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        graph[i] = NULL;
    }
    for (i = 0; i < m; i++) {
        scanf("%d %d", &j, &c);
        Node *new = malloc(sizeof(Node));
        new->color = c;
        new->next = graph[j-1];
        new->prev = NULL;
        if (graph[j-1] != NULL) graph[j-1]->prev = new;
        graph[j-1] = new;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j && graph[i] != NULL && graph[j] != NULL) {
                for (k = 0; k < 100; k++) {
                    c = 1;
                    Node *tmp = graph[i];
                    while (tmp != NULL) {
                        if (tmp->color == k) {
                            c = 0;
                            break;
                        }
                        tmp = tmp->next;
                    }
                    tmp = graph[j];
                    while (tmp != NULL) {
                        if (tmp->color == k) {
                            c = 0;
                            break;
                        }
                        tmp = tmp->next;
                    }
                    if (c == 1) {
                        Node *new = malloc(sizeof(Node));
                        new->color = k;
                        new->next = graph[j];
                        new->prev = NULL;
                        if (graph[j] != NULL) graph[j]->prev = new;
                        graph[j] = new;
                        break;
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d", graph[i]->color);
        if (graph[i]->next != NULL) printf(" ");
    }
    printf("\n");
    return 0;
}