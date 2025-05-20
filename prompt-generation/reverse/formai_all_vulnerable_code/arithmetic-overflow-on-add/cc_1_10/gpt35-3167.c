//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ROW 4
#define COL 4

typedef struct Node
{
    int x, y;
    int f, g, h;
    struct Node* parent;
}Node;

typedef struct Heap
{
    Node** arr;
    int size;
    int capacity;
}Heap;

void swap(Node** a, Node** b)
{
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void initHeap(Heap** heap, int capacity)
{
    *heap = (Heap*)malloc(sizeof(Heap));
    (*heap)->arr = (Node**)malloc(sizeof(Node*) * capacity);
    (*heap)->size = 0;
    (*heap)->capacity = capacity;
}

void push(Heap* heap, Node* node)
{
    int i = heap->size;
    heap->arr[i] = node;
    heap->size += 1;
    while (i != 0)
    {
        int p = (i - 1) / 2;
        if (heap->arr[i]->f < heap->arr[p]->f)
        {
            swap(&heap->arr[i], &heap->arr[p]);
            i = p;
        }
        else
            break;
    }
}

Node* pop(Heap* heap)
{
    if (heap->size == 0)
        return NULL;
    Node* node = heap->arr[0];
    heap->size -= 1;
    heap->arr[0] = heap->arr[heap->size];
    heap->arr[heap->size] = NULL;

    int i = 0;
    while (2 * i + 1 < heap->size)
    {
        int l = 2 * i + 1;
        int r = l + 1;
        int c = r < heap->size && heap->arr[r]->f < heap->arr[l]->f ? r : l;
        if (heap->arr[c]->f < heap->arr[i]->f)
        {
            swap(&heap->arr[c], &heap->arr[i]);
            i = c;
        }
        else
            break;
    }

    return node;
}

int findPath(int sx, int sy, int tx, int ty, int(*grid)[COL])
{
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };

    Heap* open;
    initHeap(&open, ROW * COL);
    int closed[ROW][COL];
    memset(closed, 0, sizeof(int) * ROW * COL);
    Node* start = (Node*)malloc(sizeof(Node));
    start->x = sx;
    start->y = sy;
    start->g = 0;
    start->h = abs(tx - sx) + abs(ty - sy);
    start->f = start->g + start->h;
    start->parent = NULL;

    push(open, start);

    while (open->size != 0)
    {
        Node* cur = pop(open);

        if (cur->x == tx && cur->y == ty)
        {
            Node* node = cur;
            while (node)
            {
                printf("(%d,%d) ", node->x, node->y);
                node = node->parent;
            }
            printf("\n");
            return cur->f;
        }

        closed[cur->x][cur->y] = 1;

        for (int i = 0; i < 4; i++)
        {
            int nx = cur->x + dx[i];
            int ny = cur->y + dy[i];
            if (nx < 0 || nx >= ROW || ny < 0 || ny >= COL)
                continue;
            if (closed[nx][ny] == 1 || grid[nx][ny] == 1)
                continue;

            Node* child = (Node*)malloc(sizeof(Node));
            child->x = nx;
            child->y = ny;
            child->g = cur->g + 1;
            child->h = abs(tx - nx) + abs(ty - ny);
            child->f = child->g + child->h;
            child->parent = cur;

            push(open, child);
        }
    }

    return -1;
}

int main()
{
    int grid[ROW][COL] = {
        {0,0,0,0},
        {0,1,0,0},
        {0,1,0,0},
        {0,0,0,0}
    };

    int start_x = 0;
    int start_y = 0;
    int end_x = 3;
    int end_y = 3;

    int result = findPath(start_x, start_y, end_x, end_y, grid);
    if (result == -1)
        printf("Path not found.\n");
    else
        printf("Distance: %d\n", result);

    return 0;
}