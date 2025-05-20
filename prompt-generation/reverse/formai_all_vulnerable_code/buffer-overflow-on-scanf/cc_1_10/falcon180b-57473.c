//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct node{
    int data;
    struct node* next;
} Node;

// Define the structure of a queue
typedef struct queue{
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* create_node(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Function to create an empty queue
Queue* create_queue(){
    Queue* new_queue = (Queue*)malloc(sizeof(Queue));
    new_queue->front = NULL;
    new_queue->rear = NULL;
    return new_queue;
}

// Function to add an element to the end of the queue
void enqueue(Queue* queue, int data){
    Node* new_node = create_node(data);
    if(queue->rear == NULL){
        queue->front = new_node;
        queue->rear = new_node;
    }
    else{
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

// Function to remove an element from the beginning of the queue
int dequeue(Queue* queue){
    int data;
    Node* temp_node = queue->front;
    data = temp_node->data;
    queue->front = queue->front->next;
    if(queue->front == NULL){
        queue->rear = NULL;
    }
    free(temp_node);
    return data;
}

// Function to display the elements of the queue
void display(Queue* queue){
    Node* temp_node = queue->front;
    printf("Queue: ");
    while(temp_node!= NULL){
        printf("%d ", temp_node->data);
        temp_node = temp_node->next;
    }
    printf("\n");
}

// Main function
int main(){
    Queue* queue = create_queue();
    int choice, data;
    while(1){
        printf("Enter your choice:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be enqueued: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                data = dequeue(queue);
                if(data == -1){
                    printf("Queue is empty!\n");
                }
                else{
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}