//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#define N 10

int randq(int x, int y) {
    return rand() % (y - x + 1) + x;
}

typedef struct {
    int front;
    int rear;
    int items[N];
} Queue;

void enqueue(Queue *q, int x) {
    if ((q->rear + 1) % N == q->front) {
        printf("Queue is full");
    } else {
        q->rear = (q->rear + 1) % N;
        q->items[q->rear] = x;
    }
}

int dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty");
        return -1;
    } else {
        q->front = (q->front + 1) % N;
        return q->items[q->front];
    }
}

int main() {
    int cars = 0;
    int max_speed = 5;
    int time = 0;
    int speed[N];
    Queue road;
    road.front = 0;
    road.rear = N - 1;

    // initialize the speed of each car to a random value between 1 and 5
    for (int i = 0; i < N; i++) {
        speed[i] = randq(1, max_speed);
    }

    // enqueue all the cars on the road
    for (int i = 0; i < N; i++) {
        enqueue(&road, i);
    }

    // simulation loop
    while (cars < N) {
        // dequeue the first car on the road
        int current_car = dequeue(&road);

        // calculate the distance the car travels in this time step
        int distance = speed[current_car] * time;

        // if the car exceeds the length of the road, it has exited the simulation
        if (distance > N) {
            cars++;
        } else {
            // update the speed of the car
            speed[current_car] = randq(1, max_speed);

            // enqueue the car back on the road
            enqueue(&road, current_car);
        }

        time++;
    }

    printf("%d cars passed through the road in %d time steps", cars, time);

    return 0;
}