//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10
#define INF 999999

int graph[ROW][COL] = {
    {0, 2, 5, 4, INF, INF, INF, INF, INF, INF},
    {2, 0, 1, INF, 1, INF, INF, INF, INF, INF},
    {5, 1, 0, INF, 3, 2, INF, INF, INF, INF},
    {4, INF, INF, 0, INF, INF, 4, INF, INF, INF},
    {INF, 1, 3, INF, 0, INF, INF, 6, 1, INF},
    {INF, INF, 2, INF, INF, 0, 4, 1, INF, INF},
    {INF, INF, INF, 4, INF, 4, 0, INF, INF, 7},
    {INF, INF, INF, INF, 6, 1, INF, 0, 1, 5},
    {INF, INF, INF, INF, 1, INF, INF, 1, 0, 3},
    {INF, INF, INF, INF, INF, INF, 7, 5, 3, 0}
};

int heuristic[ROW] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

struct node {
    int x, y, f, g, h, parent_x, parent_y;
};

typedef struct node node_t;

int manhattan_distance(int x1, int y1, int x2, int y2) {
    return (abs(x1 - x2) + abs(y1 - y2));
}

node_t* create_node(int x, int y, int f, int g, int h, int parent_x, int parent_y) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->x = x;
    new_node->y = y;
    new_node->f = f;
    new_node->g = g;
    new_node->h = h;
    new_node->parent_x = parent_x;
    new_node->parent_y = parent_y;
    return new_node;
}

int is_valid(int x, int y) {
    if (x < 0 || y < 0 || x >= ROW || y >= COL) {
        return 0;
    }
    return 1;
}

int is_unblocked(int x, int y) {
    if (graph[x][y] == INF) {
        return 0;
    }
    return 1;
}

int is_destination(int x, int y, int dest_x, int dest_y) {
    if (x == dest_x && y == dest_y) {
        return 1;
    }
    return 0;
}

void print_path(node_t** path, int path_len) {
    for (int i=path_len-1; i>=0; i--) {
        printf("(%d,%d)", path[i]->x, path[i]->y);
        if (i != 0) {
            printf(" -> ");
        }
    }
    printf("\n");
}

void a_star_search(int src_x, int src_y, int dest_x, int dest_y) {
    int open_list[ROW*COL], close_list[ROW][COL];
    int f_vals[ROW][COL], g_vals[ROW][COL], h_vals[ROW][COL];
    node_t* parent_list[ROW][COL];
    int open_list_size = 0, found_dest = 0;
    open_list[open_list_size++] = src_x * COL + src_y;

    for (int i=0; i<ROW; i++) {
        for (int j=0; j<COL; j++) {
            f_vals[i][j] = INF;
            g_vals[i][j] = INF;
            h_vals[i][j] = INF;
            parent_list[i][j] = NULL;
            close_list[i][j] = 0;
        }
    }
    f_vals[src_x][src_y] = g_vals[src_x][src_y] = h_vals[src_x][src_y] = 0;

    while (open_list_size != 0) {
        int curr = open_list[0];
        int curr_x = curr / COL;
        int curr_y = curr % COL;
        open_list[0] = open_list[open_list_size-1];
        open_list_size--;

        if (is_destination(curr_x, curr_y, dest_x, dest_y)) {
            found_dest = 1;
            break;
        }

        close_list[curr_x][curr_y] = 1;

        for (int i=-1; i<=1; i++) {
            for (int j=-1; j<=1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int succ_x = curr_x + i;
                int succ_y = curr_y + j;
                if (is_valid(succ_x, succ_y) == 1 && is_unblocked(succ_x, succ_y) == 1 && close_list[succ_x][succ_y] == 0) {
                    int g = g_vals[curr_x][curr_y] + graph[succ_x][succ_y];
                    int h = heuristic[succ_x] + heuristic[succ_y];
                    int f = g + h;

                    if (f < f_vals[succ_x][succ_y]) {
                        node_t* succ = create_node(succ_x, succ_y, f, g, h, curr_x, curr_y);
                        if (parent_list[succ_x][succ_y] != NULL) {
                            free(parent_list[succ_x][succ_y]);
                        }
                        parent_list[succ_x][succ_y] = succ;

                        f_vals[succ_x][succ_y] = f;
                        g_vals[succ_x][succ_y] = g;
                        h_vals[succ_x][succ_y] = h;

                        open_list[open_list_size++] = succ_x * COL + succ_y;
                    }
                }
            }
        }

        for (int i=0; i<open_list_size-1; i++) {
            for (int j=0; j<open_list_size-1-i; j++) {
                int curr_f = f_vals[open_list[j]/COL][open_list[j]%COL];
                int next_f = f_vals[open_list[j+1]/COL][open_list[j+1]%COL];
                if (curr_f > next_f) {
                    int temp = open_list[j];
                    open_list[j] = open_list[j+1];
                    open_list[j+1] = temp;
                }
            }
        }
    }

    if (found_dest == 0) {
        printf("No path exists.\n");
        return;
    }

    node_t** path = (node_t**)malloc(sizeof(node_t*) * ROW * COL);
    int path_len = 0;
    int curr_x = dest_x;
    int curr_y = dest_y;
    while (parent_list[curr_x][curr_y] != NULL) {
        path[path_len++] = parent_list[curr_x][curr_y];
        curr_x = path[path_len-1]->parent_x;
        curr_y = path[path_len-1]->parent_y;
    }

    printf("Path found: ");
    print_path(path, path_len);

    for (int i=0; i<path_len; i++) {
        free(path[i]);
    }
    free(path);
}

int main() {
    printf("A* Pathfinding Algorithm:\n");
    printf("Enter start and destination coordinates (x y): ");
    int src_x, src_y, dest_x, dest_y;
    scanf("%d %d %d %d", &src_x, &src_y, &dest_x, &dest_y);
    printf("Finding path from (%d,%d) to (%d,%d)...\n\n", src_x, src_y, dest_x, dest_y);
    a_star_search(src_x, src_y, dest_x, dest_y);
    return 0;
}