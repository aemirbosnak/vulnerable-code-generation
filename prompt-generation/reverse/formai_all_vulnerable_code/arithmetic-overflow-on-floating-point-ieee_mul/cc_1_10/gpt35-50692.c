//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

// A structure to represent a point in the grid
struct Point {
    int x, y;
};

// A structure to represent a node in the Heap
struct HeapNode {
    int f, g;
    struct Point pos;
};

// A structure to hold the Heap
struct Heap {
    int size;
    int capacity;
    struct HeapNode *nodes;
};

// A structure to hold the heuristic values
struct Heuristic {
    int values[ROW][COL];
};

// Function prototypes
bool isInsideGrid(struct Point point);
bool isObstacle(int grid[][COL], struct Point point);
bool isDestination(struct Point current, struct Point destination);
double calculateHValue(struct Point current, struct Point destination);
bool isEqual(struct Point a, struct Point b);
void printPath(struct Point path[], int pathLength);
void push(struct Heap *heap, struct HeapNode node);
void heapify(struct Heap *heap, int index);
struct HeapNode pop(struct Heap *heap);
void swap(int *a, int *b);
struct Point *findPath(int grid[][COL], struct Point source, struct Point destination);

// The implementation of A* Pathfinding Algorithm
struct Point *findPath(int grid[][COL], struct Point source, struct Point destination)
{
    // Array to hold path
    static struct Point path[ROW * COL];
    
    // Check if source and destination are valid
    if (!isInsideGrid(source) || !isInsideGrid(destination)) {
        printf("Invalid Points\n");
        return NULL;
    }
    
    // Check if source and destination are not walls
    if (isObstacle(grid, source) || isObstacle(grid, destination)) {
        printf("Source or Destination is blocked\n");
        return NULL;
    }
    
    // Check if destination is reached
    if (isDestination(source, destination)) {
        printf("You are already at the Destination\n");
        path[0] = source;
        return path;
    }
    
    // Calculate the heuristic values
    struct Heuristic heuristic;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            heuristic.values[i][j] = (int) calculateHValue((struct Point) {.x = i, .y = j}, destination);
        }
    }
    
    // Create the open and closed lists
    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));
    
    struct Heap openList;
    openList.size = 0;
    openList.capacity = ROW * COL;
    openList.nodes = malloc(sizeof(struct HeapNode) * openList.capacity);
    
    // Add the source to open list
    struct HeapNode startNode = (struct HeapNode) {.f = 0, .g = 0, .pos = source};
    push(&openList, startNode);
    
    // Loop until destination is found
    bool foundDest = false;
    while (openList.size > 0) {
        // Pop the top node
        struct HeapNode currentNode = pop(&openList);
        closedList[currentNode.pos.x][currentNode.pos.y] = true;
        
        // Check if destination is reached
        if (isDestination(currentNode.pos, destination)) {
            printf("Destination Found\n");
            foundDest = true;
            path[0] = destination;
            struct Point current = currentNode.pos;
            int pathLength = 1;
            while (!isEqual(current, source)) {
                path[pathLength++] = current;
                current = (struct Point) {.x = currentNode.pos.x - 1 + path[pathLength - 1].x, .y = currentNode.pos.y - 1 + path[pathLength - 1].y};
            }
            path[pathLength] = source;
            printPath(path, pathLength);
            break;
        }
        
        // Iterate over neighbouring cells
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                struct Point neighbour = (struct Point) {.x = currentNode.pos.x + x, .y = currentNode.pos.y + y};
                
                // Don't consider the current node or the diagonal ones
                if (x == 0 && y == 0) {
                    continue;
                }
                if (x != 0 && y != 0) {
                    continue;
                }
                
                // Check neighbour is inside the grid and is not a wall
                if (isInsideGrid(neighbour) && !isObstacle(grid, neighbour)) {
                    int gValue = currentNode.g + 1;
                    int hValue = heuristic.values[neighbour.x][neighbour.y];
                    int fValue = gValue + hValue;
                    
                    // Add to open list if not closed
                    if (!closedList[neighbour.x][neighbour.y]) {
                        struct HeapNode newNode = (struct HeapNode) {.f = fValue, .g = gValue, .pos = neighbour};
                        push(&openList, newNode);
                    }
                }
            }
        }
    }
    
    if (!foundDest) {
        printf("Destination Not Found\n");
        return NULL;
    }
    return path;
}

// Helper Functions

bool isInsideGrid(struct Point point)
{
    return (point.x >= 0 && point.x < ROW && point.y >= 0 && point.y < COL);
}

bool isObstacle(int grid[][COL], struct Point point)
{
    return (grid[point.x][point.y] == 1);
}

bool isDestination(struct Point current, struct Point destination)
{
    return (current.x == destination.x && current.y == destination.y);
}

double calculateHValue(struct Point current, struct Point destination)
{
    return sqrt((double) pow(current.x - destination.x, 2) + pow(current.y - destination.y, 2));
}

bool isEqual(struct Point a, struct Point b)
{
    return (a.x == b.x && a.y == b.y);
}

void printPath(struct Point path[], int pathLength)
{
    printf("Path: ");
    for (int i = pathLength; i >= 0; i--) {
        printf("(%d, %d) ", path[i].x, path[i].y);
    }
    printf("\n");
}

void push(struct Heap *heap, struct HeapNode node)
{
    if (heap->size < heap->capacity) {
        heap->nodes[heap->size] = node;
        int current = heap->size;
        while (heap->nodes[current].f < heap->nodes[(current - 1) / 2].f) {
            swap(&heap->nodes[current].f, &heap->nodes[(current - 1) / 2].f);
            swap(&heap->nodes[current].g, &heap->nodes[(current - 1) / 2].g);
            swap(&heap->nodes[current].pos.x, &heap->nodes[(current - 1) / 2].pos.x);
            swap(&heap->nodes[current].pos.y, &heap->nodes[(current - 1) / 2].pos.y);
            current = (current - 1) / 2;
        }
        heap->size++;
    }
}

void heapify(struct Heap *heap, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;
    
    if (left < heap->size && heap->nodes[left].f < heap->nodes[smallest].f) {
        smallest = left;
    }
    if (right < heap->size && heap->nodes[right].f < heap->nodes[smallest].f) {
        smallest = right;
    }
    if (smallest != index) {
        swap(&heap->nodes[index].f, &heap->nodes[smallest].f);
        swap(&heap->nodes[index].g, &heap->nodes[smallest].g);
        swap(&heap->nodes[index].pos.x, &heap->nodes[smallest].pos.x);
        swap(&heap->nodes[index].pos.y, &heap->nodes[smallest].pos.y);
        heapify(heap, smallest);
    }
}

struct HeapNode pop(struct Heap *heap)
{
    if (heap->size < 1) {
        printf("Heap is Empty\n");
    }
    struct HeapNode top = heap->nodes[0];
    heap->nodes[0] = heap->nodes[--heap->size];
    heapify(heap, 0);
    return top;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    // Example Map
    int grid[ROW][COL] = {
        {0, 0 ,0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 1, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    
    // Find Path
    struct Point source = (struct Point) {.x = 0, .y = 0};
    struct Point destination = (struct Point) {.x = 9, .y = 9};
    findPath(grid, source, destination);
    
    return 0;
}