//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct baggage {
    int flight_num;
    char airline_name[20];
    int num_of_bags;
};

struct node {
    struct baggage data;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
    int size;
};

void initialize(struct queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int isEmpty(struct queue* q) {
    return q->front == NULL;
}

void enqueue(struct queue* q, struct baggage data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
    }
    else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    q->size++;
}

void dequeue(struct queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    else {
        struct node* temp = q->front;
        q->front = q->front->next;
        free(temp);
        q->size--;
    }
}

void displayQueue(struct queue* q) {
    struct node* temp = q->front;
    while (temp != NULL) {
        printf("Flight %d from %s has %d bags.\n", temp->data.flight_num, temp->data.airline_name, temp->data.num_of_bags);
        temp = temp->next;
    }
}

int main() {
    struct queue q;
    initialize(&q);

    int flights = 0;
    printf("Enter number of flights: ");
    scanf("%d", &flights);

    srand(time(NULL));

    for (int i = 1; i <= flights; i++) {
        struct baggage b;
        b.flight_num = i;
        printf("\nEnter airline name for flight %d: ", i);
        scanf("%s", b.airline_name);
        b.num_of_bags = rand() % 100;
        enqueue(&q, b);
    }

    printf("\nBaggage queue:\n");
    displayQueue(&q);

    printf("\nLoading...\n");

    while (!isEmpty(&q)) {
        dequeue(&q);
    }

    printf("\nAll baggage has been loaded.\n");

    return 0;
}