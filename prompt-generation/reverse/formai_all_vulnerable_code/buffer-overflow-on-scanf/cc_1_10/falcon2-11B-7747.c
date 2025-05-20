//Falcon2-11B DATASET v1.0 Category: GPS Navigation Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
    int cost;
} Waypoint;

typedef struct {
    Waypoint* data;
    int size;
    int capacity;
} PriorityQueue;

void swap(Waypoint* a, Waypoint* b) {
    Waypoint temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(PriorityQueue* q, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < q->size && q->data[left].cost < q->data[smallest].cost) {
        smallest = left;
    }

    if (right < q->size && q->data[right].cost < q->data[smallest].cost) {
        smallest = right;
    }

    if (smallest!= index) {
        swap(&q->data[index], &q->data[smallest]);
        heapify(q, smallest);
    }
}

void insert(PriorityQueue* q, Waypoint wp) {
    q->size++;

    if (q->size == q->capacity) {
        q->capacity *= 2;
        q->data = realloc(q->data, q->capacity * sizeof(Waypoint));
    }

    q->data[q->size - 1] = wp;

    int index = q->size - 1;
    heapify(q, index);
}

void delete(PriorityQueue* q, int index) {
    q->size--;

    if (index < q->size) {
        swap(&q->data[index], &q->data[q->size - 1]);
        q->data[q->size - 1] = q->data[q->size - 1];
        q->data[index] = q->data[q->size - 1];

        heapify(q, index);
    }
}

void enqueue(PriorityQueue* q, Waypoint wp) {
    insert(q, wp);
}

void dequeue(PriorityQueue* q) {
    delete(q, 0);
}

void printQueue(PriorityQueue* q) {
    printf("Queue: ");
    for (int i = 0; i < q->size; i++) {
        printf("(%d, %d, %d) ", q->data[i].x, q->data[i].y, q->data[i].cost);
    }
    printf("\n");
}

void printWaypoints(Waypoint* waypoints, int numWaypoints) {
    printf("Waypoints: ");
    for (int i = 0; i < numWaypoints; i++) {
        printf("(%d, %d, %d) ", waypoints[i].x, waypoints[i].y, waypoints[i].cost);
    }
    printf("\n");
}

void calculateRoute(PriorityQueue* q, Waypoint* waypoints, int numWaypoints) {
    printf("Route: ");
    while (q->size > 0) {
        Waypoint wp = q->data[0];
        q->data[0] = q->data[q->size - 1];
        q->data[q->size - 1] = q->data[q->size - 1];
        q->data[q->size - 1] = q->data[q->size - 1];

        q->size--;
        printf("(%d, %d) ", wp.x, wp.y);
        delete(q, 0);
    }
    printf("\n");
}

int main() {
    int numWaypoints;
    printf("Enter the number of waypoints: ");
    scanf("%d", &numWaypoints);

    Waypoint* waypoints = malloc(numWaypoints * sizeof(Waypoint));

    for (int i = 0; i < numWaypoints; i++) {
        printf("Enter waypoint %d: ", i + 1);
        scanf("%d%d%d", &waypoints[i].x, &waypoints[i].y, &waypoints[i].cost);
    }

    PriorityQueue q;
    q.size = 0;
    q.capacity = 100;
    q.data = malloc(q.capacity * sizeof(Waypoint));

    Waypoint start = {0, 0, 0};
    Waypoint destination = {0, 0, 0};

    for (int i = 0; i < numWaypoints; i++) {
        if (waypoints[i].x == 0 && waypoints[i].y == 0) {
            start.x = waypoints[i].x;
            start.y = waypoints[i].y;
            start.cost = waypoints[i].cost;
        } else {
            insert(&q, waypoints[i]);
        }
    }

    for (int i = 0; i < numWaypoints; i++) {
        if (waypoints[i].x == 0 && waypoints[i].y == 0) {
            destination.x = waypoints[i].x;
            destination.y = waypoints[i].y;
            destination.cost = waypoints[i].cost;
        }
    }

    printf("Start: (%d, %d) ", start.x, start.y);
    printf("Destination: (%d, %d) \n", destination.x, destination.y);

    printQueue(&q);
    printWaypoints(q.data, q.size);

    calculateRoute(&q, q.data, q.size);

    free(q.data);
    free(waypoints);

    return 0;
}