//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Define the size of the maze
#define ROW_SIZE 10
#define COL_SIZE 10

// Define the start and end locations of the maze
#define START_ROW 0
#define START_COL 0
#define END_ROW 9
#define END_COL 9

// Define the wall value for the maze
#define WALL 1

// Define the node structure for storing the location and cost
typedef struct node
{
    int row;
    int col;
    int cost;
} Node;

// Define a queue for the frontier of nodes to be expanded
typedef struct queue
{
    Node** arr;
    int front;
    int rear;
    int size;
} Queue;

// Initialize the queue
Queue* initQueue(int size)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (Node**)malloc(size * sizeof(Node*));
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

// Check if the queue is empty
int isEmpty(Queue* q)
{
    return q->front == -1;
}

// Check if the queue is full
int isFull(Queue* q)
{
    return q->rear == q->size - 1;
}

// Add a node to the queue
void enqueue(Queue* q, Node* node)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q))
    {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = node;
}

// Remove a node from the queue
Node* dequeue(Queue* q)
{
    if (isEmpty(q))
    {
        return NULL;
    }
    Node* node = q->arr[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return node;
}

// Check if a location is within the maze bounds
int isValid(int row, int col)
{
    return row >= 0 && row < ROW_SIZE && col >= 0 && col < COL_SIZE;
}

// Implement the A* pathfinding algorithm
void findPath(int maze[ROW_SIZE][COL_SIZE], Node* start, Node* end)
{
    // Initialize the start node, add to queue
    start->cost = 0;
    start->row = START_ROW;
    start->col = START_COL;
    Queue* q = initQueue(ROW_SIZE * COL_SIZE);
    enqueue(q, start);

    // Initialize the visited grid
    int visited[ROW_SIZE][COL_SIZE] = { 0 };
    visited[START_ROW][START_COL] = 1;

    // Define the neighbor movement directions
    int dr[] = { -1, 0, 1, 0 };
    int dc[] = { 0, 1, 0, -1 };

    // Loop over each element in the queue
    while (!isEmpty(q))
    {
        // Dequeue the next node to be expanded
        Node* current = dequeue(q);
        int cr = current->row;
        int cc = current->col;
        int currentCost = current->cost;

        // Check if the current node is the end node
        if (cr == END_ROW && cc == END_COL)
        {
            printf("Path found! Cost: %d\n", currentCost);
            return;
        }

        // Loop over the neighbors of the current node
        for (int i = 0; i < 4; i++)
        {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            // Check if the neighbor is within the maze bounds, and not a wall or visited
            if (isValid(nr, nc) && !visited[nr][nc] && maze[nr][nc] != WALL)
            {
                // Calculate the cost to the neighbor
                int newCost = currentCost + 1;

                // Create a new node for the neighbor and add to the queue
                Node* neighbor = (Node*)malloc(sizeof(Node));
                neighbor->row = nr;
                neighbor->col = nc;
                neighbor->cost = newCost;
                enqueue(q, neighbor);

                // Mark the neighbor as visited
                visited[nr][nc] = 1;
            }
        }
    }

    // If the end node is not found, there is no path
    printf("No path found...\n");
}

// Driver code
int main()
{
    // Define the maze
    int maze[ROW_SIZE][COL_SIZE] = {
        { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 1, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    // Create the start and end nodes
    Node* start = (Node*)malloc(sizeof(Node));
    Node* end = (Node*)malloc(sizeof(Node));

    // Find the path through the maze
    findPath(maze, start, end);

    return 0;
}