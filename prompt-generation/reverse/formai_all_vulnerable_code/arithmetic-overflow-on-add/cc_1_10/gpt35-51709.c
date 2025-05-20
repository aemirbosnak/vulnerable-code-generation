//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 8

int map[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
};

int h_values[ROWS][COLS] = {
    {10, 9, 8, 7, 6, 5, 4, 3},
    {9, 8, 7, 6, 5, 4, 3, 2},
    {8, 7, 6, 5, 4, 3, 2, 1},
    {7, 6, 5, 4, 3, 2, 1, 0},
    {6, 5, 4, 3, 2, 1, 0, 1},
    {5, 4, 3, 2, 1, 0, 1, 2}
};

typedef struct {
    int x, y;
} point;

point start = {1, 1};
point end = {ROWS - 2, COLS - 2};

typedef struct node {
    point pos;
    int g, h;
    struct node *parent;
} node;

node* create_node(point pos, int g, int h, node *parent) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->pos = pos;
    new_node->g = g;
    new_node->h = h;
    new_node->parent = parent;
    return new_node;
}

int calculate_g(node *current, node *successor) {
    if (abs(current->pos.x - successor->pos.x) == 1 || abs(current->pos.y - successor->pos.y) == 1) {
        return current->g + 10;
    } else {
        return current->g + 14;
    }
}

int find_node_in_list(node *search_node, node **list, int list_length) {
    for (int i = 0; i < list_length; i++) {
        if (list[i]->pos.x == search_node->pos.x && list[i]->pos.y == search_node->pos.y) {
            return i;
        }
    }
    return -1;
}

node** insert_node_into_list(node **list, int *list_length, node *new_node) {
    *list_length += 1;
    list = (node**)realloc(list, *list_length * sizeof(node*));
    list[*list_length - 1] = new_node;
    return list;
}

node* lowest_fscore_node(node **open_list, int open_list_length) {
    int lowest_fscore = -1;
    node *lowest_node = NULL;
    for (int i = 0; i < open_list_length; i++) {
        if (lowest_fscore == -1 || open_list[i]->g + open_list[i]->h < lowest_fscore) {
            lowest_fscore = open_list[i]->g + open_list[i]->h;
            lowest_node = open_list[i];
        }
    }
    return lowest_node;
}

point* calculate_path(node *end_node, int *path_length) {
    node *current_node = end_node;
    *path_length = 0;
    while (current_node != NULL) {
        (*path_length) += 1;
        current_node = current_node->parent;
    }
    point *path = (point*)malloc(*path_length * sizeof(point));
    current_node = end_node;
    for (int i = *path_length - 1; i >= 0; i--) {
        path[i] = current_node->pos;
        current_node = current_node->parent;
    }
    return path;
}

point* astar() {
    int open_list_length = 0;
    node ** open_list = (node**)malloc(sizeof(node*));
    int closed_list_length = 0;
    node ** closed_list = (node**)malloc(sizeof(node*));

    node *start_node = create_node(start, 0, h_values[start.x][start.y], NULL);
    open_list = insert_node_into_list(open_list, &open_list_length, start_node);

    while (open_list_length > 0) {
        node *current_node = lowest_fscore_node(open_list, open_list_length);
        if (current_node->pos.x == end.x && current_node->pos.y == end.y) {
            int path_length;
            point *path = calculate_path(current_node, &path_length);
            return path;
        }
        open_list_length -= 1;
        open_list[find_node_in_list(current_node, open_list, open_list_length)] = open_list[open_list_length];
        closed_list = insert_node_into_list(closed_list, &closed_list_length, current_node);
        point successors[8] = {{current_node->pos.x - 1, current_node->pos.y - 1},
                                {current_node->pos.x - 1, current_node->pos.y},
                                {current_node->pos.x - 1, current_node->pos.y + 1},
                                {current_node->pos.x, current_node->pos.y - 1},
                                {current_node->pos.x, current_node->pos.y + 1},
                                {current_node->pos.x + 1, current_node->pos.y - 1},
                                {current_node->pos.x + 1, current_node->pos.y},
                                {current_node->pos.x + 1, current_node->pos.y + 1}};
        for (int i = 0; i < 8; i++) {
            if (successors[i].x >= 0 && successors[i].x < ROWS && successors[i].y >= 0 && successors[i].y < COLS) {
                if (map[successors[i].x][successors[i].y] == 1) {
                    node *successor = create_node(successors[i], 0, h_values[successors[i].x][successors[i].y], NULL);
                    int g_score = calculate_g(current_node, successor);
                    node *existing_node = NULL;
                    int existing_node_index = find_node_in_list(successor, open_list, open_list_length);
                    if (existing_node_index != -1) {
                        existing_node = open_list[existing_node_index];
                    } else {
                        existing_node_index = find_node_in_list(successor, closed_list, closed_list_length);
                        if (existing_node_index != -1) {
                            existing_node = closed_list[existing_node_index];
                        }
                    }
                    if (existing_node == NULL || g_score < existing_node->g) {
                        successor->g = g_score;
                        successor->parent = current_node;
                        if (existing_node_index != -1) {
                            open_list[existing_node_index] = successor;
                        } else {
                            open_list = insert_node_into_list(open_list, &open_list_length, successor);
                        }
                    }
                }
            }
        }
    }
    return NULL;
}

int main() {
    point *path = astar();
    printf("Path:");
    for (int i = 0; i < ROWS * COLS; i++) {
        if (i % COLS == 0) {
            printf("\n");
        }
        if (path != NULL) {
            bool is_on_path = false;
            for (int j = 0; j < sizeof(path) / sizeof(point); j++) {
                if (i == path[j].x * COLS + path[j].y) {
                    is_on_path = true;
                }
            }
            if (is_on_path) {
                printf("* ");
            } else {
                printf("%d ", map[i / COLS][i % COLS]);
            }
        } else {
            printf("%d ", map[i / COLS][i % COLS]);
        }
    }
    printf("\n\n");
    return 0;
}