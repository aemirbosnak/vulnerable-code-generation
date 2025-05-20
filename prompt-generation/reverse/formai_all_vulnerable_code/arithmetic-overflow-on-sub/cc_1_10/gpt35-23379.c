//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
};

struct Node
{
    int x;
    int y;
    int distance;
    struct Node* parent;
};

void printPath(struct Node* node)
{
    if (node == NULL)
    {
        return;
    }
    
    printPath(node->parent);
    printf("(%d, %d) -> ", node->x, node->y);
    
    return;
}

void shortestRoute(int start_x, int start_y, int end_x, int end_y)
{
    int visited[ROW][COL];
    memset(visited, 0, sizeof visited);
    
    visited[start_x][start_y] = 1;
    
    struct Node* q[ROW*COL];
    int front = 0;
    int rear = 0;
    
    struct Node* start = malloc(sizeof(struct Node));
    start->x = start_x;
    start->y = start_y;
    start->distance = 0;
    start->parent = NULL;
    
    q[rear++] = start;
    
    while (front < rear)
    {
        struct Node* curr = q[front++];
        
        int x = curr->x;
        int y = curr->y;
        
        if (x == end_x && y == end_y)
        {
            printf("The shortest path is %d nodes long:\n", curr->distance);
            printPath(curr);
            printf("\n");
            return;
        }
        
        struct Node* child1 = malloc(sizeof(struct Node));
        child1->x = x+1;
        child1->y = y;
        
        if (maze[x+1][y] == 0 && visited[x+1][y] == 0)
        {
            visited[x+1][y] = 1;
            child1->distance = curr->distance+1;
            child1->parent = curr;
            q[rear++] = child1;
        }
        
        struct Node* child2 = malloc(sizeof(struct Node));
        child2->x = x;
        child2->y = y+1;
        
        if (maze[x][y+1] == 0 && visited[x][y+1] == 0)
        {
            visited[x][y+1] = 1;
            child2->distance = curr->distance+1;
            child2->parent = curr;
            q[rear++] = child2;
        }
        
        struct Node* child3 = malloc(sizeof(struct Node));
        child3->x = x-1;
        child3->y = y;
        
        if (maze[x-1][y] == 0 && visited[x-1][y] == 0)
        {
            visited[x-1][y] = 1;
            child3->distance = curr->distance+1;
            child3->parent = curr;
            q[rear++] = child3;
        }
        
        struct Node* child4 = malloc(sizeof(struct Node));
        child4->x = x;
        child4->y = y-1;
        
        if (maze[x][y-1] == 0 && visited[x][y-1] == 0)
        {
            visited[x][y-1] = 1;
            child4->distance = curr->distance+1;
            child4->parent = curr;
            q[rear++] = child4;
        }
        
    }
    
    printf("Path not found.\n");
    
    return;
}

int main()
{
    int start_x = 0;
    int start_y = 0;
    
    int end_x = 9;
    int end_y = 9;
    
    shortestRoute(start_x, start_y, end_x, end_y);
    
    return 0;
}