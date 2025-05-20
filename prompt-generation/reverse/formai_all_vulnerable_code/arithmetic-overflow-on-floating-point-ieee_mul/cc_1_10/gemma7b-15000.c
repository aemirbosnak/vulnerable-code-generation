//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void draw_circle(int x, int y, int r) {
    int i, j;
    for (i = x - r; i <= x + r; i++) {
        for (j = y - r; j <= y + r; j++) {
            if (sqrt(pow(i - x, 2) + pow(j - y, 2)) <= r) {
                printf(" ");
            } else {
                printf("#");
            }
        }
    }
}

void draw_line(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int d = sqrt(dx * dx + dy * dy);
    int i;
    for (i = 0; i < d; i++) {
        int x = x1 + i * dx / d;
        int y = y1 + i * dy / d;
        printf("#");
    }
}

void draw_node(Node* node) {
    draw_circle(node->data, 0, 5);
    draw_line(node->data, 0, node->next->data, 0);
}

int main() {
    Node* head = malloc(sizeof(Node));
    head->data = 10;
    head->next = malloc(sizeof(Node));
    head->next->data = 20;
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 30;

    draw_node(head);

    return 0;
}