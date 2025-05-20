//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS+1] = {
    "##########",
    "#    #   #",
    "# ## # # #",
    "# #  # # #",
    "# #  #   #",
    "# ## #####",
    "#        #",
    "######## #",
    "#        #",
    "##########"
};

struct point {
    int x;
    int y;
};

struct stack {
    struct point data[500];
    int top;
};

void push(struct stack *s, struct point p) {
    s->data[s->top++] = p;
}

struct point pop(struct stack *s) {
    return s->data[--s->top];
}

int is_empty(struct stack *s) {
    return s->top == 0;
}

int is_exit(struct point p) {
    return p.x == 0 || p.x == ROWS-1 || p.y == 0 || p.y == COLS-1;
}

int is_visited(struct point p) {
    return maze[p.x][p.y] == 'X';
}

void mark_visited(struct point p) {
    maze[p.x][p.y] = 'X';
}

int is_clear_path(struct point p) {
    return maze[p.x][p.y] == ' ' || is_exit(p);
}

struct point* get_neighbor(struct point p) {
    static struct point nbr[6];
    nbr[0].x = p.x-2, nbr[0].y = p.y;
    nbr[1].x = p.x, nbr[1].y = p.y+2;
    nbr[2].x = p.x+2, nbr[2].y = p.y;
    nbr[3].x = p.x, nbr[3].y = p.y-2;
    nbr[4].x = p.x-1, nbr[4].y = p.y-1;
    nbr[5].x = p.x+1, nbr[5].y = p.y+1;
    return nbr;
}

int main() {
    srand(time(0));
    struct point current = {1, 1};
    struct stack path = {{{0, 0}}, 0};
    push(&path, current);
    while (!is_empty(&path)) {
        current = pop(&path);
        mark_visited(current);
        if (is_exit(current)) {
            printf("Found Exit!!");
            return 0;
        }
        struct point *neighbors = get_neighbor(current);
        int r = rand() % 6;
        for (int i = 0; i < 6; i++) {
            struct point nb = neighbors[(i+r)%6];
            if (is_clear_path(nb) && !is_visited(nb)) {
                push(&path, nb);
            }
        }
    }
    printf("No Exit Found!");
    return 0;
}