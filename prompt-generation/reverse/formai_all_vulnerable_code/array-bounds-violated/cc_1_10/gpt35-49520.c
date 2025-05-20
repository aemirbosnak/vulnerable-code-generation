//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#define INFINITY 1000000

int n;
int source, destination;
int graph[1000][1000];
int cost[1000][1000];
int path[1000];
int queue[1000], front, rear;

void astar_algorithm(int start, int goal);
void enqueue(int v);
int dequeue();
int isEmpty();
int heuristic(int current, int goal);

int main()
{
    int i, j, start_node, goal_node;

    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (if no edge exists, enter INFINITY):\n");
    for (i = 0 ; i < n ; i++)
        for (j = 0 ; j < n ; j++) 
            scanf("%d", &graph[i][j]);

    printf("Enter the source node: ");
    scanf("%d", &source);

    printf("Enter the destination node: ");
    scanf("%d", &destination);

    astar_algorithm(source, destination);

    if (path[0] != source && path[0] != -1) {
        printf("Path is not found between %d and %d\n", source, destination);
    } else {
        printf("Shortest path between %d and %d: ", source, destination);
        for (i = 0; path[i]!=-1; i++)
            printf("%d ", path[i]);
        printf("\n");
    }

    return 0;
}

void astar_algorithm(int start, int goal)
{
    int current, i, temp, distanceFromStart[n], fScore[n], prev[n];
    for (i = 0 ; i < n ; i++) {
        distanceFromStart[i] = INFINITY;
        fScore[i] = INFINITY;
        prev[i] = -1;
    }
    fScore[start] = heuristic(start, goal);
    distanceFromStart[start] = 0;
    enqueue(start);
    while (!isEmpty()) {
        current = dequeue();
        if(current == goal) {
            i = 0;
            while (current != -1) {
                path[i++] = current;
                current = prev[current];
            }
            break;
        }
        for (i = 0 ; i < n ; i++) {
            if (graph[current][i] != 0) {
                temp = distanceFromStart[current] + graph[current][i];
                if (temp < distanceFromStart[i]) {
                    distanceFromStart[i] = temp;
                    prev[i] = current;
                    fScore[i] = temp + heuristic(i, goal);
                    enqueue(i);
                }
            }
        }
    }
}

int heuristic(int current, int goal)
{
    return abs(goal - current);
}

void enqueue(int vertex)
{
    if (rear == 1000)
        printf("Queue overflow\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue()
{
    int deleted;
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        deleted = -1;
    } else {
        deleted = queue[front];
        front++;
    }
    return deleted;
}

int isEmpty()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}