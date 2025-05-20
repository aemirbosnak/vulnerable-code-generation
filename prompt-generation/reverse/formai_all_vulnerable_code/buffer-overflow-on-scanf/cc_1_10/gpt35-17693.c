//FormAI DATASET v1.0 Category: Queue Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

struct queue {
    int front, rear, size;
    int capacity;
    int* array;
};

struct queue* createQueue(int capacity)
{
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;  
    q->array = (int*)malloc(q->capacity * sizeof(int));
    return q;
}

int isFull(struct queue* q)
{
    return (q->size == q->capacity);
}

int isEmpty(struct queue* q)
{
    return (q->size == 0);
}

void enqueue(struct queue* q, int item)
{
    if (isFull(q))
        return;
    q->rear = (q->rear + 1) % q->capacity;
    q->array[q->rear] = item;
    q->size = q->size + 1;
}

int dequeue(struct queue* q)
{
    if (isEmpty(q))
        return -1;
    int item = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    return item;
}

int main()
{
    int capacity,choice,element;
    printf("Enter the maximum capacity of the queue: ");
    scanf("%d",&capacity);

    struct queue* q = createQueue(capacity);
    do{
        printf("\n***QUEUE OPERATIONS***\n");
        printf("1.Enque\n2.Deque\n3.Exit\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d",&element);
                enqueue(q,element);
                printf("Enqueued: %d",element);
                break;
            case 2:
                element = dequeue(q);
                if(element == -1){
                    printf("Queue is empty");
                }
                else{
                    printf("Dequeued: %d",element);
                }
                break;
            default:
                break;
        }
    } while(choice != 3);

    return 0;
}