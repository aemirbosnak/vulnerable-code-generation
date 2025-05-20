//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// structure for process
typedef struct {
    int pid;
    int burstTime;
} process;

// structure for queue node
typedef struct Node {
    process p;
    struct Node* next;
} queueNode;

// queue structure
typedef struct {
    queueNode* front;
    queueNode* rear;
} queue;

// create a new queue node
queueNode* createNode(process p) {
    queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
    newNode->p = p;
    newNode->next = NULL;
    return newNode;
}

// initialize empty queue
void initQueue(queue* q) { 
    q->front = NULL;
    q->rear = NULL;
}

// check if queue is empty
bool isQueueEmpty(queue* q) { 
    return q->front == NULL;
}

// enqueue a process to end of queue
void enqueue(queue* q, process p) { 
    queueNode* newNode = createNode(p);

    if (isQueueEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

// dequeue a process from front of queue
process dequeue(queue* q) { 
    if (isQueueEmpty(q)) {
        process p = {-1, -1};
        return p;
    }

    queueNode* tempNode = q->front;
    process tempProcess = tempNode->p;

    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    }
    else {
        q->front = q->front->next;
    }

    free(tempNode);
    return tempProcess;
}

// Round Robin scheduling algorithm
void roundRobinScheduling(process p[], int n, int quantum) {
    queue q;
    initQueue(&q);
    int time = 0;
    int wt[n], tat[n], rem_bt[n];

    // initialize remaining burst time of all processes
    for (int i = 0; i < n; i++) {
        rem_bt[i] = p[i].burstTime;
    }

    // add first process to queue
    enqueue(&q, p[0]);

    // scheduling loop
    while (!isQueueEmpty(&q)) {
        process currProcess = dequeue(&q);
        if (currProcess.pid == -1) {
            time++;
            continue;
        }
        int burstTime = currProcess.burstTime;
        if (burstTime <= quantum) {
            time += burstTime;
            for (int i = 0; i < n; i++) {
                if (i != currProcess.pid && rem_bt[i] > 0) {
                    enqueue(&q, p[i]);
                }
            }
        }
        else {
            time += quantum;
            burstTime -= quantum;
            for (int i = 0; i < n; i++) {
                if (i != currProcess.pid && rem_bt[i] > 0) {
                    enqueue(&q, p[i]);
                }
            }
            enqueue(&q, (process){currProcess.pid, burstTime});
        }
        wt[currProcess.pid] = time - p[currProcess.pid].burstTime;
        tat[currProcess.pid] = time;
        rem_bt[currProcess.pid] = 0;
    }

    // print out waiting time and turnaround time of each process
    printf("PID\tBurst Time\tWait Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burstTime, wt[i], tat[i]);
    }
    
    // calculate average waiting time and turnaround time of all processes
    float avgWt = 0.0, avgTat = 0.0;
    for (int i = 0; i < n; i++) {
        avgWt += wt[i];
        avgTat += tat[i];
    }
    avgWt /= n;
    avgTat /= n;
    printf("Average Waiting Time: %.2f\nAverage Turnaround Time: %.2f\n", avgWt, avgTat);
}

// main function
int main() {
    int n, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    process p[n];

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &p[i].burstTime);
        p[i].pid = i;
    }

    printf("Enter quantum time: ");
    scanf("%d", &quantum);

    roundRobinScheduling(p, n, quantum);

    return 0;
}