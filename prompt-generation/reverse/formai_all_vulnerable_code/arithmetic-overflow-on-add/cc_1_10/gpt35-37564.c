//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Define the map size
#define ROW 5
#define COL 5

// Define the heuristic function
int heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x2 - x1) + abs(y2 - y1);
}

// Define a struct for each individual node
typedef struct node {
    int x, y;
    int f, g, h;
    struct node* parent;
} node;

// Define a priority queue based on the f value of each node
typedef struct priority_queue {
    int size;
    node** nodes;
} priority_queue;

priority_queue* create_priority_queue(int max_size)
{
    priority_queue* pq = malloc(sizeof(priority_queue));
    pq->size = 0;
    pq->nodes = malloc(sizeof(node*) * max_size);
    return pq;
}

void enqueue(priority_queue* pq, node* n)
{
    int i = pq->size++;
    while (i > 0 && pq->nodes[(i-1)/2]->f > n->f) {
        pq->nodes[i] = pq->nodes[(i-1)/2];
        i = (i-1)/2;
    }
    pq->nodes[i] = n;
}

node* dequeue(priority_queue* pq)
{
    node* result = pq->nodes[0];
    pq->size--;
    node* last_node = pq->nodes[pq->size];
    int i = 0;
    while (i*2+1 < pq->size) {
        int child1 = i*2+1;
        int child2 = i*2+2;
        int smaller_child = child1;
        if (child2 < pq->size && pq->nodes[child2]->f < pq->nodes[child1]->f) {
            smaller_child = child2;
        }
        if (pq->nodes[smaller_child]->f >= last_node->f) {
            break;
        }
        pq->nodes[i] = pq->nodes[smaller_child];
        i = smaller_child;
    }
    pq->nodes[i] = last_node;
    return result;
}

bool is_valid(int x, int y)
{
    return (x >= 0 && x < ROW && y >=0 && y < COL);
}

bool is_unblocked(int grid[][COL], int x, int y)
{
    return (grid[x][y] == 0);
}

bool is_destination(int x, int y, node* dest)
{
    return (x == dest->x && y == dest->y);
}

void print_path(node* dest)
{
    if (dest == NULL) {
        return;
    }
    print_path(dest->parent);
    printf("(%d, %d)\n", dest->x, dest->y);
}

void a_star_search(int grid[][COL], node* start, node* dest)
{
    int row[] = {-1, 0, 0, 1};
    int col[] = {0, -1, 1, 0};

    bool closed_list[ROW][COL];
    memset(closed_list, false, ROW * sizeof(bool));
    closed_list[start->x][start->y] = true;

    priority_queue* open_list = create_priority_queue(ROW*COL);
    enqueue(open_list, start);

    while (open_list->size > 0)
    {
        node* curr = dequeue(open_list);

        if (is_destination(curr->x, curr->y, dest)) {
            print_path(dest);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int succ_x = curr->x + row[i];
            int succ_y = curr->y + col[i];
            if (is_valid(succ_x, succ_y) && is_unblocked(grid, succ_x, succ_y) && !closed_list[succ_x][succ_y]) {
                int succ_g = curr->g + 1;
                int succ_h = heuristic(succ_x, succ_y, dest->x, dest->y);
                int succ_f = succ_g + succ_h;

                node* succ = malloc(sizeof(node));
                succ->x = succ_x;
                succ->y = succ_y;
                succ->f = succ_f;
                succ->g = succ_g;
                succ->h = succ_h;
                succ->parent = curr;

                closed_list[succ_x][succ_y] = true;
                enqueue(open_list, succ);
            }
        }
    }

    printf("No valid path found.\n");
}

int main()
{
    int grid[ROW][COL] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0}
    };

    node* start = malloc(sizeof(node));
    start->x = 0;
    start->y = 0;
    start->f = 0;
    start->g = 0;
    start->h = 0;
    start->parent = NULL;

    node* dest = malloc(sizeof(node));
    dest->x = 4;
    dest->y = 4;
    dest->f = 0;
    dest->g = 0;
    dest->h = 0;
    dest->parent = NULL;

    a_star_search(grid, start, dest);

    return 0;
}