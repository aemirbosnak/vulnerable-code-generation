//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int val;
    struct node *next;
} Node;

int main(void) {
    int n, i, j, color[10000], colors[10000];
    Node *head;
    char graph[10000][10000];

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s", graph[i]);
    }

    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == '1') {
                Node *temp = (Node *)malloc(sizeof(Node));
                temp->val = j;
                temp->next = head->next;
                head->next = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == '1') {
                if (colors[j]!= 1) {
                    colors[j] = 1;
                    color[j] = 1;
                    for (int k = 0; k < n; k++) {
                        if (graph[i][k] == '1' && colors[k] == 0) {
                            colors[k] = color[j];
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (colors[i] == 0) {
            printf("Graph is not colorable.\n");
            return 0;
        }
    }

    printf("Graph is colorable.\n");
    return 0;
}