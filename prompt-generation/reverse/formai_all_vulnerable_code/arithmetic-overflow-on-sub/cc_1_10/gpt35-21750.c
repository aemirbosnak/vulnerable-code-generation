//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int x, y;
    struct node* parent;
}Node;

enum direction{LEFT, RIGHT, UP, DOWN};
char* directionChar[] = {"Left", "Right", "Up", "Down"};

int isValidLocation(int x, int y, int vis[])
{
    if(x>=0 && x<5 && y>=0 && y<5 && vis[x*5+y]==0)
        return 1;
    return 0;
}

void printPath(Node* node)
{
    if(node==NULL)
        return;
    printPath(node->parent);
    printf("(%d, %d) -> ",node->x, node->y);
}

void createPath(Node* start, Node* end, int vis[], int maze[][5])
{
    int i, j, k, x, y, d;
    Node *currentNode, *child;
    Node* queue[10005];
    int queueLength=1, queueStart=0;

    start->parent = NULL;
    vis[start->x*5+start->y]=1;
    queue[0] = start;

    while(queueStart<queueLength)
    {
        currentNode = queue[queueStart++];
        if(currentNode->x==end->x && currentNode->y==end->y)
        {
            printf("Path found!!\n");
            printf("Path: ");
            printPath(currentNode);
            return;
        }

        for(i=0; i<4; i++)
        {
            d = i;
            x = currentNode->x;
            y = currentNode->y;

            if(d==UP)
                x-=1;
            else if(d==DOWN)
                x+=1;
            else if(d==LEFT)
                y-=1;
            else if(d==RIGHT)
                y+=1;

            if(isValidLocation(x, y, vis) && maze[x][y]==0)
            {
                vis[x*5+y] = 1;
                child = (Node*)malloc(sizeof(Node));
                child->x = x;
                child->y = y;
                child->parent = currentNode;
                queue[queueLength++] = child;
            }
        }
    }

    printf("Path not found!");
}

void test()
{
    int vis[25] = {0};
    int maze[5][5] = {
        {0,0,0,0,1},
        {1,1,0,1,0},
        {0,0,0,1,0},
        {0,1,1,0,0},
        {0,0,0,0,0}
    };

    Node* start = (Node*)malloc(sizeof(Node));
    start->x = 0;
    start->y = 0;

    Node* end = (Node*)malloc(sizeof(Node));
    end->x = 4;
    end->y = 4;

    createPath(start, end, vis, maze);
}

int main()
{
    test();
    return 0;
}