//FormAI DATASET v1.0 Category: Queue Implementation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

// Define the structure of the Queue
struct Queue{
    int front, rear, capacity;
    int* array;
};

// Function to create a Queue of given capacity
struct Queue* createQueue(int capacity){
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if Queue is full
int isFull(struct Queue* queue){
    return (queue->rear == queue->capacity - 1);
}

// Function to check if Queue is empty
int isEmpty(struct Queue* queue){
    return (queue->front == -1);
}

// Function to add an element to the Queue
void enqueue(struct Queue* queue, int item){
    if(isFull(queue))
        printf("\nQueue is full. Cannot add element");
    else{
        queue->rear++;
        queue->array[queue->rear] = item;
        if(queue->front==-1)
            queue->front=0;
    }
}

// Function to remove an element from the Queue
int dequeue(struct Queue* queue){
    int item;
    if(isEmpty(queue)){
        printf("\nQueue is empty. Cannot remove element");
        item = -1;
    }
    else{
        item = queue->array[queue->front];
        queue->front++;
        if(queue->front > queue->rear){
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

// Function to display the elements in Queue
void display(struct Queue* queue){
    int i;
    if(isEmpty(queue))
        printf("\nQueue is empty");
    else{
        printf("\nElements in the Queue are: ");
        for(i = queue->front; i <= queue->rear; i++)
            printf("%d ", queue->array[i]);
    }
}

// Main Function
int main(){
    int choice, item, capacity;
    printf("Enter the capacity of the Queue: ");
    scanf("%d",&capacity);
    struct Queue* queue = createQueue(capacity);
    while(1){
        printf("\n\nOperations on Queue:\n"
            "1. Enqueue\n"
            "2. Dequeue\n"
            "3. Display the Queue\n"
            "4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter the element to add: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                item = dequeue(queue);
                if(item != -1)
                    printf("\nElement dequeued: %d", item);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid choice! Try again");
        }
    }
    return 0;
}