//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEIGHT 50
#define MAX_WIDTH 50

typedef struct {
    int x, y;
} Node;

int map[MAX_HEIGHT][MAX_WIDTH];
Node start, end;
int height, width;

Node openList[MAX_HEIGHT * MAX_WIDTH];
Node closedList[MAX_HEIGHT * MAX_WIDTH];
int openCounter = 0;
int closedCounter = 0;

int cost[3][3] = {
    {10, 14, 10},
    {14, 20, 14},
    {10, 14, 10}
};

int heuristic(Node current) {
    // Manhattan Distance Heuristic
    return abs(current.x - end.x) + abs(current.y - end.y);
}

int checkCoord(Node coord) {
    if (coord.x < 0 || coord.x >= height || coord.y < 0 || coord.y >= width)
        return 0;
    return 1;
}

int checkClosedList(Node current) {
    for (int i = 0; i < closedCounter; i++) {
        if (closedList[i].x == current.x && closedList[i].y == current.y)
            return 1;
    }
    return 0;
}

int checkOpenList(Node current) {
    for (int i = 0; i < openCounter; i++) {
        if (openList[i].x == current.x && openList[i].y == current.y)
            return i;
    }
    return -1;
}

void removeFromOpenList(int index) {
    for (int i = index; i < openCounter - 1; i++) {
        openList[i] = openList[i + 1];
    }
    openCounter--;
}

void addToOpenList(Node current) {
    openList[openCounter] = current;
    openCounter++;
}

void addToClosedList(Node current) {
    closedList[closedCounter] = current;
    closedCounter++;
}

int lowestFInOpenList() {
    int index = 0, lowestF = openList[0].x + openList[0].y;
    for (int i = 1; i < openCounter; i++) {
        int tempF = openList[i].x + openList[i].y;
        if (tempF < lowestF) {
            lowestF = tempF;
            index = i;
        }
    }
    return index;
}

void printMap() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == start.x && j == start.y) {
                printf("S ");
            } else if (i == end.x && j == end.y) {
                printf("E ");
             } else if (map[i][j] == 0) {
                printf(". ");
            } else if (map[i][j] == 1) {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Enter height of map: ");
    scanf("%d", &height);
    printf("Enter width of map: ");
    scanf("%d", &width);

    // Initialize map
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            map[i][j] = 0;
        }
    }

    // Mark start and end points
    printf("Enter x-coordinate of start point: ");
    scanf("%d", &start.x);
    printf("Enter y-coordinate of start point: ");
    scanf("%d", &start.y);
    map[start.x][start.y] = 2;

    printf("Enter x-coordinate of end point: ");
    scanf("%d", &end.x);
    printf("Enter y-coordinate of end point: ");
    scanf("%d", &end.y);
    map[end.x][end.y] = 3;

    // Add obstacles
    printf("Enter number of obstacles: ");
    int numObstacles;
    scanf("%d", &numObstacles);
    printf("Enter coordinates of obstacles (in the format x1 y1 x2 y2 ... xn yn): ");
    for (int i = 0; i < numObstacles; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        map[x][y] = 1;
    }

    printf("Map:\n");
    printMap();

    Node current = start;
    while (1) {
        // Add current node to closed list
        addToClosedList(current);

        int currentG = closedCounter - 1;
        int currentH = heuristic(current);
        int currentF = currentG + currentH;

        // Check adjacent nodes
        Node temp;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0)
                    continue;

                temp.x = current.x + i;
                temp.y = current.y + j;

                if (!checkCoord(temp))
                    continue;

                if (map[temp.x][temp.y] == 1 || checkClosedList(temp))
                    continue;

                int tempG = currentG + cost[i+1][j+1];
                int tempH = heuristic(temp);
                int tempF = tempG + tempH;

                int index = checkOpenList(temp);
                if (index == -1) {
                    addToOpenList(temp);
                } else if (tempG >= closedCounter - 1 && tempF >= currentF) {
                    continue;
                }

                openList[index].x = tempG;
                openList[index].y = tempH;
            }
        }

        if (openCounter == 0) {
            printf("Path not found.\n");
            return 0;
        }

        int lowestFIndex = lowestFInOpenList();
        current = openList[lowestFIndex];
        removeFromOpenList(lowestFIndex);

        if (current.x == end.x && current.y == end.y)
            break;
    }

    // Trace path
    printf("\nPath:\n");
    for (int i = closedCounter - 1; i >= 0; i--) {
        if (closedList[i].x == start.x && closedList[i].y == start.y)
            continue;
        if (closedList[i].x == end.x && closedList[i].y == end.y)
            continue;

        printf("(%d,%d) -> ", closedList[i].x, closedList[i].y);
    }
    printf("(%d,%d)\n", end.x, end.y);

    return 0;
}