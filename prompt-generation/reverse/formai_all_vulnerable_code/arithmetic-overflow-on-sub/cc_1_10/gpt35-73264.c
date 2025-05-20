//FormAI DATASET v1.0 Category: Queue ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

struct queue{
    int front;
    int rear;
    int capacity;
    int *arr; 
};

// Function prototypes
struct queue* createQueue(int capacity);
void enQueue(struct queue* q, int item);
int deQueue(struct queue* q);
int isFull(struct queue* q);
int isEmpty(struct queue* q);

int main(){
    int capacity; 
    printf("Enter the capacity of the queue:\n");
    scanf("%d", &capacity);

    struct queue* q = createQueue(capacity);
    printf("Queue has been created successfully!\n");

    int choice, item;
    do{
        printf("\n\nMain Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(isFull(q)){
                    printf("Queue is FULL!!\n");
                }
                else{
                    printf("Enter the element to be Enqueued: ");
                    scanf("%d", &item);
                    enQueue(q, item);
                    printf("%d has been Enqueued successfully!\n", item);
                }
                break;

            case 2:
                if(isEmpty(q)){
                    printf("Queue is EMPTY!!\n");
                }
                else{
                    item = deQueue(q);
                    printf("%d has been Dequeued successfully!\n", item);
                }
                break;

            case 3:
                printf("Exiting the program...Thank you!\n");
                break;

            default:
                printf("Invalid choice!!\n");
        }
    }while(choice!=3);

    return 0;
}

// Function to create a Queue of given capacity
struct queue* createQueue(int capacity){
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;
    q->arr = (int*)malloc(q->capacity * sizeof(int));
    return q;
}

// Function to check if the Queue is FULL or not
int isFull(struct queue* q){
    if(q->rear == q->capacity-1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to check if the Queue is EMPTY or not
int isEmpty(struct queue* q){
    if(q->front == -1 && q->rear == -1){
        return 1;
    }
    else{
        return 0;
    }
}

// Function to add an item to the Queue
void enQueue(struct queue* q, int item){
    if(q->rear == -1){  // Queue is empty
        q->front = q->rear = 0;
        q->arr[q->rear] = item;
    }
    else{
        q->rear++;
        q->arr[q->rear] = item;
    }
}

// Function to remove an item from the Queue
int deQueue(struct queue* q){
    int item = q->arr[q->front];

    if(q->front == q->rear){ // Only 1 element is present in the Queue
        q->front = q->rear = -1;
    }
    else{
        q->front++;
    }

    return item;
}