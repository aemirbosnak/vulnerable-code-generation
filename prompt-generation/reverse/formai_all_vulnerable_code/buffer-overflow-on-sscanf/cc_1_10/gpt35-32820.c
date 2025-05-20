//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024

typedef struct Packet{
    int id;
    int size;
    int priority;
    time_t timestamp;
} Packet;

typedef struct QueueNode{
    Packet* packet;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue{
    QueueNode* front;
    QueueNode* rear;
} Queue;

void enqueue(Queue* q, Packet* packet){
    QueueNode* node = (QueueNode*) malloc(sizeof(QueueNode));
    node->packet = packet;
    node->next = NULL;

    if(q->front == NULL && q->rear == NULL){
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
}

int isEmpty(Queue* q){
    return q->front == NULL;
}

Packet* dequeue(Queue* q){
    if(isEmpty(q)){
        return NULL;
    }

    QueueNode* node = q->front;
    Packet* packet = node->packet;

    if(q->front == q->rear){
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
    }

    free(node);
    return packet;
}

void printPacket(Packet* packet){
    printf("Packet %d - Size: %d | Priority: %d | Timestamp: %s", packet->id, packet->size, packet->priority, ctime(&(packet->timestamp))); 
}

void printQueue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
    }

    QueueNode* node = q->front;
    while(node != NULL){
        printPacket(node->packet);
        node = node->next;
    }
}

int main(){
    Queue highPriorityQueue = {NULL, NULL};
    Queue mediumPriorityQueue = {NULL, NULL};
    Queue lowPriorityQueue = {NULL, NULL};

    int packetId = 1;
    int priority, size;
    char input[MAX_PACKET_SIZE];

    printf("Welcome to the Network Quality of Service (QoS) monitor!\n");

    while(1){
        printf("\nEnter packet details (priority size): ");
        fgets(input, MAX_PACKET_SIZE, stdin);

        if(strcmp(input, "exit\n") == 0){
            break;
        }

        if(sscanf(input, "%d %d", &priority, &size) != 2){
            printf("Invalid input! Please enter two integers separated by a space.\n");
            continue;
        }

        if(priority < 1 || priority > 3){
            printf("Invalid priority! Please enter a number between 1 and 3.\n");
            continue;
        }

        Packet* packet = (Packet*) malloc(sizeof(Packet));
        packet->id = packetId++;
        packet->priority = priority;
        packet->size = size;
        packet->timestamp = time(NULL);

        switch(priority){
            case 1:
                enqueue(&highPriorityQueue, packet);
                break;
            case 2:
                enqueue(&mediumPriorityQueue, packet);
                break;
            case 3:
                enqueue(&lowPriorityQueue, packet);
                break;
        }

        printf("Packet received.\n");
    }

    printf("High priority queue:\n");
    printQueue(&highPriorityQueue);

    printf("Medium priority queue:\n");
    printQueue(&mediumPriorityQueue);

    printf("Low priority queue:\n");
    printQueue(&lowPriorityQueue);

    return 0;
}