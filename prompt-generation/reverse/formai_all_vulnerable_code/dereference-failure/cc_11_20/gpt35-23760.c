//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

struct Node
{
    int x, y;
    int f; // f = g + h
    int g; // cost from starting node
    int h; // heuristic distance to end node
    struct Node* parent;
};

// A* pathfinding algorithm
void AStar(int map[][COL], struct Node start, struct Node end)
{
    // create open and closed list
    struct Node* openList[ROW*COL] = { NULL };
    struct Node* closedList[ROW*COL] = { NULL };

    // initialize start node values
    start.g = 0;
    start.h = abs(end.x - start.x) + abs(end.y - start.y);
    start.f = start.g + start.h;
    start.parent = NULL;
    
    int openSize = 0;
    int closedSize = 0;
    
    // add start node to open list
    openList[0] = &start;
    openSize++;

    // loop until end node is found or open list is empty
    while (openSize > 0)
    {
        // get the node with the lowest f value
        struct Node* curr = openList[0];
        int currIndex = 0;
        for (int i = 1; i < openSize; i++)
        {
            if (openList[i]->f < curr->f)
            {
                curr = openList[i];
                currIndex = i;
            }
        }

        // move current node from open to closed list
        openList[currIndex] = openList[openSize - 1];
        openList[openSize - 1] = NULL;
        openSize--;
        closedList[closedSize] = curr;
        closedSize++;

        // if end node is found, return path
        if (curr->x == end.x && curr->y == end.y)
        {
            struct Node* path[ROW*COL] = { NULL };
            struct Node* temp = curr;
            int pathSize = 0;

            while (temp != NULL)
            {
                path[pathSize] = temp;
                pathSize++;
                temp = temp->parent;
            }

            printf("Path Found: ");
            for (int i = pathSize - 1; i >= 0; i--)
            {
                printf("(%d,%d) ", path[i]->x, path[i]->y);
            }
            printf("\n");
            return;
        }

        // generate successors
        struct Node* successors[4] = { NULL };
        int numSuccessors = 0;
        int currRow = curr->x;
        int currCol = curr->y;

        // check up
        if (currRow > 0 && map[currRow-1][currCol] == 0)
        {
            successors[numSuccessors] = (struct Node*)malloc(sizeof(struct Node));
            successors[numSuccessors]->x = currRow - 1;
            successors[numSuccessors]->y = currCol;
            numSuccessors++;
        }

        // check down
        if (currRow < ROW-1 && map[currRow+1][currCol] == 0)
        {
            successors[numSuccessors] = (struct Node*)malloc(sizeof(struct Node));
            successors[numSuccessors]->x = currRow + 1;
            successors[numSuccessors]->y = currCol;
            numSuccessors++;
        }

        // check left
        if (currCol > 0 && map[currRow][currCol-1] == 0)
        {
            successors[numSuccessors] = (struct Node*)malloc(sizeof(struct Node));
            successors[numSuccessors]->x = currRow;
            successors[numSuccessors]->y = currCol - 1;
            numSuccessors++;
        }

        // check right
        if (currCol < COL-1 && map[currRow][currCol+1] == 0)
        {
            successors[numSuccessors] = (struct Node*)malloc(sizeof(struct Node));
            successors[numSuccessors]->x = currRow;
            successors[numSuccessors]->y = currCol + 1;
            numSuccessors++;
        }

        // calculate f, g, and h values for each successor
        for (int i = 0; i < numSuccessors; i++)
        {
            int g = curr->g + 1;
            int h = abs(end.x - successors[i]->x) + abs(end.y - successors[i]->y);
            int f = g + h;

            successors[i]->g = g;
            successors[i]->h = h;
            successors[i]->f = f;
            successors[i]->parent = curr;

            // check if successor is already on closed list
            int found = 0;
            for (int j = 0; j < closedSize; j++)
            {
                if (successors[i]->x == closedList[j]->x && successors[i]->y == closedList[j]->y)
                {
                    found = 1;
                    break;
                }
            }

            if (found) continue;

            // check if successor is already on open list
            found = 0;
            for (int j = 0; j < openSize; j++)
            {
                if (successors[i]->x == openList[j]->x && successors[i]->y == openList[j]->y)
                {
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                openList[openSize] = successors[i];
                openSize++;
            }
            else
            {
                free(successors[i]);
            }
        }
    }

    // no path found
    printf("No Path Found.\n");
}

int main()
{
    int map[ROW][COL] = {
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0}
    };
    
    struct Node start = { 0, 0, 0, 0, 0, NULL };
    struct Node end = { 9, 9, 0, 0, 0, NULL };
    
    AStar(map, start, end);
    
    return 0;
}