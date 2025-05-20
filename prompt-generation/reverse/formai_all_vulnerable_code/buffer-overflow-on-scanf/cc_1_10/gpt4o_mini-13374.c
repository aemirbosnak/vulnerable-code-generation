//GPT-4o-mini DATASET v1.0 Category: Queue Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10
#define MAX_NAME_LENGTH 30

typedef struct Survivor {
    char name[MAX_NAME_LENGTH];
    int age;
} Survivor;

typedef struct Queue {
    Survivor survivors[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

int isFull(Queue* q) {
    return q->size == MAX_SIZE;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

void enqueue(Queue* q, Survivor survivor) {
    if (isFull(q)) {
        printf("The survivor queue is full! No more souls can be added.\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->survivors[q->rear] = survivor;
    q->size++;
    printf("Survivor %s, age %d has joined the ranks! Total survivors: %d\n", survivor.name, survivor.age, q->size);
}

Survivor dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("There are no survivors left to rescue...\n");
        Survivor emptySurvivor = {"None", 0};
        return emptySurvivor;
    }
    Survivor tmp = q->survivors[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    printf("Rescued %s, age %d from the queue. Remaining survivors: %d\n", tmp.name, tmp.age, q->size);
    return tmp;
}

void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("The queue of survivors is empty, just shadows of memory remain...\n");
        return;
    }
    printf("Current survivors in the queue:\n");
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % MAX_SIZE;
        printf("  %s, age %d\n", q->survivors[index].name, q->survivors[index].age);
    }
}

void freeQueue(Queue* q) {
    free(q);
    printf("The queue has been dismantled. No more survivors will be added...\n");
}

int main() {
    Queue* survivorQueue = createQueue();
    char input[100];
    int age;

    printf("In this world, survivors are precious. Fill the queue with souls...\n");

    while (1) {
        printf("Enter survivor's name (or type 'exit' to leave): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;  // Strip newline character

        if (strcmp(input, "exit") == 0) {
            break;
        }

        printf("Enter age of survivor %s: ", input);
        scanf("%d", &age);
        while(getchar() != '\n'); // Clear the input buffer

        Survivor newSurvivor;
        strcpy(newSurvivor.name, input);
        newSurvivor.age = age;

        enqueue(survivorQueue, newSurvivor);
        printQueue(survivorQueue);
    }

    while (!isEmpty(survivorQueue)) {
        dequeue(survivorQueue);
    }
    
    freeQueue(survivorQueue);
    return 0;
}