//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define MAX_EDGES 2000

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct edge {
    int src;
    int dest;
} edge;

int main() {
    int n, m;
    node* head = NULL;
    edge* edges = NULL;

    scanf("%d %d", &n, &m);

    head = (node*)malloc(sizeof(node));
    head->next = NULL;

    edges = (edge*)malloc(m * sizeof(edge));

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &edges[i].src, &edges[i].dest);
    }

    for (int i = 0; i < n; i++) {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->next = NULL;
        head->next = new_node;
        head = head->next;
    }

    for (int i = 0; i < m; i++) {
        node* src_node = NULL;
        node* dest_node = NULL;

        for (node* cur_node = head; cur_node!= NULL; cur_node = cur_node->next) {
            if (cur_node->data == edges[i].src) {
                src_node = cur_node;
                break;
            }
        }

        for (node* cur_node = head; cur_node!= NULL; cur_node = cur_node->next) {
            if (cur_node->data == edges[i].dest) {
                dest_node = cur_node;
                break;
            }
        }

        if (src_node!= NULL && dest_node!= NULL) {
            src_node->next = dest_node;
            dest_node->next = src_node->next;
        }
    }

    for (node* cur_node = head; cur_node!= NULL; cur_node = cur_node->next) {
        printf("%d ", cur_node->data);
    }

    free(head);
    free(edges);

    return 0;
}