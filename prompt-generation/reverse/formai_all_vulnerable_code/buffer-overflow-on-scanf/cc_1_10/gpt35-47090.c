//FormAI DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the structure of a Queue node.
struct QueueNode {
    int data;
    struct QueueNode* next;
};

// Defining the structure of a Queue.
struct Queue {
    struct QueueNode *front, *rear;
};

// Function to create a new Queue node.
struct QueueNode* createQueueNode(int data) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create a new Queue.
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if a Queue is empty.
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Function to add an element to the Queue.
void enqueue(struct Queue* q, int data) {
    struct QueueNode* temp = createQueueNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = temp; 
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Function to remove an element from the Queue.
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        return -1;
    }
    struct QueueNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

int main() {
    // Creating a new Queue.
    struct Queue* queue = createQueue();
    printf("Greetings! Welcome to the medieval Queue. Shall we build one?\n\n");

    // Waiting for the user to respond.
    while(1) {
        printf("Please enter 'Aye' to add an element to the Queue, 'Nay' to remove an element from the Queue and 'Farewell' to exit.\n");
        char input[50];
        scanf("%s", input);
        
        // Checking the user's response and taking the appropriate action.
        if (strcmp(input, "Aye") == 0) {
            printf("Please enter an integer to add to the Queue: ");
            int data;
            scanf("%d", &data);
            enqueue(queue, data);
            printf("%d has been added to the Queue.\n", data);
        }
        else if (strcmp(input, "Nay") == 0) {
            int data = dequeue(queue);
            if (data == -1) {
                printf("The Queue is empty!\n");
            }
            else {
                printf("%d has been removed from the Queue.\n", data);
            }
        }
        else if (strcmp(input, "Farewell") == 0) {
            printf("Farewell, my dear friend. May the blessings of the Queen guide you on your journey.\n");
            break;
        }
        else {
            printf("That's not a valid command, my friend. Please try again.\n");
        }
    }
    
    // Freeing the memory used by the Queue.
    struct QueueNode* current = queue->front;
    while (current != NULL) {
        struct QueueNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
    return 0;
}