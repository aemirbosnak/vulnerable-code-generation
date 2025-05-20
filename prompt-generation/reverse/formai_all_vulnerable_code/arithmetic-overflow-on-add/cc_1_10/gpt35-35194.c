//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 10
#define COL 13

// Define nodes
struct node
{
    int x, y;
    int f, g, h;
    struct node *parent;
};

// Initialize arrays
struct node *openList[ROW*COL];
struct node *closedList[ROW*COL];

int openListCount = 0;
int closedListCount = 0;

int obstacleGrid[ROW][COL] =
{
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
    { 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0},
    { 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    { 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
    { 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
    { 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0},
    { 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}
};

// Define functions
int isDestination(int x, int y, struct node *destination);
int isUnBlocked(int x, int y);
int calculateHValue(int x, int y, struct node *destination);
struct node * createNode(int x, int y);
void printPath(struct node *nodePath);
void aStarSearch(struct node *start, struct node *destination);

// Main function
int main()
{
    struct node *startNode = createNode(1, 1);
    struct node *destination = createNode(8, 11);
    
    aStarSearch(startNode, destination);
    
    return 0;
}

// Check if current node is destination
int isDestination(int x, int y, struct node *destination)
{
    if (x == destination->x && y == destination->y)
    {
        return 1;
    }
    
    return 0;
}

// Check if given block is unblocked
int isUnBlocked(int x, int y)
{
    if (obstacleGrid[x][y] == 0)
    {
        return 1;
    }
    
    return 0;
}

// Calculate H value using Manhattan distance
int calculateHValue(int x, int y, struct node *destination)
{
    int h = abs(x - destination->x) + abs(y - destination->y);
    
    return h;
}

// Create new node
struct node * createNode(int x, int y)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->x = x;
    newNode->y = y;
    newNode->f = 0;
    newNode->g = 0;
    newNode->h = 0;
    newNode->parent = NULL;
    
    return newNode;
}

// Print the path
void printPath(struct node *nodePath)
{
    if (nodePath == NULL)
    {
        return;
    }
    
    printPath(nodePath->parent);
    printf("(%d,%d) ", nodePath->x, nodePath->y);
}

// A* search algorithm
void aStarSearch(struct node *start, struct node *destination)
{
    // Add start node to open list
    openList[openListCount++] = start;
    
    while (openListCount > 0)
    {
        // Set current node to node with lowest F score in open list
        int currentIndex = 0;
        int currentF = openList[0]->f;
        
        for (int i = 1; i < openListCount; i++)
        {
            if (openList[i]->f < currentF)
            {
                currentIndex = i;
                currentF = openList[i]->f;
            }
        }
        
        struct node *currentNode = openList[currentIndex];
        
        // Remove current node from open list and add to closed list
        for (int i = 0; i < openListCount; i++)
        {
            if (openList[i] == currentNode)
            {
                for (int j = i; j < openListCount - 1; j++)
                {
                    openList[j] = openList[j + 1];
                }
                
                openListCount--;
                break;
            }
        }
        
        closedList[closedListCount++] = currentNode;
        
        // Check if current node is destination
        if (isDestination(currentNode->x, currentNode->y, destination))
        {
            printPath(currentNode);
            return;
        }
        
        // Check neighbors
        struct node *neighborNodes[8];
        int neighborCount = 0;
        
        // North
        if (isUnBlocked(currentNode->x - 1, currentNode->y))
        {
            neighborNodes[neighborCount++] = createNode(currentNode->x - 1, currentNode->y);
        }
        
        // South
        if (isUnBlocked(currentNode->x + 1, currentNode->y))
        {
            neighborNodes[neighborCount++] = createNode(currentNode->x + 1, currentNode->y);
        }
        
        // East
        if (isUnBlocked(currentNode->x, currentNode->y + 1))
        {
            neighborNodes[neighborCount++] = createNode(currentNode->x, currentNode->y + 1);
        }
        
        // West
        if (isUnBlocked(currentNode->x, currentNode->y - 1))
        {
            neighborNodes[neighborCount++] = createNode(currentNode->x, currentNode->y - 1);
        }

        // Calculate F, G, H values for each neighbor
        for (int i = 0; i < neighborCount; i++)
        {
            struct node *neighbor = neighborNodes[i];
            
            int g = currentNode->g + 1;
            int h = calculateHValue(neighbor->x, neighbor->y, destination);
            int f = g + h;
            
            // Check if neighbor is already in closed list
            int foundClosed = 0;
            for (int j = 0; j < closedListCount; j++)
            {
                if (closedList[j]->x == neighbor->x && closedList[j]->y == neighbor->y)
                {
                    foundClosed = 1;
                    break;
                }
            }
            
            if (foundClosed)
            {
                continue;
            }
            
            // Check if neighbor is already in open list
            int foundOpen = 0;
            for (int j = 0; j < openListCount; j++)
            {
                if (openList[j]->x == neighbor->x && openList[j]->y == neighbor->y)
                {
                    foundOpen = 1;
                    
                    if (f < openList[j]->f)
                    {
                        openList[j]->f = f;
                        openList[j]->g = g;
                        openList[j]->h = h;
                        openList[j]->parent = currentNode;
                    }
                    
                    break;
                }
            }
            
            // Add neighbor to open list
            if (!foundOpen)
            {
                neighbor->f = f;
                neighbor->g = g;
                neighbor->h = h;
                neighbor->parent = currentNode;
                
                openList[openListCount++] = neighbor;
            }
        }
    }
    
    // No path found
    printf("No path found.\n");
}