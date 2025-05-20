//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Define the structure of the Queue
typedef struct Queue{
    int data;
    struct Queue* next;
}Queue;

// Create an empty Queue
Queue* createQueue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->next = NULL;
    return queue;
}

// Check if the Queue is empty
bool isEmpty(Queue* queue){
    return queue->next == NULL;
}

// Add an element to the Queue
void enqueue(Queue* queue, int data){
    Queue* newNode = (Queue*)malloc(sizeof(Queue));
    newNode->data = data;
    newNode->next = NULL;
    if(isEmpty(queue)){
        queue->next = newNode;
    }else{
        Queue* temp = queue->next;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Remove an element from the Queue
int dequeue(Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
        return -1;
    }else{
        Queue* temp = queue->next;
        int data = temp->data;
        queue->next = temp->next;
        free(temp);
        return data;
    }
}

// Display the elements of the Queue
void displayQueue(Queue* queue){
    if(isEmpty(queue)){
        printf("Queue is empty\n");
    }else{
        Queue* temp = queue->next;
        printf("Queue elements: ");
        while(temp!= NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main(){
    Queue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    displayQueue(queue);
    int dequeuedData = dequeue(queue);
    printf("Dequeued data: %d\n", dequeuedData);
    displayQueue(queue);
    return 0;
}