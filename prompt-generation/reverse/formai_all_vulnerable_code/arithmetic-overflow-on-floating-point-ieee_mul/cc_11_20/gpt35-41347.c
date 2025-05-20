//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 8
#define COL 8

typedef struct
{
    int x, y;
} Point;

// define obstacles on the map
int obstacles[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
};

// A* search algorithm implementation function
void AStarSearch(Point start, Point end)
{
    int visited[ROW][COL] = {0};   // set all values to 0
    int cost[ROW][COL] = {0};      // set all values to 0
    Point parent[ROW][COL] = {{0}}; // set all values to 0
    Point neighbors[8];            // holds current cells neighbors
    int i, j, dx, dy, neighbor_cost, tentative_g_score;
    
    // create the open and closed list for nodes
    Point openList[ROW * COL];
    int openListCount = 0;
    Point closedList[ROW * COL];
    int closedListCount = 0;
    
    // add the start node to the open list
    openList[openListCount++] = start;
    
    // loop until we've found the end node or exhausted all possible paths
    while (openListCount != 0)
    {
        // get the cell with the lowest estimated score
        int currentIndex = 0;
        float currentCost = INFINITY;   // set initial value to infinity
        for (i = 0; i < openListCount; i++)
        {
            float estimatedCost = cost[openList[i].y][openList[i].x] + sqrt(pow(end.x - openList[i].x, 2.0) + pow(end.y - openList[i].y, 2.0));
            if (estimatedCost < currentCost)
            {
                currentIndex = i;
                currentCost = estimatedCost;
            }
        }
        
        // get the current node
        Point current = openList[currentIndex];
        
        // check if we've reached the end
        if (current.x == end.x && current.y == end.y)
        {
            // construct the path and print it out
            Point path[ROW * COL];
            int pathCount = 0;
            while (current.x != start.x || current.y != start.y)
            {
                path[pathCount++] = current;
                current = parent[current.y][current.x];
            }
            printf("Path found:\n");
            for (int i = pathCount - 1; i >= 0; i--)
            {
                printf("(%d, %d) ", path[i].x, path[i].y);
            }
            printf("\n");
            return;
        }
        
        // remove the best cell from the open list and add it to the closed list
        openList[currentIndex] = openList[--openListCount];
        closedList[closedListCount++] = current;
        
        // get the current node's neighbors
        int neighborsCount = 0;
        for (dx = -1; dx <= 1; dx++)
        {
            for (dy = -1; dy <= 1; dy++)
            {
                if (dx == 0 && dy == 0) continue;
                int x = current.x + dx, y = current.y + dy;
                if (x < 0 || x >= COL || y < 0 || y >= ROW) continue;
                if (obstacles[y][x] == 1) continue; // ignore obstacles
                if (visited[y][x]) continue;
                neighbors[neighborsCount++] = (Point){x, y};
                visited[y][x] = 1;
            }
        }
        
        // loop through neighbors
        for (i = 0; i < neighborsCount; i++)
        {
            // calculate cost to neighbor
            neighbor_cost = obstacles[neighbors[i].y][neighbors[i].x];
            tentative_g_score = cost[current.y][current.x] + neighbor_cost;
            
            // if neighbor is already in the open list
            int neighborInOpenList = 0;
            for (j = 0; j < openListCount; j++)
            {
                if (openList[j].x == neighbors[i].x && openList[j].y == neighbors[i].y)
                {
                    neighborInOpenList = 1;
                    break;
                }
            }
            if (!neighborInOpenList || tentative_g_score < cost[neighbors[i].y][neighbors[i].x])
            {
                cost[neighbors[i].y][neighbors[i].x] = tentative_g_score;
                float estimatedCost = tentative_g_score + sqrt(pow(end.x - neighbors[i].x, 2.0) + pow(end.y - neighbors[i].y, 2.0));
                int neighborInClosedList = 0;
                for (j = 0; j < closedListCount; j++)
                {
                    if (closedList[j].x == neighbors[i].x && closedList[j].y == neighbors[i].y)
                    {
                        neighborInClosedList = 1;
                        break;
                    }
                }
                if (!neighborInClosedList)
                {
                    parent[neighbors[i].y][neighbors[i].x] = current;
                    openList[openListCount++] = neighbors[i];
                }
            }
        }
    }
    // if we've reached here, it means there's no path
    printf("No path found\n");
}

// main function
int main(void)
{
    Point start = {0, 0};
    Point end   = {7, 7};
    AStarSearch(start, end);
    return 0;
}