//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_X 100
#define MAX_Y 100

typedef struct {
    int x, y;
    float g, h, f;
    struct node *parent;
} node;

node *open_list, *closed_list;
node *start, *end;
int map[MAX_X][MAX_Y];

float heuristic(node *a, node *b) {
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

float g_score(node *a, node *b) {
    return a->g + 1;
}

float f_score(node *a) {
    return a->g + a->h;
}

node *pop_open_list() {
    node *n = open_list;
    open_list = open_list->parent;
    return n;
}

void push_open_list(node *n) {
    n->parent = open_list;
    open_list = n;
}

void push_closed_list(node *n) {
    n->parent = closed_list;
    closed_list = n;
}

int is_in_closed_list(node *n) {
    for (node *i = closed_list; i != NULL; i = i->parent) {
        if (i->x == n->x && i->y == n->y) {
            return 1;
        }
    }
    return 0;
}

int is_in_open_list(node *n) {
    for (node *i = open_list; i != NULL; i = i->parent) {
        if (i->x == n->x && i->y == n->y) {
            return 1;
        }
    }
    return 0;
}

node *get_lowest_f_score() {
    node *n = open_list;
    node *lowest = open_list;
    for (; n != NULL; n = n->parent) {
        if (n->f < lowest->f) {
            lowest = n;
        }
    }
    return lowest;
}

node *get_neighbor(node *n, int x, int y) {
    if (x < 0 || x >= MAX_X || y < 0 || y >= MAX_Y || map[x][y] == -1) {
        return NULL;
    }
    node *neighbor = (node *)malloc(sizeof(node));
    neighbor->x = x;
    neighbor->y = y;
    neighbor->g = g_score(n, neighbor);
    neighbor->h = heuristic(neighbor, end);
    neighbor->f = f_score(neighbor);
    return neighbor;
}

node *a_star() {
    push_open_list(start);
    while (open_list != NULL) {
        node *current = pop_open_list();
        push_closed_list(current);
        if (current->x == end->x && current->y == end->y) {
            return current;
        }
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                if (x == 0 && y == 0) {
                    continue;
                }
                node *neighbor = get_neighbor(current, current->x + x, current->y + y);
                if (neighbor == NULL || is_in_closed_list(neighbor)) {
                    continue;
                }
                if (!is_in_open_list(neighbor) || g_score(current, neighbor) < neighbor->g) {
                    neighbor->parent = current;
                    if (!is_in_open_list(neighbor)) {
                        push_open_list(neighbor);
                    }
                }
            }
        }
    }
    return NULL;
}

int main() {
    FILE *f = fopen("map.txt", "r");
    if (f == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }
    for (int y = 0; y < MAX_Y; y++) {
        for (int x = 0; x < MAX_X; x++) {
            fscanf(f, "%d ", &map[x][y]);
        }
    }
    fclose(f);
    start = (node *)malloc(sizeof(node));
    start->x = 0;
    start->y = 0;
    start->g = 0;
    start->h = heuristic(start, end);
    start->f = f_score(start);
    end = (node *)malloc(sizeof(node));
    end->x = MAX_X - 1;
    end->y = MAX_Y - 1;
    node *path = a_star();
    if (path == NULL) {
        printf("No path found.\n");
        return 1;
    }
    while (path != NULL) {
        printf("(%d, %d)\n", path->x, path->y);
        path = path->parent;
    }
    return 0;
}