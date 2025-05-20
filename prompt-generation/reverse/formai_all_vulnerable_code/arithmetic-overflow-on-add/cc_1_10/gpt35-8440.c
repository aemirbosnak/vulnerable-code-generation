//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define ROW 10 // Define row size of the grid
#define COL 10 // Define column size of the grid

// Structure for holding a cell's coordinates
struct cell 
{ 
    int x, y; 
};

// Data structure to represent a node in the search tree
struct node
{
    struct cell pos; // position in the grid
    int f, g, h; // f = total cost, g = cost so far, h = heuristic cost
    struct node *parent; // pointer to parent node
};

// Function to create a new node
struct node *createNode(struct cell pos, int f, int g, int h, struct node *parent)
{
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->pos = pos;
    newNode->f = f;
    newNode->g = g;
    newNode->h = h;
    newNode->parent = parent;
    return newNode;
}

// Function to calculate Manhattan distance as a heuristic
int heuristic(struct cell curr, struct cell goal)
{
    return abs(curr.x - goal.x) + abs(curr.y - goal.y);
}

// Function to check if a cell is valid and not blocked
int isValid(int grid[][COL], int row, int col, struct cell pos)
{
    return (pos.x >= 0 && pos.x < row && pos.y >= 0 && pos.y < col && grid[pos.x][pos.y] == 0);
}

// Function to print the path from start to goal
void printPath(struct node *goalNode)
{
    struct node *curr = goalNode;
    printf("Path: ");
    while (curr != NULL)
    {
        printf("(%d, %d) ", curr->pos.x, curr->pos.y);
        curr = curr->parent;
    }
}

// Function to implement A* pathfinding algorithm
void aStar(int grid[][COL], struct cell start, struct cell goal)
{
    // Define 8 possible directions to move in
    int dx[] = {-1, 0, 1, 0, -1, 1, -1, 1};
    int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};

    // Create open and closed lists as a heap (min priority queue)
    struct node **openList = (struct node **) malloc(ROW*COL*sizeof(struct node *));
    int openSize = 0;
    struct node **closedList = (struct node **) malloc(ROW*COL*sizeof(struct node *));
    int closedSize = 0;

    // Create start node and add to the open list
    struct node *startNode = createNode(start, 0, 0, 0, NULL);
    startNode->f = heuristic(start, goal);
    openList[openSize++] = startNode;

    // Loop until path is found or open list is empty
    while (openSize > 0)
    {
        // Find the node with the lowest f-cost in the open list
        int minCost = openList[0]->f;
        int minIndex = 0;
        for (int i = 1; i < openSize; i++)
        {
            if (openList[i]->f < minCost)
            {
                minCost = openList[i]->f;
                minIndex = i;
            }
        }

        // Remove the node with the lowest f-cost from the open list and add to the closed list
        struct node *currNode = openList[minIndex];
        openList[minIndex] = openList[--openSize];
        closedList[closedSize++] = currNode;

        // Check if currNode is goal node
        if (currNode->pos.x == goal.x && currNode->pos.y == goal.y)
        {
            printPath(currNode);
            return;
        }

        // Generate children of currNode and add to open list
        for (int i = 0; i < 8; i++)
        {
            struct cell childPos = {currNode->pos.x + dx[i], currNode->pos.y + dy[i]};

            // Check if child is valid and not in closed list
            if (isValid(grid, ROW, COL, childPos))
            {
                // Calculate cost of child and add to open list
                int g = currNode->g + 1; // Assuming each step costs 1
                int h = heuristic(childPos, goal);
                int f = g + h;
                struct node *child = createNode(childPos, f, g, h, currNode);
                int duplicate = 0;
                for (int j = 0; j < closedSize; j++)
                {
                    if (childPos.x == closedList[j]->pos.x && childPos.y == closedList[j]->pos.y)
                    {
                        duplicate = 1;
                        break;
                    }
                }
                if (!duplicate)
                {
                    duplicate = 0;
                    for (int j = 0; j < openSize; j++)
                    {
                        if (childPos.x == openList[j]->pos.x && childPos.y == openList[j]->pos.y)
                        {
                            duplicate = 1;
                            if (f < openList[j]->f) // If new path is better, update node in open list
                            {
                                openList[j]->f = f;
                                openList[j]->g = g;
                                openList[j]->h = h;
                                openList[j]->parent = currNode;
                            }
                            break;
                        }
                    }
                    if (!duplicate)
                    {
                        openList[openSize++] = child;
                    }
                }
            }
        }
    }

    printf("Path not found.\n");

    // Free dynamically allocated memory
    for (int i = 0; i < openSize; i++)
    {
        free(openList[i]);
    }
    free(openList);
    for (int i = 0; i < closedSize; i++)
    {
        free(closedList[i]);
    }
    free(closedList);
}

int main()
{
    // Define grid with 1s representing obstacles and 0s representing free cells
    int grid[ROW][COL] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
                          {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
                          {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
                          {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
                          {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
                          {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
                          {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
                          {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    struct cell start = {1, 1};
    struct cell goal = {8, 8};

    aStar(grid, start, goal);

    return 0;
}